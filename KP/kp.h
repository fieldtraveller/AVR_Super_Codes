/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

kp.h

Default Settings:
Keypad Dimensions: 4x4 (columns x rows)
R1:D0
R2:D1
R3:D2
R4:D3
C1:D4
C2:D5
C3:D6
C4:D7
External Interrupt Type: INT2/PB2

DESCRIPTION:Keypad interfacing with Atmel ATmega 32/16/8.
            Macros related to kp.c defined here. Also contains function declarations.

        kp_init():Initializes the Pins.
        kp_read():Call this function to read which key is press at that instance
        kp_checkpin():Checks the status of the row pin
        kp_setpin():Set column pin as output low
        kp_resetpin():Reset column pin as input/tri-stated
        kp_putdata():Put data in circular queue
        kp_getdata():Get data from circular queue

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef KP_H_
#define KP_H_

/******************************************************************************************************/

#include "cf.h"

/******************************************************************************************************/
//Default row size macro
/******************************************************************************************************/

#if !defined(KP_MAX_ROW)
#define KP_MAX_ROW 4
#endif

/******************************************************************************************************/
//Default column size macro
/******************************************************************************************************/

#if !defined(KP_MAX_COLUMN)
#define KP_MAX_COLUMN 4
#endif

/******************************************************************************************************/
//Default GPIO port macro
/******************************************************************************************************/

#if !defined(KP_GPIO_PORT)
#define KP_GPIO_PORT D
#endif

/******************************************************************************************************/
//Row macros
/******************************************************************************************************/
//Default row macros
/******************************************************************************************************/

#if !defined(KP_1_ROW_GPIO_PORT)
#define KP_1_ROW_GPIO_PORT KP_GPIO_PORT
#endif

#if !defined(KP_2_ROW_GPIO_PORT)
#define KP_2_ROW_GPIO_PORT KP_GPIO_PORT
#endif

/******************************************************************************************************/
//Row GPIO port name macros
/******************************************************************************************************/

#if KP_MAX_ROW >= 1

#if !defined(KP_ROW_0_GPIO_PORT)
#define KP_ROW_0_GPIO_PORT KP_1_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 2

#if !defined(KP_ROW_1_GPIO_PORT)
#define KP_ROW_1_GPIO_PORT KP_1_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 3

#if !defined(KP_ROW_2_GPIO_PORT)
#define KP_ROW_2_GPIO_PORT KP_1_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 4

#if !defined(KP_ROW_3_GPIO_PORT)
#define KP_ROW_3_GPIO_PORT KP_1_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 5

#if !defined(KP_ROW_4_GPIO_PORT)
#define KP_ROW_4_GPIO_PORT KP_1_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 6

#if !defined(KP_ROW_5_GPIO_PORT)
#define KP_ROW_5_GPIO_PORT KP_1_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 7

#if !defined(KP_ROW_6_GPIO_PORT)
#define KP_ROW_6_GPIO_PORT KP_1_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 8

#if !defined(KP_ROW_7_GPIO_PORT)
#define KP_ROW_7_GPIO_PORT KP_1_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 9

#if !defined(KP_ROW_8_GPIO_PORT)
#define KP_ROW_8_GPIO_PORT KP_2_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 10

#if !defined(KP_ROW_9_GPIO_PORT)
#define KP_ROW_9_GPIO_PORT KP_2_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 11

#if !defined(KP_ROW_10_GPIO_PORT)
#define KP_ROW_10_GPIO_PORT KP_2_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 12

#if !defined(KP_ROW_11_GPIO_PORT)
#define KP_ROW_11_GPIO_PORT KP_2_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 13

#if !defined(KP_ROW_12_GPIO_PORT)
#define KP_ROW_12_GPIO_PORT KP_2_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 14

#if !defined(KP_ROW_13_GPIO_PORT)
#define KP_ROW_13_GPIO_PORT KP_2_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 15

#if !defined(KP_ROW_14_GPIO_PORT)
#define KP_ROW_14_GPIO_PORT KP_2_ROW_GPIO_PORT
#endif

#endif

#if KP_MAX_ROW >= 16

#if !defined(KP_ROW_15_GPIO_PORT)
#define KP_ROW_15_GPIO_PORT KP_2_ROW_GPIO_PORT
#endif

#endif

/******************************************************************************************************/
//Row GPIO pin number macros
/******************************************************************************************************/

#if KP_MAX_ROW >= 1

#if !defined(KP_ROW_0_GPIO_PIN)
#define KP_ROW_0_GPIO_PIN 0
#endif

#endif

#if KP_MAX_ROW >= 2

#if !defined(KP_ROW_1_GPIO_PIN)
#define KP_ROW_1_GPIO_PIN 1
#endif

#endif

#if KP_MAX_ROW >= 3

#if !defined(KP_ROW_2_GPIO_PIN)
#define KP_ROW_2_GPIO_PIN 2
#endif

#endif

#if KP_MAX_ROW >= 4

#if !defined(KP_ROW_3_GPIO_PIN)
#define KP_ROW_3_GPIO_PIN 3
#endif

#endif

#if KP_MAX_ROW >= 5

#if !defined(KP_ROW_4_GPIO_PIN)
#define KP_ROW_4_GPIO_PIN 4
#endif

#endif

#if KP_MAX_ROW >= 6

#if !defined(KP_ROW_5_GPIO_PIN)
#define KP_ROW_5_GPIO_PIN 5
#endif

#endif

#if KP_MAX_ROW >= 7

#if !defined(KP_ROW_6_GPIO_PIN)
#define KP_ROW_6_GPIO_PIN 6
#endif

#endif

#if KP_MAX_ROW >= 8

#if !defined(KP_ROW_7_GPIO_PIN)
#define KP_ROW_7_GPIO_PIN 7
#endif

#endif

#if KP_MAX_ROW >= 9

#if !defined(KP_ROW_8_GPIO_PIN)
#define KP_ROW_8_GPIO_PIN 0
#endif

#endif

#if KP_MAX_ROW >= 10

#if !defined(KP_ROW_9_GPIO_PIN)
#define KP_ROW_9_GPIO_PIN 1
#endif

#endif

#if KP_MAX_ROW >= 11

#if !defined(KP_ROW_10_GPIO_PIN)
#define KP_ROW_10_GPIO_PIN 2
#endif

#endif

#if KP_MAX_ROW >= 12

#if !defined(KP_ROW_11_GPIO_PIN)
#define KP_ROW_11_GPIO_PIN 3
#endif

#endif

#if KP_MAX_ROW >= 13

#if !defined(KP_ROW_12_GPIO_PIN)
#define KP_ROW_12_GPIO_PIN 4
#endif

#endif

#if KP_MAX_ROW >= 14

#if !defined(KP_ROW_13_GPIO_PIN)
#define KP_ROW_13_GPIO_PIN 5
#endif

#endif

#if KP_MAX_ROW >= 15

#if !defined(KP_ROW_14_GPIO_PIN)
#define KP_ROW_14_GPIO_PIN 6
#endif

#endif

#if KP_MAX_ROW >= 16

#if !defined(KP_ROW_15_GPIO_PIN)
#define KP_ROW_15_GPIO_PIN 7
#endif

#endif

/******************************************************************************************************/
//Row DDR macros
/******************************************************************************************************/

#if KP_MAX_ROW >= 1

#if !defined(KP_DDR_ROW_0)
#define KP_DDR_ROW_0 DDR(KP_ROW_0_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 2

#if !defined(KP_DDR_ROW_1)
#define KP_DDR_ROW_1 DDR(KP_ROW_1_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 3

#if !defined(KP_DDR_ROW_2)
#define KP_DDR_ROW_2 DDR(KP_ROW_2_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 4

#if !defined(KP_DDR_ROW_3)
#define KP_DDR_ROW_3 DDR(KP_ROW_3_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 5

#if !defined(KP_DDR_ROW_4)
#define KP_DDR_ROW_4 DDR(KP_ROW_4_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 6

#if !defined(KP_DDR_ROW_5)
#define KP_DDR_ROW_5 DDR(KP_ROW_5_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 7

#if !defined(KP_DDR_ROW_6)
#define KP_DDR_ROW_6 DDR(KP_ROW_6_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 8

#if !defined(KP_DDR_ROW_7)
#define KP_DDR_ROW_7 DDR(KP_ROW_7_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 9

#if !defined(KP_DDR_ROW_8)
#define KP_DDR_ROW_8 DDR(KP_ROW_8_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 10

#if !defined(KP_DDR_ROW_9)
#define KP_DDR_ROW_9 DDR(KP_ROW_9_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 11

#if !defined(KP_DDR_ROW_10)
#define KP_DDR_ROW_10 DDR(KP_ROW_10_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 12

#if !defined(KP_DDR_ROW_11)
#define KP_DDR_ROW_11 DDR(KP_ROW_11_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 13

#if !defined(KP_DDR_ROW_12)
#define KP_DDR_ROW_12 DDR(KP_ROW_12_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 14

#if !defined(KP_DDR_ROW_13)
#define KP_DDR_ROW_13 DDR(KP_ROW_13_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 15

#if !defined(KP_DDR_ROW_14)
#define KP_DDR_ROW_14 DDR(KP_ROW_14_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 16

#if !defined(KP_DDR_ROW_15)
#define KP_DDR_ROW_15 DDR(KP_ROW_15_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Row PIN macros
/******************************************************************************************************/

#if KP_MAX_ROW >= 1

#if !defined(KP_PIN_ROW_0)
#define KP_PIN_ROW_0 PIN(KP_ROW_0_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 2

#if !defined(KP_PIN_ROW_1)
#define KP_PIN_ROW_1 PIN(KP_ROW_1_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 3

#if !defined(KP_PIN_ROW_2)
#define KP_PIN_ROW_2 PIN(KP_ROW_2_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 4

#if !defined(KP_PIN_ROW_3)
#define KP_PIN_ROW_3 PIN(KP_ROW_3_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 5

#if !defined(KP_PIN_ROW_4)
#define KP_PIN_ROW_4 PIN(KP_ROW_4_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 6

#if !defined(KP_PIN_ROW_5)
#define KP_PIN_ROW_5 PIN(KP_ROW_5_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 7

#if !defined(KP_PIN_ROW_6)
#define KP_PIN_ROW_6 PIN(KP_ROW_6_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 8

#if !defined(KP_PIN_ROW_7)
#define KP_PIN_ROW_7 PIN(KP_ROW_7_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 9

#if !defined(KP_PIN_ROW_8)
#define KP_PIN_ROW_8 PIN(KP_ROW_8_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 10

#if !defined(KP_PIN_ROW_9)
#define KP_PIN_ROW_9 PIN(KP_ROW_9_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 11

#if !defined(KP_PIN_ROW_10)
#define KP_PIN_ROW_10 PIN(KP_ROW_10_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 12

#if !defined(KP_PIN_ROW_11)
#define KP_PIN_ROW_11 PIN(KP_ROW_11_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 13

#if !defined(KP_PIN_ROW_12)
#define KP_PIN_ROW_12 PIN(KP_ROW_12_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 14

#if !defined(KP_PIN_ROW_13)
#define KP_PIN_ROW_13 PIN(KP_ROW_13_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 15

#if !defined(KP_PIN_ROW_14)
#define KP_PIN_ROW_14 PIN(KP_ROW_14_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 16

#if !defined(KP_PIN_ROW_15)
#define KP_PIN_ROW_15 PIN(KP_ROW_15_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Row PORT macros
/******************************************************************************************************/

#if KP_MAX_ROW >= 1

#if !defined(KP_PORT_ROW_0)
#define KP_PORT_ROW_0 PORT(KP_ROW_0_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 2

#if !defined(KP_PORT_ROW_1)
#define KP_PORT_ROW_1 PORT(KP_ROW_1_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 3

#if !defined(KP_PORT_ROW_2)
#define KP_PORT_ROW_2 PORT(KP_ROW_2_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 4

#if !defined(KP_PORT_ROW_3)
#define KP_PORT_ROW_3 PORT(KP_ROW_3_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 5

#if !defined(KP_PORT_ROW_4)
#define KP_PORT_ROW_4 PORT(KP_ROW_4_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 6

#if !defined(KP_PORT_ROW_5)
#define KP_PORT_ROW_5 PORT(KP_ROW_5_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 7

#if !defined(KP_PORT_ROW_6)
#define KP_PORT_ROW_6 PORT(KP_ROW_6_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 8

#if !defined(KP_PORT_ROW_7)
#define KP_PORT_ROW_7 PORT(KP_ROW_7_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 9

#if !defined(KP_PORT_ROW_8)
#define KP_PORT_ROW_8 PORT(KP_ROW_8_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 10

#if !defined(KP_PORT_ROW_9)
#define KP_PORT_ROW_9 PORT(KP_ROW_9_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 11

#if !defined(KP_PORT_ROW_10)
#define KP_PORT_ROW_10 PORT(KP_ROW_10_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 12

#if !defined(KP_PORT_ROW_11)
#define KP_PORT_ROW_11 PORT(KP_ROW_11_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 13

#if !defined(KP_PORT_ROW_12)
#define KP_PORT_ROW_12 PORT(KP_ROW_12_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 14

#if !defined(KP_PORT_ROW_13)
#define KP_PORT_ROW_13 PORT(KP_ROW_13_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 15

#if !defined(KP_PORT_ROW_14)
#define KP_PORT_ROW_14 PORT(KP_ROW_14_GPIO_PORT)
#endif

#endif

#if KP_MAX_ROW >= 16

#if !defined(KP_PORT_ROW_15)
#define KP_PORT_ROW_15 PORT(KP_ROW_15_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Column macros
/******************************************************************************************************/
//Default Column GPIO port name macros
/******************************************************************************************************/

#if !defined(KP_1_COLUMN_GPIO_PORT)
#define KP_1_COLUMN_GPIO_PORT KP_GPIO_PORT
#endif

#if !defined(KP_2_COLUMN_GPIO_PORT)
#define KP_2_COLUMN_GPIO_PORT KP_GPIO_PORT
#endif

/******************************************************************************************************/
//Column GPIO port name macro
/******************************************************************************************************/

#if KP_MAX_COLUMN >= 1

#if !defined(KP_COLUMN_0_GPIO_PORT)
#define KP_COLUMN_0_GPIO_PORT KP_1_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 2

#if !defined(KP_COLUMN_1_GPIO_PORT)
#define KP_COLUMN_1_GPIO_PORT KP_1_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 3

#if !defined(KP_COLUMN_2_GPIO_PORT)
#define KP_COLUMN_2_GPIO_PORT KP_1_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 4

#if !defined(KP_COLUMN_3_GPIO_PORT)
#define KP_COLUMN_3_GPIO_PORT KP_1_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 5

#if !defined(KP_COLUMN_4_GPIO_PORT)
#define KP_COLUMN_4_GPIO_PORT KP_1_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 6

#if !defined(KP_COLUMN_5_GPIO_PORT)
#define KP_COLUMN_5_GPIO_PORT KP_1_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 7

#if !defined(KP_COLUMN_6_GPIO_PORT)
#define KP_COLUMN_6_GPIO_PORT KP_1_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 8

