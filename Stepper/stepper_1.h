/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

stepper_1.h

DESCRIPTION: TO BE USED TO INTERFACE 2 PHASE, 4 WIRE(EXCLUDING COMMON LINES) BIPOLAR/UNIPOLAR STEPPER MOTOR.
REPLACE "1" BY A NUMBER AND ADD THE FILE AFTER RENAMING IT.
ABOVE INSTRUCTION TO BE FOLLOWED FOR EACH NEW STEPPER MOTOR.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef STEPPER_1_H_
#define STEPPER_1_H_

/******************************************************************************************************/

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>

/******************************************************************************************************/

#include "cf.h"
#include "stepper.h"

/******************************************************************************************************/
//GPIO PORT
/******************************************************************************************************/

#if !defined(STEPPER_1_ALL_GPIO_PORT)
#define STEPPER_1_ALL_GPIO_PORT A
#endif

/******************************************************************************************************/

#if !defined(STEPPER_1_A_PLUS_GPIO_PORT)
#define STEPPER_1_A_PLUS_GPIO_PORT STEPPER_1_ALL_GPIO_PORT
#endif

#if !defined(STEPPER_1_A_MINUS_GPIO_PORT)
#define STEPPER_1_A_MINUS_GPIO_PORT STEPPER_1_ALL_GPIO_PORT
#endif

#if !defined(STEPPER_1_B_PLUS_GPIO_PORT)
#define STEPPER_1_B_PLUS_GPIO_PORT STEPPER_1_ALL_GPIO_PORT
#endif

#if !defined(STEPPER_1_B_MINUS_GPIO_PORT)
#define STEPPER_1_B_MINUS_GPIO_PORT STEPPER_1_ALL_GPIO_PORT
#endif

/******************************************************************************************************/
//GPIO PINS
/******************************************************************************************************/

#if !defined(STEPPER_1_A_PLUS_GPIO_PIN)
#define STEPPER_1_A_PLUS_GPIO_PIN 0
#endif

#if !defined(STEPPER_1_A_MINUS_GPIO_PIN)
#define STEPPER_1_A_MINUS_GPIO_PIN 1
#endif

#if !defined(STEPPER_1_B_PLUS_GPIO_PIN)
#define STEPPER_1_B_PLUS_GPIO_PIN 2
#endif

#if !defined(STEPPER_1_B_MINUS_GPIO_PIN)
#define STEPPER_1_B_MINUS_GPIO_PIN 3
#endif

/******************************************************************************************************/
//DDR MACROS
/******************************************************************************************************/
/*
#if !defined(STEPPER_1_DDR_A_PLUS)
#define STEPPER_1_DDR_A_PLUS DDR(STEPPER_1_A_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_DDR_A_MINUS)
#define STEPPER_1_DDR_A_MINUS DDR(STEPPER_1_A_MINUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_DDR_B_PLUS)
#define STEPPER_1_DDR_B_PLUS DDR(STEPPER_1_B_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_DDR_B_MINUS)
#define STEPPER_1_DDR_B_MINUS DDR(STEPPER_1_B_MINUS_GPIO_PORT)
#endif
*/
/******************************************************************************************************/
//PIN MACROS
/******************************************************************************************************/
/*
#if !defined(STEPPER_1_PIN_A_PLUS)
#define STEPPER_1_PIN_A_PLUS PIN(STEPPER_1_A_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_PIN_A_MINUS)
#define STEPPER_1_PIN_A_MINUS PIN(STEPPER_1_A_MINUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_PIN_B_PLUS)
#define STEPPER_1_PIN_B_PLUS PIN(STEPPER_1_B_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_PIN_B_MINUS)
#define STEPPER_1_PIN_B_MINUS PIN(STEPPER_1_B_MINUS_GPIO_PORT)
#endif
*/
/******************************************************************************************************/
//PORT MACROS
/******************************************************************************************************/
/*
#if !defined(STEPPER_1_PORT_A_PLUS)
#define STEPPER_1_PORT_A_PLUS PORT(STEPPER_1_A_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_PORT_A_MINUS)
#define STEPPER_1_PORT_A_MINUS PORT(STEPPER_1_A_MINUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_PORT_B_PLUS)
#define STEPPER_1_PORT_B_PLUS PORT(STEPPER_1_B_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_1_PORT_B_MINUS)
#define STEPPER_1_PORT_B_MINUS PORT(STEPPER_1_B_MINUS_GPIO_PORT)
#endif
*/
/******************************************************************************************************/
//ADDRESS MACROS
/******************************************************************************************************/
//DDR
/******************************************************************************************************/

