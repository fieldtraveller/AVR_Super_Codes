/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

shift.h

DESCRIPTION:Shift library to be use with shift register interfacing.

Default Settings:
Module 1:
Data:D0
Clock:D1
Latch:D2

Module 2:
Data:D3
Clock:D4
Latch:D5

Module 3:
Data:C0
Clock:C1
Latch:C2

Module 4:
Data:C3
Clock:C4
Latch:C5

All Modules in output mode,no latch.

Shift Module=Shift register+code.

74595 are 8-stage serial shift registers with a storage register and
3-state outputs. The registers have separate clocks.
Data is shifted on the positive-going transitions of the shift register clock input (SHCP).
The data in each register is transferred to the storage register on a positive-going
transition of the storage register clock input (STCP). If both clocks are connected together,
the shift register will always be one clock pulse ahead of the storage register.
The shift register has a serial input (DS) and a serial standard output (Q7S) for cascading.
It is also provided with asynchronous reset (active LOW) for all 8 shift register stages. The
storage register has 8 parallel 3-state bus driver outputs. Data in the storage register
appears at the output whenever the output enable input (OE) is LOW.

100 MHz (typical) shift out frequency
Operating Voltage:5V

Pin Discription of 74595
SYMBOL PIN 	DESCRIPTION
 Q1 	1   PARALLEL DATA OUTPUT 1
 Q2 	2   PARALLEL DATA OUTPUT 2
 Q3 	3   PARALLEL DATA OUTPUT 3
 Q4 	4   PARALLEL DATA OUTPUT 4
 Q5 	5   PARALLEL DATA OUTPUT 5
 Q6 	6   PARALLEL DATA OUTPUT 6
 Q7 	7   PARALLEL DATA OUTPUT 7
 GND 	8   GROUND (0 V)
 Q7S 	9   SERIAL DATA OUTPUT
 MR 	10  MASTER RESET (ACTIVE LOW)
 SHCP 	11  SHIFT REGISTER CLOCK INPUT(RISING EDGE)
 STCP 	12  STORAGE REGISTER CLOCK INPUT(RISING EDGE)
 OE 	13  OUTPUT ENABLE INPUT (ACTIVE LOW)
 DS 	14  SERIAL DATA INPUT
 Q0 	15  PARALLEL DATA OUTPUT 0
 VCC 	16  SUPPLY VOLTAGE

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef SHIFT_H_
#define SHIFT_H_

/******************************************************************************************************/

#include "cf.h"

/******************************************************************************************************/
//Module select
/******************************************************************************************************/

#if !defined(SHIFT_1_USE)
#define SHIFT_1_USE NO
#else
#undef SHIFT_1_USE
#define SHIFT_1_USE YES
#endif

/******************************************************************************************************/

#if !defined(SHIFT_2_USE)
#define SHIFT_2_USE NO
#else
#undef SHIFT_2_USE
#define SHIFT_2_USE YES
#endif

/******************************************************************************************************/

#if !defined(SHIFT_3_USE)
#define SHIFT_3_USE NO
#else
#undef SHIFT_3_USE
#define SHIFT_3_USE YES
#endif

/******************************************************************************************************/

#if !defined(SHIFT_4_USE)
#define SHIFT_4_USE NO
#else
#undef SHIFT_4_USE
#define SHIFT_4_USE YES
#endif

/******************************************************************************************************/

#if !((SHIFT_1_USE)||(SHIFT_2_USE)||(SHIFT_3_USE)||(SHIFT_4_USE))
#error "No Module selected."
#endif

/******************************************************************************************************/
//Module Discription
/******************************************************************************************************/
//Module 1
/******************************************************************************************************/

#if (SHIFT_1_USE) == YES

/******************************************************************************************************/
//Input/Output Select
/******************************************************************************************************/

#if defined(SHIFT_1_USE_AS_OUTPUT)
#undef SHIFT_1_USE_AS_OUTPUT
#define SHIFT_1_USE_AS_OUTPUT YES
#elif defined(SHIFT_1_USE_AS_INPUT)
#define SHIFT_1_USE_AS_OUTPUT NO
#elif !defined(SHIFT_1_USE_AS_OUTPUT)
#define SHIFT_1_USE_AS_OUTPUT YES
#endif

/******************************************************************************************************/
//Default GPIO port name macro
/******************************************************************************************************/

#if !defined(SHIFT_1_GPIO_PORT)
#define SHIFT_1_GPIO_PORT D
#endif

/******************************************************************************************************/
//Data pin settings
/******************************************************************************************************/

#if !defined(SHIFT_1_DATA_GPIO_PIN)
#define SHIFT_1_DATA_GPIO_PIN 0
#endif

#if !defined(SHIFT_1_DATA_GPIO_PORT)
#define SHIFT_1_DATA_GPIO_PORT SHIFT_1_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_1_DATA)
#define SHIFT_DDR_1_DATA DDR(SHIFT_1_DATA_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_1_DATA)
#define SHIFT_PORT_1_DATA PORT(SHIFT_1_DATA_GPIO_PORT)
#endif

#if !defined(SHIFT_PIN_1_DATA)
#define SHIFT_PIN_1_DATA PIN(SHIFT_1_DATA_GPIO_PORT)
#endif

