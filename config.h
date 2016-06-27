#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <Arduino.h>

#define LEFT                true
#define RIGHT              false

#define DELTA                 60
#define MIN_VALUE      (0*DELTA)
#define MAX_VALUE     (11*DELTA)

#define LED_PIN                7
#define NUM_LEDS              24
#define NUM_RINGS              2

#define LEFT_ARM_PIN           5
#define RIGHT_ARM_PIN          9

#define LEFT_ARM_LOWER        70
#define LEFT_ARM_UPPER       160
#define RIGHT_ARM_LOWER      137
#define RIGHT_ARM_UPPER       50 

#define ARM_DELAY             30
#define ARM_STEPS             25

#define LEFT_SENSOR_PIN       A4
#define RIGHT_SENSOR_PIN      A5

#define LEFT_UP_PIN            3
#define LEFT_DOWN_PIN          4
#define RIGHT_UP_PIN           0
#define RIGHT_DOWN_PIN         2 

#define PIEZO_PIN              1

#define LEDS_PER_RING   (NUM_LEDS/NUM_RINGS)
#define OFFSET_LEFT            6
#define OFFSET_RIGHT           6
#define DELAY                 15

#endif