#if !defined(STEPPER_1_ADDRESS_OF_DDR_ALL)

#if (STEPPER_1_ALL_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_DDR_ALL (uint8_t*)&DDRA
#elif (STEPPER_1_ALL_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_DDR_ALL (uint8_t*)&DDRB
#elif (STEPPER_1_ALL_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_DDR_ALL (uint8_t*)&DDRC
#elif (STEPPER_1_ALL_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_DDR_ALL (uint8_t*)&DDRD
#endif

#endif

/******************************************************************************************************/

#if !defined(STEPPER_1_ADDRESS_OF_DDR_A_PLUS)

#if (STEPPER_1_A_PLUS_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_DDR_A_PLUS (uint8_t*)&DDRA
#elif (STEPPER_1_A_PLUS_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_DDR_A_PLUS (uint8_t*)&DDRB
#elif (STEPPER_1_A_PLUS_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_DDR_A_PLUS (uint8_t*)&DDRC
#elif (STEPPER_1_A_PLUS_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_DDR_A_PLUS (uint8_t*)&DDRD
#endif

#endif

#if !defined(STEPPER_1_ADDRESS_OF_DDR_A_MINUS)

#if (STEPPER_1_A_MINUS_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_DDR_A_MINUS (uint8_t*)&DDRA
#elif (STEPPER_1_A_MINUS_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_DDR_A_MINUS (uint8_t*)&DDRB
#elif (STEPPER_1_A_MINUS_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_DDR_A_MINUS (uint8_t*)&DDRC
#elif (STEPPER_1_A_MINUS_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_DDR_A_MINUS (uint8_t*)&DDRD
#endif

#endif

#if !defined(STEPPER_1_ADDRESS_OF_DDR_B_PLUS)

#if (STEPPER_1_B_PLUS_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_DDR_B_PLUS (uint8_t*)&DDRA
#elif (STEPPER_1_B_PLUS_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_DDR_B_PLUS (uint8_t*)&DDRB
#elif (STEPPER_1_B_PLUS_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_DDR_B_PLUS (uint8_t*)&DDRC
#elif (STEPPER_1_B_PLUS_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_DDR_B_PLUS (uint8_t*)&DDRD
#endif

#endif

#if !defined(STEPPER_1_ADDRESS_OF_DDR_B_MINUS)

#if (STEPPER_1_B_MINUS_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_DDR_B_MINUS (uint8_t*)&DDRA
#elif (STEPPER_1_B_MINUS_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_DDR_B_MINUS (uint8_t*)&DDRB
#elif (STEPPER_1_B_MINUS_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_DDR_B_MINUS (uint8_t*)&DDRC
#elif (STEPPER_1_B_MINUS_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_DDR_B_MINUS (uint8_t*)&DDRD
#endif

#endif

/******************************************************************************************************/
//PIN
/******************************************************************************************************/
/*
#if !defined(STEPPER_1_ADDRESS_OF_PIN_A_PLUS)
#define STEPPER_1_ADDRESS_OF_PIN_A_PLUS APPEND_2_1(&,APPEND_2_1(PIN,STEPPER_1_A_PLUS_GPIO_PORT)))
#endif

#if !defined(STEPPER_1_ADDRESS_OF_PIN_A_MINUS)
#define STEPPER_1_ADDRESS_OF_PIN_A_MINUS APPEND_2_1(&,APPEND_2_1(PIN,STEPPER_1_A_MINUS_GPIO_PORT))
#endif

#if !defined(STEPPER_1_ADDRESS_OF_PIN_B_PLUS)
#define STEPPER_1_ADDRESS_OF_PIN_B_PLUS APPEND_2_1(&,APPEND_2_1(PIN,STEPPER_1_B_PLUS_GPIO_PORT))
#endif

#if !defined(STEPPER_1_ADDRESS_OF_PIN_B_MINUS)
#define STEPPER_1_ADDRESS_OF_PIN_B_MINUS APPEND_2_1(&,APPEND_2_1(PIN,STEPPER_1_B_MINUS_GPIO_PORT))
#endif
*/
/******************************************************************************************************/
//PORT
/******************************************************************************************************/

#if !defined(STEPPER_1_ADDRESS_OF_PORT_ALL)

#if (STEPPER_1_ALL_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_PORT_ALL (uint8_t*)&PORTA
#elif (STEPPER_1_ALL_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_PORT_ALL (uint8_t*)&PORTB
#elif (STEPPER_1_ALL_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_PORT_ALL (uint8_t*)&PORTC
#elif (STEPPER_1_ALL_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_PORT_ALL (uint8_t*)&PORTD
#endif

