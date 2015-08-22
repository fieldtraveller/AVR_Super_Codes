/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

uart.c

DESCRIPTION:FOR MORE INFO CHECK uart.h
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/interrupt.h>

/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include "uart.h"

/******************************************************************************************************/
//GLOBAL VARIABLES
/******************************************************************************************************/

#if (UART_TX_ENABLED == YES)
volatile unsigned char uart_tx_buffer[UART_TX_BUFFER_SIZE],uart_tx_in_p,uart_tx_out_p,uart_tx_buffer_count;
#endif

#if (UART_RX_ENABLED == YES)
volatile unsigned char uart_rx_buffer[UART_TX_BUFFER_SIZE],uart_rx_in_p,uart_rx_out_p,uart_rx_buffer_count;
#endif

unsigned char uart_flags;

/******************************************************************************************************/
//ISR DEFINITIONS
/******************************************************************************************************/

#if (UART_TX_ENABLED == YES)
ISR(UART_TX_INTERRUPT_VECTOR)   //TX_INTERRUPT
{
    if(uart_tx_buffer_count != 0)
    {
        UDR =uart_tx_buffer[uart_tx_out_p];
        uart_tx_out_p++;

        if (uart_tx_out_p >= UART_TX_BUFFER_SIZE)
            uart_tx_out_p =0;

        uart_tx_buffer_count--;

        uart_flags &= ~UART_TX_BUFFER_FULL;
    }
    else
    {
        UCSRB&=~(1<<UDRIE); //DISABLE USART DATA REGISTER EMPTY INTERRUPT
    }
}
#endif

/******************************************************************************************************/

#if (UART_RX_ENABLED == YES)
ISR(UART_RX_INTERRUPT_VECTOR)   //RX_INTERRUPT
{
    uart_flags |=(0x1C & UCSRA);

    if (uart_rx_buffer_count<UART_RX_BUFFER_SIZE)
    {
        uart_rx_buffer[uart_rx_in_p]= UDR;
        uart_rx_in_p++;
        uart_rx_buffer_count++;

        if (uart_rx_in_p >= UART_RX_BUFFER_SIZE)
            uart_rx_in_p =0;

        uart_flags &= ~UART_RX_BUFFER_EMPTY;
    }
    else
    {
        uart_flags |=UART_RX_BUFFER_FULL;
    }
}
#endif

/******************************************************************************************************/
//FUNCTION DEFINITIONS
/******************************************************************************************************/

#if (USE_uart_init == YES)
void uart_init(void)    //INITIALIZE UART
{
    #if (UART_TX_ENABLED == YES)
    uart_tx_in_p = 0;
    uart_tx_out_p = 0;
    uart_tx_buffer_count = 0;
    #endif

    #if (UART_RX_ENABLED == YES)
    uart_rx_in_p = 0;
    uart_rx_out_p = 0;
    uart_rx_buffer_count = 0;
    #endif

    uart_flags=0;

    #if (UART_USE_2X == YES)
    UCSRA|=(1<<U2X);
    #endif

    UBRRH = (unsigned char)((UART_BAUD)>>8);
    UBRRL = (unsigned char)(UART_BAUD);

    UCSRC = UART_UCSRC_MASK;

    #if (UART_NUMBER_OF_DATA_BITS == 9)
    UCSRB|= (1<<UCSZ2);
    #endif

    //UCSRC|= ((1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0));

    #if (UART_TX_ENABLED == YES) //ENABLE TX
    UCSRB|=(1<<TXEN);
    #endif

    #if (UART_RX_ENABLED == YES) //ENABLE RX AND RX COMPLETE INTERRUPT
    UCSRB|=((1<<RXEN)|(1<<RXCIE));
    #endif

    sei();  //ENABLE GLOBAL INTERRUPTS
}
#endif

/******************************************************************************************************/

#if (USE_uart_tx_putdata == YES)
void uart_tx_putdata(unsigned char value)   //PUT DATA INTO CIRCULAR QUEUE
{
    if (uart_tx_buffer_count<UART_TX_BUFFER_SIZE)
    {
        uart_tx_buffer[uart_tx_in_p]= value;
        uart_tx_in_p++;
        uart_tx_buffer_count++;

        if (uart_tx_in_p >= UART_TX_BUFFER_SIZE)
            uart_tx_in_p =0;

        UCSRB|=(1<<UDRIE);  //ENABLE USART DATA REGISTER EMPTY INTERRUPT
    }
    else
    {
        uart_flags |= UART_TX_BUFFER_FULL;
    }
}
#endif

/******************************************************************************************************/

#if (USE_uart_rx_getdata == YES)
unsigned char uart_rx_getdata(void) //GET DATA FROM CIRCULAR QUEUE
{
    unsigned char data;

    while(uart_rx_buffer_count == 0);
    //uart_flags |= UART_RX_BUFFER_EMPTY;
    //return 0;

    data = uart_rx_buffer[uart_rx_out_p];
    uart_rx_out_p++;

    if (uart_rx_out_p >= UART_RX_BUFFER_SIZE)
        uart_rx_out_p =0;

    uart_rx_buffer_count--;

    uart_flags &= ~UART_RX_BUFFER_FULL;

    return data;
}
#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
