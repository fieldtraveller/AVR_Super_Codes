/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

kb.h

ps/2 Male Connector Pin-out:
1=Data
2=NC
3=GND
4=Vcc
5=CLK
6=NC

Default Settings:
Buffer size:8
Data pin:PD3
Clock pin:PD2/INT0

DESCRIPTION:PS/2 Keyboard interfacing with Atmel ATmega 32/16/8.

    kb_init():Initializes the Pins.
    kb_cmd():Used to send commands to keyboard.
    kb_decode():Identifies the various kinds of scan codes.
    kb_scan2ascii():Decodes scan code to ascii codes.
    kb_putdata():Insert data in a queue.
    kb_getdata():Delete/use data from the queue.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef KB_H_
#define KB_H_

/******************************************************************************************************/

#include <avr/interrupt.h>
#include "cf.h"

/******************************************************************************************************/
//Defaults Buffer(circular queue) size
/******************************************************************************************************/

#if !defined(KB_BUFFER_SIZE)
#define KB_BUFFER_SIZE 8
#endif

/******************************************************************************************************/
//Default GPIO port name macro
/******************************************************************************************************/

#if !defined(KB_GPIO_PORT)
#define KB_GPIO_PORT D
#endif

/******************************************************************************************************/
//Default GPIO pin number macros
/******************************************************************************************************/

#if !defined(KB_CLOCK_GPIO_PIN)
#define KB_CLOCK_GPIO_PIN 2
#endif

#if !defined(KB_DATA_GPIO_PIN)
#define KB_DATA_GPIO_PIN 3
#endif

/******************************************************************************************************/
//GPIO port name macros
/******************************************************************************************************/

#if !defined (KB_CLOCK_GPIO_PORT)
#define KB_CLOCK_GPIO_PORT KB_GPIO_PORT
#endif

#if !defined (KB_DATA_GPIO_PORT)
#define KB_DATA_GPIO_PORT KB_GPIO_PORT
#endif

/******************************************************************************************************/
//Identifying macros
/******************************************************************************************************/

#define KB_CLOCK APPEND_3_1(_P,KB_CLOCK_GPIO_PORT,KB_CLOCK_GPIO_PIN)
#define KB_DATA APPEND_3_1(_P,KB_DATA_GPIO_PORT,KB_DATA_GPIO_PIN)

/******************************************************************************************************/
//Misc macros
/******************************************************************************************************/

#define KB_DATA_MASK (1<<KB_DATA_GPIO_PIN)
#define KB_ACKNOWLEDGEMENT_BYTE_IS_SENT YES

/******************************************************************************************************/

#if defined(KB_USE_WINDOWS_MULTIMEDIA_KEYS)
#undef KB_USE_WINDOWS_MULTIMEDIA_KEYS
#define KB_USE_WINDOWS_MULTIMEDIA_KEYS YES
#else
#define KB_USE_WINDOWS_MULTIMEDIA_KEYS NO
#endif

/******************************************************************************************************/

#if defined(KB_USE_ACPI_KEYS)
#undef KB_USE_ACPI_KEYS
#define KB_USE_ACPI_KEYS YES
#else
#define KB_USE_ACPI_KEYS NO
#endif

/******************************************************************************************************/

#if defined(KB_USE_CONTROL_COMBINATIONS)
#undef KB_USE_CONTROL_COMBINATIONS
#define KB_USE_CONTROL_COMBINATIONS YES
#else
#define KB_USE_CONTROL_COMBINATIONS NO
#endif

/******************************************************************************************************/

#if defined(KB_USE_ALTERNATE_COMBINATIONS)
#undef KB_USE_ALTERNATE_COMBINATIONS
#define KB_USE_ALTERNATE_COMBINATIONS YES
#else
#define KB_USE_ALTERNATE_COMBINATIONS NO
#endif

/******************************************************************************************************/

#if ((!(KB_USE_CONTROL_COMBINATIONS))&&(KB_USE_ALTERNATE_COMBINATIONS))
#define KB_ALTERNATE_OFFSET 3
#elif ((KB_USE_CONTROL_COMBINATIONS)&&(KB_USE_ALTERNATE_COMBINATIONS))
#define KB_ALTERNATE_OFFSET 4
#endif

/******************************************************************************************************/

#if !defined(KB_USE_WDT)
#define KB_USE_WDT NO
#else
#undef KB_USE_WDT
#define KB_USE_WDT YES
#endif

/******************************************************************************************************/
//Error check
/******************************************************************************************************/

#if KB_CLOCK==KB_DATA
#error "Data pin and clock pin are same"
#endif

#if !((KB_CLOCK==_PD2)||(KB_CLOCK==_PD3)||(KB_CLOCK==_PB2))
#error "Clock pin has to be an external interrupt pin"
#endif

/******************************************************************************************************/
//Data and Clock line GPIO registers macros
/******************************************************************************************************/

