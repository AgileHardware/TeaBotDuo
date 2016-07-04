#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <Arduino.h>

#define LEFT                      0
#define RIGHT                     1
#define NUM_SIDES                 2

#define DELTA         ((long)60000)
#define MIN_VALUE         (DELTA*0)
#define MAX_VALUE        (DELTA*11)
#define LEFT_DEFAULT       (360000)
#define RIGHT_DEFAULT      (360000)        


#define LED_PIN                    7
#define NUM_LEDS                  24
#define NUM_RINGS                  2

#define LEFT_ARM_PIN               9
#define RIGHT_ARM_PIN              5

#define LEFT_ARM_LOWER           137
#define LEFT_ARM_UPPER            50
#define RIGHT_ARM_LOWER           60
#define RIGHT_ARM_UPPER          148  

#define ARM_DELAY                100
#define ARM_DELAY_LONG (5*ARM_DELAY)
#define ARM_STEPS                 10

#define LEFT_SENSOR_PIN       A4
#define RIGHT_SENSOR_PIN      A5

#define LEFT_UP_PIN            0
#define LEFT_DOWN_PIN          2
#define RIGHT_UP_PIN           3
#define RIGHT_DOWN_PIN         4 

#define PIEZO_PIN              1

#define LEDS_PER_RING  (NUM_LEDS/NUM_RINGS)
#define OFFSET_LEFT      LEDS_PER_RING        
#define OFFSET_RIGHT           0
#define ROTATION_LEFT          6
#define ROTATION_RIGHT         6
#define DELAY                 15

#endif
