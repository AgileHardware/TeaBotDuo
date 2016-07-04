#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <Arduino.h>

#define LEFT                       0
#define RIGHT                      1
#define NUM_SIDES                  2

#define MS_PER_LED     ((long)60000)         //  1 min
#define MIN_VALUE     (MS_PER_LED*0)         //  0 min
#define MAX_VALUE    (MS_PER_LED*11)         // 11 min
#define LEFT_DEFAULT  ((long)360000)         //  6 min      Maybe you want to use different  
#define RIGHT_DEFAULT ((long)360000)         //  6 min      values for both sides? 
#define STAY_ACTIVE   ((long)900000)         // 15 min


#define LED_PIN                    7
#define NUM_LEDS                  24
#define NUM_RINGS          NUM_SIDES

#define LEFT_ARM_PIN               9
#define RIGHT_ARM_PIN              5

#define LEFT_ARM_LOWER           137          // depending on how you 
#define LEFT_ARM_UPPER            50          // mounted the arms, their
#define RIGHT_ARM_LOWER           60          // values for lower and upper
#define RIGHT_ARM_UPPER          148          // position need adjustment

#define ARM_DELAY                100
#define ARM_DELAY_LONG (5*ARM_DELAY)
#define ARM_STEPS                 10

#define LEFT_SENSOR_PIN           A4
#define RIGHT_SENSOR_PIN          A5

#define LEFT_UP_PIN                0
#define LEFT_DOWN_PIN              2
#define RIGHT_UP_PIN               3
#define RIGHT_DOWN_PIN             4 

#define PIEZO_PIN                  1

#define LEDS_PER_RING  (NUM_LEDS/NUM_RINGS)

#define OFFSET_LEFT         LEDS_PER_RING     // depending on how  
#define OFFSET_RIGHT               0          // you wired and 
#define ROTATION_LEFT              6          // glued the LED rings
#define ROTATION_RIGHT             5          // these 4 values need to be adjusted

#endif
