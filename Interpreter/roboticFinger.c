#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/robofingerlib.c"


int validatePosition(int btn){
    if (btn >= 0 && btn <= 9){
        return 1;
    } else {
        return 0;
    }

}

/**
 * This function read the specified code from the file
 * and do the interpreter work. Use the driver library
 * to send the information to the driver.
 */
int main (char argc, char * argv[]) {    
    FILE * fp;    
    if(strcmp(argv[1], "-c") == 0){ //Check the -c flag
        if(argc < 3){
            printf("Error, configuration file not provided.\n");
            exit(0);
        } else {
            fp = fopen(argv[2], "r"); //Read the specified file
            if (fp == NULL){
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            else{
                char command[256];
                int resolution = 0, btn = 0, pTime = 0, stop = 0; //Create the multiple variables
                char * line = NULL; //Char variable to read each line in the file
                size_t len = 0;
                size_t read;
                while ((read = getline(&line, &len, fp)) != -1) {
                    if (stop == 0){
                            if(line[0] == '#' || line[0] == '\n')
                            continue;
                        else{
                            sscanf(line, "%s", command);      
                            if(strcmp(command, "resolution") == 0){  //Read the and compare if the command is resolution                            sscanf(line, "%s %d", command, &resolution);
                                sscanf(line, "%s %d", command, &resolution); //Read the variaables set with the command
                                setResolution(resolution);
                            } else if(strcmp(command, "moveT") == 0){  //Read the and compare if the command is moveT
                                sscanf(line, "%s %d", command, &btn); //Read the variaables set with the command
                                if(validatePosition(btn)){
                                    setMoveT(btn);
                                } else {
                                    stop = 1; //Setting stop flag in 1
                                    printf("Value %d out of bounds [0,9]\n", btn);
                                    reset();
                                }
                                
                            } else if(strcmp(command, "moveP") == 0){  //Read the and compare if the command is moveP
                                sscanf(line, "%s %d %d", command, &btn, &pTime); //Read the variaables set with the command
                                if(validatePosition(btn)){
                                    setMoveP(btn, pTime);
                                } else {
                                    stop = 1; //Setting stop flag in 1
                                    printf("Value %d out of bounds [0,9]\n", btn);
                                    reset();
                                }
                            } else if(strcmp(command, "move") == 0){  //Read the and compare if the command is move
                                sscanf(line, "%s %d", command, &btn); //Read the variaables set with the command
                                if(validatePosition(btn)){
                                    setMove(btn);
                                } else {
                                    stop = 1; //Setting stop flag in 1
                                    printf("Value %d out of bounds [0,9]\n", btn);
                                    reset();
                                }
                            } else if(strcmp(command, "moveS") == 0){  //Read the and compare if the command is move
                                sscanf(line, "%s %d", command, &btn); //Read the variaables set with the command
                                if(validatePosition(btn)){
                                    setMoveS(btn);
                                } else {
                                    stop = 1; //Setting stop flag in 1
                                    printf("Value %d out of bounds [0,9]\n", btn);
                                    reset();
                                }
                            } else if(strcmp(command, "touch") == 0){  //Read the and compare if the command is touch
                                setTouch();
                            } else if(strcmp(command, "press") == 0){  //Read the and compare if the command is press
                                sscanf(line, "%s %d", command, &pTime); //Read the variaables set with the command
                                setPress(pTime);
                            }

                            //printf("%s:\n", command);
                            //printf("resolution\t%d\n", resolution);
                            //printf("x\t\t%d\n", x);
                            //printf("y\t\t%d\n", y);
                            //printf("btn\t\t%d\n", btn);
                            //printf("pTime\t\t%d\n", pTime);
                            //printf("***ARDUINO**************\n(%d %d),%d,%d,%d\n", btn, resolution, press, pTime);
                            // printf("%d,%d,%d,%d\n\n\n", btn, resolution, press, pTime);

                            // pTime = 0;
                            // press = 0;
                            // btn = 0;
                        }
                    }
                }
                fclose(fp);    
            }
        }
    } else {
        printf("Error, no the right flag. \n");
        exit(0);
    }
}