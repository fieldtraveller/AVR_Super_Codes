/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

servo_3.h

DESCRIPTION:
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef SERVO_3_H_
#define SERVO_3_H_

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

#include "cf.h"

/******************************************************************************************************/
//GPIO PORT
/******************************************************************************************************/

#ifndef SERVO_3_DATA_GPIO_PORT
#define SERVO_3_DATA_GPIO_PORT SERVO_ALL_DATA_GPIO_PORT
#endif

/******************************************************************************************************/
//GPIO PINS
/******************************************************************************************************/

#ifndef SERVO_3_DATA_GPIO_PIN
#define SERVO_3_DATA_GPIO_PIN 2
#endif

/******************************************************************************************************/
//ADDRESS MACROS
/******************************************************************************************************/
//DDR
/******************************************************************************************************/

#ifndef SERVO_3_ADDRESS_OF_DDR_DATA
#if (SERVO_3_DATA_GPIO_PORT == A)
#define SERVO_3_ADDRESS_OF_DDR_DATA (uint8_t*)&DDRA
#elif (SERVO_3_DATA_GPIO_PORT == B)
#define SERVO_3_ADDRESS_OF_DDR_DATA (uint8_t*)&DDRB
#elif (SERVO_3_DATA_GPIO_PORT == C)
#define SERVO_3_ADDRESS_OF_DDR_DATA (uint8_t*)&DDRC
#elif (SERVO_3_DATA_GPIO_PORT == D)
#define SERVO_3_ADDRESS_OF_DDR_DATA (uint8_t*)&DDRD
#endif
#endif

/******************************************************************************************************/
//CHANNEL SELECT
/******************************************************************************************************/

#ifndef SERVO_3_CHANNEL
#define SERVO_3_CHANNEL 2
#elif ((SERVO_3_CHANNEL>=SERVO_NUMBER_OF_CHANNELS_PER_TIMER)||(SERVO_3_CHANNEL<0))
#error "INCORRECT VALUE OF SERVO_3_CHANNEL"
#endif

#ifndef SERVO_3_CHANNEL_MASK
#define SERVO_3_CHANNEL_MASK (SERVO_3_CHANNEL<<3)
#endif

/******************************************************************************************************/
//TIMER SELECT
/******************************************************************************************************/

#ifndef SERVO_3_TIMER
#define SERVO_3_TIMER SERVO_TIMER_0
#elif ((SERVO_3_TIMER>=SERVO_NUMBER_OF_TIMERS)||(SERVO_3_TIMER<0))
#error "INCORRECT VALUE OF SERVO_3_TIMER"
#endif

#ifndef SERVO_3_TIMER_MASK
#define SERVO_3_TIMER_MASK (SERVO_3_TIMER<<6)
#endif

/******************************************************************************************************/

#if (SERVO_3_TIMER == SERVO_TIMER_0)

#ifndef SERVO_USE_TIMER_0
#define SERVO_USE_TIMER_0 YES
#else
#undef SERVO_USE_TIMER_0
#define SERVO_USE_TIMER_0 YES
#endif

#elif (SERVO_3_TIMER == SERVO_TIMER_1)

#ifndef SERVO_USE_TIMER_1
#define SERVO_USE_TIMER_1 YES
#else
#undef SERVO_USE_TIMER_1
#define SERVO_USE_TIMER_1 YES
#endif

#elif (SERVO_3_TIMER == SERVO_TIMER_2)

#ifndef SERVO_USE_TIMER_2
#define SERVO_USE_TIMER_2 YES
#else
#undef SERVO_USE_TIMER_2
#define SERVO_USE_TIMER_2 YES
#endif

#endif

/******************************************************************************************************/
//GLOBAL VARIABLES
/******************************************************************************************************/

SERVO SERVO_3_STRUCT =
{
    SERVO_3_ADDRESS_OF_DDR_DATA,
    (SERVO_3_TIMER_MASK+SERVO_3_CHANNEL_MASK+SERVO_3_DATA_GPIO_PIN)
};

/******************************************************************************************************/

#define SERVO_3 &SERVO_3_STRUCT

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
