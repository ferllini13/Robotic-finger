#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int robo_write(char *cmd)
{
    int ret, fd;
    fd = open("/dev/robofinger", O_WRONLY);
    if (fd < 0)
    {
        perror("Failed to open RoboFinger. Is it plugged in?");
        return errno;
    }
    printf("Command: %s\n", cmd);
    ret = write(fd, cmd, strlen(cmd));
    if (ret < 0)
    {
        perror("Failed to write the message to RoboFinger.");
        return errno;
    }
    return 0;
}