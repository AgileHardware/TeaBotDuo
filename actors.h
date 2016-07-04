#ifndef __ACTORS_H__
#define __ACTORS_H__

#include <Arduino.h>
#include "config.h"

//                        RRGGBB  
#define EYE_COLOR     0x000000ff
#define LID_COLOR     0x00000000
#define BALL_COLOR    0x003f3f3f
#define BACKGND_COLOR 0x00000000
#define SELECT_COLOR  0x0000ff00
#define COUNT_COLOR   0x007f0000
#define READY_COLOR   0x000000ff

#define BRIGHTNESS          0x7f

#define TONE_DELAY           100

void setupLeds();
void setupArms();

void ensureArmLow(byte side);
void lowerArm(byte side);
void raiseArm(byte side);

void soundSignal();

void glowEyes();
long animateEyes();
void drawCountDown(byte side, long ms, long color);
void showAll();

#endif
