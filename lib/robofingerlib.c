#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "../include/robofingerlib.h"

int btn = 0, resolution = 0, press = 0;

int robo_write(char *cmd)
{
    int ret, fd;
    fd = open("/dev/robofinger", O_WRONLY);
    if (fd < 0)
    {
        perror("Failed to open RoboFinger. Is it plugged in?");
        return errno;
    }
    printf("Command:\t%s\n", cmd);
    ret = write(fd, cmd, strlen(cmd));
    if (ret < 0)
    {
        perror("Failed to write the message to RoboFinger.");
        return errno;
    }
    return 0;
}

void setResolution (int pResolution){
    resolution = pResolution;
    printf("Setting resolution in %d\n\n", resolution);
}
void setMoveT (int pBtn){
    btn = pBtn; //Set selected btn
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
    printf("Command:\t%d,%d,%d,0\n", pBtn, resolution, press);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}
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
    printf("Command:\t%d,%d,%d,%d\n", pBtn, resolution, press, pTime);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}
void setMoveS (int pBtn){
    btn = pBtn; //Set selected btn
    printf("Setting position in %d\n\n", btn);
}

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
    printf("Command:\t%d,%d,%d,0\n", pBtn, resolution, press);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}
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
    printf("Command:\t%d,%d,%d,0\n", btn, resolution, press);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}
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
    printf("Command:\t%d,%d,%d,%d\n", btn, resolution, press, pTime);
    if (robo_write(str) == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}

void reset (){
    printf("Setting initial position");
     if (robo_write("10,10,10,10") == 0){
        printf("Done\n\n");
    } else {
        printf("Error\n\n");
    }
}