/******************************************************************************************************/
//Additional Data macros
/******************************************************************************************************/

#if defined(SHIFT_1_DATA_PIN_PULL_UP_ENABLE)
#undef SHIFT_1_DATA_PIN_PULL_UP_ENABLE
#define SHIFT_1_DATA_PIN_PULL_UP_ENABLE YES
#else
#define SHIFT_1_DATA_PIN_PULL_UP_ENABLE NO
#endif

/******************************************************************************************************/
//Clock pin settings
/******************************************************************************************************/

#if !defined(SHIFT_1_CLOCK_GPIO_PIN)
#define SHIFT_1_CLOCK_GPIO_PIN 1
#endif

#if !defined(SHIFT_1_CLOCK_GPIO_PORT)
#define SHIFT_1_CLOCK_GPIO_PORT SHIFT_1_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_CLOCK_1)
#define SHIFT_DDR_1_CLOCK DDR(SHIFT_1_CLOCK_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_1_CLOCK)
#define SHIFT_PORT_1_CLOCK PORT(SHIFT_1_CLOCK_GPIO_PORT)
#endif

/******************************************************************************************************/
//Latch Pin settings
/******************************************************************************************************/

#if !defined(SHIFT_1_LATCH_ENABLE)
#define SHIFT_1_LATCH_ENABLE NO
#else
#undef SHIFT_1_LATCH_ENABLE
#define SHIFT_1_LATCH_ENABLE YES
#endif

/******************************************************************************************************/

#if (SHIFT_1_LATCH_ENABLE)== YES

#if !defined(SHIFT_1_LATCH_GPIO_PIN)
#define SHIFT_1_LATCH_GPIO_PIN 2
#endif

#if !defined(SHIFT_LATCH_1_GPIO_PORT)
#define SHIFT_1_LATCH_GPIO_PORT SHIFT_1_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_1_LATCH)
#define SHIFT_DDR_1_LATCH DDR(SHIFT_1_LATCH_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_1_LATCH)
#define SHIFT_PORT_1_LATCH PORT(SHIFT_1_LATCH_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Array macros
/******************************************************************************************************/

#if (SHIFT_1_USE_AS_OUTPUT)==YES

#if APPEND_2_1(_P,SHIFT_1_DATA_GPIO_PORT)==_PA
#define SHIFT_1_DATA_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_1_DATA_GPIO_PORT)==_PB
#define SHIFT_1_DATA_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_1_DATA_GPIO_PORT)==_PC
#define SHIFT_1_DATA_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_1_DATA_GPIO_PORT)==_PD
#define SHIFT_1_DATA_I_O 0x12
#endif

#else

#if APPEND_2_1(_P,SHIFT_1_DATA_GPIO_PORT)==_PA
#define SHIFT_1_DATA_I_O 0x19
#elif APPEND_2_1(_P,SHIFT_1_DATA_GPIO_PORT)==_PB
#define SHIFT_1_DATA_I_O 0x16
#elif APPEND_2_1(_P,SHIFT_1_DATA_GPIO_PORT)==_PC
#define SHIFT_1_DATA_I_O 0x13
#elif APPEND_2_1(_P,SHIFT_1_DATA_GPIO_PORT)==_PD
#define SHIFT_1_DATA_I_O 0x10
#endif

#endif

/******************************************************************************************************/

#if APPEND_2_1(_P,SHIFT_1_CLOCK_GPIO_PORT)==_PA
#define SHIFT_1_CLOCK_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_1_CLOCK_GPIO_PORT)==_PB
#define SHIFT_1_CLOCK_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_1_CLOCK_GPIO_PORT)==_PC
#define SHIFT_1_CLOCK_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_1_CLOCK_GPIO_PORT)==_PD
#define SHIFT_1_CLOCK_I_O 0x12
#endif

/******************************************************************************************************/

#if (SHIFT_1_LATCH_ENABLE)==YES

#if APPEND_2_1(_P,SHIFT_1_LATCH_GPIO_PORT)==_PA
#define SHIFT_1_LATCH_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_1_LATCH_GPIO_PORT)==_PB
#define SHIFT_1_LATCH_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_1_LATCH_GPIO_PORT)==_PC
#define SHIFT_1_LATCH_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_1_LATCH_GPIO_PORT)==_PD
#define SHIFT_1_LATCH_I_O 0x12
#endif

#endif

/******************************************************************************************************/
//Identifying macros
/******************************************************************************************************/

#define SHIFT_1_DATA APPEND_3_1(_P,SHIFT_1_DATA_GPIO_PORT,SHIFT_1_DATA_GPIO_PIN)
#define SHIFT_1_CLOCK APPEND_3_1(_P,SHIFT_1_CLOCK_GPIO_PORT,SHIFT_1_CLOCK_GPIO_PIN)

#if (SHIFT_1_LATCH_ENABLE)
#define SHIFT_1_LATCH APPEND_3_1(_P,SHIFT_1_LATCH_GPIO_PORT,SHIFT_1_LATCH_GPIO_PIN)
#endif

/******************************************************************************************************/
//Error check
/******************************************************************************************************/

#if SHIFT_1_DATA==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)
#if SHIFT_1_DATA==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#if SHIFT_1_CLOCK==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
//Module 2
/******************************************************************************************************/

