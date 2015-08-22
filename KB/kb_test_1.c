/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

kb_test_1.c

DESCRIPTION:kb library testing code.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/io.h>

/******************************************************************************************************/

#define F_CPU 16000000UL

/******************************************************************************************************/

#include "kb.c"
#include "kb.h"

#include "lcd.h"

/******************************************************************************************************/

void main(void)
{
	lcd_init();

    kb_init();

	kb_cmd(0xED);
	kb_cmd(0x07);

	lcd_char(kb_getdata());

	kb_cmd(0xED);
	kb_cmd(0x03);

	while(1)
	{
		lcd_char(kb_getdata());
	}
}

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
