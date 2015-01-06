/*
 * LED_Ring_test.c
 *
 * Created: 1/2/2015 1:49:16 PM
 *  Author: Bob
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#ifndef F_CPU
#define F_CPU 8000000UL
#endif

void illuminate(int LEDx);

int main(void)
{
	/* Configure output pins */
	DDRA = 0xFF;
	DDRB = 0x77;
	
	/*Configure internal pull-up for switch input*/
	PORTB ^= (1<< PORTB3);
	
	/*Configure interrupt mask*/
	EICRA ^= (1 << ISC11); //These two lines set it to interrupt on low level (not rise/fall)
	EICRA &= ~(1 << ISC10);
	PCMSK1 ^= (1 << PCINT11); //Mask to only interrupt on PCINT11
	PCICR ^= (1 <<PCIE1);
	sei(); //Sets global interrupt bit in SREG
	
	/*define program variables*/
	int i;
	
	/*Main program loop*/
    while(1)
    {
        for(i = 1; i<=40;i++)
		{
			illuminate(i);	
			_delay_ms(20);

		}		
    }
}

/*A function which activates LEDs 1 - 40*/
void illuminate(int LEDx)
{
	PORTA = 0x00;
	PORTB |= (0x57);
	switch (LEDx) {
		case 1: 
			PORTA |= 0x01;
			PORTB &= ~(0x01);
			break;
		case 2:
			PORTA |= 0x01;
			PORTB &= ~(0x04);
			break;
		case 3:
			PORTA |= 0x01;
			PORTB &= ~(0x10);
			break;
		case 4: 
			PORTA |= 0x01;
			PORTB &= ~(0x40);
			break;
		case 5:
			PORTA |= 0x01;
			PORTB &= ~(0x02);
			break;
		case 6:
			PORTA |= 0x02;
			PORTB &= ~(0x01);
			break;
		case 7:
			PORTA |= 0x02;
			PORTB &= ~(0x04);
			break;
		case 8:
			PORTA |= 0x02;
			PORTB &= ~(0x10);
			break;
		case 9:
			PORTA |= 0x02;
			PORTB &= ~(0x40);
			break;
		case 10:
			PORTA |= 0x02;
			PORTB &= ~(0x02);
			break;
		case 11:
			PORTA |= 0x04;
			PORTB &= ~(0x01);
			break;
		case 12:
			PORTA |= 0x04;
			PORTB &= ~(0x04);
			break;
		case 13:
			PORTA |= 0x04;
			PORTB &= ~(0x10);
			break;
		case 14:
			PORTA |= 0x04;
			PORTB &= ~(0x40);
			break;
		case 15:
			PORTA |= 0x04;
			PORTB &= ~(0x02);
			break;
		case 16:
			PORTA |= 0x08;
			PORTB &= ~(0x01);
			break;
		case 17:
			PORTA |= 0x08;
			PORTB &= ~(0x04);
			break;
		case 18:
			PORTA |= 0x08;
			PORTB &= ~(0x10);
			break;
		case 19:
			PORTA |= 0x08;
			PORTB &= ~(0x40);
			break;
		case 20:
			PORTA |= 0x08;
			PORTB &= ~(0x02);
			break;
		case 21:
			PORTA |= 0x10;
			PORTB &= ~(0x01);
			break;
		case 22:
			PORTA |= 0x10;
			PORTB &= ~(0x04);
			break;
		case 23:
			PORTA |= 0x10;
			PORTB &= ~(0x10);
			break;
		case 24:
			PORTA |= 0x10;
			PORTB &= ~(0x40);
			break;
		case 25:
			PORTA |= 0x10;
			PORTB &= ~(0x02);
			break;
		case 26:
			PORTA |= 0x20;
			PORTB &= ~(0x01);
			break;
		case 27:
			PORTA |= 0x20;
			PORTB &= ~(0x04);
			break;
		case 28:
			PORTA |= 0x20;
			PORTB &= ~(0x10);
			break;
		case 29:
			PORTA |= 0x20;
			PORTB &= ~(0x40);
			break;
		case 30:
			PORTA |= 0x20;
			PORTB &= ~(0x02);
			break;
		case 31:
			PORTA |= 0x40;
			PORTB &= ~(0x01);
			break;
		case 32:
			PORTA |= 0x40;
			PORTB &= ~(0x04);
			break;
		case 33:
			PORTA |= 0x40;
			PORTB &= ~(0x10);
			break;
		case 34:
			PORTA |= 0x40;
			PORTB &= ~(0x40);
			break;
		case 35:
			PORTA |= 0x40;
			PORTB &= ~(0x02);
			break;
		case 36:
			PORTA |= 0x80;
			PORTB &= ~(0x01);
			break;
		case 37:
			PORTA |= 0x80;
			PORTB &= ~(0x04);
			break;
		case 38:
			PORTA |= 0x80;
			PORTB &= ~(0x10);
			break;
		case 39:
			PORTA |= 0x80;
			PORTB &= ~(0x40);
			break;
		case 40:
			PORTA |= 0x80;
			PORTB &= ~(0x02);
			break;
	}	
}

ISR(PCINT1_vect)
{
	PORTB ^= (1<<PORTB5);
	_delay_ms(250);
	_delay_ms(250);
	_delay_ms(250);
	_delay_ms(250);
	
	PORTB &= ~(1<<PORTB5);
}