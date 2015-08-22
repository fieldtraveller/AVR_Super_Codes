/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

stepper_$.h

DESCRIPTION: TO BE USED TO INTERFACE 2 PHASE, 4 WIRE(EXCLUDING COMMON LINES) BIPOLAR/UNIPOLAR STEPPER MOTOR.
REPLACE "$" BY A NUMBER AND ADD THE FILE AFTER RENAMING IT.
ABOVE INSTRUCTION TO BE FOLLOWED FOR EACH NEW STEPPER MOTOR.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef STEPPER_$_H_
#define STEPPER_$_H_

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

#if !defined(STEPPER_$_ALL_GPIO_PORT)
#define STEPPER_$_ALL_GPIO_PORT A
#endif

/******************************************************************************************************/

#if !defined(STEPPER_$_A_PLUS_GPIO_PORT)
#define STEPPER_$_A_PLUS_GPIO_PORT STEPPER_$_ALL_GPIO_PORT
#endif

#if !defined(STEPPER_$_A_MINUS_GPIO_PORT)
#define STEPPER_$_A_MINUS_GPIO_PORT STEPPER_$_ALL_GPIO_PORT
#endif

#if !defined(STEPPER_$_B_PLUS_GPIO_PORT)
#define STEPPER_$_B_PLUS_GPIO_PORT STEPPER_$_ALL_GPIO_PORT
#endif

#if !defined(STEPPER_$_B_MINUS_GPIO_PORT)
#define STEPPER_$_B_MINUS_GPIO_PORT STEPPER_$_ALL_GPIO_PORT
#endif

/******************************************************************************************************/
//GPIO PINS
/******************************************************************************************************/

#if !defined(STEPPER_$_A_PLUS_GPIO_PIN)
#define STEPPER_$_A_PLUS_GPIO_PIN 0
#endif

#if !defined(STEPPER_$_A_MINUS_GPIO_PIN)
#define STEPPER_$_A_MINUS_GPIO_PIN 1
#endif

#if !defined(STEPPER_$_B_PLUS_GPIO_PIN)
#define STEPPER_$_B_PLUS_GPIO_PIN 2
#endif

#if !defined(STEPPER_$_B_MINUS_GPIO_PIN)
#define STEPPER_$_B_MINUS_GPIO_PIN 3
#endif

/******************************************************************************************************/
//DDR MACROS
/******************************************************************************************************/
/*
#if !defined(STEPPER_$_DDR_A_PLUS)
#define STEPPER_$_DDR_A_PLUS DDR(STEPPER_$_A_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_DDR_A_MINUS)
#define STEPPER_$_DDR_A_MINUS DDR(STEPPER_$_A_MINUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_DDR_B_PLUS)
#define STEPPER_$_DDR_B_PLUS DDR(STEPPER_$_B_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_DDR_B_MINUS)
#define STEPPER_$_DDR_B_MINUS DDR(STEPPER_$_B_MINUS_GPIO_PORT)
#endif
*/
/******************************************************************************************************/
//PIN MACROS
/******************************************************************************************************/
/*
#if !defined(STEPPER_$_PIN_A_PLUS)
#define STEPPER_$_PIN_A_PLUS PIN(STEPPER_$_A_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_PIN_A_MINUS)
#define STEPPER_$_PIN_A_MINUS PIN(STEPPER_$_A_MINUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_PIN_B_PLUS)
#define STEPPER_$_PIN_B_PLUS PIN(STEPPER_$_B_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_PIN_B_MINUS)
#define STEPPER_$_PIN_B_MINUS PIN(STEPPER_$_B_MINUS_GPIO_PORT)
#endif
*/
/******************************************************************************************************/
//PORT MACROS
/******************************************************************************************************/
/*
#if !defined(STEPPER_$_PORT_A_PLUS)
#define STEPPER_$_PORT_A_PLUS PORT(STEPPER_$_A_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_PORT_A_MINUS)
#define STEPPER_$_PORT_A_MINUS PORT(STEPPER_$_A_MINUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_PORT_B_PLUS)
#define STEPPER_$_PORT_B_PLUS PORT(STEPPER_$_B_PLUS_GPIO_PORT)
#endif

#if !defined(STEPPER_$_PORT_B_MINUS)
#define STEPPER_$_PORT_B_MINUS PORT(STEPPER_$_B_MINUS_GPIO_PORT)
#endif
*/
/******************************************************************************************************/
//ADDRESS MACROS
/******************************************************************************************************/
//DDR
/******************************************************************************************************/

