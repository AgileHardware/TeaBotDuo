#ifndef __STATE_H__
#define __STATE_H__

#include <Arduino.h>
#include "config.h"

#define IDLE                   0
#define SELECT_TIME            1
#define COUNT_DOWN             2  
#define TEA_READY              3

void setupStateMachine();

#endif

