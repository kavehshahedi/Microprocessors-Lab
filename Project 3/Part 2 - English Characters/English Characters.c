/*******************************************************
Project : English Characters
Version : 1.0.0
Date    : 2020-12-26
Author  : Kaveh Shahedi
Company : Kharazmi University
Comments: Shows English characters on a LCD using timers

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

char characters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int timerZeroOverflow = 0;
int currentCharCounter = 0;

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    if(currentCharCounter < 26){
        timerZeroOverflow++;
        if(timerZeroOverflow == 50)
        {
            char buffer[26];
            sprintf(buffer, "%c", characters[currentCharCounter]);
            
            lcd_puts(buffer);
            
            currentCharCounter++;
            timerZeroOverflow = 0;  
        }
    }else timerZeroOverflow = 0;
    
    TCNT1H = 0xFF;
    TCNT1L = 0xF0;
}

void main(void)
{
    lcd_init(13);
    
    TIMSK = (0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

    TCCR1A = (0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
    TCCR1B = (0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (1<<CS12) | (0<<CS11) | (1<<CS10);
    TCNT1H = 0xFF;
    TCNT1L = 0xF0;

    MCUCR = (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR = (0<<ISC2);

    #asm("sei")

    while (1)
    {
    // Place your code here

    }
}
