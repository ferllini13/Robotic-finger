#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "../include/robofingerlib.h"

int btn = 0, resolution = 0, press = 0;

/**
 * This function write the message to the USB,
 * sending the message/command recieved by the parameter
 * cmd.
 */
int robo_write(char *cmd)
{
    int ret, fd;
    fd = open("/dev/robofinger", O_WRONLY);
    if (fd < 0)
    {
        perror("Failed to open RoboFinger. Is it plugged in?");
        return errno;
    }
    printf("Command:\t*%s*\n", cmd);
    ret = write(fd, cmd, strlen(cmd));
    if (ret < 0)
    {
        perror("Failed to write the message to RoboFinger.");
        return errno;
    }
    return 0;
}

/**
 * This function sets the selected resolution to be sent to 
 * the device. The resolution is recieved by the parameter 
 * pResolution.
 */
void setResolution (int pResolution){
    resolution = pResolution;
    printf("\nSetting resolution in %d\n", resolution);
}

/**
 * This function receive the number of the button to which
 * will be touched, it also sets the button value. It send
 * the move and touch instruction to the device. The
 * parameter pBtn receives the button value.
 */
void setMoveT (int pBtn){
    btn = pBtn; //Set selected btn
    press = 1; //Set the press flag to 1

    char str[20];
    
    char tmpBtn[10];
    sprintf(tmpBtn, "%d", btn);

    char tmpRes[10];
    sprintf(tmpRes, "%d", resolution); 

    char tmpPress[10];
    sprintf(tmpPress, "%d", press); 

    // printf("resolution:\t%d\n", resolution);
    // printf("tmpRes:\t%s\n\n", tmpRes);

    // printf("press:\t%d\n", press);
    // printf("tmpPress:\t%s\n\n", tmpPress);
    

    strcpy(str, tmpBtn);
    strcat(str, ","); 
    strcat(str, tmpRes); 
    strcat(str, ",");   
    strcat(str, tmpPress);
    strcat(str, ",0");
   // printf("Command:\t%d,%d,%d,0\n", pBtn, resolution, press);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}

/**
 * This function receives the number of the button which
 * will be pressed by a specified amount of time, it also
 * sets the button value. It send the move and press
 * instruction to the device. The parameter pBtn receives the
 * button value, and the parameter pTime receives the number
 * of seconds that the button will be pressed.
 */
void setMoveP (int pBtn, int pTime){
    btn = pBtn; //Set selected btn
    press = 1; //Set the press flag to 1

    char str[8];
    
    char tmpBtn[10];
    sprintf(tmpBtn, "%d", btn);

    char tmpRes[10];
    sprintf(tmpRes, "%d", resolution); 

    char tmpPress[10];
    sprintf(tmpPress, "%d", press); 

    char tmpTime[10];
    sprintf(tmpTime, "%d", pTime); 

    // printf("resolution:\t%d\n", resolution);
    // printf("tmpRes:\t%s\n\n", tmpRes);

    // printf("press:\t%d\n", press);
    // printf("tmpPress:\t%s\n\n", tmpPress);
    

    strcpy(str, tmpBtn);
    strcat(str, ","); 
    strcat(str, tmpRes); 
    strcat(str, ",");   
    strcat(str, tmpPress);
    strcat(str, ",");
    strcat(str, tmpTime);    
   // printf("Command:\t%d,%d,%d,%d\n", pBtn, resolution, press, pTime);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}

/**
 * This function sets the value of the last movement to use it later.
 * The parameter pBtn receives the button value.
 */
void setMoveS (int pBtn){
    btn = pBtn; //Set selected btn
    printf("Setting position in %d\n", btn);
}

/**
 * This function receives the number of the button and send the move
 * instruction to the device, it also sets the button value. The
 * parameter pBtn receives the button value.
 */
void setMove (int pBtn){
    btn = pBtn; //Set selected btn
    press = 0; //Set the press flag to 0

    char str[8];
    
    char tmpBtn[10];
    sprintf(tmpBtn, "%d", btn);

    char tmpRes[10];
    sprintf(tmpRes, "%d", resolution); 

    char tmpPress[10];
    sprintf(tmpPress, "%d", press);

    // printf("resolution:\t%d\n", resolution);
    // printf("tmpRes:\t%s\n\n", tmpRes);

    // printf("press:\t%d\n", press);
    // printf("tmpPress:\t%s\n\n", tmpPress);
    

    strcpy(str, tmpBtn);
    strcat(str, ","); 
    strcat(str, tmpRes); 
    strcat(str, ",");   
    strcat(str, tmpPress);
    strcat(str, ",0");
   // printf("Command:\t%d,%d,%d,0\n", pBtn, resolution, press);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}

/**
 * This function sends the touch instruction to the device in
 * the last settled position (it ignores the initial position).
 */ 
void setTouch (){
    press = 1; //Set the press flag to 1

    char str[8];
    
    char tmpBtn[10];
    sprintf(tmpBtn, "%d", btn);

    char tmpRes[10];
    sprintf(tmpRes, "%d", resolution); 

    char tmpPress[10];
    sprintf(tmpPress, "%d", press);

    // printf("resolution:\t%d\n", resolution);
    // printf("tmpRes:\t%s\n\n", tmpRes);

    // printf("press:\t%d\n", press);
    // printf("tmpPress:\t%s\n\n", tmpPress);
    

    strcpy(str, tmpBtn);
    strcat(str, ","); 
    strcat(str, tmpRes); 
    strcat(str, ",");   
    strcat(str, tmpPress);
    strcat(str, ",0");
   // printf("Command:\t%d,%d,%d,0\n", btn, resolution, press);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}

/**
 * This function sends the press instruction with the number of
 * seconds to the device in the last settled position (it ignores
 * the initial position). The parameter pTime receives the number
 * of seconds that the button will be pressed.
 */ 
void setPress (int pTime){
    press = 1; //Set the press flag to 1

    char str[8];
    
    char tmpBtn[10];
    sprintf(tmpBtn, "%d", btn);

    char tmpRes[10];
    sprintf(tmpRes, "%d", resolution); 

    char tmpPress[10];
    sprintf(tmpPress, "%d", press); 

    char tmpTime[10];
    sprintf(tmpTime, "%d", pTime); 

    // printf("resolution:\t%d\n", resolution);
    // printf("tmpRes:\t%s\n\n", tmpRes);

    // printf("press:\t%d\n", press);
    // printf("tmpPress:\t%s\n\n", tmpPress);
    

    strcpy(str, tmpBtn);
    strcat(str, ","); 
    strcat(str, tmpRes); 
    strcat(str, ",");   
    strcat(str, tmpPress);
    strcat(str, ",");
    strcat(str, tmpTime); 
   // printf("Command:\t%d,%d,%d,%d\n", btn, resolution, press, pTime);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}

/**
 * This function is used when the values read by the interpreter
 * are out of bounds. Sends a "do nothing" instruction to the
 * device.
 */
void reset (){
    printf("Do nothing\n");
     if (robo_write("10,10,10,10") == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}