#if !defined(KP_COLUMN_7_GPIO_PORT)
#define KP_COLUMN_7_GPIO_PORT KP_1_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 9

#if !defined(KP_COLUMN_8_GPIO_PORT)
#define KP_COLUMN_8_GPIO_PORT KP_2_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 10

#if !defined(KP_COLUMN_9_GPIO_PORT)
#define KP_COLUMN_9_GPIO_PORT KP_2_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 11

#if !defined(KP_COLUMN_10_GPIO_PORT)
#define KP_COLUMN_10_GPIO_PORT KP_2_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 12

#if !defined(KP_COLUMN_11_GPIO_PORT)
#define KP_COLUMN_11_GPIO_PORT KP_2_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 13

#if !defined(KP_COLUMN_12_GPIO_PORT)
#define KP_COLUMN_12_GPIO_PORT KP_2_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 14

#if !defined(KP_COLUMN_13_GPIO_PORT)
#define KP_COLUMN_13_GPIO_PORT KP_2_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 15

#if !defined(KP_COLUMN_14_GPIO_PORT)
#define KP_COLUMN_14_GPIO_PORT KP_2_COLUMN_GPIO_PORT
#endif

#endif

#if KP_MAX_COLUMN >= 16

#if !defined(KP_COLUMN_15_GPIO_PORT)
#define KP_COLUMN_15_GPIO_PORT KP_2_COLUMN_GPIO_PORT
#endif

#endif

/******************************************************************************************************/
//Column pin number macros
/******************************************************************************************************/

#if KP_MAX_COLUMN >= 5

#if !defined(KP_COLUMN_0_GPIO_PIN)
#define KP_COLUMN_0_GPIO_PIN 0
#endif

#elif KP_MAX_COLUMN >= 1

#if !defined(KP_COLUMN_0_GPIO_PIN)
#define KP_COLUMN_0_GPIO_PIN 4
#endif

#endif

#if KP_MAX_COLUMN >= 5

#if !defined(KP_COLUMN_1_GPIO_PIN)
#define KP_COLUMN_1_GPIO_PIN 1
#endif

#elif KP_MAX_COLUMN >= 2

#if !defined(KP_COLUMN_1_GPIO_PIN)
#define KP_COLUMN_1_GPIO_PIN 5
#endif

#endif

#if KP_MAX_COLUMN >= 5

#if !defined(KP_COLUMN_2_GPIO_PIN)
#define KP_COLUMN_2_GPIO_PIN 2
#endif

#elif KP_MAX_COLUMN >= 3

#if !defined(KP_COLUMN_2_GPIO_PIN)
#define KP_COLUMN_2_GPIO_PIN 6
#endif

#endif

#if KP_MAX_COLUMN >= 5

#if !defined(KP_COLUMN_3_GPIO_PIN)
#define KP_COLUMN_3_GPIO_PIN 3
#endif

#elif KP_MAX_COLUMN >= 4

#if !defined(KP_COLUMN_3_GPIO_PIN)
#define KP_COLUMN_3_GPIO_PIN 7
#endif

#endif

#if KP_MAX_COLUMN >= 5

#if !defined(KP_COLUMN_4_GPIO_PIN)
#define KP_COLUMN_4_GPIO_PIN 4
#endif

#endif

#if KP_MAX_COLUMN >= 6

#if !defined(KP_COLUMN_5_GPIO_PIN)
#define KP_COLUMN_5_GPIO_PIN 5
#endif

#endif

#if KP_MAX_COLUMN >= 7

#if !defined(KP_COLUMN_6_GPIO_PIN)
#define KP_COLUMN_6_GPIO_PIN 6
#endif

#endif

#if KP_MAX_COLUMN >= 8

#if !defined(KP_COLUMN_7_GPIO_PIN)
#define KP_COLUMN_7_GPIO_PIN 7
#endif

#endif

#if KP_MAX_COLUMN >= 9

#if !defined(KP_COLUMN_8_GPIO_PIN)
#define KP_COLUMN_8_GPIO_PIN 0
#endif

#endif

#if KP_MAX_COLUMN >= 10

#if !defined(KP_COLUMN_9_GPIO_PIN)
#define KP_COLUMN_9_GPIO_PIN 1
#endif

#endif

#if KP_MAX_COLUMN >= 11

#if !defined(KP_COLUMN_10_GPIO_PIN)
#define KP_COLUMN_10_GPIO_PIN 2
#endif

#endif

#if KP_MAX_COLUMN >= 12

#if !defined(KP_COLUMN_11_GPIO_PIN)
#define KP_COLUMN_11_GPIO_PIN 3
#endif

#endif

#if KP_MAX_COLUMN >= 13

#if !defined(KP_COLUMN_12_GPIO_PIN)
#define KP_COLUMN_12_GPIO_PIN 4
#endif

#endif

#if KP_MAX_COLUMN >= 14

#if !defined(KP_COLUMN_13_GPIO_PIN)
#define KP_COLUMN_13_GPIO_PIN 5
#endif

#endif

#if KP_MAX_COLUMN >= 15

#if !defined(KP_COLUMN_14_GPIO_PIN)
#define KP_COLUMN_14_GPIO_PIN 6
#endif

#endif

#if KP_MAX_COLUMN >= 16

#if !defined(KP_COLUMN_15_GPIO_PIN)
#define KP_COLUMN_15_GPIO_PIN 7
#endif

#endif

/******************************************************************************************************/
//Column DDR macros
/******************************************************************************************************/

#if KP_MAX_COLUMN >= 1

#if !defined(KP_DDR_COLUMN_0)
#define KP_DDR_COLUMN_0 DDR(KP_COLUMN_0_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 2

#if !defined(KP_DDR_COLUMN_1)
#define KP_DDR_COLUMN_1 DDR(KP_COLUMN_1_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 3

#if !defined(KP_DDR_COLUMN_2)
#define KP_DDR_COLUMN_2 DDR(KP_COLUMN_2_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 4

#if !defined(KP_DDR_COLUMN_3)
#define KP_DDR_COLUMN_3 DDR(KP_COLUMN_3_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 5

#if !defined(KP_DDR_COLUMN_4)
#define KP_DDR_COLUMN_4 DDR(KP_COLUMN_4_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 6

#if !defined(KP_DDR_COLUMN_5)
#define KP_DDR_COLUMN_5 DDR(KP_COLUMN_5_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 7

#if !defined(KP_DDR_COLUMN_6)
#define KP_DDR_COLUMN_6 DDR(KP_COLUMN_6_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 8

#if !defined(KP_DDR_COLUMN_7)
#define KP_DDR_COLUMN_7 DDR(KP_COLUMN_7_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 9

#if !defined(KP_DDR_COLUMN_8)
#define KP_DDR_COLUMN_8 DDR(KP_COLUMN_8_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 10

#if !defined(KP_DDR_COLUMN_9)
#define KP_DDR_COLUMN_9 DDR(KP_COLUMN_9_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 11

#if !defined(KP_DDR_COLUMN_10)
#define KP_DDR_COLUMN_10 DDR(KP_COLUMN_10_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 12

#if !defined(KP_DDR_COLUMN_11)
#define KP_DDR_COLUMN_11 DDR(KP_COLUMN_11_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 13

#if !defined(KP_DDR_COLUMN_12)
#define KP_DDR_COLUMN_12 DDR(KP_COLUMN_12_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 14

#if !defined(KP_DDR_COLUMN_13)
#define KP_DDR_COLUMN_13 DDR(KP_COLUMN_13_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 15

#if !defined(KP_DDR_COLUMN_14)
#define KP_DDR_COLUMN_14 DDR(KP_COLUMN_14_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 16

#if !defined(KP_DDR_COLUMN_15)
#define KP_DDR_COLUMN_15 DDR(KP_COLUMN_15_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Column PORT macros
/******************************************************************************************************/

#if KP_MAX_COLUMN >= 1

#if !defined(KP_PORT_COLUMN_0)
#define KP_PORT_COLUMN_0 PORT(KP_COLUMN_0_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 2

#if !defined(KP_PORT_COLUMN_1)
#define KP_PORT_COLUMN_1 PORT(KP_COLUMN_1_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 3

#if !defined(KP_PORT_COLUMN_2)
#define KP_PORT_COLUMN_2 PORT(KP_COLUMN_2_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 4

#if !defined(KP_PORT_COLUMN_3)
#define KP_PORT_COLUMN_3 PORT(KP_COLUMN_3_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 5

#if !defined(KP_PORT_COLUMN_4)
#define KP_PORT_COLUMN_4 PORT(KP_COLUMN_4_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 6

#if !defined(KP_PORT_COLUMN_5)
#define KP_PORT_COLUMN_5 PORT(KP_COLUMN_5_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 7

#if !defined(KP_PORT_COLUMN_6)
#define KP_PORT_COLUMN_6 PORT(KP_COLUMN_6_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 8

#if !defined(KP_PORT_COLUMN_7)
#define KP_PORT_COLUMN_7 PORT(KP_COLUMN_7_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 9

#if !defined(KP_PORT_COLUMN_8)
#define KP_PORT_COLUMN_8 PORT(KP_COLUMN_8_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 10

#if !defined(KP_PORT_COLUMN_9)
#define KP_PORT_COLUMN_9 PORT(KP_COLUMN_9_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 11

#if !defined(KP_PORT_COLUMN_10)
#define KP_PORT_COLUMN_10 PORT(KP_COLUMN_10_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 12

#if !defined(KP_PORT_COLUMN_11)
#define KP_PORT_COLUMN_11 PORT(KP_COLUMN_11_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 13

#if !defined(KP_PORT_COLUMN_12)
#define KP_PORT_COLUMN_12 PORT(KP_COLUMN_12_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 14

#if !defined(KP_PORT_COLUMN_13)
#define KP_PORT_COLUMN_13 PORT(KP_COLUMN_13_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 15

#if !defined(KP_PORT_COLUMN_14)
#define KP_PORT_COLUMN_14 PORT(KP_COLUMN_14_GPIO_PORT)
#endif

#endif

#if KP_MAX_COLUMN >= 16

#if !defined(KP_PORT_COLUMN_15)
#define KP_PORT_COLUMN_15 PORT(KP_COLUMN_15_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Identifying macros
/******************************************************************************************************/
#if KP_MAX_ROW >=1

#define KP_ROW_0 APPEND_3_1(_P,KP_ROW_0_GPIO_PORT,KP_ROW_0_GPIO_PIN)

#endif

#if KP_MAX_ROW >=2

#define KP_ROW_1 APPEND_3_1(_P,KP_ROW_1_GPIO_PORT,KP_ROW_1_GPIO_PIN)

#endif

#if KP_MAX_ROW >=3

#define KP_ROW_2 APPEND_3_1(_P,KP_ROW_2_GPIO_PORT,KP_ROW_2_GPIO_PIN)

#endif

#if KP_MAX_ROW >=4

#define KP_ROW_3 APPEND_3_1(_P,KP_ROW_3_GPIO_PORT,KP_ROW_3_GPIO_PIN)

#endif

#if KP_MAX_ROW >=5

#define KP_ROW_4 APPEND_3_1(_P,KP_ROW_4_GPIO_PORT,KP_ROW_4_GPIO_PIN)

#endif

#if KP_MAX_ROW >=6

#define KP_ROW_5 APPEND_3_1(_P,KP_ROW_5_GPIO_PORT,KP_ROW_5_GPIO_PIN)

#endif

#if KP_MAX_ROW >=7

#define KP_ROW_6 APPEND_3_1(_P,KP_ROW_6_GPIO_PORT,KP_ROW_6_GPIO_PIN)

#endif

#if KP_MAX_ROW >=8

#define KP_ROW_7 APPEND_3_1(_P,KP_ROW_7_GPIO_PORT,KP_ROW_7_GPIO_PIN)

#endif

#if KP_MAX_ROW >=9

#define KP_ROW_8 APPEND_3_1(_P,KP_ROW_8_GPIO_PORT,KP_ROW_8_GPIO_PIN)

#endif

#if KP_MAX_ROW >=10

#define KP_ROW_9 APPEND_3_1(_P,KP_ROW_9_GPIO_PORT,KP_ROW_9_GPIO_PIN)

#endif

#if KP_MAX_ROW >=11

#define KP_ROW_10 APPEND_3_1(_P,KP_ROW_10_GPIO_PORT,KP_ROW_10_GPIO_PIN)

#endif

#if KP_MAX_ROW >=12

#define KP_ROW_11 APPEND_3_1(_P,KP_ROW_11_GPIO_PORT,KP_ROW_11_GPIO_PIN)

#endif

#if KP_MAX_ROW >=13

#define KP_ROW_12 APPEND_3_1(_P,KP_ROW_12_GPIO_PORT,KP_ROW_12_GPIO_PIN)

#endif

#if KP_MAX_ROW >=14

#define KP_ROW_13 APPEND_3_1(_P,KP_ROW_13_GPIO_PORT,KP_ROW_13_GPIO_PIN)

#endif

#if KP_MAX_ROW >=15

#define KP_ROW_14 APPEND_3_1(_P,KP_ROW_14_GPIO_PORT,KP_ROW_14_GPIO_PIN)

#endif

#if KP_MAX_ROW >=16

#define KP_ROW_15 APPEND_3_1(_P,KP_ROW_15_GPIO_PORT,KP_ROW_15_GPIO_PIN)

#endif

/******************************************************************************************************/

#if KP_MAX_COLUMN >=1

#define KP_COLUMN_0 APPEND_3_1(_P,KP_COLUMN_0_GPIO_PORT,KP_COLUMN_0_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=2

#define KP_COLUMN_1 APPEND_3_1(_P,KP_COLUMN_1_GPIO_PORT,KP_COLUMN_1_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=3

#define KP_COLUMN_2 APPEND_3_1(_P,KP_COLUMN_2_GPIO_PORT,KP_COLUMN_2_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=4

#define KP_COLUMN_3 APPEND_3_1(_P,KP_COLUMN_3_GPIO_PORT,KP_COLUMN_3_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=5

#define KP_COLUMN_4 APPEND_3_1(_P,KP_COLUMN_4_GPIO_PORT,KP_COLUMN_4_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=6

#define KP_COLUMN_5 APPEND_3_1(_P,KP_COLUMN_5_GPIO_PORT,KP_COLUMN_5_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=7

#define KP_COLUMN_6 APPEND_3_1(_P,KP_COLUMN_6_GPIO_PORT,KP_COLUMN_6_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=8

#define KP_COLUMN_7 APPEND_3_1(_P,KP_COLUMN_7_GPIO_PORT,KP_COLUMN_7_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=9

#define KP_COLUMN_8 APPEND_3_1(_P,KP_COLUMN_8_GPIO_PORT,KP_COLUMN_8_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=10

#define KP_COLUMN_9 APPEND_3_1(_P,KP_COLUMN_9_GPIO_PORT,KP_COLUMN_9_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=11

#define KP_COLUMN_10 APPEND_3_1(_P,KP_COLUMN_10_GPIO_PORT,KP_COLUMN_10_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=12

#define KP_COLUMN_11 APPEND_3_1(_P,KP_COLUMN_11_GPIO_PORT,KP_COLUMN_11_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=13