#if (SHIFT_2_USE) == YES

/******************************************************************************************************/
//Input/Output Select
/******************************************************************************************************/

#if defined(SHIFT_2_USE_AS_OUTPUT)
#undef SHIFT_2_USE_AS_OUTPUT
#define SHIFT_2_USE_AS_OUTPUT YES
#elif defined(SHIFT_2_USE_AS_INPUT)
#define SHIFT_2_USE_AS_OUTPUT NO
#elif !defined(SHIFT_2_USE_AS_OUTPUT)
#define SHIFT_2_USE_AS_OUTPUT YES
#endif

/******************************************************************************************************/
//Default GPIO port name macro
/******************************************************************************************************/

#if !defined(SHIFT_2_GPIO_PORT)
#define SHIFT_2_GPIO_PORT D
#endif

/******************************************************************************************************/
//Data pin settings
/******************************************************************************************************/

#if !defined(SHIFT_2_DATA_GPIO_PIN)
#define SHIFT_2_DATA_GPIO_PIN 3
#endif

#if !defined(SHIFT_2_DATA_GPIO_PORT)
#define SHIFT_2_DATA_GPIO_PORT SHIFT_2_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_2_DATA)
#define SHIFT_DDR_2_DATA DDR(SHIFT_2_DATA_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_2_DATA)
#define SHIFT_PORT_2_DATA PORT(SHIFT_2_DATA_GPIO_PORT)
#endif

#if !defined(SHIFT_PIN_2_DATA)
#define SHIFT_PIN_2_DATA PIN(SHIFT_2_DATA_GPIO_PORT)
#endif

/******************************************************************************************************/
//Additional Data macros
/******************************************************************************************************/

#if defined(SHIFT_2_DATA_PIN_PULL_UP_ENABLE)
#undef SHIFT_2_DATA_PIN_PULL_UP_ENABLE
#define SHIFT_2_DATA_PIN_PULL_UP_ENABLE YES
#else
#define SHIFT_2_DATA_PIN_PULL_UP_ENABLE NO
#endif

/******************************************************************************************************/
//Clock pin settings
/******************************************************************************************************/

#if !defined(SHIFT_2_CLOCK_GPIO_PIN)
#define SHIFT_2_CLOCK_GPIO_PIN 4
#endif

#if !defined(SHIFT_2_CLOCK_GPIO_PORT)
#define SHIFT_2_CLOCK_GPIO_PORT SHIFT_2_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_CLOCK_2)
#define SHIFT_DDR_2_CLOCK DDR(SHIFT_2_CLOCK_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_2_CLOCK)
#define SHIFT_PORT_2_CLOCK PORT(SHIFT_2_CLOCK_GPIO_PORT)
#endif

/******************************************************************************************************/
//Latch Pin settings
/******************************************************************************************************/

#if !defined(SHIFT_2_LATCH_ENABLE)
#define SHIFT_2_LATCH_ENABLE NO
#else
#undef SHIFT_2_LATCH_ENABLE
#define SHIFT_2_LATCH_ENABLE YES
#endif

/******************************************************************************************************/

#if (SHIFT_2_LATCH_ENABLE)== YES

#if !defined(SHIFT_2_LATCH_GPIO_PIN)
#define SHIFT_2_LATCH_GPIO_PIN 5
#endif

#if !defined(SHIFT_LATCH_2_GPIO_PORT)
#define SHIFT_2_LATCH_GPIO_PORT SHIFT_2_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_2_LATCH)
#define SHIFT_DDR_2_LATCH DDR(SHIFT_2_LATCH_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_2_LATCH)
#define SHIFT_PORT_2_LATCH PORT(SHIFT_2_LATCH_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Array macros
/******************************************************************************************************/

#if (SHIFT_2_USE_AS_OUTPUT)==YES

#if APPEND_2_1(_P,SHIFT_2_DATA_GPIO_PORT)==_PA
#define SHIFT_2_DATA_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_2_DATA_GPIO_PORT)==_PB
#define SHIFT_2_DATA_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_2_DATA_GPIO_PORT)==_PC
#define SHIFT_2_DATA_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_2_DATA_GPIO_PORT)==_PD
#define SHIFT_2_DATA_I_O 0x12
#endif

#else

#if APPEND_2_1(_P,SHIFT_2_DATA_GPIO_PORT)==_PA
#define SHIFT_2_DATA_I_O 0x19
#elif APPEND_2_1(_P,SHIFT_2_DATA_GPIO_PORT)==_PB
#define SHIFT_2_DATA_I_O 0x16
#elif APPEND_2_1(_P,SHIFT_2_DATA_GPIO_PORT)==_PC
#define SHIFT_2_DATA_I_O 0x13
#elif APPEND_2_1(_P,SHIFT_2_DATA_GPIO_PORT)==_PD
#define SHIFT_2_DATA_I_O 0x10
#endif

#endif

/******************************************************************************************************/

#if APPEND_2_1(_P,SHIFT_2_CLOCK_GPIO_PORT)==_PA
#define SHIFT_2_CLOCK_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_2_CLOCK_GPIO_PORT)==_PB
#define SHIFT_2_CLOCK_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_2_CLOCK_GPIO_PORT)==_PC
#define SHIFT_2_CLOCK_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_2_CLOCK_GPIO_PORT)==_PD
#define SHIFT_2_CLOCK_I_O 0x12
#endif

