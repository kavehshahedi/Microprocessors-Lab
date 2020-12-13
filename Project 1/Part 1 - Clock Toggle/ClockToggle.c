/*******************************************************
Project : Clock Toggle
Version : 
Date    : 2020-12-13
Author  : Kaveh Shahedi
Company : Kharazmi University
Comments: Toggle the pin #0 between 0 and 1 every 0.5 seconds.


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
*******************************************************/

#include <mega16.h>

static unsigned int time_count;

interrupt [TIM0_OVF] void timer0_ovf_isr(void){
	TCNT0 = 56;
	time_count = time_count + 1;

	if(time_count == 3787){
		PORTA.0 = (PORTA.0 ^ 1);
		time_count = 0;
	}
}

void main(void){
	DDRA = 0x01;

	TCCR0 = 0x02;
	TCNT0 = 56;

	TIMSK = 0x01;

	#asm("sei");

	while(1){

	}
}