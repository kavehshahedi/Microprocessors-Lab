/*******************************************************
Project : Frequency Calculator
Version : 1.0.0
Date    : 2020-12-26
Author  : Kaveh Shahedi
Company : Kharazmi University
Comments: Calculates pulse frequency using input capture mode

Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <alcd.h>
#include <stdio.h>
#include <delay.h>

#define ICR1 256 * ICR1H + ICR1L;

unsigned int riseStartEdge;
unsigned int fallStartEdge;
unsigned int riseEndEdge;

char frequency[16];

unsigned int period;
long freq;

void main(void)
{
    lcd_init(16);

    PORTD = 0x00;
    
    while(1)
    {
        TCCR1A = 0;
        TCNT1=0;
        TIFR = (1<<ICF1);      

        TCCR1B = 0x41;  
        while ((TIFR&(1<<ICF1)) == 0);
        riseStartEdge = ICR1;         
        TIFR = (1<<ICF1);     
                
        TCCR1B = 0x01;    
        while ((TIFR&(1<<ICF1)) == 0);
        fallStartEdge = ICR1;          
        TIFR = (1<<ICF1);     
                
        TCCR1B = 0x41;
        while ((TIFR&(1<<ICF1)) == 0);
        riseEndEdge = ICR1; 
        TIFR = (1<<ICF1);

        TCCR1B = 0;
		
		if(riseStartEdge < riseEndEdge)
		{
			period = riseEndEdge - riseStartEdge;
			
			freq= 8000000UL/period;
            sprintf(frequency,"Freq: %d Hz", (int)freq);
			
            lcd_clear();
			lcd_puts(frequency);
		}else lcd_puts("Waiting...");
        
        delay_ms(100);
	}
}
