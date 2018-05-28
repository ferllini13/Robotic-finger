#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>

#define DEVICE_NAME "robofinger"
#define DEVICE_MAX_PATH 20
#define DEVICE_NUM 0
#define DEVICE_MAX_BUF_LEN 200

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Luis Saborio - Andres Arias - Francisco Alvarado");
MODULE_DESCRIPTION("Robotic Finger capable of interacting with touchscreen devices.");
MODULE_VERSION("1.0");

DEFINE_MUTEX(dev_mutex);

static int robo_open(struct inode *, struct file *);
static int robo_release(struct inode *, struct file *);
static ssize_t robo_write(struct file *, const char *, size_t, loff_t *);

// Estructura para el manejo de las operaciones
static struct file_operations dev_ops = {
    .owner = THIS_MODULE,
    .open = robo_open,
    .release = robo_release,
    .write = robo_write,
};

static struct cdev cdev;
static struct class *class;
static int dev_mjr;
static int major_number;


/** @brief RoboFinger module initialization function.
 *  The __init macro means that the function is only used at initialization time
 *  and that it can be discarded and its memory freed up after that point.
 *  @return returns 0 if successful.
 */
static int __init robo_init(void)
{
    dev_t devt;
    major_number = register_chrdev(0, DEVICE_NAME, &dev_ops);
    if (major_number < 0){
        printk(KERN_ALERT "RoboFinger failed to register a major number\n");
        return major_number;
    }
    devt = MKDEV(0, 0);
    if (alloc_chrdev_region(&devt, 0, 1, DEVICE_NAME) < 0)
        return -1;
    dev_mjr = MAJOR(devt);

    cdev_init(&cdev, &dev_ops);
    cdev.owner = THIS_MODULE;
    devt = MKDEV(dev_mjr, 0);
    if (cdev_add(&cdev, devt, 1))
    {
        unregister_chrdev_region(MKDEV(dev_mjr, 0), 1);
        return -1;
    }

    class = class_create(THIS_MODULE, DEVICE_NAME);
    if (!class)
        cdev_del(&cdev);

    devt = MKDEV(dev_mjr, 0);
    if (!(device_create(class, NULL, devt, NULL, DEVICE_NAME)))
        class_destroy(class);

    printk(KERN_INFO "RoboFinger succesfully initialized!\n");
    return 0;
}

/** @brief RoboFinger cleanup function
 *  The __exit macro notifies that function is not required.
 */
static void __exit robo_exit(void)
{
    device_destroy(class, MKDEV(dev_mjr, 0));
    class_destroy(class);
    cdev_del(&cdev);
    unregister_chrdev_region(MKDEV(dev_mjr, 0), 1);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "RoboFinger succesfully unmounted.\n");
}

static struct file *device = NULL;

/** @brief RoboFinger open function that is called each time the device is opened
 *  @param inodep A pointer to an inode object (defined in linux/fs.h)
 *  @param filep A pointer to a file object (defined in linux/fs.h)
 *  @return returns 0 if successful, -EBUSY if the device is busy.
 */
static int robo_open(struct inode *inodep, struct file *filep)
{
    char filename[DEVICE_MAX_PATH];

    if(!(mutex_trylock(&dev_mutex))) // Multiprocess syncronization.
    {
        printk(KERN_ALERT "RoboFinger busy.\n");
        return -EBUSY;
    }

    printk(KERN_INFO "RoboFinger opened.\n");
    snprintf(filename, DEVICE_MAX_PATH, "/dev/ttyACM%d", DEVICE_NUM);
    device = filp_open(filename, 0, O_RDWR);
    if (PTR_RET(device)) {
        mutex_unlock(&dev_mutex);
        printk(KERN_INFO "RoboFinger opened.\n");
        return PTR_RET(device);
    }
    return 0;
}

/** @brief RoboFinger release function that is called whenever the device is closed/released by
 *  the userspace library.
 *  @param inodep A pointer to an inode object (defined in linux/fs.h)
 *  @param filep A pointer to a file object (defined in linux/fs.h)
 *  @return returns 0 if successful.
 */
static int robo_release(struct inode *inodep, struct file *filep)
{
    if(!IS_ERR_OR_NULL(device))
        filp_close(device, 0);
    mutex_unlock(&dev_mutex);
    printk(KERN_INFO "RoboFinger released.");
    return 0;
}

/** @brief This function is called whenever the device is being written to from user space.
 *  @param filep A pointer to a file object
 *  @param buf The buffer to that contains the string to write to the device
 *  @param count The length of the array of data that is being passed in the const char buffer
 *  @param f_pos The offset if required.
 *  @return returns 0 if successful, -EFAULT if not.
 */
static ssize_t robo_write(struct file *filep,
                 const char __user * buf, size_t count,
                 loff_t * f_pos)
{
    const char kbuf[DEVICE_MAX_BUF_LEN];
    int result;
    mm_segment_t oldfs;

	printk(KERN_INFO "User writing %d characters into RoboFinger.\n", (int)count);
    count = count < DEVICE_MAX_BUF_LEN ? count : DEVICE_MAX_BUF_LEN;
    if (copy_from_user((char *)kbuf, (const char __user *)buf, count))
        return -EFAULT;

    if (!IS_ERR_OR_NULL(device))
    {
        oldfs = get_fs();
        set_fs(KERNEL_DS);
        device->f_pos = 0;
        result = device->f_op->write(device, kbuf, count, &device->f_pos);
        set_fs(oldfs);
        return result;
    }
    else
        return -EFAULT;
}

module_init(robo_init);
module_exit(robo_exit);