#if !defined(STEPPER_$_ADDRESS_OF_DDR_ALL)

#if (STEPPER_$_ALL_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_DDR_ALL (uint8_t*)&DDRA
#elif (STEPPER_$_ALL_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_DDR_ALL (uint8_t*)&DDRB
#elif (STEPPER_$_ALL_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_DDR_ALL (uint8_t*)&DDRC
#elif (STEPPER_$_ALL_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_DDR_ALL (uint8_t*)&DDRD
#endif

#endif

/******************************************************************************************************/

#if !defined(STEPPER_$_ADDRESS_OF_DDR_A_PLUS)

#if (STEPPER_$_A_PLUS_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_DDR_A_PLUS (uint8_t*)&DDRA
#elif (STEPPER_$_A_PLUS_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_DDR_A_PLUS (uint8_t*)&DDRB
#elif (STEPPER_$_A_PLUS_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_DDR_A_PLUS (uint8_t*)&DDRC
#elif (STEPPER_$_A_PLUS_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_DDR_A_PLUS (uint8_t*)&DDRD
#endif

#endif

#if !defined(STEPPER_$_ADDRESS_OF_DDR_A_MINUS)

#if (STEPPER_$_A_MINUS_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_DDR_A_MINUS (uint8_t*)&DDRA
#elif (STEPPER_$_A_MINUS_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_DDR_A_MINUS (uint8_t*)&DDRB
#elif (STEPPER_$_A_MINUS_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_DDR_A_MINUS (uint8_t*)&DDRC
#elif (STEPPER_$_A_MINUS_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_DDR_A_MINUS (uint8_t*)&DDRD
#endif

#endif

#if !defined(STEPPER_$_ADDRESS_OF_DDR_B_PLUS)

#if (STEPPER_$_B_PLUS_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_DDR_B_PLUS (uint8_t*)&DDRA
#elif (STEPPER_$_B_PLUS_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_DDR_B_PLUS (uint8_t*)&DDRB
#elif (STEPPER_$_B_PLUS_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_DDR_B_PLUS (uint8_t*)&DDRC
#elif (STEPPER_$_B_PLUS_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_DDR_B_PLUS (uint8_t*)&DDRD
#endif

#endif

#if !defined(STEPPER_$_ADDRESS_OF_DDR_B_MINUS)

#if (STEPPER_$_B_MINUS_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_DDR_B_MINUS (uint8_t*)&DDRA
#elif (STEPPER_$_B_MINUS_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_DDR_B_MINUS (uint8_t*)&DDRB
#elif (STEPPER_$_B_MINUS_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_DDR_B_MINUS (uint8_t*)&DDRC
#elif (STEPPER_$_B_MINUS_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_DDR_B_MINUS (uint8_t*)&DDRD
#endif

#endif

/******************************************************************************************************/
//PIN
/******************************************************************************************************/
/*
#if !defined(STEPPER_$_ADDRESS_OF_PIN_A_PLUS)
#define STEPPER_$_ADDRESS_OF_PIN_A_PLUS APPEND_2_1(&,APPEND_2_1(PIN,STEPPER_$_A_PLUS_GPIO_PORT)))
#endif

#if !defined(STEPPER_$_ADDRESS_OF_PIN_A_MINUS)
#define STEPPER_$_ADDRESS_OF_PIN_A_MINUS APPEND_2_1(&,APPEND_2_1(PIN,STEPPER_$_A_MINUS_GPIO_PORT))
#endif

#if !defined(STEPPER_$_ADDRESS_OF_PIN_B_PLUS)
#define STEPPER_$_ADDRESS_OF_PIN_B_PLUS APPEND_2_1(&,APPEND_2_1(PIN,STEPPER_$_B_PLUS_GPIO_PORT))
#endif

#if !defined(STEPPER_$_ADDRESS_OF_PIN_B_MINUS)
#define STEPPER_$_ADDRESS_OF_PIN_B_MINUS APPEND_2_1(&,APPEND_2_1(PIN,STEPPER_$_B_MINUS_GPIO_PORT))
#endif
*/
/******************************************************************************************************/
//PORT
/******************************************************************************************************/

#if !defined(STEPPER_$_ADDRESS_OF_PORT_ALL)

#if (STEPPER_$_ALL_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_PORT_ALL (uint8_t*)&PORTA
#elif (STEPPER_$_ALL_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_PORT_ALL (uint8_t*)&PORTB
#elif (STEPPER_$_ALL_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_PORT_ALL (uint8_t*)&PORTC
#elif (STEPPER_$_ALL_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_PORT_ALL (uint8_t*)&PORTD
#endif

