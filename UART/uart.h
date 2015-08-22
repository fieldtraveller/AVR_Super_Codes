/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

uart.h

DESCRIPTION:THIS HEADER FILE IS INTENDED TO BE USED WHEN USING UART WITH AVR.

DEFAULTS:
ASYNCHRONOUS
8 BIT DATA
NO PARITY
1 STOP BIT
9600 BAUD
NORMAL SPEED(NO 2X SPEED)

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef UART_H_
#define UART_H_

/******************************************************************************************************/

#include <avr/interrupt.h>

/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include "cf.h"

/******************************************************************************************************/
//TIME PASS
/******************************************************************************************************/

#ifndef ALEX
#warning "You're not my master."
#endif

/******************************************************************************************************/
//CONFIGURATION MACROS
/******************************************************************************************************/

#ifndef UART_USE_IN_ASYNC   //USE IN ASYNCHRONOUS MODE
#define UART_USE_IN_ASYNC YES
#endif

#ifdef UART_USE_IN_SYNC   //USE IN SYNCHRONOUS MODE
#define UART_USE_IN_ASYNC NO
#endif

/******************************************************************************************************/

#ifndef UART_NUMBER_OF_DATA_BITS
#define UART_NUMBER_OF_DATA_BITS 8
#endif

/******************************************************************************************************/

#ifndef UART_ENABLE_PARITY
#define UART_ENABLE_PARITY NO
#endif

#ifdef UART_DISABLE_PARITY
#undef UART_ENABLE_PARITY
#define UART_ENABLE_PARITY NO
#endif

#if (UART_ENABLE_PARITY == YES)

#ifndef UART_USE_EVEN_PARITY
#define UART_USE_EVEN_PARITY YES
#endif

#ifdef UART_USE_ODD_PARITY
#undef UART_USE_EVEN_PARITY
#define UART_USE_EVEN_PARITY NO
#endif

#endif

/******************************************************************************************************/

#ifndef UART_NUMBER_OF_STOP_BITS
#define UART_NUMBER_OF_STOP_BITS 1
#endif

/******************************************************************************************************/

#if (UART_USE_IN_ASYNC == YES)
#define UART_USE_IN_ASYNC_MASK 0
#elif (UART_USE_IN_ASYNC == NO)
#define UART_USE_IN_ASYNC_MASK (1<<UMSEL)
#endif

/******************************************************************************************************/

#if (UART_NUMBER_OF_DATA_BITS == 5)
#define UART_DATA_BIT_MASK 0
#elif (UART_NUMBER_OF_DATA_BITS == 6)
#define UART_DATA_BIT_MASK (1<<UCSZ0)
#elif (UART_NUMBER_OF_DATA_BITS == 7)
#define UART_DATA_BIT_MASK (1<<UCSZ1)
#elif (UART_NUMBER_OF_DATA_BITS == 8)
#define UART_DATA_BIT_MASK ((1<<UCSZ1)|(1<<UCSZ0))
#elif (UART_NUMBER_OF_DATA_BITS == 9)
#define UART_DATA_BIT_MASK ((1<<UCSZ1)|(1<<UCSZ0))
#else
#error "This is an error because I said so."
#endif

/******************************************************************************************************/

#if (UART_ENABLE_PARITY == NO)
#define UART_PARITY_BIT_MASK 0
#elif (UART_ENABLE_PARITY == YES)

#if (UART_USE_EVEN_PARITY == YES)
#define UART_PARITY_BIT_MASK (1<<UPM1)
#elif (UART_USE_EVEN_PARITY == NO)
#define UART_PARITY_BIT_MASK ((1<<UPM1)|(1<<UPM0))
#endif

#endif

/******************************************************************************************************/

#if (UART_NUMBER_OF_STOP_BITS == 1)
#define UART_STOP_BIT_MASK 0
#elif (UART_NUMBER_OF_STOP_BITS == 2)
#define UART_STOP_BIT_MASK (1<<USBS)
#else
#error "You're out of your mind!"
#endif

/******************************************************************************************************/

#define UART_UCSRC_MASK ((1<<URSEL) | UART_USE_IN_ASYNC_MASK | UART_DATA_BIT_MASK | UART_PARITY_BIT_MASK | UART_STOP_BIT_MASK)

/******************************************************************************************************/

#ifndef UART_TX_ENABLED
#ifndef UART_TX_DISABLED
#define UART_TX_ENABLED YES
#else
#define UART_TX_ENABLED NO
#endif
#endif

#ifndef UART_RX_ENABLED
#ifndef UART_RX_DISABLED
#define UART_RX_ENABLED YES
#else
#define UART_RX_ENABLED NO
#endif
#endif

/******************************************************************************************************/

#ifndef UART_USE_2X //Double the USART Transmission Speed
#define UART_USE_2X NO
#endif

#ifndef UART_SET_BAUD
#define UART_SET_BAUD 9600
#endif

#ifndef UART_DEFINE_BAUD
#define UART_DEFINE_BAUD  (((F_CPU) + 8UL * (UART_SET_BAUD)) / (16UL * (UART_SET_BAUD)) -1UL)
#endif

#ifndef UART_DEFINE_BAUD_2X
#define UART_DEFINE_BAUD_2X  ( ((((F_CPU) + 4UL * (UART_SET_BAUD)) / (8UL * (UART_SET_BAUD)) -1UL)) | 0x8000)
#endif

#if (UART_USE_2X == NO)
#define UART_BAUD UART_DEFINE_BAUD
#else
#define UART_BAUD UART_DEFINE_BAUD_2X
#endif

/******************************************************************************************************/

#ifndef UART_TX_INTERRUPT_VECTOR
#define UART_TX_INTERRUPT_VECTOR USART_UDRE_vect
#endif

#ifndef UART_RX_INTERRUPT_VECTOR
#define UART_RX_INTERRUPT_VECTOR USART_RXC_vect
#endif

#ifndef UART_TX_BUFFER_SIZE
#define UART_TX_BUFFER_SIZE 8
#endif

#ifndef UART_RX_BUFFER_SIZE
#define UART_RX_BUFFER_SIZE 8
#endif

/******************************************************************************************************/
//FLAG BYTE CONFIGURATION
/******************************************************************************************************/

#define UART_TX_BUFFER_FULL 0x01
#define UART_RX_BUFFER_FULL 0x02
#define UART_PARITY_ERROR 0x04
#define UART_DATA_OVERRUN_ERROR 0x08
#define UART_FRAME_ERROR 0x10
#define UART_RX_BUFFER_EMPTY 0x20

/******************************************************************************************************/
//USE MACROS
/******************************************************************************************************/

#ifndef USE_uart_init
#define USE_uart_init YES
#endif

#ifndef USE_uart_tx_putdata
#define USE_uart_tx_putdata YES
#endif

#ifndef USE_uart_rx_getdata
#define USE_uart_rx_getdata YES
#endif

/******************************************************************************************************/
//FUNCTION PROTOTYPES
/******************************************************************************************************/

#if (USE_uart_init == YES)
void uart_init(void);
#endif

#if (USE_uart_tx_putdata == YES)
void uart_tx_putdata(unsigned char);
#endif

#if (USE_uart_rx_getdata == YES)
unsigned char uart_rx_getdata(void);
#endif

/******************************************************************************************************/
//SIMPLIFIED FUNCTION NAMES
/******************************************************************************************************/

#define uart_putc(x) uart_tx_putdata(x)
#define uart_getc() uart_rx_getdata()

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
