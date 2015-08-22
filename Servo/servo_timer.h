/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

servo_timer.h

DESCRIPTION:
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef SERVO_TIMER_H_
#define SERVO_TIMER_H_

/******************************************************************************************************/

#include <stdint.h>

/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include "cf.h"

/******************************************************************************************************/
//GLOBAL VARIABLES
/******************************************************************************************************/

#if ((defined(SERVO_USE_TIMER_0))&&(SERVO_USE_TIMER_0 == YES))
volatile uint8_t servo_timer_0_ticks[SERVO_NUMBER_OF_CHANNELS_PER_TIMER]={155,155,155,155,155,155,155,155};
SERVO *servo_timer_0_channels[SERVO_NUMBER_OF_CHANNELS_PER_TIMER];
volatile uint8_t servo_timer_0_status=0;
#endif

#if ((defined(SERVO_USE_TIMER_1))&&(SERVO_USE_TIMER_1 == YES))
volatile uint8_t servo_timer_1_ticks[SERVO_NUMBER_OF_CHANNELS_PER_TIMER]={155,155,155,155,155,155,155,155};
SERVO *servo_timer_1_channels[SERVO_NUMBER_OF_CHANNELS_PER_TIMER];
volatile uint8_t servo_timer_1_status=0;
#endif

#if ((defined(SERVO_USE_TIMER_2))&&(SERVO_USE_TIMER_2 == YES))
volatile uint8_t servo_timer_2_ticks[SERVO_NUMBER_OF_CHANNELS_PER_TIMER]={155,155,155,155,155,155,155,155};
SERVO *servo_timer_2_channels[SERVO_NUMBER_OF_CHANNELS_PER_TIMER];
volatile uint8_t servo_timer_2_status=0;
#endif

/******************************************************************************************************/
//USE MACROS
/******************************************************************************************************/

#ifndef USE_servo_timer_init
#define USE_servo_timer_init YES
#endif

#ifndef USE_servo_timer_interrupt_handler
#define USE_servo_timer_interrupt_handler YES
#endif


/******************************************************************************************************/
//FUNCTION PROTOTYPE
/******************************************************************************************************/

#if (USE_servo_timer_init == YES)
void servo_timer_init(void);
#endif

#if (USE_servo_timer_interrupt_handler == YES)
void servo_timer_interrupt_handler(uint8_t*,uint8_t*,SERVO**,uint8_t*);
#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
