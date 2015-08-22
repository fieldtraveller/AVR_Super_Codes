#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#include "lcd.c"

#define DELAY 1

//Full Step delay: 1.7 millisecond
//Half Step delay: 1 millisecond

void main()
{
	//lcd_init();
	//lcd_char('C');
	DDRA=0xFF;

	int number_of_iterations=450,count_0,motor_position_count=0;

	//_delay_ms(DELAY);

	/*

	//Step_in_degrees=(360/(((number_of_iterations)-(number_of_iterations*9))/2))

	for(count_0=0;count_0<number_of_iterations;count_0++)
	{
		switch(motor_position_count)
		{
			case 0:
				PORTA=0b11111110;
				_delay_ms(DELAY);
				break;

			case 1:
				PORTA=0b11111010;
				_delay_ms(DELAY);
				break;

			case 2:
				PORTA=0b11111011;
				_delay_ms(DELAY);
				break;

			case 3:
				PORTA=0b11111001;
				_delay_ms(DELAY);
				break;

			case 4:
				PORTA=0b11111101;
				_delay_ms(DELAY);
				break;

			case 5:
				PORTA=0b11110101;
				_delay_ms(DELAY);
				break;

			case 6:
				PORTA=0b11110111;
				_delay_ms(DELAY);
				break;

			case 7:
				PORTA=0b11110110;
				_delay_ms(DELAY);
				break;

			default:
				motor_position_count=-1;
		}

		motor_position_count++;
	}


	_delay_ms(1000);

	for(count_0=0;count_0<number_of_iterations;count_0++)
	{
		switch(motor_position_count)
		{
			case 0:
				PORTA=0b11110110;
				_delay_ms(DELAY);
				break;

			case 1:
				PORTA=0b11110111;
				_delay_ms(DELAY);
				break;

			case 2:
				PORTA=0b11110101;
				_delay_ms(DELAY);
				break;

			case 3:
				PORTA=0b11111101;
				_delay_ms(DELAY);
				break;

			case 4:
				PORTA=0b11111001;
				_delay_ms(DELAY);
				break;

			case 5:
				PORTA=0b11111011;
				_delay_ms(DELAY);
				break;

			case 6:
				PORTA=0b11111010;
				_delay_ms(DELAY);
				break;

			case 7:
				PORTA=0b11111110;
				_delay_ms(DELAY);
				break;

			default:
				motor_position_count=-1;
		}

		motor_position_count++;
	}

	//*/

	while(1)
	{
		/*
		//Full step, high torque, forward
		//DELAY 1.58
		PORTA=0b11111110;
		_delay_ms(DELAY);
		PORTA=0b11111011;
		_delay_ms(DELAY);
		PORTA=0b11111101;
		_delay_ms(DELAY);
		PORTA=0b11110111;
		_delay_ms(DELAY);
		//*/

		/*
		//Full step, reduced torque, forward
		//DELAY 1.7
		PORTA=0b11111010;
		_delay_ms(DELAY);
		PORTA=0b11111001;
		_delay_ms(DELAY);
		PORTA=0b11110101;
		_delay_ms(DELAY);
		PORTA=0b11110110;
		_delay_ms(DELAY);
		//*/

		/*
		//Half Step, forward, inefficient as it causes mild heating of motor under no load
		PORTA=0b11111110;
		_delay_ms(DELAY);
		PORTA=0b11111010;
		_delay_ms(DELAY);
		PORTA=0b11111011;
		_delay_ms(DELAY);
		PORTA=0b11111001;
		_delay_ms(DELAY);
		PORTA=0b11111101;
		_delay_ms(DELAY);
		PORTA=0b11110101;
		_delay_ms(DELAY);
		PORTA=0b11110111;
		_delay_ms(DELAY);
		PORTA=0b11110110;
		_delay_ms(DELAY);
		//*/

		/*
		//unipolar sequence
		PORTA=~0b11111110;
		_delay_ms(DELAY);
		PORTA=~0b11111010;
		_delay_ms(DELAY);
		PORTA=~0b11111011;
		_delay_ms(DELAY);
		PORTA=~0b11111001;
		_delay_ms(DELAY);
		PORTA=~0b11111101;
		_delay_ms(DELAY);
		PORTA=~0b11110101;
		_delay_ms(DELAY);
		PORTA=~0b11110111;
		_delay_ms(DELAY);
		PORTA=~0b11110110;
		_delay_ms(DELAY);
		//*/
	}
}

