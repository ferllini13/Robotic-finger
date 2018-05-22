#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This function takes the value of the x and y parameters and 
 * identifies the number of the button that will be pressed
 *    _0___1___2_ -> y
 * 0 | 1 | 2 | 3 |
 * 1 | 4 | 5 | 6 |
 * 2 | 7 | 8 | 9 |
 * 3 |___|_0_|___|
 * |
 * V
 * x
 */
void setBtn(int x, int y, int * btn){
    if(x == 0 && y == 0){
        *btn = 1;
    } else if(x == 0 && y == 1){
        *btn = 2;
    } else if(x == 0 && y == 2){
        *btn = 3;
    } else if(x == 1 && y == 0){
        *btn = 4;
    } else if(x == 1 && y == 1){
        *btn = 5;
    } else if(x == 1 && y == 2){
        *btn = 6;
    } else if(x == 2 && y == 0){
        *btn = 7;
    } else if(x == 2 && y == 1){
        *btn = 8;
    } else if(x == 2 && y == 2){
        *btn = 9;
    } else if(x == 3 && y == 1){
        *btn = 0;
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
//       if(strcmp()){  //
//       if(1){ 
            fp = fopen(argv[2], "r"); //Read the specified file
            if (fp == NULL){
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            else{
                char command[256];
                int resolution = 0, x = 0, y = 0, pTime = 0, press = 0, btn = 0; //Create the multiple variables
                char * line = NULL; //Char variable to read each line in the file
                size_t len = 0;
                size_t read;

                while ((read = getline(&line, &len, fp)) != -1) {
                    if(line[0] == '#' || line[0] == '\n')
                        continue;
                    else{
                        sscanf(line, "%s", command);      
                        if(strcmp(command, "resolution") == 0){  //Read the and compare if the command is resolution                            sscanf(line, "%s %d", command, &resolution);
                        } else if(strcmp(command, "moveT") == 0){  //Read the and compare if the command is moveT
                            sscanf(line, "%s %d %d", command, &x, &y); //Read the variaables set with the command
                            setBtn(x, y, &btn); //Call the function that takes the value of the x and y parameters and set the button to press
                            press = 1; //Set the press flag to 1
                        } else if(strcmp(command, "moveP") == 0){  //Read the and compare if the command is moveP
                            sscanf(line, "%s %d %d %d", command, &x, &y, &pTime); //Read the variaables set with the command
                            press = 1; //Set the press flag to 1
                            setBtn(x, y, &btn); //Call the function that takes the value of the x and y parameters and set the button to press
                        } else if(strcmp(command, "move") == 0){  //Read the and compare if the command is move
                            sscanf(line, "%s %d %d", command, &x, &y); //Read the variaables set with the command
                            press = 0; //Set the press flag to 0
                            setBtn(x, y, &btn); //Call the function that takes the value of the x and y parameters and set the button to press
                        } else if(strcmp(command, "touch") == 0){  //Read the and compare if the command is touch
                            press = 1; //Set the press flag to 1
                        } else if(strcmp(command, "press") == 0){  //Read the and compare if the command is press
                            sscanf(line, "%s %d", command, &pTime); //Read the variaables set with the command
                            press = 1; //Set the press flag to 1
                        }

                        //printf("%s:\n", command);
                        //printf("resolution\t%d\n", resolution);
                        //printf("x\t\t%d\n", x);
                        //printf("y\t\t%d\n", y);
                        //printf("btn\t\t%d\n", btn);
                        //printf("pTime\t\t%d\n", pTime);
                        //printf("***ARDUINO**************\n(%d %d),%d,%d,%d\n", x, y, resolution, press, pTime);
                        printf("%d,%d,%d,%d\n\n\n", btn, resolution, press, pTime);

                        x = 0;
                        y = 0;
                        pTime = 0;
                        press = 0;
                        btn = 0;
                    }
                }
                fclose(fp);    
            }
 //      }
    } else {
        printf("Error.\n");
    }
}