/******************************************************************************************************/

#if (SHIFT_2_LATCH_ENABLE)==YES

#if APPEND_2_1(_P,SHIFT_2_LATCH_GPIO_PORT)==_PA
#define SHIFT_2_LATCH_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_2_LATCH_GPIO_PORT)==_PB
#define SHIFT_2_LATCH_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_2_LATCH_GPIO_PORT)==_PC
#define SHIFT_2_LATCH_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_2_LATCH_GPIO_PORT)==_PD
#define SHIFT_2_LATCH_I_O 0x12
#endif

#endif

/******************************************************************************************************/
//Identifying macros
/******************************************************************************************************/

#define SHIFT_2_DATA APPEND_3_1(_P,SHIFT_2_DATA_GPIO_PORT,SHIFT_2_DATA_GPIO_PIN)
#define SHIFT_2_CLOCK APPEND_3_1(_P,SHIFT_2_CLOCK_GPIO_PORT,SHIFT_2_CLOCK_GPIO_PIN)

#if (SHIFT_2_LATCH_ENABLE)
#define SHIFT_2_LATCH APPEND_3_1(_P,SHIFT_2_LATCH_GPIO_PORT,SHIFT_2_LATCH_GPIO_PIN)
#endif

/******************************************************************************************************/
//Error check
/******************************************************************************************************/

#if SHIFT_2_DATA==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)
#if SHIFT_2_DATA==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#if SHIFT_2_CLOCK==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
//Module 3
/******************************************************************************************************/

#if (SHIFT_3_USE) == YES

/******************************************************************************************************/
//Input/Output Select
/******************************************************************************************************/

#if defined(SHIFT_3_USE_AS_OUTPUT)
#undef SHIFT_3_USE_AS_OUTPUT
#define SHIFT_3_USE_AS_OUTPUT YES
#elif defined(SHIFT_3_USE_AS_INPUT)
#define SHIFT_3_USE_AS_OUTPUT NO
#elif !defined(SHIFT_3_USE_AS_OUTPUT)
#define SHIFT_3_USE_AS_OUTPUT YES
#endif

/******************************************************************************************************/
//Default GPIO port name macro
/******************************************************************************************************/

#if !defined(SHIFT_3_GPIO_PORT)
#define SHIFT_3_GPIO_PORT C
#endif

/******************************************************************************************************/
//Data pin settings
/******************************************************************************************************/

#if !defined(SHIFT_3_DATA_GPIO_PIN)
#define SHIFT_3_DATA_GPIO_PIN 0
#endif

#if !defined(SHIFT_3_DATA_GPIO_PORT)
#define SHIFT_3_DATA_GPIO_PORT SHIFT_3_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_3_DATA)
#define SHIFT_DDR_3_DATA DDR(SHIFT_3_DATA_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_3_DATA)
#define SHIFT_PORT_3_DATA PORT(SHIFT_3_DATA_GPIO_PORT)
#endif

#if !defined(SHIFT_PIN_3_DATA)
#define SHIFT_PIN_3_DATA PIN(SHIFT_3_DATA_GPIO_PORT)
#endif

/******************************************************************************************************/
//Additional Data macros
/******************************************************************************************************/

#if defined(SHIFT_3_DATA_PIN_PULL_UP_ENABLE)
#undef SHIFT_3_DATA_PIN_PULL_UP_ENABLE
#define SHIFT_3_DATA_PIN_PULL_UP_ENABLE YES
#else
#define SHIFT_3_DATA_PIN_PULL_UP_ENABLE NO
#endif

/******************************************************************************************************/
//Clock pin settings
/******************************************************************************************************/

#if !defined(SHIFT_3_CLOCK_GPIO_PIN)
#define SHIFT_3_CLOCK_GPIO_PIN 1
#endif

#if !defined(SHIFT_3_CLOCK_GPIO_PORT)
#define SHIFT_3_CLOCK_GPIO_PORT SHIFT_3_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_CLOCK_3)
#define SHIFT_DDR_3_CLOCK DDR(SHIFT_3_CLOCK_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_3_CLOCK)
#define SHIFT_PORT_3_CLOCK PORT(SHIFT_3_CLOCK_GPIO_PORT)
#endif

/******************************************************************************************************/
//Latch Pin settings
/******************************************************************************************************/

#if !defined(SHIFT_3_LATCH_ENABLE)
#define SHIFT_3_LATCH_ENABLE NO
#else
#undef SHIFT_3_LATCH_ENABLE
#define SHIFT_3_LATCH_ENABLE YES
#endif

/******************************************************************************************************/

#if (SHIFT_3_LATCH_ENABLE)== YES

#if !defined(SHIFT_3_LATCH_GPIO_PIN)
#define SHIFT_3_LATCH_GPIO_PIN 2
#endif

#if !defined(SHIFT_LATCH_3_GPIO_PORT)
#define SHIFT_3_LATCH_GPIO_PORT SHIFT_3_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_3_LATCH)
#define SHIFT_DDR_3_LATCH DDR(SHIFT_3_LATCH_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_3_LATCH)
#define SHIFT_PORT_3_LATCH PORT(SHIFT_3_LATCH_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Array macros
/******************************************************************************************************/