#define KP_COLUMN_12 APPEND_3_1(_P,KP_COLUMN_12_GPIO_PORT,KP_COLUMN_12_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=14

#define KP_COLUMN_13 APPEND_3_1(_P,KP_COLUMN_13_GPIO_PORT,KP_COLUMN_13_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=15

#define KP_COLUMN_14 APPEND_3_1(_P,KP_COLUMN_14_GPIO_PORT,KP_COLUMN_14_GPIO_PIN)

#endif

#if KP_MAX_COLUMN >=16

#define KP_COLUMN_15 APPEND_3_1(_P,KP_COLUMN_15_GPIO_PORT,KP_COLUMN_15_GPIO_PIN)

#endif


/******************************************************************************************************/
//Error Check
/******************************************************************************************************/

#if KP_MAX_ROW >=2

#if (KP_ROW_1==KP_ROW_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=3

#if (KP_ROW_2==KP_ROW_0)||(KP_ROW_2==KP_ROW_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=4

#if (KP_ROW_3==KP_ROW_0)||(KP_ROW_3==KP_ROW_1)||(KP_ROW_3==KP_ROW_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=5

#if (KP_ROW_4==KP_ROW_0)||(KP_ROW_4==KP_ROW_1)||(KP_ROW_4==KP_ROW_2)||(KP_ROW_4==KP_ROW_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=6

#if (KP_ROW_5==KP_ROW_0)||(KP_ROW_5==KP_ROW_1)||(KP_ROW_5==KP_ROW_2)||(KP_ROW_5==KP_ROW_3)||(KP_ROW_5==KP_ROW_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=7

