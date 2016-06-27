#ifndef __ACTORS_H__
#define __ACTORS_H__

#include <Arduino.h>
#include "config.h"

#define LEFT_DEFAULT_VALUE     6
#define RIGHT_DEFAULT_VALUE    6

//                        RRGGBB  
#define EYE_COLOR     0x000000ff
#define LID_COLOR     0x00000000
#define BALL_COLOR    0x003f3f3f
#define BACKGND_COLOR 0x00000000
#define SELECT_COLOR  0x0000ff00
#define COUNT_COLOR   0x00ff0000
#define READY_COLOR   0x000000ff

#define BRIGHTNESS          0xff

#define TONE_DELAY           100

void setupLeds();
void setupArms();

void lowerArm(boolean left);
void raiseArm(boolean left);

void soundSignal();

void creepyGlowingEyes();
long animateEyes();
void drawCountDown(boolean left, int seconds, long color);

#endif