#if (SHIFT_3_USE_AS_OUTPUT)==YES

#if APPEND_2_1(_P,SHIFT_3_DATA_GPIO_PORT)==_PA
#define SHIFT_3_DATA_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_3_DATA_GPIO_PORT)==_PB
#define SHIFT_3_DATA_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_3_DATA_GPIO_PORT)==_PC
#define SHIFT_3_DATA_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_3_DATA_GPIO_PORT)==_PD
#define SHIFT_3_DATA_I_O 0x12
#endif

#else

#if APPEND_2_1(_P,SHIFT_3_DATA_GPIO_PORT)==_PA
#define SHIFT_3_DATA_I_O 0x19
#elif APPEND_2_1(_P,SHIFT_3_DATA_GPIO_PORT)==_PB
#define SHIFT_3_DATA_I_O 0x16
#elif APPEND_2_1(_P,SHIFT_3_DATA_GPIO_PORT)==_PC
#define SHIFT_3_DATA_I_O 0x13
#elif APPEND_2_1(_P,SHIFT_3_DATA_GPIO_PORT)==_PD
#define SHIFT_3_DATA_I_O 0x10
#endif

#endif

/******************************************************************************************************/

#if APPEND_2_1(_P,SHIFT_3_CLOCK_GPIO_PORT)==_PA
#define SHIFT_3_CLOCK_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_3_CLOCK_GPIO_PORT)==_PB
#define SHIFT_3_CLOCK_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_3_CLOCK_GPIO_PORT)==_PC
#define SHIFT_3_CLOCK_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_3_CLOCK_GPIO_PORT)==_PD
#define SHIFT_3_CLOCK_I_O 0x12
#endif

/******************************************************************************************************/

#if (SHIFT_3_LATCH_ENABLE)==YES

#if APPEND_2_1(_P,SHIFT_3_LATCH_GPIO_PORT)==_PA
#define SHIFT_3_LATCH_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_3_LATCH_GPIO_PORT)==_PB
#define SHIFT_3_LATCH_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_3_LATCH_GPIO_PORT)==_PC
#define SHIFT_3_LATCH_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_3_LATCH_GPIO_PORT)==_PD
#define SHIFT_3_LATCH_I_O 0x12
#endif

#endif

/******************************************************************************************************/
//Identifying macros
/******************************************************************************************************/

#define SHIFT_3_DATA APPEND_3_1(_P,SHIFT_3_DATA_GPIO_PORT,SHIFT_3_DATA_GPIO_PIN)
#define SHIFT_3_CLOCK APPEND_3_1(_P,SHIFT_3_CLOCK_GPIO_PORT,SHIFT_3_CLOCK_GPIO_PIN)

#if (SHIFT_3_LATCH_ENABLE)
#define SHIFT_3_LATCH APPEND_3_1(_P,SHIFT_3_LATCH_GPIO_PORT,SHIFT_3_LATCH_GPIO_PIN)
#endif

/******************************************************************************************************/
//Error check
/******************************************************************************************************/

#if SHIFT_3_DATA==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)
#if SHIFT_3_DATA==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#if SHIFT_3_CLOCK==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
//Module 4
/******************************************************************************************************/

#if (SHIFT_4_USE) == YES

/******************************************************************************************************/
//Input/Output Select
/******************************************************************************************************/

#if defined(SHIFT_4_USE_AS_OUTPUT)
#undef SHIFT_4_USE_AS_OUTPUT
#define SHIFT_4_USE_AS_OUTPUT YES
#elif defined(SHIFT_4_USE_AS_INPUT)
#define SHIFT_4_USE_AS_OUTPUT NO
#elif !defined(SHIFT_4_USE_AS_OUTPUT)
#define SHIFT_4_USE_AS_OUTPUT YES
#endif

/******************************************************************************************************/
//Default GPIO port name macro
/******************************************************************************************************/

#if !defined(SHIFT_4_GPIO_PORT)
#define SHIFT_4_GPIO_PORT C
#endif

/******************************************************************************************************/
//Data pin settings
/******************************************************************************************************/

#if !defined(SHIFT_4_DATA_GPIO_PIN)
#define SHIFT_4_DATA_GPIO_PIN 3
#endif

#if !defined(SHIFT_4_DATA_GPIO_PORT)
#define SHIFT_4_DATA_GPIO_PORT SHIFT_4_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_4_DATA)
#define SHIFT_DDR_4_DATA DDR(SHIFT_4_DATA_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_4_DATA)
#define SHIFT_PORT_4_DATA PORT(SHIFT_4_DATA_GPIO_PORT)
#endif

#if !defined(SHIFT_PIN_4_DATA)
#define SHIFT_PIN_4_DATA PIN(SHIFT_4_DATA_GPIO_PORT)
#endif

/******************************************************************************************************/
//Additional Data macros
/******************************************************************************************************/

#if defined(SHIFT_4_DATA_PIN_PULL_UP_ENABLE)
#undef SHIFT_4_DATA_PIN_PULL_UP_ENABLE
#define SHIFT_4_DATA_PIN_PULL_UP_ENABLE YES
#else
#define SHIFT_4_DATA_PIN_PULL_UP_ENABLE NO
#endif

