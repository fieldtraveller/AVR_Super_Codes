/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

servo_$.h

DESCRIPTION:
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef SERVO_$_H_
#define SERVO_$_H_

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

#ifndef SERVO_$_DATA_GPIO_PORT
#define SERVO_$_DATA_GPIO_PORT SERVO_ALL_DATA_GPIO_PORT
#endif

/******************************************************************************************************/
//GPIO PINS
/******************************************************************************************************/

#ifndef SERVO_$_DATA_GPIO_PIN
#define SERVO_$_DATA_GPIO_PIN 0
#endif

/******************************************************************************************************/
//ADDRESS MACROS
/******************************************************************************************************/
//DDR
/******************************************************************************************************/

#ifndef SERVO_$_ADDRESS_OF_DDR_DATA
#if (SERVO_$_DATA_GPIO_PORT == A)
#define SERVO_$_ADDRESS_OF_DDR_DATA (uint8_t*)&DDRA
#elif (SERVO_$_DATA_GPIO_PORT == B)
#define SERVO_$_ADDRESS_OF_DDR_DATA (uint8_t*)&DDRB
#elif (SERVO_$_DATA_GPIO_PORT == C)
#define SERVO_$_ADDRESS_OF_DDR_DATA (uint8_t*)&DDRC
#elif (SERVO_$_DATA_GPIO_PORT == D)
#define SERVO_$_ADDRESS_OF_DDR_DATA (uint8_t*)&DDRD
#endif
#endif

/******************************************************************************************************/
//CHANNEL SELECT
/******************************************************************************************************/

#ifndef SERVO_$_CHANNEL
#define SERVO_$_CHANNEL 0
#elif ((SERVO_$_CHANNEL>=SERVO_NUMBER_OF_CHANNELS_PER_TIMER)||(SERVO_$_CHANNEL<0))
#error "INCORRECT VALUE OF SERVO_$_CHANNEL"
#endif

#ifndef SERVO_$_CHANNEL_MASK
#define SERVO_$_CHANNEL_MASK (SERVO_$_CHANNEL<<3)
#endif

/******************************************************************************************************/
//TIMER SELECT
/******************************************************************************************************/

#ifndef SERVO_$_TIMER
#define SERVO_$_TIMER SERVO_TIMER_0
#elif ((SERVO_$_TIMER>=SERVO_NUMBER_OF_TIMERS)||(SERVO_$_TIMER<0))
#error "INCORRECT VALUE OF SERVO_$_TIMER"
#endif

#ifndef SERVO_$_TIMER_MASK
#define SERVO_$_TIMER_MASK (SERVO_$_TIMER<<6)
#endif

/******************************************************************************************************/

#if (SERVO_$_TIMER == SERVO_TIMER_0)

#ifndef SERVO_USE_TIMER_0
#define SERVO_USE_TIMER_0 YES
#else
#undef SERVO_USE_TIMER_0
#define SERVO_USE_TIMER_0 YES
#endif

#elif (SERVO_$_TIMER == SERVO_TIMER_1)

#ifndef SERVO_USE_TIMER_1
#define SERVO_USE_TIMER_1 YES
#else
#undef SERVO_USE_TIMER_1
#define SERVO_USE_TIMER_1 YES
#endif

#elif (SERVO_$_TIMER == SERVO_TIMER_2)

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

SERVO SERVO_$_STRUCT =
{
    SERVO_$_ADDRESS_OF_DDR_DATA,
    (SERVO_$_TIMER_MASK+SERVO_$_CHANNEL_MASK+SERVO_$_DATA_GPIO_PIN)
};

/******************************************************************************************************/

#define SERVO_$ &SERVO_$_STRUCT

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
