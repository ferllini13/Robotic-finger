#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main (char argc, char * argv[]) {    
    FILE * fp;    
    if(strcmp(argv[1], "-c") == 0){
//        if(strcmp()){ 
        if(1){ 
            fp = fopen(argv[2], "r");
            if (fp == NULL){
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            else{
                char command[256];
                int resolution = 0, x = 0, y = 0, pTime = 0, press = 0, btn = 0;
                char * line = NULL;
                size_t len = 0;
                size_t read;

                while ((read = getline(&line, &len, fp)) != -1) {
                    if(line[0] == '#' || line[0] == '\n')
                        continue;
                    else{
                        sscanf(line, "%s", command);      
                        if(strcmp(command, "resolution") == 0){  //Read the
                            sscanf(line, "%s %d", command, &resolution);
                        } else if(strcmp(command, "moveT") == 0){  //Read the 
                            sscanf(line, "%s %d %d", command, &x, &y);
                            setBtn(x, y, &btn);
                            press = 1;
                        } else if(strcmp(command, "moveP") == 0){  //Read the 
                            sscanf(line, "%s %d %d %d", command, &x, &y, &pTime);
                            press = 1;
                            setBtn(x, y, &btn);
                        } else if(strcmp(command, "move") == 0){  //Read the 
                            sscanf(line, "%s %d %d", command, &x, &y);
                            press = 0;
                            setBtn(x, y, &btn);
                        } else if(strcmp(command, "touch") == 0){  //Read the
                            press = 1;                 
                        } else if(strcmp(command, "press") == 0){  //Read the 
                            sscanf(line, "%s %d", command, &pTime);
                            press = 1;
                        }

                        // printf("%s:\n", command);
                        // printf("resolution\t%d\n", resolution);
                        // printf("x\t\t%d\n", x);
                        // printf("y\t\t%d\n", y);
                        // printf("btn\t\t%d\n", btn);
                        // printf("pTime\t\t%d\n", pTime);
                        // printf("***ARDUINO**************\n(%d %d),%d,%d,%d\n", x, y, resolution, press, pTime);
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
        }
    } else {
        printf("Error.\n");
    }
}