/******************************************************************************************************/
//Clock pin settings
/******************************************************************************************************/

#if !defined(SHIFT_4_CLOCK_GPIO_PIN)
#define SHIFT_4_CLOCK_GPIO_PIN 4
#endif

#if !defined(SHIFT_4_CLOCK_GPIO_PORT)
#define SHIFT_4_CLOCK_GPIO_PORT SHIFT_4_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_CLOCK_4)
#define SHIFT_DDR_4_CLOCK DDR(SHIFT_4_CLOCK_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_4_CLOCK)
#define SHIFT_PORT_4_CLOCK PORT(SHIFT_4_CLOCK_GPIO_PORT)
#endif

/******************************************************************************************************/
//Latch Pin settings
/******************************************************************************************************/

#if !defined(SHIFT_4_LATCH_ENABLE)
#define SHIFT_4_LATCH_ENABLE NO
#else
#undef SHIFT_4_LATCH_ENABLE
#define SHIFT_4_LATCH_ENABLE YES
#endif

/******************************************************************************************************/

#if (SHIFT_4_LATCH_ENABLE)== YES

#if !defined(SHIFT_4_LATCH_GPIO_PIN)
#define SHIFT_4_LATCH_GPIO_PIN 5
#endif

#if !defined(SHIFT_LATCH_4_GPIO_PORT)
#define SHIFT_4_LATCH_GPIO_PORT SHIFT_4_GPIO_PORT
#endif

#if !defined(SHIFT_DDR_4_LATCH)
#define SHIFT_DDR_4_LATCH DDR(SHIFT_4_LATCH_GPIO_PORT)
#endif

#if !defined(SHIFT_PORT_4_LATCH)
#define SHIFT_PORT_4_LATCH PORT(SHIFT_4_LATCH_GPIO_PORT)
#endif

#endif

/******************************************************************************************************/
//Array macros
/******************************************************************************************************/

#if (SHIFT_4_USE_AS_OUTPUT)==YES

#if APPEND_2_1(_P,SHIFT_4_DATA_GPIO_PORT)==_PA
#define SHIFT_4_DATA_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_4_DATA_GPIO_PORT)==_PB
#define SHIFT_4_DATA_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_4_DATA_GPIO_PORT)==_PC
#define SHIFT_4_DATA_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_4_DATA_GPIO_PORT)==_PD
#define SHIFT_4_DATA_I_O 0x12
#endif

#else

#if APPEND_2_1(_P,SHIFT_4_DATA_GPIO_PORT)==_PA
#define SHIFT_4_DATA_I_O 0x19
#elif APPEND_2_1(_P,SHIFT_4_DATA_GPIO_PORT)==_PB
#define SHIFT_4_DATA_I_O 0x16
#elif APPEND_2_1(_P,SHIFT_4_DATA_GPIO_PORT)==_PC
#define SHIFT_4_DATA_I_O 0x13
#elif APPEND_2_1(_P,SHIFT_4_DATA_GPIO_PORT)==_PD
#define SHIFT_4_DATA_I_O 0x10
#endif

#endif

/******************************************************************************************************/

#if APPEND_2_1(_P,SHIFT_4_CLOCK_GPIO_PORT)==_PA
#define SHIFT_4_CLOCK_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_4_CLOCK_GPIO_PORT)==_PB
#define SHIFT_4_CLOCK_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_4_CLOCK_GPIO_PORT)==_PC
#define SHIFT_4_CLOCK_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_4_CLOCK_GPIO_PORT)==_PD
#define SHIFT_4_CLOCK_I_O 0x12
#endif

/******************************************************************************************************/

#if (SHIFT_4_LATCH_ENABLE)==YES

#if APPEND_2_1(_P,SHIFT_4_LATCH_GPIO_PORT)==_PA
#define SHIFT_4_LATCH_I_O 0x1B
#elif APPEND_2_1(_P,SHIFT_4_LATCH_GPIO_PORT)==_PB
#define SHIFT_4_LATCH_I_O 0x18
#elif APPEND_2_1(_P,SHIFT_4_LATCH_GPIO_PORT)==_PC
#define SHIFT_4_LATCH_I_O 0x15
#elif APPEND_2_1(_P,SHIFT_4_LATCH_GPIO_PORT)==_PD
#define SHIFT_4_LATCH_I_O 0x12
#endif

#endif

/******************************************************************************************************/
//Identifying macros
/******************************************************************************************************/

#define SHIFT_4_DATA APPEND_3_1(_P,SHIFT_4_DATA_GPIO_PORT,SHIFT_4_DATA_GPIO_PIN)
#define SHIFT_4_CLOCK APPEND_3_1(_P,SHIFT_4_CLOCK_GPIO_PORT,SHIFT_4_CLOCK_GPIO_PIN)

#if (SHIFT_4_LATCH_ENABLE)
#define SHIFT_4_LATCH APPEND_3_1(_P,SHIFT_4_LATCH_GPIO_PORT,SHIFT_4_LATCH_GPIO_PIN)
#endif

/******************************************************************************************************/
//Error check
/******************************************************************************************************/

