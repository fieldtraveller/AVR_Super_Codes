/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

cf.h

DESCRIPTION: Standard macros defined here.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Note:All macros involving code manipulation should follow the following format
(LIBRARY NAME)_(DDR/PIN/PORT)_(NAME OF MACRO)_(GPIO_PORT/GPIO_PIN)
*/
/******************************************************************************************************/

#ifndef CF_H_
#define CF_H_

/******************************************************************************************************/
//TIME PASS
/******************************************************************************************************/

#define ALEX 18031994

/******************************************************************************************************/
//Standard Appending macros
/******************************************************************************************************/

#define APPEND_2_0(a,s) a##s
#define APPEND_2_1(a,s) APPEND_2_0(a,s)

#define APPEND_3_0(a,s,d) a##s##d
#define APPEND_3_1(a,s,d) APPEND_3_0(a,s,d)

/******************************************************************************************************/
//Standard register manipulation macros
/******************************************************************************************************/

#define PORT(x) APPEND_2_0(PORT,x)
#define PIN(x) APPEND_2_0(PIN,x)
#define DDR(x) APPEND_2_0(DDR,x)

/******************************************************************************************************/

#define NOP asm("nop")
#define SET_BIT(port, bit) (port) |= (1 << (bit))
#define CLEAR_BIT(port, bit) (port) &= ~(1 << (bit))

/******************************************************************************************************/

#define _PA 255
#define _PB 254
#define _PC 253
#define _PD 252

#define _PA0 0
#define _PA1 1
#define _PA2 2
#define _PA3 3
#define _PA4 4
#define _PA5 5
#define _PA6 6
#define _PA7 7

#define _PB0 8
#define _PB1 9
#define _PB2 10
#define _PB3 11
#define _PB4 12
#define _PB5 13
#define _PB6 14
#define _PB7 15

#define _PC0 16
#define _PC1 17
#define _PC2 18
#define _PC3 19
#define _PC4 20
#define _PC5 21
#define _PC6 22
#define _PC7 23

#define _PD0 24
#define _PD1 25
#define _PD2 26
#define _PD3 27
#define _PD4 28
#define _PD5 29
#define _PD6 30
#define _PD7 31

/******************************************************************************************************/

#define YES 1
#define NO  0

#define ONE YES
#define ZERO NO

#define TRUE YES
#define FALSE NO

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
