#ifndef _ROBOFINGERLIB_H
#define _ROBOFINGERLIB_H

int robo_write(char *);
void setResolution (int);
void setMoveT (int);
void setMoveP (int, int);
void setMove (int);
void setMoveS (int);
void setTouch ();
void setPress (int);
void reset ();

#endif