#endif

/******************************************************************************************************/

#if !defined(STEPPER_$_ADDRESS_OF_PORT_A_PLUS)

#if (STEPPER_$_A_PLUS_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_PORT_A_PLUS (uint8_t*)&PORTA
#elif (STEPPER_$_A_PLUS_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_PORT_A_PLUS (uint8_t*)&PORTB
#elif (STEPPER_$_A_PLUS_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_PORT_A_PLUS (uint8_t*)&PORTC
#elif (STEPPER_$_A_PLUS_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_PORT_A_PLUS (uint8_t*)&PORTD
#endif

#endif

#if !defined(STEPPER_$_ADDRESS_OF_PORT_A_MINUS)

#if (STEPPER_$_A_MINUS_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_PORT_A_MINUS (uint8_t*)&PORTA
#elif (STEPPER_$_A_MINUS_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_PORT_A_MINUS (uint8_t*)&PORTB
#elif (STEPPER_$_A_MINUS_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_PORT_A_MINUS (uint8_t*)&PORTC
#elif (STEPPER_$_A_MINUS_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_PORT_A_MINUS (uint8_t*)&PORTD
#endif

#endif

#if !defined(STEPPER_$_ADDRESS_OF_PORT_B_PLUS)

#if (STEPPER_$_B_PLUS_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_PORT_B_PLUS (uint8_t*)&PORTA
#elif (STEPPER_$_B_PLUS_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_PORT_B_PLUS (uint8_t*)&PORTB
#elif (STEPPER_$_B_PLUS_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_PORT_B_PLUS (uint8_t*)&PORTC
#elif (STEPPER_$_B_PLUS_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_PORT_B_PLUS (uint8_t*)&PORTD
#endif

#endif

#if !defined(STEPPER_$_ADDRESS_OF_PORT_B_MINUS)

#if (STEPPER_$_B_MINUS_GPIO_PORT == A)
#define STEPPER_$_ADDRESS_OF_PORT_B_MINUS (uint8_t*)&PORTA
#elif (STEPPER_$_B_MINUS_GPIO_PORT == B)
#define STEPPER_$_ADDRESS_OF_PORT_B_MINUS (uint8_t*)PORTB
#elif (STEPPER_$_B_MINUS_GPIO_PORT == C)
#define STEPPER_$_ADDRESS_OF_PORT_B_MINUS (uint8_t*)&PORTC
#elif (STEPPER_$_B_MINUS_GPIO_PORT == D)
#define STEPPER_$_ADDRESS_OF_PORT_B_MINUS (uint8_t*)&PORTD
#endif

#endif

/******************************************************************************************************/
//MISC MACROS
/******************************************************************************************************/

#if !defined(STEPPER_$_IS_UNIPOLAR)

#define STEPPER_$_IS_UNIPOLAR NO
#define STEPPER_$_IS_BIPOLAR YES
#define STEPPER_$_FLAG 0

#elif (STEPPER_$_IS_UNIPOLAR == YES)

//#define STEPPER_$_IS_UNIPOLAR NO
#define STEPPER_$_IS_BIPOLAR NO
#define STEPPER_$_FLAG (1<<7)

#else

#undef STEPPER_$_IS_UNIPOLAR
#define STEPPER_$_IS_UNIPOLAR no
#define STEPPER_$_IS_BIPOLAR YES
#define STEPPER_$_FLAG 0

#endif

/******************************************************************************************************/
//GLOBAL VARIABLES
/******************************************************************************************************/

STEPPER STEPPER_$_STRUCT=
{
    #if (STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)

    STEPPER_$_ADDRESS_OF_DDR_ALL,

    #elif (STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)

    STEPPER_$_ADDRESS_OF_DDR_A_PLUS,
    STEPPER_$_ADDRESS_OF_DDR_A_MINUS,
    STEPPER_$_ADDRESS_OF_DDR_B_PLUS,
    STEPPER_$_ADDRESS_OF_DDR_B_MINUS,

    #endif

    STEPPER_$_A_PLUS_GPIO_PIN,
    STEPPER_$_A_MINUS_GPIO_PIN,
    STEPPER_$_B_PLUS_GPIO_PIN,
    STEPPER_$_B_MINUS_GPIO_PIN,

    STEPPER_$_FLAG
};

/******************************************************************************************************/

#define STEPPER_$ &STEPPER_$_STRUCT

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