#if SHIFT_4_DATA==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)
#if SHIFT_4_DATA==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#if SHIFT_4_CLOCK==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
//Inter Module Error check
/******************************************************************************************************/

#if ((SHIFT_1_USE) == YES)

/******************************************************************************************************/

#if ((SHIFT_2_USE) == YES)

#if SHIFT_1_DATA==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_DATA==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_1_DATA==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_1_CLOCK==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_CLOCK==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_1_CLOCK==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_1_LATCH==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_LATCH==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_1_LATCH==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_3_USE) == YES)

#if SHIFT_1_DATA==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_DATA==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_1_DATA==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_1_CLOCK==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_CLOCK==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_1_CLOCK==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_1_LATCH==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_LATCH==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_1_LATCH==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_4_USE) == YES)

#if SHIFT_1_DATA==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_DATA==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_1_DATA==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_1_CLOCK==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_CLOCK==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_1_CLOCK==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_1_LATCH==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_1_LATCH==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_1_LATCH==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_2_USE) == YES)

/******************************************************************************************************/

#if ((SHIFT_1_USE) == YES)

/******************************************************************************************************/

#if SHIFT_2_DATA==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_DATA==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_2_DATA==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_2_CLOCK==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_CLOCK==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_2_CLOCK==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_2_LATCH==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_LATCH==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_2_LATCH==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_3_USE) == YES)

#if SHIFT_2_DATA==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_DATA==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_2_DATA==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_2_CLOCK==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_CLOCK==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_2_CLOCK==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_2_LATCH==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_LATCH==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_2_LATCH==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_4_USE) == YES)

#if SHIFT_2_DATA==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_DATA==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_2_DATA==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_2_CLOCK==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_CLOCK==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_2_CLOCK==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_2_LATCH==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_2_LATCH==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_2_LATCH==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_3_USE) == YES)

/******************************************************************************************************/

#if ((SHIFT_1_USE) == YES)

/******************************************************************************************************/

#if SHIFT_3_DATA==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_DATA==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_3_DATA==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_3_CLOCK==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_CLOCK==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_3_CLOCK==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_3_LATCH==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_LATCH==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_3_LATCH==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_2_USE) == YES)

/******************************************************************************************************/

#if SHIFT_3_DATA==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_DATA==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_3_DATA==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_3_CLOCK==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_CLOCK==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_3_CLOCK==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_3_LATCH==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_LATCH==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_3_LATCH==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_4_USE) == YES)

/******************************************************************************************************/

#if SHIFT_3_DATA==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_DATA==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_3_DATA==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_3_CLOCK==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_CLOCK==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_3_CLOCK==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_3_LATCH==SHIFT_4_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_3_LATCH==SHIFT_4_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_3_LATCH==SHIFT_4_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_4_USE) == YES)

/******************************************************************************************************/

#if ((SHIFT_1_USE) == YES)

/******************************************************************************************************/

#if SHIFT_4_DATA==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_DATA==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_4_DATA==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_4_CLOCK==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_CLOCK==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_4_CLOCK==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_4_LATCH==SHIFT_1_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_LATCH==SHIFT_1_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_1_LATCH_ENABLE)

#if SHIFT_4_LATCH==SHIFT_1_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_2_USE) == YES)

/******************************************************************************************************/

#if SHIFT_4_DATA==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_DATA==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_4_DATA==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_4_CLOCK==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_CLOCK==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_4_CLOCK==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_4_LATCH==SHIFT_2_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_LATCH==SHIFT_2_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_2_LATCH_ENABLE)

#if SHIFT_4_LATCH==SHIFT_2_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if ((SHIFT_3_USE) == YES)

/******************************************************************************************************/

#if SHIFT_4_DATA==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_DATA==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_4_DATA==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if SHIFT_4_CLOCK==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_CLOCK==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_4_CLOCK==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

/******************************************************************************************************/

#if (SHIFT_4_LATCH_ENABLE)

#if SHIFT_4_LATCH==SHIFT_3_DATA
#error "Two pins have the same function"
#endif

#if SHIFT_4_LATCH==SHIFT_3_CLOCK
#error "Two pins have the same function"
#endif

#if (SHIFT_3_LATCH_ENABLE)

#if SHIFT_4_LATCH==SHIFT_3_LATCH
#error "Two pins have the same function"
#endif

#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
//Misc Macros
/******************************************************************************************************/

#if !defined(SHIFT_CLOCK_DELAY)
#define SHIFT_CLOCK_DELAY 0
#endif

/******************************************************************************************************/

#if !defined(SHIFT_LATCH_DELAY)
#define SHIFT_LATCH_DELAY 0
#endif

/******************************************************************************************************/
//USE macros
/******************************************************************************************************/

#if !defined(USE_shift_init)
#define USE_shift_init YES
#endif

/******************************************************************************************************/

#if !defined(USE_shift_clock)
#define USE_shift_clock YES
#endif

/******************************************************************************************************/

#if (SHIFT_1_USE) == YES

#if (SHIFT_1_LATCH_ENABLE)==YES

#if !defined(USE_shift_latch_data)
#define USE_shift_latch_data YES
#endif

#endif

#endif

#if (SHIFT_2_USE) == YES

#if (SHIFT_2_LATCH_ENABLE)==YES