#if !defined (KB_PORT_CLOCK)
#define KB_PORT_CLOCK PORT(KB_CLOCK_GPIO_PORT)
#endif

#if !defined (KB_PIN_CLOCK)
#define KB_PIN_CLOCK PIN(KB_CLOCK_GPIO_PORT)
#endif

#if !defined (KB_DDR_CLOCK)
#define KB_DDR_CLOCK DDR(KB_CLOCK_GPIO_PORT)
#endif

#if !defined (KB_PORT_DATA)
#define KB_PORT_DATA PORT(KB_DATA_GPIO_PORT)
#endif

#if !defined (KB_PIN_DATA)
#define KB_PIN_DATA PIN(KB_DATA_GPIO_PORT)
#endif

#if !defined (KB_DDR_DATA)
#define KB_DDR_DATA DDR(KB_DATA_GPIO_PORT)
#endif

/******************************************************************************************************/
/*
Interrupt Settings
External Interrupt pin is used as the clock pin of the interface.
External Interrupt pin can be any one of the following.
PD2/INT0
PD3/INT1
PB2/INT2
*/
/******************************************************************************************************/

#if KB_CLOCK==_PD2

    #define KB_INTERRUPT_TYPE 0

    #define KB_ISR_ENABLE GICR =(GICR & ~(0x40))|(0x40);

    #define KB_ISR_VECTOR INT0_vect

    #define KB_ISR_RISING MCUCR = (MCUCR & ~(0x03))|(0x03);

    #define KB_ISR_FALLING MCUCR = (MCUCR & ~(0x03))|(0x02);

#elif KB_CLOCK==_PD3

    #define KB_INTERRUPT_TYPE 1

    #define KB_ISR_ENABLE GICR =(GICR  & ~(0x80))|(0x80);

    #define KB_ISR_VECTOR INT1_vect

    #define KB_ISR_RISING MCUCR = (MCUCR & ~(0x0C))|(0x0C);

    #define KB_ISR_FALLING MCUCR = (MCUCR & ~(0x0C))|(0x08);

#elif KB_CLOCK==_PB2

    #define KB_INTERRUPT_TYPE 2

    #define KB_ISR_ENABLE GICR =(GICR & ~(0x20))|(0x20);

    #define KB_ISR_VECTOR INT2_vect

    #define KB_ISR_RISING MCUCSR = (MCUCSR & ~(0x40))|(0x40);

    #define KB_ISR_FALLING MCUCSR = (MCUCSR & ~(0x40))|(0x00);

#endif

/******************************************************************************************************/
//kb_flags_RX byte setting
/******************************************************************************************************/

#define KB_CAPS_LOCK_FLAG 1
#define KB_SHIFT_FLAG 2
#define KB_CTRL_FLAG 4
#define KB_ALT_FLAG 8
#define KB_EDGE_FLAG 16
#define KB_BREAK_CODE_FLAG 32
#define KB_EXTENDED_FLAG 64
#define KB_BAT_CHECK_FLAG 128

#define KB_RISE_FLAG KB_EDGE_FLAG
#define KB_FALL_FLAG 0

#define KB_ACKNOWLEDGEMENT_BYTE_CHECK_FLAG KB_BAT_CHECK_FLAG

/******************************************************************************************************/
//kb_flags_TX Byte settings
/******************************************************************************************************/

#define KB_MODE_FLAG 1 //1=TX,0=RX
#define KB_PARITY_FLAG 2
#define KB_ACKNOWLEDGEMENT_BIT_FLAG 4
#define KB_PREVIOUS_FLAG_WAS_EXTENDED 8
#define KB_LEFT_CONTROL 16
#define KB_LEFT_ALTERNATE 32

#define KB_TX_MODE_FLAG KB_MODE_FLAG
#define KB_RX_MODE_FLAG 0

/******************************************************************************************************/
//Function USE macros
/******************************************************************************************************/

#if !defined(USE_kb_init)
#define USE_kb_init YES
#endif

#if !defined(USE_kb_decode)
#define USE_kb_decode YES
#endif

#if !defined(USE_kb_scan2ascii)
#define USE_kb_scan2ascii YES
#endif

#if !defined(USE_kb_putdata)
#define USE_kb_putdata YES
#endif

#if !defined(USE_kb_getdata)
#define USE_kb_getdata YES
#endif

#if !defined(USE_kb_cmd)
#define USE_kb_cmd YES
#endif

/******************************************************************************************************/
//Function Prototypes
/******************************************************************************************************/

#if (USE_kb_init)==YES
void kb_init(void);
#endif

#if (USE_kb_cmd)==YES
void kb_cmd(unsigned char);
#endif

#if (USE_kb_decode)==YES
void kb_decode(void);
#endif

#if (USE_kb_scan2ascii)==YES
void kb_scan2ascii(void);
#endif

#if (USE_kb_putdata)==YES
void kb_putdata(unsigned char);
#endif

#if (USE_kb_getdata)==YES
unsigned char kb_getdata(void);
#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
