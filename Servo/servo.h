/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

servo.h

DESCRIPTION:
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef SERVO_H_
#define SERVO_H_

/******************************************************************************************************/

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>

/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include <util/atomic.h>

/******************************************************************************************************/
//NUMBER OF SERVOS
/******************************************************************************************************/

#define SERVO_NUMBER_OF_TIMERS 3    //ALSO INCLUDES 16 BIT TIMERS
#define SERVO_NUMBER_OF_CHANNELS_PER_TIMER 8

#define SERVO_TOTAL_NUMBER_OF_CHANNELS (SERVO_NUMBER_OF_TIMERS*SERVO_NUMBER_OF_CHANNELS_PER_TIMER)

/******************************************************************************************************/
//SERVO TIMERS
/******************************************************************************************************/

#ifndef SERVO_TIMER_0
#define SERVO_TIMER_0 0
#endif

#ifndef SERVO_TIMER_1
#define SERVO_TIMER_1 1
#endif

#ifndef SERVO_TIMER_2
#define SERVO_TIMER_2 2
#endif

/******************************************************************************************************/
//GPIO PORT
/******************************************************************************************************/

#if !defined(SERVO_ALL_DATA_GPIO_PORT)
#define SERVO_ALL_DATA_GPIO_PORT A
#endif

/******************************************************************************************************/
//USER DEFINED DATA TYPES
/******************************************************************************************************/

struct SERVO_STRUCT
{
    uint8_t* SERVO_ADDRESS_OF_IOR_DATA;
    uint8_t SERVO_TIMER_CHANNEL_DATA_GPIO_PIN;
};

/******************************************************************************************************/

#define SERVO_VALUE_OF_ADDRESS_OF_DDR_DATA(INPUT_SERVO_STRUCT) (INPUT_SERVO_STRUCT->SERVO_ADDRESS_OF_IOR_DATA)
#define SERVO_VALUE_OF_ADDRESS_OF_PORT_DATA(INPUT_SERVO_STRUCT) (INPUT_SERVO_STRUCT->SERVO_ADDRESS_OF_IOR_DATA)
#define SERVO_VALUE_OF_DATA_GPIO_PIN(INPUT_SERVO_STRUCT) ((INPUT_SERVO_STRUCT->SERVO_TIMER_CHANNEL_DATA_GPIO_PIN)&(0x07))
#define SERVO_VALUE_OF_CHANNEL(INPUT_SERVO_STRUCT) (((INPUT_SERVO_STRUCT->SERVO_TIMER_CHANNEL_DATA_GPIO_PIN)&(0x38))>>3)
#define SERVO_VALUE_OF_TIMER(INPUT_SERVO_STRUCT) (((INPUT_SERVO_STRUCT->SERVO_TIMER_CHANNEL_DATA_GPIO_PIN)>>6)& (0x03))
#define SERVO_VALUE_OF_DATA_GPIO_TIMER_CHANNEL_PIN(INPUT_SERVO_STRUCT) (INPUT_SERVO_STRUCT->SERVO_TIMER_CHANNEL_DATA_GPIO_PIN)

#define SERVO_TIMER_CHANNEL_COUNT(STATUS) (STATUS & (0x0F))
#define SERVO_TIMER_CHANNEL_PULSE_POSITION(STATUS) (STATUS & (1<<7))

/******************************************************************************************************/

#define SERVO struct SERVO_STRUCT

/******************************************************************************************************/
//USE MACROS
/******************************************************************************************************/

#ifndef USE_servo_init
#define USE_servo_init YES
#endif

#ifndef USE_servo_set_angle
#define USE_servo_set_angle YES
#endif

/******************************************************************************************************/
//FUNCTION PROTOTYPES
/******************************************************************************************************/

#if (USE_servo_init == YES)
void servo_init(SERVO*);
#endif

#if (USE_servo_set_angle == YES)
void servo_set_angle(SERVO*,float);
#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