#if !defined(USE_shift_latch_data)
#define USE_shift_latch_data YES
#endif

#endif

#endif

#if (SHIFT_3_USE) == YES

#if (SHIFT_3_LATCH_ENABLE)==YES

#if !defined(USE_shift_latch_data)
#define USE_shift_latch_data YES
#endif

#endif

#endif

#if (SHIFT_4_USE) == YES

#if (SHIFT_4_LATCH_ENABLE)==YES

#if !defined(USE_shift_latch_data)
#define USE_shift_latch_data YES
#endif

#endif

#endif

#if !defined(USE_shift_latch_data)
#define USE_shift_latch_data NO
#endif

/******************************************************************************************************/

#if (SHIFT_1_USE) == YES

#if (SHIFT_1_USE_AS_OUTPUT)==YES

#if !defined(USE_shift_data_out_bit)
#define USE_shift_data_out_bit YES
#endif

#endif

#endif

#if (SHIFT_2_USE) == YES

#if (SHIFT_2_USE_AS_OUTPUT)==YES

#if !defined(USE_shift_data_out_bit)
#define USE_shift_data_out_bit YES
#endif

#endif

#endif

#if (SHIFT_3_USE) == YES

#if (SHIFT_3_USE_AS_OUTPUT)==YES

#if !defined(USE_shift_data_out_bit)
#define USE_shift_data_out_bit YES
#endif

#endif

#endif

#if (SHIFT_4_USE) == YES

#if (SHIFT_4_USE_AS_OUTPUT)==YES

#if !defined(USE_shift_data_out_bit)
#define USE_shift_data_out_bit YES
#endif

#endif

#endif

#if !defined(USE_shift_data_out_bit)
#define USE_shift_data_out_bit NO
#endif

/******************************************************************************************************/

#if !defined(USE_shift_data_out_byte)
#define USE_shift_data_out_byte USE_shift_data_out_bit
#endif

/******************************************************************************************************/

#if !defined(USE_shift_data_in_bit)
#define USE_shift_data_in_bit !(USE_shift_data_out_bit)
#endif

/******************************************************************************************************/

#if !defined(USE_shift_data_in_byte)
#define USE_shift_data_in_byte USE_shift_data_in_bit
#endif

/******************************************************************************************************/
//Functin Prototypes
/******************************************************************************************************/

#if (USE_shift_init)
void shift_init(void);
#endif

#if (USE_shift_clock)
void shift_clock(unsigned char*);
#endif

#if (USE_shift_latch_data)
void shift_latch_data(unsigned char*);
#endif

#if (USE_shift_data_out_bit)
void shift_data_out_bit(unsigned char,unsigned char*);
#endif

#if (USE_shift_data_out_byte)
void shift_data_out_byte(unsigned char,unsigned char*);
#endif

#if (USE_shift_data_in_bit)
unsigned char shift_data_in_bit(unsigned char*);
#endif

#if (USE_shift_data_in_byte)
unsigned char shift_data_in_byte(unsigned char*);
#endif

/******************************************************************************************************/
//Global Variables
/******************************************************************************************************/

#if (SHIFT_1_USE) == YES

const unsigned char SHIFT_1[] PROGMEM =
{
    SHIFT_1_DATA_I_O,
    SHIFT_1_DATA_GPIO_PIN,
    SHIFT_1_CLOCK_I_O,
    SHIFT_1_CLOCK_GPIO_PIN

    #if (SHIFT_1_LATCH_ENABLE)==YES
    ,SHIFT_1_LATCH_I_O,
    SHIFT_1_LATCH_GPIO_PIN
    #endif
};

#endif

/******************************************************************************************************/

#if (SHIFT_2_USE) == YES

const unsigned char SHIFT_2[] PROGMEM =
{
    SHIFT_2_DATA_I_O,
    SHIFT_2_DATA_GPIO_PIN,
    SHIFT_2_CLOCK_I_O,
    SHIFT_2_CLOCK_GPIO_PIN

    #if (SHIFT_2_LATCH_ENABLE)==YES
    ,SHIFT_2_LATCH_I_O,
    SHIFT_2_LATCH_GPIO_PIN
    #endif
};

#endif

/******************************************************************************************************/

#if (SHIFT_3_USE) == YES

const unsigned char SHIFT_3[] PROGMEM=
{
    SHIFT_3_DATA_I_O,
    SHIFT_3_DATA_GPIO_PIN,
    SHIFT_3_CLOCK_I_O,
    SHIFT_3_CLOCK_GPIO_PIN

    #if (SHIFT_3_LATCH_ENABLE)==YES
    ,SHIFT_3_LATCH_I_O,
    SHIFT_3_LATCH_GPIO_PIN
    #endif
};

#endif

/******************************************************************************************************/

#if (SHIFT_4_USE) == YES

const unsigned char SHIFT_4[] PROGMEM=
{
    SHIFT_4_DATA_I_O,
    SHIFT_4_DATA_GPIO_PIN,
    SHIFT_4_CLOCK_I_O,
    SHIFT_4_CLOCK_GPIO_PIN

    #if (SHIFT_4_LATCH_ENABLE)==YES
    ,SHIFT_4_LATCH_I_O,
    SHIFT_4_LATCH_GPIO_PIN
    #endif
};

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