#if (KP_ROW_6==KP_ROW_0)||(KP_ROW_6==KP_ROW_1)||(KP_ROW_6==KP_ROW_2)||(KP_ROW_6==KP_ROW_3)||(KP_ROW_6==KP_ROW_4)||\
    (KP_ROW_6==KP_ROW_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=8

#if (KP_ROW_7==KP_ROW_0)||(KP_ROW_7==KP_ROW_1)||(KP_ROW_7==KP_ROW_2)||(KP_ROW_7==KP_ROW_3)||(KP_ROW_7==KP_ROW_4)||\
    (KP_ROW_7==KP_ROW_5)||(KP_ROW_7==KP_ROW_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=9

#if (KP_ROW_8==KP_ROW_0)||(KP_ROW_8==KP_ROW_1)||(KP_ROW_8==KP_ROW_2)||(KP_ROW_8==KP_ROW_3)||(KP_ROW_8==KP_ROW_4)||\
    (KP_ROW_8==KP_ROW_5)||(KP_ROW_8==KP_ROW_6)||(KP_ROW_8==KP_ROW_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=10

#if (KP_ROW_9==KP_ROW_0)||(KP_ROW_9==KP_ROW_1)||(KP_ROW_9==KP_ROW_2)||(KP_ROW_9==KP_ROW_3)||(KP_ROW_9==KP_ROW_4)||\
    (KP_ROW_9==KP_ROW_5)||(KP_ROW_9==KP_ROW_6)||(KP_ROW_9==KP_ROW_7)||(KP_ROW_9==KP_ROW_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=11

#if (KP_ROW_10==KP_ROW_0)||(KP_ROW_10==KP_ROW_1)||(KP_ROW_10==KP_ROW_2)||(KP_ROW_10==KP_ROW_3)||(KP_ROW_10==KP_ROW_4)||\
    (KP_ROW_10==KP_ROW_5)||(KP_ROW_10==KP_ROW_6)||(KP_ROW_10==KP_ROW_7)||(KP_ROW_10==KP_ROW_8)||(KP_ROW_10==KP_ROW_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=12

#if (KP_ROW_11==KP_ROW_0)||(KP_ROW_11==KP_ROW_1)||(KP_ROW_11==KP_ROW_2)||(KP_ROW_11==KP_ROW_3)||(KP_ROW_11==KP_ROW_4)||\
    (KP_ROW_11==KP_ROW_5)||(KP_ROW_11==KP_ROW_6)||(KP_ROW_11==KP_ROW_7)||(KP_ROW_11==KP_ROW_8)||(KP_ROW_11==KP_ROW_9)||\
    (KP_ROW_11==KP_ROW_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=13

#if (KP_ROW_12==KP_ROW_0)||(KP_ROW_12==KP_ROW_1)||(KP_ROW_12==KP_ROW_2)||(KP_ROW_12==KP_ROW_3)||(KP_ROW_12==KP_ROW_4)||\
    (KP_ROW_12==KP_ROW_5)||(KP_ROW_12==KP_ROW_6)||(KP_ROW_12==KP_ROW_7)||(KP_ROW_12==KP_ROW_8)||(KP_ROW_12==KP_ROW_9)||\
    (KP_ROW_12==KP_ROW_10)||(KP_ROW_12==KP_ROW_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=14

#if (KP_ROW_13==KP_ROW_0)||(KP_ROW_13==KP_ROW_1)||(KP_ROW_13==KP_ROW_2)||(KP_ROW_13==KP_ROW_3)||(KP_ROW_13==KP_ROW_4)||\
    (KP_ROW_13==KP_ROW_5)||(KP_ROW_13==KP_ROW_6)||(KP_ROW_13==KP_ROW_7)||(KP_ROW_13==KP_ROW_8)||(KP_ROW_13==KP_ROW_9)||\
    (KP_ROW_13==KP_ROW_10)||(KP_ROW_13==KP_ROW_11)||(KP_ROW_13==KP_ROW_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=15

#if (KP_ROW_14==KP_ROW_0)||(KP_ROW_14==KP_ROW_1)||(KP_ROW_14==KP_ROW_2)||(KP_ROW_14==KP_ROW_3)||(KP_ROW_14==KP_ROW_4)||\
    (KP_ROW_14==KP_ROW_5)||(KP_ROW_14==KP_ROW_6)||(KP_ROW_14==KP_ROW_7)||(KP_ROW_14==KP_ROW_8)||(KP_ROW_14==KP_ROW_9)||\
    (KP_ROW_14==KP_ROW_10)||(KP_ROW_14==KP_ROW_11)||(KP_ROW_14==KP_ROW_12)||(KP_ROW_14==KP_ROW_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=16

#if (KP_ROW_15==KP_ROW_0)||(KP_ROW_15==KP_ROW_1)||(KP_ROW_15==KP_ROW_2)||(KP_ROW_15==KP_ROW_3)||(KP_ROW_15==KP_ROW_4)||\
    (KP_ROW_15==KP_ROW_5)||(KP_ROW_15==KP_ROW_6)||(KP_ROW_15==KP_ROW_7)||(KP_ROW_15==KP_ROW_8)||(KP_ROW_15==KP_ROW_9)||\
    (KP_ROW_15==KP_ROW_10)||(KP_ROW_15==KP_ROW_11)||(KP_ROW_15==KP_ROW_12)||(KP_ROW_15==KP_ROW_13)||(KP_ROW_15==KP_ROW_14)
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if KP_MAX_COLUMN >=2

#if (KP_COLUMN_1==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_COLUMN_2==KP_COLUMN_0)||(KP_COLUMN_2==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_COLUMN_3==KP_COLUMN_0)||(KP_COLUMN_3==KP_COLUMN_1)||(KP_COLUMN_3==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_COLUMN_4==KP_COLUMN_0)||(KP_COLUMN_4==KP_COLUMN_1)||(KP_COLUMN_4==KP_COLUMN_2)||(KP_COLUMN_4==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_COLUMN_5==KP_COLUMN_0)||(KP_COLUMN_5==KP_COLUMN_1)||(KP_COLUMN_5==KP_COLUMN_2)||(KP_COLUMN_5==KP_COLUMN_3)||(KP_COLUMN_5==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_COLUMN_6==KP_COLUMN_0)||(KP_COLUMN_6==KP_COLUMN_1)||(KP_COLUMN_6==KP_COLUMN_2)||(KP_COLUMN_6==KP_COLUMN_3)||(KP_COLUMN_6==KP_COLUMN_4)||\
    (KP_COLUMN_6==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_COLUMN_7==KP_COLUMN_0)||(KP_COLUMN_7==KP_COLUMN_1)||(KP_COLUMN_7==KP_COLUMN_2)||(KP_COLUMN_7==KP_COLUMN_3)||(KP_COLUMN_7==KP_COLUMN_4)||\
    (KP_COLUMN_7==KP_COLUMN_5)||(KP_COLUMN_7==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_COLUMN_8==KP_COLUMN_0)||(KP_COLUMN_8==KP_COLUMN_1)||(KP_COLUMN_8==KP_COLUMN_2)||(KP_COLUMN_8==KP_COLUMN_3)||(KP_COLUMN_8==KP_COLUMN_4)||\
    (KP_COLUMN_8==KP_COLUMN_5)||(KP_COLUMN_8==KP_COLUMN_6)||(KP_COLUMN_8==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_COLUMN_9==KP_COLUMN_0)||(KP_COLUMN_9==KP_COLUMN_1)||(KP_COLUMN_9==KP_COLUMN_2)||(KP_COLUMN_9==KP_COLUMN_3)||(KP_COLUMN_9==KP_COLUMN_4)||\
    (KP_COLUMN_9==KP_COLUMN_5)||(KP_COLUMN_9==KP_COLUMN_6)||(KP_COLUMN_9==KP_COLUMN_7)||(KP_COLUMN_9==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_COLUMN_10==KP_COLUMN_0)||(KP_COLUMN_10==KP_COLUMN_1)||(KP_COLUMN_10==KP_COLUMN_2)||(KP_COLUMN_10==KP_COLUMN_3)||(KP_COLUMN_10==KP_COLUMN_4)||\
    (KP_COLUMN_10==KP_COLUMN_5)||(KP_COLUMN_10==KP_COLUMN_6)||(KP_COLUMN_10==KP_COLUMN_7)||(KP_COLUMN_10==KP_COLUMN_8)||(KP_COLUMN_10==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_COLUMN_11==KP_COLUMN_0)||(KP_COLUMN_11==KP_COLUMN_1)||(KP_COLUMN_11==KP_COLUMN_2)||(KP_COLUMN_11==KP_COLUMN_3)||(KP_COLUMN_11==KP_COLUMN_4)||\
    (KP_COLUMN_11==KP_COLUMN_5)||(KP_COLUMN_11==KP_COLUMN_6)||(KP_COLUMN_11==KP_COLUMN_7)||(KP_COLUMN_11==KP_COLUMN_8)||(KP_COLUMN_11==KP_COLUMN_9)||\
    (KP_COLUMN_11==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_COLUMN_12==KP_COLUMN_0)||(KP_COLUMN_12==KP_COLUMN_1)||(KP_COLUMN_12==KP_COLUMN_2)||(KP_COLUMN_12==KP_COLUMN_3)||(KP_COLUMN_12==KP_COLUMN_4)||\
    (KP_COLUMN_12==KP_COLUMN_5)||(KP_COLUMN_12==KP_COLUMN_6)||(KP_COLUMN_12==KP_COLUMN_7)||(KP_COLUMN_12==KP_COLUMN_8)||(KP_COLUMN_12==KP_COLUMN_9)||\
    (KP_COLUMN_12==KP_COLUMN_10)||(KP_COLUMN_12==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_COLUMN_13==KP_COLUMN_0)||(KP_COLUMN_13==KP_COLUMN_1)||(KP_COLUMN_13==KP_COLUMN_2)||(KP_COLUMN_13==KP_COLUMN_3)||(KP_COLUMN_13==KP_COLUMN_4)||\
    (KP_COLUMN_13==KP_COLUMN_5)||(KP_COLUMN_13==KP_COLUMN_6)||(KP_COLUMN_13==KP_COLUMN_7)||(KP_COLUMN_13==KP_COLUMN_8)||(KP_COLUMN_13==KP_COLUMN_9)||\
    (KP_COLUMN_13==KP_COLUMN_10)||(KP_COLUMN_13==KP_COLUMN_11)||(KP_COLUMN_13==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_COLUMN_14==KP_COLUMN_0)||(KP_COLUMN_14==KP_COLUMN_1)||(KP_COLUMN_14==KP_COLUMN_2)||(KP_COLUMN_14==KP_COLUMN_3)||(KP_COLUMN_14==KP_COLUMN_4)||\
    (KP_COLUMN_14==KP_COLUMN_5)||(KP_COLUMN_14==KP_COLUMN_6)||(KP_COLUMN_14==KP_COLUMN_7)||(KP_COLUMN_14==KP_COLUMN_8)||(KP_COLUMN_14==KP_COLUMN_9)||\
    (KP_COLUMN_14==KP_COLUMN_10)||(KP_COLUMN_14==KP_COLUMN_11)||(KP_COLUMN_14==KP_COLUMN_12)||(KP_COLUMN_14==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_COLUMN_15==KP_COLUMN_0)||(KP_COLUMN_15==KP_COLUMN_1)||(KP_COLUMN_15==KP_COLUMN_2)||(KP_COLUMN_15==KP_COLUMN_3)||(KP_COLUMN_15==KP_COLUMN_4)||\
    (KP_COLUMN_15==KP_COLUMN_5)||(KP_COLUMN_15==KP_COLUMN_6)||(KP_COLUMN_15==KP_COLUMN_7)||(KP_COLUMN_15==KP_COLUMN_8)||(KP_COLUMN_15==KP_COLUMN_9)||\
    (KP_COLUMN_15==KP_COLUMN_10)||(KP_COLUMN_15==KP_COLUMN_11)||(KP_COLUMN_15==KP_COLUMN_12)||(KP_COLUMN_15==KP_COLUMN_13)||(KP_COLUMN_15==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if KP_MAX_ROW >=1

#if KP_MAX_COLUMN >=1

#if (KP_ROW_0==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_0==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_0==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_0==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_0==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_0==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_0==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_0==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_0==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_0==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_0==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_0==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_0==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_0==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_0==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_0==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=2

#if KP_MAX_COLUMN >=1

#if (KP_ROW_1==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_1==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_1==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_1==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_1==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_1==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_1==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_1==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_1==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_1==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_1==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_1==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_1==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_1==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_1==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_1==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=3

#if KP_MAX_COLUMN >=1

#if (KP_ROW_2==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_2==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_2==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_2==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_2==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_2==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_2==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_2==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_2==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_2==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_2==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_2==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_2==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_2==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_2==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_2==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=4

#if KP_MAX_COLUMN >=1

#if (KP_ROW_3==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_3==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_3==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_3==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_3==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_3==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_3==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_3==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_3==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_3==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_3==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_3==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_3==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_3==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_3==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_3==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=5

#if KP_MAX_COLUMN >=1

#if (KP_ROW_4==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_4==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_4==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_4==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_4==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_4==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_4==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_4==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_4==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_4==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_4==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_4==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_4==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_4==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_4==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_4==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=6

#if KP_MAX_COLUMN >=1

#if (KP_ROW_5==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_5==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_5==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_5==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_5==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_5==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_5==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_5==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_5==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_5==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_5==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_5==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_5==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_5==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_5==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_5==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=7

#if KP_MAX_COLUMN >=1

#if (KP_ROW_6==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_6==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_6==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_6==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_6==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_6==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_6==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_6==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_6==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_6==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_6==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_6==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_6==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_6==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_6==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_6==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=8

#if KP_MAX_COLUMN >=1

#if (KP_ROW_7==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_7==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_7==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_7==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_7==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_7==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_7==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_7==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_7==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_7==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_7==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_7==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_7==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_7==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_7==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_7==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=9

#if KP_MAX_COLUMN >=1

#if (KP_ROW_8==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_8==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_8==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_8==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_8==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_8==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_8==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_8==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_8==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_8==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_8==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_8==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_8==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_8==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_8==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_8==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=10

#if KP_MAX_COLUMN >=1

#if (KP_ROW_9==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_9==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_9==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_9==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_9==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_9==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_9==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_9==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_9==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_9==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_9==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_9==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_9==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_9==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_9==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_9==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=11

#if KP_MAX_COLUMN >=1

#if (KP_ROW_10==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_10==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_10==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_10==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_10==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_10==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_10==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_10==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_10==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_10==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_10==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_10==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_10==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_10==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_10==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_10==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=12

#if KP_MAX_COLUMN >=1

#if (KP_ROW_11==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_11==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_11==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_11==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_11==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_11==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_11==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_11==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_11==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_11==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_11==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_11==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_11==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_11==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_11==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_11==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=13

#if KP_MAX_COLUMN >=1

#if (KP_ROW_12==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_12==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_12==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_12==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_12==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_12==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_12==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_12==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_12==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_12==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_12==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_12==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_12==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_12==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_12==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_12==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=14

#if KP_MAX_COLUMN >=1

#if (KP_ROW_13==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_13==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_13==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_13==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_13==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_13==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_13==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_13==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_13==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_13==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_13==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_13==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_13==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_13==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_13==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_13==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=15

#if KP_MAX_COLUMN >=1

#if (KP_ROW_14==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_14==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_14==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_14==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_14==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_14==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_14==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_14==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_14==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_14==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_14==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_14==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_14==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_14==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_14==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_14==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

#if KP_MAX_ROW >=16

#if KP_MAX_COLUMN >=1

#if (KP_ROW_15==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_ROW_15==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_ROW_15==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_ROW_15==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_ROW_15==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_ROW_15==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_ROW_15==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_ROW_15==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_ROW_15==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_ROW_15==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_ROW_15==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_ROW_15==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_ROW_15==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_ROW_15==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_ROW_15==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_ROW_15==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/
//Interrupt Select
/******************************************************************************************************/

#if !defined(KP_INTERRUPT_BASED)
#define KP_INTERRUPT_BASED NO
#else
#undef KP_INTERRUPT_BASED
#define KP_INTERRUPT_BASED YES
#endif

#define KP_INTERRUPT_TYPE_DEFAULT 2

#if !defined(KP_INTERRUPT_TYPE)
#define KP_INTERRUPT_TYPE KP_INTERRUPT_TYPE_DEFAULT
#endif

/******************************************************************************************************/
//Interrupt Definitions
/******************************************************************************************************/

#if (KP_INTERRUPT_TYPE)== 0

#define KP_ISR_ENABLE GICR =(GICR & ~(0x40))|(0x40);

#define KP_ISR_FALLING MCUCR = (MCUCR & ~(0x03))|(0x02);

#define KP_INTERRUPT_GPIO_PORT D
#define KP_INTERRUPT_GPIO_PIN 2

#elif (KP_INTERRUPT_TYPE)== 1

#define KP_ISR_ENABLE GICR =(GICR  & ~(0x80))|(0x80);

#define KP_ISR_FALLING MCUCR = (MCUCR & ~(0x0C))|(0x08);

#define KP_INTERRUPT_GPIO_PORT D
#define KP_INTERRUPT_GPIO_PIN 3

#elif (KP_INTERRUPT_TYPE)== 2

#define KP_ISR_ENABLE GICR =(GICR & ~(0x20))|(0x20);

#define KP_ISR_FALLING MCUCSR = (MCUCSR & ~(0x40))|(0x00);

#define KP_INTERRUPT_GPIO_PORT B
#define KP_INTERRUPT_GPIO_PIN 2

#endif

/******************************************************************************************************/

#define KP_DDR_INTERRUPT DDR(KP_INTERRUPT_GPIO_PORT)
#define KP_PORT_INTERRUPT PORT(KP_INTERRUPT_GPIO_PORT)
#define KP_INTERRUPT APPEND_3_1(_P,KP_INTERRUPT_GPIO_PORT,KP_INTERRUPT_GPIO_PIN)

/******************************************************************************************************/

#define KP_ISR_VECTOR APPEND_3_1(INT,KP_INTERRUPT_TYPE,_vect)

/******************************************************************************************************/
//Default Buffer size
/******************************************************************************************************/

#if !defined(KP_BUFFER_SIZE)
#define KP_BUFFER_SIZE 8
#endif

/******************************************************************************************************/
//Error Check
/******************************************************************************************************/

#if (KP_INTERRUPT_BASED) //== YES

#if KP_MAX_ROW >=1

#if (KP_INTERRUPT==KP_ROW_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=2

#if (KP_INTERRUPT==KP_ROW_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=3

#if (KP_INTERRUPT==KP_ROW_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=4

#if (KP_INTERRUPT==KP_ROW_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=5

#if (KP_INTERRUPT==KP_ROW_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=6

#if (KP_INTERRUPT==KP_ROW_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=7

#if (KP_INTERRUPT==KP_ROW_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=8

#if (KP_INTERRUPT==KP_ROW_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=9

#if (KP_INTERRUPT==KP_ROW_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=10

#if (KP_INTERRUPT==KP_ROW_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=11

#if (KP_INTERRUPT==KP_ROW_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=12

#if (KP_INTERRUPT==KP_ROW_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=13

#if (KP_INTERRUPT==KP_ROW_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=14

#if (KP_INTERRUPT==KP_ROW_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=15

#if (KP_INTERRUPT==KP_ROW_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_ROW >=16

#if (KP_INTERRUPT==KP_ROW_15)
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if KP_MAX_COLUMN >=1

#if (KP_INTERRUPT==KP_COLUMN_0)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=2

#if (KP_INTERRUPT==KP_COLUMN_1)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=3

#if (KP_INTERRUPT==KP_COLUMN_2)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=4

#if (KP_INTERRUPT==KP_COLUMN_3)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=5

#if (KP_INTERRUPT==KP_COLUMN_4)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=6

#if (KP_INTERRUPT==KP_COLUMN_5)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=7

#if (KP_INTERRUPT==KP_COLUMN_6)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=8

#if (KP_INTERRUPT==KP_COLUMN_7)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=9

#if (KP_INTERRUPT==KP_COLUMN_8)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=10

#if (KP_INTERRUPT==KP_COLUMN_9)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=11

#if (KP_INTERRUPT==KP_COLUMN_10)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=12

#if (KP_INTERRUPT==KP_COLUMN_11)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=13

#if (KP_INTERRUPT==KP_COLUMN_12)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=14

#if (KP_INTERRUPT==KP_COLUMN_13)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=15

#if (KP_INTERRUPT==KP_COLUMN_14)
#error "Two pins have the same function"
#endif

#endif

#if KP_MAX_COLUMN >=16

#if (KP_INTERRUPT==KP_COLUMN_15)
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/
//Optimization Algorithm
/******************************************************************************************************/

#if KP_MAX_ROW >=1

#if APPEND_2_1(_P, KP_ROW_0_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_0 ((0x01)<< KP_ROW_0_GPIO_PIN)
#else
#define KP_DDRA_VALUE_ROW_0 0
#endif

#if APPEND_2_1(_P,KP_ROW_0_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_0 ((0x01)<< KP_ROW_0_GPIO_PIN)
#else
#define KP_DDRB_VALUE_ROW_0 0
#endif

#if APPEND_2_1(_P,KP_ROW_0_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_0 ((0x01)<< KP_ROW_0_GPIO_PIN)
#else
#define KP_DDRC_VALUE_ROW_0 0
#endif

#if APPEND_2_1(_P,KP_ROW_0_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_0 ((0x01)<< KP_ROW_0_GPIO_PIN)
#else
#define KP_DDRD_VALUE_ROW_0 0
#endif

#endif

#if KP_MAX_ROW >=2

#if APPEND_2_1(_P,KP_ROW_1_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_1 ((0x01)<< KP_ROW_1_GPIO_PIN)+KP_DDRA_VALUE_ROW_0
#else
#define KP_DDRA_VALUE_ROW_1 0+KP_DDRA_VALUE_ROW_0
#endif

#if APPEND_2_1(_P,KP_ROW_1_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_1 ((0x01)<< KP_ROW_1_GPIO_PIN)+KP_DDRB_VALUE_ROW_0
#else
#define KP_DDRB_VALUE_ROW_1 0+KP_DDRB_VALUE_ROW_0
#endif

#if APPEND_2_1(_P,KP_ROW_1_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_1 ((0x01)<< KP_ROW_1_GPIO_PIN)+KP_DDRC_VALUE_ROW_0
#else
#define KP_DDRC_VALUE_ROW_1 0+KP_DDRC_VALUE_ROW_0
#endif

#if APPEND_2_1(_P,KP_ROW_1_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_1 ((0x01)<< KP_ROW_1_GPIO_PIN)+KP_DDRD_VALUE_ROW_0
#else
#define KP_DDRD_VALUE_ROW_1 0+KP_DDRD_VALUE_ROW_0
#endif

#endif

#if KP_MAX_ROW >=3

#if APPEND_2_1(_P,KP_ROW_2_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_2 ((0x01)<< KP_ROW_2_GPIO_PIN)+KP_DDRA_VALUE_ROW_1
#else
#define KP_DDRA_VALUE_ROW_2 0+KP_DDRA_VALUE_ROW_1
#endif

#if APPEND_2_1(_P,KP_ROW_2_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_2 ((0x01)<< KP_ROW_2_GPIO_PIN)+KP_DDRB_VALUE_ROW_1
#else
#define KP_DDRB_VALUE_ROW_2 0+KP_DDRB_VALUE_ROW_1
#endif

#if APPEND_2_1(_P,KP_ROW_2_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_2 ((0x01)<< KP_ROW_2_GPIO_PIN)+KP_DDRC_VALUE_ROW_1
#else
#define KP_DDRC_VALUE_ROW_2 0+KP_DDRC_VALUE_ROW_1
#endif

#if APPEND_2_1(_P,KP_ROW_2_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_2 ((0x01)<< KP_ROW_2_GPIO_PIN)+KP_DDRD_VALUE_ROW_1
#else
#define KP_DDRD_VALUE_ROW_2 0+KP_DDRD_VALUE_ROW_1
#endif

#endif

#if KP_MAX_ROW >=4

#if APPEND_2_1(_P,KP_ROW_3_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_3 ((0x01)<< KP_ROW_3_GPIO_PIN)+KP_DDRA_VALUE_ROW_2
#else
#define KP_DDRA_VALUE_ROW_3 0+KP_DDRA_VALUE_ROW_2
#endif

#if APPEND_2_1(_P,KP_ROW_3_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_3 ((0x01)<< KP_ROW_3_GPIO_PIN)+KP_DDRB_VALUE_ROW_2
#else
#define KP_DDRB_VALUE_ROW_3 0+KP_DDRB_VALUE_ROW_2
#endif

#if APPEND_2_1(_P,KP_ROW_3_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_3 ((0x01)<< KP_ROW_3_GPIO_PIN)+KP_DDRC_VALUE_ROW_2
#else
#define KP_DDRC_VALUE_ROW_3 0+KP_DDRC_VALUE_ROW_2
#endif

#if APPEND_2_1(_P,KP_ROW_3_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_3 ((0x01)<< KP_ROW_3_GPIO_PIN)+KP_DDRD_VALUE_ROW_2
#else
#define KP_DDRD_VALUE_ROW_3 0+KP_DDRD_VALUE_ROW_2
#endif

#endif

#if KP_MAX_ROW >=5

#if APPEND_2_1(_P,KP_ROW_4_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_4 ((0x01)<< KP_ROW_4_GPIO_PIN)+KP_DDRA_VALUE_ROW_3
#else
#define KP_DDRA_VALUE_ROW_4 0+KP_DDRA_VALUE_ROW_3
#endif

#if APPEND_2_1(_P,KP_ROW_4_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_4 ((0x01)<< KP_ROW_4_GPIO_PIN)+KP_DDRB_VALUE_ROW_3
#else
#define KP_DDRB_VALUE_ROW_4 0+KP_DDRB_VALUE_ROW_3
#endif

#if APPEND_2_1(_P,KP_ROW_4_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_4 ((0x01)<< KP_ROW_4_GPIO_PIN)+KP_DDRC_VALUE_ROW_3
#else
#define KP_DDRC_VALUE_ROW_4 0+KP_DDRC_VALUE_ROW_3
#endif

#if APPEND_2_1(_P,KP_ROW_4_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_4 ((0x01)<< KP_ROW_4_GPIO_PIN)+KP_DDRD_VALUE_ROW_3
#else
#define KP_DDRD_VALUE_ROW_4 0+KP_DDRD_VALUE_ROW_3
#endif

#endif

#if KP_MAX_ROW >=6

#if APPEND_2_1(_P,KP_ROW_5_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_5 ((0x01)<< KP_ROW_5_GPIO_PIN)+KP_DDRA_VALUE_ROW_4
#else
#define KP_DDRA_VALUE_ROW_5 0+KP_DDRA_VALUE_ROW_4
#endif

#if APPEND_2_1(_P,KP_ROW_5_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_5 ((0x01)<< KP_ROW_5_GPIO_PIN)+KP_DDRB_VALUE_ROW_4
#else
#define KP_DDRB_VALUE_ROW_5 0+KP_DDRB_VALUE_ROW_4
#endif

#if APPEND_2_1(_P,KP_ROW_5_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_5 ((0x01)<< KP_ROW_5_GPIO_PIN)+KP_DDRC_VALUE_ROW_4
#else
#define KP_DDRC_VALUE_ROW_5 0+KP_DDRC_VALUE_ROW_4
#endif

#if APPEND_2_1(_P,KP_ROW_5_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_5 ((0x01)<< KP_ROW_5_GPIO_PIN)+KP_DDRD_VALUE_ROW_4
#else
#define KP_DDRD_VALUE_ROW_5 0+KP_DDRD_VALUE_ROW_4
#endif

#endif

#if KP_MAX_ROW >=7

#if APPEND_2_1(_P,KP_ROW_6_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_6 ((0x01)<< KP_ROW_6_GPIO_PIN)+KP_DDRA_VALUE_ROW_5
#else
#define KP_DDRA_VALUE_ROW_6 0+KP_DDRA_VALUE_ROW_5
#endif

#if APPEND_2_1(_P,KP_ROW_6_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_6 ((0x01)<< KP_ROW_6_GPIO_PIN)+KP_DDRB_VALUE_ROW_5
#else
#define KP_DDRB_VALUE_ROW_6 0+KP_DDRB_VALUE_ROW_5
#endif

#if APPEND_2_1(_P,KP_ROW_6_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_6 ((0x01)<< KP_ROW_6_GPIO_PIN)+KP_DDRC_VALUE_ROW_5
#else
#define KP_DDRC_VALUE_ROW_6 0+KP_DDRC_VALUE_ROW_5
#endif

#if APPEND_2_1(_P,KP_ROW_6_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_6 ((0x01)<< KP_ROW_6_GPIO_PIN)+KP_DDRD_VALUE_ROW_5
#else
#define KP_DDRD_VALUE_ROW_6 0+KP_DDRD_VALUE_ROW_5
#endif

#endif

#if KP_MAX_ROW >=8

#if APPEND_2_1(_P,KP_ROW_7_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_7 ((0x01)<< KP_ROW_7_GPIO_PIN)+KP_DDRA_VALUE_ROW_6
#else
#define KP_DDRA_VALUE_ROW_7 0+KP_DDRA_VALUE_ROW_6
#endif

#if APPEND_2_1(_P,KP_ROW_7_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_7 ((0x01)<< KP_ROW_7_GPIO_PIN)+KP_DDRB_VALUE_ROW_6
#else
#define KP_DDRB_VALUE_ROW_7 0+KP_DDRB_VALUE_ROW_6
#endif

#if APPEND_2_1(_P,KP_ROW_7_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_7 ((0x01)<< KP_ROW_7_GPIO_PIN)+KP_DDRC_VALUE_ROW_6
#else
#define KP_DDRC_VALUE_ROW_7 0+KP_DDRC_VALUE_ROW_6
#endif

#if APPEND_2_1(_P,KP_ROW_7_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_7 ((0x01)<< KP_ROW_7_GPIO_PIN)+KP_DDRD_VALUE_ROW_6
#else
#define KP_DDRD_VALUE_ROW_7 0+KP_DDRD_VALUE_ROW_6
#endif

#endif

#if KP_MAX_ROW >=9

#if APPEND_2_1(_P,KP_ROW_8_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_8 ((0x01)<< KP_ROW_8_GPIO_PIN)+KP_DDRA_VALUE_ROW_7
#else
#define KP_DDRA_VALUE_ROW_8 0+KP_DDRA_VALUE_ROW_7
#endif

#if APPEND_2_1(_P,KP_ROW_8_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_8 ((0x01)<< KP_ROW_8_GPIO_PIN)+KP_DDRB_VALUE_ROW_7
#else
#define KP_DDRB_VALUE_ROW_8 0+KP_DDRB_VALUE_ROW_7
#endif

#if APPEND_2_1(_P,KP_ROW_8_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_8 ((0x01)<< KP_ROW_8_GPIO_PIN)+KP_DDRC_VALUE_ROW_7
#else
#define KP_DDRC_VALUE_ROW_8 0+KP_DDRC_VALUE_ROW_7
#endif

#if APPEND_2_1(_P,KP_ROW_8_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_8 ((0x01)<< KP_ROW_8_GPIO_PIN)+KP_DDRD_VALUE_ROW_7
#else
#define KP_DDRD_VALUE_ROW_8 0+KP_DDRD_VALUE_ROW_7
#endif

#endif

#if KP_MAX_ROW >=10

#if APPEND_2_1(_P,KP_ROW_9_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_9 ((0x01)<< KP_ROW_9_GPIO_PIN)+KP_DDRA_VALUE_ROW_8
#else
#define KP_DDRA_VALUE_ROW_9 0+KP_DDRA_VALUE_ROW_8
#endif

#if APPEND_2_1(_P,KP_ROW_9_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_9 ((0x01)<< KP_ROW_9_GPIO_PIN)+KP_DDRB_VALUE_ROW_8
#else
#define KP_DDRB_VALUE_ROW_9 0+KP_DDRB_VALUE_ROW_8
#endif

#if APPEND_2_1(_P,KP_ROW_9_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_9 ((0x01)<< KP_ROW_9_GPIO_PIN)+KP_DDRC_VALUE_ROW_8
#else
#define KP_DDRC_VALUE_ROW_9 0+KP_DDRC_VALUE_ROW_8
#endif

#if APPEND_2_1(_P,KP_ROW_9_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_9 ((0x01)<< KP_ROW_9_GPIO_PIN)+KP_DDRD_VALUE_ROW_8
#else
#define KP_DDRD_VALUE_ROW_9 0+KP_DDRD_VALUE_ROW_8
#endif

#endif

#if KP_MAX_ROW >=11

#if APPEND_2_1(_P,KP_ROW_10_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_10 ((0x01)<< KP_ROW_10_GPIO_PIN)+KP_DDRA_VALUE_ROW_9
#else
#define KP_DDRA_VALUE_ROW_10 0+KP_DDRA_VALUE_ROW_9
#endif

#if APPEND_2_1(_P,KP_ROW_10_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_10 ((0x01)<< KP_ROW_10_GPIO_PIN)+KP_DDRB_VALUE_ROW_9
#else
#define KP_DDRB_VALUE_ROW_10 0+KP_DDRB_VALUE_ROW_9
#endif

#if APPEND_2_1(_P,KP_ROW_10_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_10 ((0x01)<< KP_ROW_10_GPIO_PIN)+KP_DDRC_VALUE_ROW_9
#else
#define KP_DDRC_VALUE_ROW_10 0+KP_DDRC_VALUE_ROW_9
#endif

#if APPEND_2_1(_P,KP_ROW_10_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_10 ((0x01)<< KP_ROW_10_GPIO_PIN)+KP_DDRD_VALUE_ROW_9
#else
#define KP_DDRD_VALUE_ROW_10 0+KP_DDRD_VALUE_ROW_9
#endif

#endif

#if KP_MAX_ROW >=12

#if APPEND_2_1(_P,KP_ROW_11_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_11 ((0x01)<< KP_ROW_11_GPIO_PIN)+KP_DDRA_VALUE_ROW_10
#else
#define KP_DDRA_VALUE_ROW_11 0+KP_DDRA_VALUE_ROW_10
#endif

#if APPEND_2_1(_P,KP_ROW_11_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_11 ((0x01)<< KP_ROW_11_GPIO_PIN)+KP_DDRB_VALUE_ROW_10
#else
#define KP_DDRB_VALUE_ROW_11 0+KP_DDRB_VALUE_ROW_10
#endif

#if APPEND_2_1(_P,KP_ROW_11_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_11 ((0x01)<< KP_ROW_11_GPIO_PIN)+KP_DDRC_VALUE_ROW_10
#else
#define KP_DDRC_VALUE_ROW_11 0+KP_DDRC_VALUE_ROW_10
#endif

#if APPEND_2_1(_P,KP_ROW_11_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_11 ((0x01)<< KP_ROW_11_GPIO_PIN)+KP_DDRD_VALUE_ROW_10
#else
#define KP_DDRD_VALUE_ROW_11 0+KP_DDRD_VALUE_ROW_10
#endif

#endif

#if KP_MAX_ROW >=13

#if APPEND_2_1(_P,KP_ROW_12_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_12 ((0x01)<< KP_ROW_12_GPIO_PIN)+KP_DDRA_VALUE_ROW_11
#else
#define KP_DDRA_VALUE_ROW_12 0+KP_DDRA_VALUE_ROW_11
#endif

#if APPEND_2_1(_P,KP_ROW_12_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_12 ((0x01)<< KP_ROW_12_GPIO_PIN)+KP_DDRB_VALUE_ROW_11
#else
#define KP_DDRB_VALUE_ROW_12 0+KP_DDRB_VALUE_ROW_11
#endif

#if APPEND_2_1(_P,KP_ROW_12_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_12 ((0x01)<< KP_ROW_12_GPIO_PIN)+KP_DDRC_VALUE_ROW_11
#else
#define KP_DDRC_VALUE_ROW_12 0+KP_DDRC_VALUE_ROW_11
#endif

#if APPEND_2_1(_P,KP_ROW_12_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_12 ((0x01)<< KP_ROW_12_GPIO_PIN)+KP_DDRD_VALUE_ROW_11
#else
#define KP_DDRD_VALUE_ROW_12 0+KP_DDRD_VALUE_ROW_11
#endif

#endif

#if KP_MAX_ROW >=14

#if APPEND_2_1(_P,KP_ROW_13_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_13 ((0x01)<< KP_ROW_13_GPIO_PIN)+KP_DDRA_VALUE_ROW_12
#else
#define KP_DDRA_VALUE_ROW_13 0+KP_DDRA_VALUE_ROW_12
#endif

#if APPEND_2_1(_P,KP_ROW_13_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_13 ((0x01)<< KP_ROW_13_GPIO_PIN)+KP_DDRB_VALUE_ROW_12
#else
#define KP_DDRB_VALUE_ROW_13 0+KP_DDRB_VALUE_ROW_12
#endif

#if APPEND_2_1(_P,KP_ROW_13_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_13 ((0x01)<< KP_ROW_13_GPIO_PIN)+KP_DDRC_VALUE_ROW_12
#else
#define KP_DDRC_VALUE_ROW_13 0+KP_DDRC_VALUE_ROW_12
#endif

#if APPEND_2_1(_P,KP_ROW_13_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_13 ((0x01)<< KP_ROW_13_GPIO_PIN)+KP_DDRD_VALUE_ROW_12
#else
#define KP_DDRD_VALUE_ROW_13 0+KP_DDRD_VALUE_ROW_12
#endif

#endif

#if KP_MAX_ROW >=15

#if APPEND_2_1(_P,KP_ROW_14_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_14 ((0x01)<< KP_ROW_14_GPIO_PIN)+KP_DDRA_VALUE_ROW_13
#else
#define KP_DDRA_VALUE_ROW_14 0+KP_DDRA_VALUE_ROW_13
#endif

#if APPEND_2_1(_P,KP_ROW_14_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_14 ((0x01)<< KP_ROW_14_GPIO_PIN)+KP_DDRB_VALUE_ROW_13
#else
#define KP_DDRB_VALUE_ROW_14 0+KP_DDRB_VALUE_ROW_13
#endif

#if APPEND_2_1(_P,KP_ROW_14_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_14 ((0x01)<< KP_ROW_14_GPIO_PIN)+KP_DDRC_VALUE_ROW_13
#else
#define KP_DDRC_VALUE_ROW_14 0+KP_DDRC_VALUE_ROW_13
#endif

#if APPEND_2_1(_P,KP_ROW_14_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_14 ((0x01)<< KP_ROW_14_GPIO_PIN)+KP_DDRD_VALUE_ROW_13
#else
#define KP_DDRD_VALUE_ROW_14 0+KP_DDRD_VALUE_ROW_13
#endif

#endif

#if KP_MAX_ROW >=16

#if APPEND_2_1(_P,KP_ROW_15_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_ROW_15 ((0x01)<< KP_ROW_15_GPIO_PIN)+KP_DDRA_VALUE_ROW_14
#else
#define KP_DDRA_VALUE_ROW_15 0+KP_DDRA_VALUE_ROW_14
#endif

#if APPEND_2_1(_P,KP_ROW_15_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_ROW_15 ((0x01)<< KP_ROW_15_GPIO_PIN)+KP_DDRB_VALUE_ROW_14
#else
#define KP_DDRB_VALUE_ROW_15 0+KP_DDRB_VALUE_ROW_14
#endif

#if APPEND_2_1(_P,KP_ROW_15_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_ROW_15 ((0x01)<< KP_ROW_15_GPIO_PIN)+KP_DDRC_VALUE_ROW_14
#else
#define KP_DDRC_VALUE_ROW_15 0+KP_DDRC_VALUE_ROW_14
#endif

#if APPEND_2_1(_P,KP_ROW_15_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_ROW_15 ((0x01)<< KP_ROW_15_GPIO_PIN)+KP_DDRD_VALUE_ROW_14
#else
#define KP_DDRD_VALUE_ROW_15 0+KP_DDRD_VALUE_ROW_14
#endif

#endif

/******************************************************************************************************/

#if KP_MAX_COLUMN >=1

#if APPEND_2_1(_P,KP_COLUMN_0_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_0 ((0x01)<< KP_COLUMN_0_GPIO_PIN)
#else
#define KP_DDRA_VALUE_COLUMN_0 0
#endif

#if APPEND_2_1(_P,KP_COLUMN_0_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_0 ((0x01)<< KP_COLUMN_0_GPIO_PIN)
#else
#define KP_DDRB_VALUE_COLUMN_0 0
#endif

#if APPEND_2_1(_P,KP_COLUMN_0_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_0 ((0x01)<< KP_COLUMN_0_GPIO_PIN)
#else
#define KP_DDRC_VALUE_COLUMN_0 0
#endif

#if APPEND_2_1(_P,KP_COLUMN_0_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_0 ((0x01)<< KP_COLUMN_0_GPIO_PIN)
#else
#define KP_DDRD_VALUE_COLUMN_0 0
#endif

#endif

#if KP_MAX_COLUMN >=2

#if APPEND_2_1(_P,KP_COLUMN_1_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_1 ((0x01)<< KP_COLUMN_1_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_0
#else
#define KP_DDRA_VALUE_COLUMN_1 0+KP_DDRA_VALUE_COLUMN_0
#endif

#if APPEND_2_1(_P,KP_COLUMN_1_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_1 ((0x01)<< KP_COLUMN_1_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_0
#else
#define KP_DDRB_VALUE_COLUMN_1 0+KP_DDRB_VALUE_COLUMN_0
#endif

#if APPEND_2_1(_P,KP_COLUMN_1_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_1 ((0x01)<< KP_COLUMN_1_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_0
#else
#define KP_DDRC_VALUE_COLUMN_1 0+KP_DDRC_VALUE_COLUMN_0
#endif

#if APPEND_2_1(_P,KP_COLUMN_1_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_1 ((0x01)<< KP_COLUMN_1_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_0
#else
#define KP_DDRD_VALUE_COLUMN_1 0+KP_DDRD_VALUE_COLUMN_0
#endif

#endif

#if KP_MAX_COLUMN >=3

#if APPEND_2_1(_P,KP_COLUMN_2_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_2 ((0x01)<< KP_COLUMN_2_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_1
#else
#define KP_DDRA_VALUE_COLUMN_2 0+KP_DDRA_VALUE_COLUMN_1
#endif

#if APPEND_2_1(_P,KP_COLUMN_2_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_2 ((0x01)<< KP_COLUMN_2_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_1
#else
#define KP_DDRB_VALUE_COLUMN_2 0+KP_DDRB_VALUE_COLUMN_1
#endif

#if APPEND_2_1(_P,KP_COLUMN_2_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_2 ((0x01)<< KP_COLUMN_2_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_1
#else
#define KP_DDRC_VALUE_COLUMN_2 0+KP_DDRC_VALUE_COLUMN_1
#endif

#if APPEND_2_1(_P,KP_COLUMN_2_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_2 ((0x01)<< KP_COLUMN_2_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_1
#else
#define KP_DDRD_VALUE_COLUMN_2 0+KP_DDRD_VALUE_COLUMN_1
#endif

#endif

#if KP_MAX_COLUMN >=4

#if APPEND_2_1(_P,KP_COLUMN_3_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_3 ((0x01)<< KP_COLUMN_3_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_2
#else
#define KP_DDRA_VALUE_COLUMN_3 0+KP_DDRA_VALUE_COLUMN_2
#endif

#if APPEND_2_1(_P,KP_COLUMN_3_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_3 ((0x01)<< KP_COLUMN_3_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_2
#else
#define KP_DDRB_VALUE_COLUMN_3 0+KP_DDRB_VALUE_COLUMN_2
#endif

#if APPEND_2_1(_P,KP_COLUMN_3_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_3 ((0x01)<< KP_COLUMN_3_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_2
#else
#define KP_DDRC_VALUE_COLUMN_3 0+KP_DDRC_VALUE_COLUMN_2
#endif

#if APPEND_2_1(_P,KP_COLUMN_3_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_3 ((0x01)<< KP_COLUMN_3_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_2
#else
#define KP_DDRD_VALUE_COLUMN_3 0+KP_DDRD_VALUE_COLUMN_2
#endif

#endif

#if KP_MAX_COLUMN >=5

#if APPEND_2_1(_P,KP_COLUMN_4_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_4 ((0x01)<< KP_COLUMN_4_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_3
#else
#define KP_DDRA_VALUE_COLUMN_4 0+KP_DDRA_VALUE_COLUMN_3
#endif

#if APPEND_2_1(_P,KP_COLUMN_4_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_4 ((0x01)<< KP_COLUMN_4_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_3
#else
#define KP_DDRB_VALUE_COLUMN_4 0+KP_DDRB_VALUE_COLUMN_3
#endif

#if APPEND_2_1(_P,KP_COLUMN_4_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_4 ((0x01)<< KP_COLUMN_4_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_3
#else
#define KP_DDRC_VALUE_COLUMN_4 0+KP_DDRC_VALUE_COLUMN_3
#endif

#if APPEND_2_1(_P,KP_COLUMN_4_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_4 ((0x01)<< KP_COLUMN_4_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_3
#else
#define KP_DDRD_VALUE_COLUMN_4 0+KP_DDRD_VALUE_COLUMN_3
#endif

#endif

#if KP_MAX_COLUMN >=6

#if APPEND_2_1(_P,KP_COLUMN_5_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_5 ((0x01)<< KP_COLUMN_5_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_4
#else
#define KP_DDRA_VALUE_COLUMN_5 0+KP_DDRA_VALUE_COLUMN_4
#endif

#if APPEND_2_1(_P,KP_COLUMN_5_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_5 ((0x01)<< KP_COLUMN_5_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_4
#else
#define KP_DDRB_VALUE_COLUMN_5 0+KP_DDRB_VALUE_COLUMN_4
#endif

#if APPEND_2_1(_P,KP_COLUMN_5_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_5 ((0x01)<< KP_COLUMN_5_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_4
#else
#define KP_DDRC_VALUE_COLUMN_5 0+KP_DDRC_VALUE_COLUMN_4
#endif

#if APPEND_2_1(_P,KP_COLUMN_5_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_5 ((0x01)<< KP_COLUMN_5_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_4
#else
#define KP_DDRD_VALUE_COLUMN_5 0+KP_DDRD_VALUE_COLUMN_4
#endif

#endif

#if KP_MAX_COLUMN >=7

#if APPEND_2_1(_P,KP_COLUMN_6_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_6 ((0x01)<< KP_COLUMN_6_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_5
#else
#define KP_DDRA_VALUE_COLUMN_6 0+KP_DDRA_VALUE_COLUMN_5
#endif

#if APPEND_2_1(_P,KP_COLUMN_6_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_6 ((0x01)<< KP_COLUMN_6_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_5
#else
#define KP_DDRB_VALUE_COLUMN_6 0+KP_DDRB_VALUE_COLUMN_5
#endif

#if APPEND_2_1(_P,KP_COLUMN_6_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_6 ((0x01)<< KP_COLUMN_6_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_5
#else
#define KP_DDRC_VALUE_COLUMN_6 0+KP_DDRC_VALUE_COLUMN_5
#endif

#if APPEND_2_1(_P,KP_COLUMN_6_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_6 ((0x01)<< KP_COLUMN_6_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_5
#else
#define KP_DDRD_VALUE_COLUMN_6 0+KP_DDRD_VALUE_COLUMN_5
#endif

#endif

#if KP_MAX_COLUMN >=8

#if APPEND_2_1(_P,KP_COLUMN_7_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_7 ((0x01)<< KP_COLUMN_7_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_6
#else
#define KP_DDRA_VALUE_COLUMN_7 0+KP_DDRA_VALUE_COLUMN_6
#endif

#if APPEND_2_1(_P,KP_COLUMN_7_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_7 ((0x01)<< KP_COLUMN_7_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_6
#else
#define KP_DDRB_VALUE_COLUMN_7 0+KP_DDRB_VALUE_COLUMN_6
#endif

#if APPEND_2_1(_P,KP_COLUMN_7_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_7 ((0x01)<< KP_COLUMN_7_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_6
#else
#define KP_DDRC_VALUE_COLUMN_7 0+KP_DDRC_VALUE_COLUMN_6
#endif

#if APPEND_2_1(_P,KP_COLUMN_7_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_7 ((0x01)<< KP_COLUMN_7_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_6
#else
#define KP_DDRD_VALUE_COLUMN_7 0+KP_DDRD_VALUE_COLUMN_6
#endif

#endif

#if KP_MAX_COLUMN >=9

#if APPEND_2_1(_P,KP_COLUMN_8_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_8 ((0x01)<< KP_COLUMN_8_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_7
#else
#define KP_DDRA_VALUE_COLUMN_8 0+KP_DDRA_VALUE_COLUMN_7
#endif

#if APPEND_2_1(_P,KP_COLUMN_8_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_8 ((0x01)<< KP_COLUMN_8_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_7
#else
#define KP_DDRB_VALUE_COLUMN_8 0+KP_DDRB_VALUE_COLUMN_7
#endif

#if APPEND_2_1(_P,KP_COLUMN_8_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_8 ((0x01)<< KP_COLUMN_8_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_7
#else
#define KP_DDRC_VALUE_COLUMN_8 0+KP_DDRC_VALUE_COLUMN_7
#endif

#if APPEND_2_1(_P,KP_COLUMN_8_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_8 ((0x01)<< KP_COLUMN_8_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_7
#else
#define KP_DDRD_VALUE_COLUMN_8 0+KP_DDRD_VALUE_COLUMN_7
#endif

#endif

#if KP_MAX_COLUMN >=10

#if APPEND_2_1(_P,KP_COLUMN_9_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_9 ((0x01)<< KP_COLUMN_9_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_8
#else
#define KP_DDRA_VALUE_COLUMN_9 0+KP_DDRA_VALUE_COLUMN_8
#endif

#if APPEND_2_1(_P,KP_COLUMN_9_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_9 ((0x01)<< KP_COLUMN_9_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_8
#else
#define KP_DDRB_VALUE_COLUMN_9 0+KP_DDRB_VALUE_COLUMN_8
#endif

#if APPEND_2_1(_P,KP_COLUMN_9_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_9 ((0x01)<< KP_COLUMN_9_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_8
#else
#define KP_DDRC_VALUE_COLUMN_9 0+KP_DDRC_VALUE_COLUMN_8
#endif

#if APPEND_2_1(_P,KP_COLUMN_9_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_9 ((0x01)<< KP_COLUMN_9_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_8
#else
#define KP_DDRD_VALUE_COLUMN_9 0+KP_DDRD_VALUE_COLUMN_8
#endif

#endif

#if KP_MAX_COLUMN >=11

#if APPEND_2_1(_P,KP_COLUMN_10_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_10 ((0x01)<< KP_COLUMN_10_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_9
#else
#define KP_DDRA_VALUE_COLUMN_10 0+KP_DDRA_VALUE_COLUMN_9
#endif

#if APPEND_2_1(_P,KP_COLUMN_10_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_10 ((0x01)<< KP_COLUMN_10_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_9
#else
#define KP_DDRB_VALUE_COLUMN_10 0+KP_DDRB_VALUE_COLUMN_9
#endif

#if APPEND_2_1(_P,KP_COLUMN_10_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_10 ((0x01)<< KP_COLUMN_10_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_9
#else
#define KP_DDRC_VALUE_COLUMN_10 0+KP_DDRC_VALUE_COLUMN_9
#endif

#if APPEND_2_1(_P,KP_COLUMN_10_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_10 ((0x01)<< KP_COLUMN_10_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_9
#else
#define KP_DDRD_VALUE_COLUMN_10 0+KP_DDRD_VALUE_COLUMN_9
#endif

#endif

#if KP_MAX_COLUMN >=12

#if APPEND_2_1(_P,KP_COLUMN_11_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_11 ((0x01)<< KP_COLUMN_11_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_10
#else
#define KP_DDRA_VALUE_COLUMN_11 0+KP_DDRA_VALUE_COLUMN_10
#endif

#if APPEND_2_1(_P,KP_COLUMN_11_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_11 ((0x01)<< KP_COLUMN_11_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_10
#else
#define KP_DDRB_VALUE_COLUMN_11 0+KP_DDRB_VALUE_COLUMN_10
#endif

#if APPEND_2_1(_P,KP_COLUMN_11_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_11 ((0x01)<< KP_COLUMN_11_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_10
#else
#define KP_DDRC_VALUE_COLUMN_11 0+KP_DDRC_VALUE_COLUMN_10
#endif

#if APPEND_2_1(_P,KP_COLUMN_11_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_11 ((0x01)<< KP_COLUMN_11_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_10
#else
#define KP_DDRD_VALUE_COLUMN_11 0+KP_DDRD_VALUE_COLUMN_10
#endif

#endif

#if KP_MAX_COLUMN >=13

#if APPEND_2_1(_P,KP_COLUMN_12_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_12 ((0x01)<< KP_COLUMN_12_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_11
#else
#define KP_DDRA_VALUE_COLUMN_12 0+KP_DDRA_VALUE_COLUMN_11
#endif

#if APPEND_2_1(_P,KP_COLUMN_12_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_12 ((0x01)<< KP_COLUMN_12_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_11
#else
#define KP_DDRB_VALUE_COLUMN_12 0+KP_DDRB_VALUE_COLUMN_11
#endif

#if APPEND_2_1(_P,KP_COLUMN_12_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_12 ((0x01)<< KP_COLUMN_12_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_11
#else
#define KP_DDRC_VALUE_COLUMN_12 0+KP_DDRC_VALUE_COLUMN_11
#endif

#if APPEND_2_1(_P,KP_COLUMN_12_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_12 ((0x01)<< KP_COLUMN_12_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_11
#else
#define KP_DDRD_VALUE_COLUMN_12 0+KP_DDRD_VALUE_COLUMN_11
#endif

#endif

#if KP_MAX_COLUMN >=14

#if APPEND_2_1(_P,KP_COLUMN_13_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_13 ((0x01)<< KP_COLUMN_13_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_12
#else
#define KP_DDRA_VALUE_COLUMN_13 0+KP_DDRA_VALUE_COLUMN_12
#endif

#if APPEND_2_1(_P,KP_COLUMN_13_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_13 ((0x01)<< KP_COLUMN_13_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_12
#else
#define KP_DDRB_VALUE_COLUMN_13 0+KP_DDRB_VALUE_COLUMN_12
#endif

#if APPEND_2_1(_P,KP_COLUMN_13_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_13 ((0x01)<< KP_COLUMN_13_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_12
#else
#define KP_DDRC_VALUE_COLUMN_13 0+KP_DDRC_VALUE_COLUMN_12
#endif

#if APPEND_2_1(_P,KP_COLUMN_13_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_13 ((0x01)<< KP_COLUMN_13_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_12
#else
#define KP_DDRD_VALUE_COLUMN_13 0+KP_DDRD_VALUE_COLUMN_12
#endif

#endif

#if KP_MAX_COLUMN >=15

#if APPEND_2_1(_P,KP_COLUMN_14_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_14 ((0x01)<< KP_COLUMN_14_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_13
#else
#define KP_DDRA_VALUE_COLUMN_14 0+KP_DDRA_VALUE_COLUMN_13
#endif

#if APPEND_2_1(_P,KP_COLUMN_14_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_14 ((0x01)<< KP_COLUMN_14_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_13
#else
#define KP_DDRB_VALUE_COLUMN_14 0+KP_DDRB_VALUE_COLUMN_13
#endif

#if APPEND_2_1(_P,KP_COLUMN_14_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_14 ((0x01)<< KP_COLUMN_14_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_13
#else
#define KP_DDRC_VALUE_COLUMN_14 0+KP_DDRC_VALUE_COLUMN_13
#endif

#if APPEND_2_1(_P,KP_COLUMN_14_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_14 ((0x01)<< KP_COLUMN_14_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_13
#else
#define KP_DDRD_VALUE_COLUMN_14 0+KP_DDRD_VALUE_COLUMN_13
#endif

#endif

#if KP_MAX_COLUMN >=16

#if APPEND_2_1(_P,KP_COLUMN_15_GPIO_PORT) == _PA
#define KP_DDRA_VALUE_COLUMN_15 ((0x01)<< KP_COLUMN_15_GPIO_PIN)+KP_DDRA_VALUE_COLUMN_14
#else
#define KP_DDRA_VALUE_COLUMN_15 0+KP_DDRA_VALUE_COLUMN_14
#endif

#if APPEND_2_1(_P,KP_COLUMN_15_GPIO_PORT) == _PB
#define KP_DDRB_VALUE_COLUMN_15 ((0x01)<< KP_COLUMN_15_GPIO_PIN)+KP_DDRB_VALUE_COLUMN_14
#else
#define KP_DDRB_VALUE_COLUMN_15 0+KP_DDRB_VALUE_COLUMN_14
#endif

#if APPEND_2_1(_P,KP_COLUMN_15_GPIO_PORT) == _PC
#define KP_DDRC_VALUE_COLUMN_15 ((0x01)<< KP_COLUMN_15_GPIO_PIN)+KP_DDRC_VALUE_COLUMN_14
#else
#define KP_DDRC_VALUE_COLUMN_15 0+KP_DDRC_VALUE_COLUMN_14
#endif

#if APPEND_2_1(_P,KP_COLUMN_15_GPIO_PORT) == _PD
#define KP_DDRD_VALUE_COLUMN_15 ((0x01)<< KP_COLUMN_15_GPIO_PIN)+KP_DDRD_VALUE_COLUMN_14
#else
#define KP_DDRD_VALUE_COLUMN_15 0+KP_DDRD_VALUE_COLUMN_14
#endif

#endif

/******************************************************************************************************/

#if KP_MAX_ROW ==1
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_0
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_0
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_0
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_0
#endif

#if KP_MAX_ROW ==2
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_1
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_1
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_1
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_1
#endif

#if KP_MAX_ROW ==3
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_2
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_2
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_2
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_2
#endif

#if KP_MAX_ROW ==4
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_3
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_3
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_3
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_3
#endif

#if KP_MAX_ROW ==5
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_4
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_4
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_4
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_4
#endif

#if KP_MAX_ROW ==6
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_5
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_5
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_5
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_5
#endif

#if KP_MAX_ROW ==7
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_6
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_6
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_6
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_6
#endif

#if KP_MAX_ROW ==8
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_7
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_7
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_7
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_7
#endif

#if KP_MAX_ROW ==9
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_8
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_8
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_8
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_8
#endif

#if KP_MAX_ROW ==10
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_9
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_9
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_9
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_9
#endif

#if KP_MAX_ROW ==11
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_10
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_10
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_10
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_10
#endif

#if KP_MAX_ROW ==12
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_11
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_11
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_11
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_11
#endif

#if KP_MAX_ROW ==13
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_12
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_12
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_12
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_12
#endif

#if KP_MAX_ROW ==14
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_13
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_13
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_13
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_13
#endif

#if KP_MAX_ROW ==15
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_14
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_14
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_14
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_14
#endif

#if KP_MAX_ROW ==16
#define KP_DDRA_VALUE_ROW_FINAL KP_DDRA_VALUE_ROW_15
#define KP_DDRB_VALUE_ROW_FINAL KP_DDRB_VALUE_ROW_15
#define KP_DDRC_VALUE_ROW_FINAL KP_DDRC_VALUE_ROW_15
#define KP_DDRD_VALUE_ROW_FINAL KP_DDRD_VALUE_ROW_15
#endif

/******************************************************************************************************/

#if KP_MAX_COLUMN ==1
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_0
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_0
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_0
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_0
#endif

#if KP_MAX_COLUMN ==2
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_1
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_1
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_1
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_1
#endif

#if KP_MAX_COLUMN ==3
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_2
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_2
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_2
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_2
#endif

#if KP_MAX_COLUMN ==4
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_3
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_3
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_3
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_3
#endif

#if KP_MAX_COLUMN ==5
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_4
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_4
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_4
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_4
#endif

#if KP_MAX_COLUMN ==6
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_5
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_5
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_5
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_5
#endif

#if KP_MAX_COLUMN ==7
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_6
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_6
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_6
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_6
#endif

#if KP_MAX_COLUMN ==8
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_7
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_7
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_7
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_7
#endif

#if KP_MAX_COLUMN ==9
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_8
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_8
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_8
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_8
#endif

#if KP_MAX_COLUMN ==10
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_9
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_9
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_9
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_9
#endif

#if KP_MAX_COLUMN ==11
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_10
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_10
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_10
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_10
#endif

#if KP_MAX_COLUMN ==12
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_11
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_11
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_11
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_11
#endif

#if KP_MAX_COLUMN ==13
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_12
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_12
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_12
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_12
#endif

#if KP_MAX_COLUMN ==14
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_13
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_13
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_13
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_13
#endif

#if KP_MAX_COLUMN ==15
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_14
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_14
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_14
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_14
#endif

#if KP_MAX_COLUMN ==16
#define KP_DDRA_VALUE_COLUMN_FINAL KP_DDRA_VALUE_COLUMN_15
#define KP_DDRB_VALUE_COLUMN_FINAL KP_DDRB_VALUE_COLUMN_15
#define KP_DDRC_VALUE_COLUMN_FINAL KP_DDRC_VALUE_COLUMN_15
#define KP_DDRD_VALUE_COLUMN_FINAL KP_DDRD_VALUE_COLUMN_15
#endif

/******************************************************************************************************/
//Values of Individual bits of a byte
/******************************************************************************************************/

#define KP_DDRA_VALUE_FINAL KP_DDRA_VALUE_COLUMN_FINAL+KP_DDRA_VALUE_ROW_FINAL
#define KP_DDRB_VALUE_FINAL KP_DDRB_VALUE_COLUMN_FINAL+KP_DDRB_VALUE_ROW_FINAL
#define KP_DDRC_VALUE_FINAL KP_DDRC_VALUE_COLUMN_FINAL+KP_DDRC_VALUE_ROW_FINAL
#define KP_DDRD_VALUE_FINAL KP_DDRD_VALUE_COLUMN_FINAL+KP_DDRD_VALUE_ROW_FINAL

/******************************************************************************************************/

#define KP_DDRA_VALUE_ROW_FINAL_BIT_0 ((KP_DDRA_VALUE_ROW_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRA_VALUE_ROW_FINAL_BIT_1 ((KP_DDRA_VALUE_ROW_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRA_VALUE_ROW_FINAL_BIT_2 ((KP_DDRA_VALUE_ROW_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRA_VALUE_ROW_FINAL_BIT_3 ((KP_DDRA_VALUE_ROW_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRA_VALUE_ROW_FINAL_BIT_4 ((KP_DDRA_VALUE_ROW_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRA_VALUE_ROW_FINAL_BIT_5 ((KP_DDRA_VALUE_ROW_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRA_VALUE_ROW_FINAL_BIT_6 ((KP_DDRA_VALUE_ROW_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRA_VALUE_ROW_FINAL_BIT_7 ((KP_DDRA_VALUE_ROW_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRB_VALUE_ROW_FINAL_BIT_0 ((KP_DDRB_VALUE_ROW_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRB_VALUE_ROW_FINAL_BIT_1 ((KP_DDRB_VALUE_ROW_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRB_VALUE_ROW_FINAL_BIT_2 ((KP_DDRB_VALUE_ROW_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRB_VALUE_ROW_FINAL_BIT_3 ((KP_DDRB_VALUE_ROW_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRB_VALUE_ROW_FINAL_BIT_4 ((KP_DDRB_VALUE_ROW_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRB_VALUE_ROW_FINAL_BIT_5 ((KP_DDRB_VALUE_ROW_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRB_VALUE_ROW_FINAL_BIT_6 ((KP_DDRB_VALUE_ROW_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRB_VALUE_ROW_FINAL_BIT_7 ((KP_DDRB_VALUE_ROW_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRC_VALUE_ROW_FINAL_BIT_0 ((KP_DDRC_VALUE_ROW_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRC_VALUE_ROW_FINAL_BIT_1 ((KP_DDRC_VALUE_ROW_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRC_VALUE_ROW_FINAL_BIT_2 ((KP_DDRC_VALUE_ROW_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRC_VALUE_ROW_FINAL_BIT_3 ((KP_DDRC_VALUE_ROW_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRC_VALUE_ROW_FINAL_BIT_4 ((KP_DDRC_VALUE_ROW_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRC_VALUE_ROW_FINAL_BIT_5 ((KP_DDRC_VALUE_ROW_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRC_VALUE_ROW_FINAL_BIT_6 ((KP_DDRC_VALUE_ROW_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRC_VALUE_ROW_FINAL_BIT_7 ((KP_DDRC_VALUE_ROW_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRD_VALUE_ROW_FINAL_BIT_0 ((KP_DDRD_VALUE_ROW_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRD_VALUE_ROW_FINAL_BIT_1 ((KP_DDRD_VALUE_ROW_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRD_VALUE_ROW_FINAL_BIT_2 ((KP_DDRD_VALUE_ROW_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRD_VALUE_ROW_FINAL_BIT_3 ((KP_DDRD_VALUE_ROW_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRD_VALUE_ROW_FINAL_BIT_4 ((KP_DDRD_VALUE_ROW_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRD_VALUE_ROW_FINAL_BIT_5 ((KP_DDRD_VALUE_ROW_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRD_VALUE_ROW_FINAL_BIT_6 ((KP_DDRD_VALUE_ROW_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRD_VALUE_ROW_FINAL_BIT_7 ((KP_DDRD_VALUE_ROW_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_0 ((KP_DDRA_VALUE_COLUMN_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_1 ((KP_DDRA_VALUE_COLUMN_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_2 ((KP_DDRA_VALUE_COLUMN_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_3 ((KP_DDRA_VALUE_COLUMN_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_4 ((KP_DDRA_VALUE_COLUMN_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_5 ((KP_DDRA_VALUE_COLUMN_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_6 ((KP_DDRA_VALUE_COLUMN_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_7 ((KP_DDRA_VALUE_COLUMN_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_0 ((KP_DDRB_VALUE_COLUMN_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_1 ((KP_DDRB_VALUE_COLUMN_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_2 ((KP_DDRB_VALUE_COLUMN_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_3 ((KP_DDRB_VALUE_COLUMN_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_4 ((KP_DDRB_VALUE_COLUMN_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_5 ((KP_DDRB_VALUE_COLUMN_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_6 ((KP_DDRB_VALUE_COLUMN_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_7 ((KP_DDRB_VALUE_COLUMN_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_0 ((KP_DDRC_VALUE_COLUMN_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_1 ((KP_DDRC_VALUE_COLUMN_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_2 ((KP_DDRC_VALUE_COLUMN_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_3 ((KP_DDRC_VALUE_COLUMN_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_4 ((KP_DDRC_VALUE_COLUMN_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_5 ((KP_DDRC_VALUE_COLUMN_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_6 ((KP_DDRC_VALUE_COLUMN_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_7 ((KP_DDRC_VALUE_COLUMN_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_0 ((KP_DDRD_VALUE_COLUMN_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_1 ((KP_DDRD_VALUE_COLUMN_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_2 ((KP_DDRD_VALUE_COLUMN_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_3 ((KP_DDRD_VALUE_COLUMN_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_4 ((KP_DDRD_VALUE_COLUMN_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_5 ((KP_DDRD_VALUE_COLUMN_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_6 ((KP_DDRD_VALUE_COLUMN_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_7 ((KP_DDRD_VALUE_COLUMN_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRA_VALUE_FINAL_BIT_0 ((KP_DDRA_VALUE_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRA_VALUE_FINAL_BIT_1 ((KP_DDRA_VALUE_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRA_VALUE_FINAL_BIT_2 ((KP_DDRA_VALUE_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRA_VALUE_FINAL_BIT_3 ((KP_DDRA_VALUE_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRA_VALUE_FINAL_BIT_4 ((KP_DDRA_VALUE_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRA_VALUE_FINAL_BIT_5 ((KP_DDRA_VALUE_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRA_VALUE_FINAL_BIT_6 ((KP_DDRA_VALUE_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRA_VALUE_FINAL_BIT_7 ((KP_DDRA_VALUE_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRB_VALUE_FINAL_BIT_0 ((KP_DDRB_VALUE_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRB_VALUE_FINAL_BIT_1 ((KP_DDRB_VALUE_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRB_VALUE_FINAL_BIT_2 ((KP_DDRB_VALUE_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRB_VALUE_FINAL_BIT_3 ((KP_DDRB_VALUE_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRB_VALUE_FINAL_BIT_4 ((KP_DDRB_VALUE_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRB_VALUE_FINAL_BIT_5 ((KP_DDRB_VALUE_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRB_VALUE_FINAL_BIT_6 ((KP_DDRB_VALUE_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRB_VALUE_FINAL_BIT_7 ((KP_DDRB_VALUE_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRC_VALUE_FINAL_BIT_0 ((KP_DDRC_VALUE_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRC_VALUE_FINAL_BIT_1 ((KP_DDRC_VALUE_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRC_VALUE_FINAL_BIT_2 ((KP_DDRC_VALUE_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRC_VALUE_FINAL_BIT_3 ((KP_DDRC_VALUE_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRC_VALUE_FINAL_BIT_4 ((KP_DDRC_VALUE_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRC_VALUE_FINAL_BIT_5 ((KP_DDRC_VALUE_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRC_VALUE_FINAL_BIT_6 ((KP_DDRC_VALUE_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRC_VALUE_FINAL_BIT_7 ((KP_DDRC_VALUE_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/

#define KP_DDRD_VALUE_FINAL_BIT_0 ((KP_DDRD_VALUE_FINAL) & ((0x01) << 0))? 1 : 0
#define KP_DDRD_VALUE_FINAL_BIT_1 ((KP_DDRD_VALUE_FINAL) & ((0x01) << 1))? 1 : 0
#define KP_DDRD_VALUE_FINAL_BIT_2 ((KP_DDRD_VALUE_FINAL) & ((0x01) << 2))? 1 : 0
#define KP_DDRD_VALUE_FINAL_BIT_3 ((KP_DDRD_VALUE_FINAL) & ((0x01) << 3))? 1 : 0
#define KP_DDRD_VALUE_FINAL_BIT_4 ((KP_DDRD_VALUE_FINAL) & ((0x01) << 4))? 1 : 0
#define KP_DDRD_VALUE_FINAL_BIT_5 ((KP_DDRD_VALUE_FINAL) & ((0x01) << 5))? 1 : 0
#define KP_DDRD_VALUE_FINAL_BIT_6 ((KP_DDRD_VALUE_FINAL) & ((0x01) << 6))? 1 : 0
#define KP_DDRD_VALUE_FINAL_BIT_7 ((KP_DDRD_VALUE_FINAL) & ((0x01) << 7))? 1 : 0

/******************************************************************************************************/
//Number of one's in a byte
/******************************************************************************************************/

#define KP_DDRA_VALUE_ROW_FINAL_BIT_SUM    (KP_DDRA_VALUE_ROW_FINAL_BIT_0) + (KP_DDRA_VALUE_ROW_FINAL_BIT_1) +\
                                           (KP_DDRA_VALUE_ROW_FINAL_BIT_2) + (KP_DDRA_VALUE_ROW_FINAL_BIT_3) +\
                                           (KP_DDRA_VALUE_ROW_FINAL_BIT_4) + (KP_DDRA_VALUE_ROW_FINAL_BIT_5) +\
                                           (KP_DDRA_VALUE_ROW_FINAL_BIT_6) + (KP_DDRA_VALUE_ROW_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRB_VALUE_ROW_FINAL_BIT_SUM    (KP_DDRB_VALUE_ROW_FINAL_BIT_0) + (KP_DDRB_VALUE_ROW_FINAL_BIT_1) +\
                                           (KP_DDRB_VALUE_ROW_FINAL_BIT_2) + (KP_DDRB_VALUE_ROW_FINAL_BIT_3) +\
                                           (KP_DDRB_VALUE_ROW_FINAL_BIT_4) + (KP_DDRB_VALUE_ROW_FINAL_BIT_5) +\
                                           (KP_DDRB_VALUE_ROW_FINAL_BIT_6) + (KP_DDRB_VALUE_ROW_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRC_VALUE_ROW_FINAL_BIT_SUM    (KP_DDRC_VALUE_ROW_FINAL_BIT_0) + (KP_DDRC_VALUE_ROW_FINAL_BIT_1) +\
                                           (KP_DDRC_VALUE_ROW_FINAL_BIT_2) + (KP_DDRC_VALUE_ROW_FINAL_BIT_3) +\
                                           (KP_DDRC_VALUE_ROW_FINAL_BIT_4) + (KP_DDRC_VALUE_ROW_FINAL_BIT_5) +\
                                           (KP_DDRC_VALUE_ROW_FINAL_BIT_6) + (KP_DDRC_VALUE_ROW_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRD_VALUE_ROW_FINAL_BIT_SUM    (KP_DDRD_VALUE_ROW_FINAL_BIT_0) + (KP_DDRD_VALUE_ROW_FINAL_BIT_1) +\
                                           (KP_DDRD_VALUE_ROW_FINAL_BIT_2) + (KP_DDRD_VALUE_ROW_FINAL_BIT_3) +\
                                           (KP_DDRD_VALUE_ROW_FINAL_BIT_4) + (KP_DDRD_VALUE_ROW_FINAL_BIT_5) +\
                                           (KP_DDRD_VALUE_ROW_FINAL_BIT_6) + (KP_DDRD_VALUE_ROW_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRA_VALUE_COLUMN_FINAL_BIT_SUM (KP_DDRA_VALUE_COLUMN_FINAL_BIT_0) + (KP_DDRA_VALUE_COLUMN_FINAL_BIT_1) +\
                                           (KP_DDRA_VALUE_COLUMN_FINAL_BIT_2) + (KP_DDRA_VALUE_COLUMN_FINAL_BIT_3) +\
                                           (KP_DDRA_VALUE_COLUMN_FINAL_BIT_4) + (KP_DDRA_VALUE_COLUMN_FINAL_BIT_5) +\
                                           (KP_DDRA_VALUE_COLUMN_FINAL_BIT_6) + (KP_DDRA_VALUE_COLUMN_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRB_VALUE_COLUMN_FINAL_BIT_SUM (KP_DDRB_VALUE_COLUMN_FINAL_BIT_0) + (KP_DDRB_VALUE_COLUMN_FINAL_BIT_1) +\
                                           (KP_DDRB_VALUE_COLUMN_FINAL_BIT_2) + (KP_DDRB_VALUE_COLUMN_FINAL_BIT_3) +\
                                           (KP_DDRB_VALUE_COLUMN_FINAL_BIT_4) + (KP_DDRB_VALUE_COLUMN_FINAL_BIT_5) +\
                                           (KP_DDRB_VALUE_COLUMN_FINAL_BIT_6) + (KP_DDRB_VALUE_COLUMN_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRC_VALUE_COLUMN_FINAL_BIT_SUM (KP_DDRC_VALUE_COLUMN_FINAL_BIT_0) + (KP_DDRC_VALUE_COLUMN_FINAL_BIT_1) +\
                                           (KP_DDRC_VALUE_COLUMN_FINAL_BIT_2) + (KP_DDRC_VALUE_COLUMN_FINAL_BIT_3) +\
                                           (KP_DDRC_VALUE_COLUMN_FINAL_BIT_4) + (KP_DDRC_VALUE_COLUMN_FINAL_BIT_5) +\
                                           (KP_DDRC_VALUE_COLUMN_FINAL_BIT_6) + (KP_DDRC_VALUE_COLUMN_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRD_VALUE_COLUMN_FINAL_BIT_SUM (KP_DDRD_VALUE_COLUMN_FINAL_BIT_0) + (KP_DDRD_VALUE_COLUMN_FINAL_BIT_1) +\
                                           (KP_DDRD_VALUE_COLUMN_FINAL_BIT_2) + (KP_DDRD_VALUE_COLUMN_FINAL_BIT_3) +\
                                           (KP_DDRD_VALUE_COLUMN_FINAL_BIT_4) + (KP_DDRD_VALUE_COLUMN_FINAL_BIT_5) +\
                                           (KP_DDRD_VALUE_COLUMN_FINAL_BIT_6) + (KP_DDRD_VALUE_COLUMN_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRA_VALUE_FINAL_BIT_SUM (KP_DDRA_VALUE_FINAL_BIT_0) + (KP_DDRA_VALUE_FINAL_BIT_1) +\
                                    (KP_DDRA_VALUE_FINAL_BIT_2) + (KP_DDRA_VALUE_FINAL_BIT_3) +\
                                    (KP_DDRA_VALUE_FINAL_BIT_4) + (KP_DDRA_VALUE_FINAL_BIT_5) +\
                                    (KP_DDRA_VALUE_FINAL_BIT_6) + (KP_DDRA_VALUE_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRB_VALUE_FINAL_BIT_SUM (KP_DDRB_VALUE_FINAL_BIT_0) + (KP_DDRB_VALUE_FINAL_BIT_1) +\
                                    (KP_DDRB_VALUE_FINAL_BIT_2) + (KP_DDRB_VALUE_FINAL_BIT_3) +\
                                    (KP_DDRB_VALUE_FINAL_BIT_4) + (KP_DDRB_VALUE_FINAL_BIT_5) +\
                                    (KP_DDRB_VALUE_FINAL_BIT_6) + (KP_DDRB_VALUE_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRC_VALUE_FINAL_BIT_SUM (KP_DDRC_VALUE_FINAL_BIT_0) + (KP_DDRC_VALUE_FINAL_BIT_1) +\
                                    (KP_DDRC_VALUE_FINAL_BIT_2) + (KP_DDRC_VALUE_FINAL_BIT_3) +\
                                    (KP_DDRC_VALUE_FINAL_BIT_4) + (KP_DDRC_VALUE_FINAL_BIT_5) +\
                                    (KP_DDRC_VALUE_FINAL_BIT_6) + (KP_DDRC_VALUE_FINAL_BIT_7)

/******************************************************************************************************/

#define KP_DDRD_VALUE_FINAL_BIT_SUM (KP_DDRD_VALUE_FINAL_BIT_0) + (KP_DDRD_VALUE_FINAL_BIT_1) +\
                                    (KP_DDRD_VALUE_FINAL_BIT_2) + (KP_DDRD_VALUE_FINAL_BIT_3) +\
                                    (KP_DDRD_VALUE_FINAL_BIT_4) + (KP_DDRD_VALUE_FINAL_BIT_5) +\
                                    (KP_DDRD_VALUE_FINAL_BIT_6) + (KP_DDRD_VALUE_FINAL_BIT_7)

/******************************************************************************************************/
//Optimization cost calculations
/******************************************************************************************************/

//NOT EXACT,ONLY APPROXIMATIONS
/*
NUMBER OF BITS MANIPULATED          NUMBER OF INSTRUCTIONS
            0                                  0
            1                           1(MOSTLY) OR 2
          1<X<8                             3 OR 4
            8                                  1

e.g.
    DDRA = 0x00;//1 INSTRUCTION
    DDRA &= ~ (KP_DDRA_VALUE_FINAL);//3 INSTRUCTIONS
    DDRA = (DDRA & ~(KP_DDRA_VALUE_ROW_FINAL))|(KP_DDRA_VALUE_COLUMN_FINAL);//4 INSTRUCTIONS

    NOTE:   NOT INCLUDING THE OPERATIONS ON GENERAL PURPOSE REGISTERS.
            OPERATIONS ON GENERAL PURPOSE REGISTERS CONSIDERED ADD 1 TO EACH OF THE LAST 2 CASES.
            AS THE SAME REGISTER MAY BE USED AGAIN IT MAY BE REQUIRED TO SET THE ERROR APPROPRIATELY.
*/

#define KP_OPTIMIZATION_COST_1_ERROR 0

#define KP_OPTIMIZATION_COST_1  (1-(KP_INTERRUPT_BASED))*\
                                (((KP_DDRA_VALUE_FINAL_BIT_SUM)>1 ? ((KP_DDRA_VALUE_FINAL_BIT_SUM)== 8 ? 2 : 3) : ((KP_DDRA_VALUE_FINAL_BIT_SUM)==0 ? 0 : 1 )) +\
                                ((KP_DDRB_VALUE_FINAL_BIT_SUM)>1 ? ((KP_DDRB_VALUE_FINAL_BIT_SUM)== 8 ? 2 : 3) : ((KP_DDRB_VALUE_FINAL_BIT_SUM)==0 ? 0 : 1 )) +\
                                ((KP_DDRC_VALUE_FINAL_BIT_SUM)>1 ? ((KP_DDRC_VALUE_FINAL_BIT_SUM)== 8 ? 2 : 3) : ((KP_DDRC_VALUE_FINAL_BIT_SUM)==0 ? 0 : 1 )) +\
                                ((KP_DDRD_VALUE_FINAL_BIT_SUM)>1 ? ((KP_DDRD_VALUE_FINAL_BIT_SUM)== 8 ? 2 : 3) : ((KP_DDRD_VALUE_FINAL_BIT_SUM)==0 ? 0 : 1 ))) +\
                                (1+(KP_INTERRUPT_BASED))*\
                                (((((KP_DDRA_VALUE_ROW_FINAL_BIT_SUM)>1)||((KP_DDRA_VALUE_COLUMN_FINAL_BIT_SUM)>1)) ? (((KP_DDRA_VALUE_FINAL_BIT_SUM)== 8) ? 2 : 4) : ((((KP_DDRA_VALUE_ROW_FINAL_BIT_SUM)==0)&&((KP_DDRA_VALUE_COLUMN_FINAL_BIT_SUM)==0)) ? 0 : ((((KP_DDRA_VALUE_ROW_FINAL_BIT_SUM)==1)&&((KP_DDRA_VALUE_COLUMN_FINAL_BIT_SUM)==1))? 4 :1 ))) +\
                                ((((KP_DDRB_VALUE_ROW_FINAL_BIT_SUM)>1)||((KP_DDRB_VALUE_COLUMN_FINAL_BIT_SUM)>1)) ? (((KP_DDRB_VALUE_FINAL_BIT_SUM)== 8) ? 2 : 4) : ((((KP_DDRB_VALUE_ROW_FINAL_BIT_SUM)==0)&&((KP_DDRB_VALUE_COLUMN_FINAL_BIT_SUM)==0)) ? 0 : ((((KP_DDRB_VALUE_ROW_FINAL_BIT_SUM)==1)&&((KP_DDRB_VALUE_COLUMN_FINAL_BIT_SUM)==1))? 4 :1 ))) +\
                                ((((KP_DDRC_VALUE_ROW_FINAL_BIT_SUM)>1)||((KP_DDRC_VALUE_COLUMN_FINAL_BIT_SUM)>1)) ? (((KP_DDRC_VALUE_FINAL_BIT_SUM)== 8) ? 2 : 4) : ((((KP_DDRC_VALUE_ROW_FINAL_BIT_SUM)==0)&&((KP_DDRC_VALUE_COLUMN_FINAL_BIT_SUM)==0)) ? 0 : ((((KP_DDRC_VALUE_ROW_FINAL_BIT_SUM)==1)&&((KP_DDRC_VALUE_COLUMN_FINAL_BIT_SUM)==1))? 4 :1 ))) +\
                                ((((KP_DDRD_VALUE_ROW_FINAL_BIT_SUM)>1)||((KP_DDRD_VALUE_COLUMN_FINAL_BIT_SUM)>1)) ? (((KP_DDRD_VALUE_FINAL_BIT_SUM)== 8) ? 2 : 4) : ((((KP_DDRD_VALUE_ROW_FINAL_BIT_SUM)==0)&&((KP_DDRD_VALUE_COLUMN_FINAL_BIT_SUM)==0)) ? 0 : ((((KP_DDRD_VALUE_ROW_FINAL_BIT_SUM)==1)&&((KP_DDRD_VALUE_COLUMN_FINAL_BIT_SUM)==1))? 4 :1 )))) -\
                                (KP_OPTIMIZATION_COST_1_ERROR)

#define KP_OPTIMIZATION_COST_2 2*((KP_MAX_ROW)+(KP_MAX_COLUMN))

/******************************************************************************************************/

#define KP_OPTIMIZATION_FOR_INTERRUPT_COST_1 ((KP_DDRA_VALUE_COLUMN_FINAL_BIT_SUM)>1 ? ((KP_DDRA_VALUE_COLUMN_FINAL_BIT_SUM)== 8 ? 1 : 3) : ((KP_DDRA_VALUE_COLUMN_FINAL_BIT_SUM)==0 ? 0 : 1 )) +\
                                             ((KP_DDRB_VALUE_COLUMN_FINAL_BIT_SUM)>1 ? ((KP_DDRB_VALUE_COLUMN_FINAL_BIT_SUM)== 8 ? 1 : 3) : ((KP_DDRB_VALUE_COLUMN_FINAL_BIT_SUM)==0 ? 0 : 1 )) +\
                                             ((KP_DDRC_VALUE_COLUMN_FINAL_BIT_SUM)>1 ? ((KP_DDRC_VALUE_COLUMN_FINAL_BIT_SUM)== 8 ? 1 : 3) : ((KP_DDRC_VALUE_COLUMN_FINAL_BIT_SUM)==0 ? 0 : 1 )) +\
                                             ((KP_DDRD_VALUE_COLUMN_FINAL_BIT_SUM)>1 ? ((KP_DDRD_VALUE_COLUMN_FINAL_BIT_SUM)== 8 ? 1 : 3) : ((KP_DDRD_VALUE_COLUMN_FINAL_BIT_SUM)==0 ? 0 : 1 ))

#define KP_OPTIMIZATION_FOR_INTERRUPT_COST_2 (KP_MAX_COLUMN)

/******************************************************************************************************/
//Optimation Method select
/******************************************************************************************************/

#if KP_OPTIMIZATION_COST_2 >= KP_OPTIMIZATION_COST_1
#define KP_OPTIMIZATION 1
#elif KP_OPTIMIZATION_COST_2 < KP_OPTIMIZATION_COST_1
#define KP_OPTIMIZATION 2
#endif

/******************************************************************************************************/
/*
KP_OPTIMIZATION 1: Number of cycles depends on the pin configurations
                   Max number of cycles:48(approx)

KP_OPTIMIZATION 2: Number of cycles independent of the pin configurations.
                   Max number of cycles:64
*/
/******************************************************************************************************/

#if KP_OPTIMIZATION_FOR_INTERRUPT_COST_2 >= KP_OPTIMIZATION_FOR_INTERRUPT_COST_1
#define KP_OPTIMIZATION_FOR_INTERRUPT 1
#elif KP_OPTIMIZATION_FOR_INTERRUPT_COST_2 < KP_OPTIMIZATION_FOR_INTERRUPT_COST_1
#define KP_OPTIMIZATION_FOR_INTERRUPT 2
#endif

/******************************************************************************************************/
//Function USE macros
/******************************************************************************************************/

#if !defined(USE_kp_init)
#define USE_kp_init YES
#endif

#if !defined(USE_kp_read)
#define USE_kp_read YES
#endif

#if !defined(USE_kp_checkpin)
#define USE_kp_checkpin YES
#endif

#if !defined(USE_kp_setpin)
#define USE_kp_setpin YES
#endif

#if !defined(USE_kp_resetpin)
#define USE_kp_resetpin YES
#endif

#if (KP_INTERRUPT_BASED) == YES

#if !defined(USE_kp_putdata)
#define USE_kp_putdata YES
#endif

#else

#if !defined(USE_kp_putdata)
#define USE_kp_putdata NO
#endif

#endif

#if (KP_INTERRUPT_BASED) == YES

#if !defined(USE_kp_getdata)
#define USE_kp_getdata YES
#endif

#else

#if !defined(USE_kp_getdata)
#define USE_kp_getdata NO
#endif

#endif

/******************************************************************************************************/
//Function Prototypes
/******************************************************************************************************/

#if (USE_kp_init)==YES
void kp_init(void);
#endif

#if (USE_kp_read)==YES
uint8_t kp_read(void);
#endif

#if (USE_kp_checkpin)==YES
unsigned char kp_checkpin(unsigned char);
#endif

#if (USE_kp_setpin)==YES
void kp_setpin(unsigned char);
#endif

#if (USE_kp_resetpin)==YES
void kp_resetpin(unsigned char);
#endif

#if (KP_INTERRUPT_BASED) == YES

#if (USE_kp_putdata)==YES
void kp_putdata(unsigned char);
#endif

#if (USE_kp_getdata)==YES
unsigned char kp_getdata(void);
#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