#endif

/******************************************************************************************************/

#if !defined(STEPPER_1_ADDRESS_OF_PORT_A_PLUS)

#if (STEPPER_1_A_PLUS_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_PORT_A_PLUS (uint8_t*)&PORTA
#elif (STEPPER_1_A_PLUS_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_PORT_A_PLUS (uint8_t*)&PORTB
#elif (STEPPER_1_A_PLUS_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_PORT_A_PLUS (uint8_t*)&PORTC
#elif (STEPPER_1_A_PLUS_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_PORT_A_PLUS (uint8_t*)&PORTD
#endif

#endif

#if !defined(STEPPER_1_ADDRESS_OF_PORT_A_MINUS)

#if (STEPPER_1_A_MINUS_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_PORT_A_MINUS (uint8_t*)&PORTA
#elif (STEPPER_1_A_MINUS_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_PORT_A_MINUS (uint8_t*)&PORTB
#elif (STEPPER_1_A_MINUS_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_PORT_A_MINUS (uint8_t*)&PORTC
#elif (STEPPER_1_A_MINUS_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_PORT_A_MINUS (uint8_t*)&PORTD
#endif

#endif

#if !defined(STEPPER_1_ADDRESS_OF_PORT_B_PLUS)

#if (STEPPER_1_B_PLUS_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_PORT_B_PLUS (uint8_t*)&PORTA
#elif (STEPPER_1_B_PLUS_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_PORT_B_PLUS (uint8_t*)&PORTB
#elif (STEPPER_1_B_PLUS_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_PORT_B_PLUS (uint8_t*)&PORTC
#elif (STEPPER_1_B_PLUS_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_PORT_B_PLUS (uint8_t*)&PORTD
#endif

#endif

#if !defined(STEPPER_1_ADDRESS_OF_PORT_B_MINUS)

#if (STEPPER_1_B_MINUS_GPIO_PORT == A)
#define STEPPER_1_ADDRESS_OF_PORT_B_MINUS (uint8_t*)&PORTA
#elif (STEPPER_1_B_MINUS_GPIO_PORT == B)
#define STEPPER_1_ADDRESS_OF_PORT_B_MINUS (uint8_t*)PORTB
#elif (STEPPER_1_B_MINUS_GPIO_PORT == C)
#define STEPPER_1_ADDRESS_OF_PORT_B_MINUS (uint8_t*)&PORTC
#elif (STEPPER_1_B_MINUS_GPIO_PORT == D)
#define STEPPER_1_ADDRESS_OF_PORT_B_MINUS (uint8_t*)&PORTD
#endif

#endif

/******************************************************************************************************/
//MISC MACROS
/******************************************************************************************************/

#if !defined(STEPPER_1_IS_UNIPOLAR)

#define STEPPER_1_IS_UNIPOLAR NO
#define STEPPER_1_IS_BIPOLAR YES
#define STEPPER_1_FLAG 0

#elif (STEPPER_1_IS_UNIPOLAR == YES)

//#define STEPPER_1_IS_UNIPOLAR NO
#define STEPPER_1_IS_BIPOLAR NO
#define STEPPER_1_FLAG (1<<7)

#else

#undef STEPPER_1_IS_UNIPOLAR
#define STEPPER_1_IS_UNIPOLAR no
#define STEPPER_1_IS_BIPOLAR YES
#define STEPPER_1_FLAG 0

#endif

/******************************************************************************************************/
//GLOBAL VARIABLES
/******************************************************************************************************/

STEPPER STEPPER_1_STRUCT=
{
    #if (STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)

    STEPPER_1_ADDRESS_OF_DDR_ALL,

    #elif (STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)

    STEPPER_1_ADDRESS_OF_DDR_A_PLUS,
    STEPPER_1_ADDRESS_OF_DDR_A_MINUS,
    STEPPER_1_ADDRESS_OF_DDR_B_PLUS,
    STEPPER_1_ADDRESS_OF_DDR_B_MINUS,

    #endif

    STEPPER_1_A_PLUS_GPIO_PIN,
    STEPPER_1_A_MINUS_GPIO_PIN,
    STEPPER_1_B_PLUS_GPIO_PIN,
    STEPPER_1_B_MINUS_GPIO_PIN,

    STEPPER_1_FLAG
};

/******************************************************************************************************/

#define STEPPER_1 &STEPPER_1_STRUCT

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
