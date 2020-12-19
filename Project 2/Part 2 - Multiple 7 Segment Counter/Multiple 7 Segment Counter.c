/*******************************************************
Project : Multiple 7 Segment Counter
Version : 1.0.0
Date    : 2020-12-19
Author  : Kaveh Shahedi
Company : Kharazmi University
Comments: Display a counter on four 7 segment displays
*******************************************************/
#include <mega16.h>
#include <delay.h>

#define ZERO 0b00111111;
#define ONE 0b00000110;
#define TWO 0b01011011;
#define THREE 0b01001111;
#define FOUR 0b01100110;
#define FIVE 0b01101101;
#define SIX 0b01111101;
#define SEVEN 0b00000111;
#define EIGHT 0b01111111;
#define NINE 0b01101111;

int getNumber(int number);

int counter[4] = {0,0,0,0};
int lastSevenSegment = 3;

int xorOpt;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    xorOpt = PORTC ^ 0xFF;
    PORTC= xorOpt ^ 0xFF;
    
    PORTD = getNumber(counter[lastSevenSegment]);
    
    lastSevenSegment--;
    if(lastSevenSegment < 0){
        lastSevenSegment = 3;
    }
    
    xorOpt = xorOpt >> 1;
    if(xorOpt ==0)
        xorOpt = 8;
    
    xorOpt = xorOpt ^ 0xFF;
    PORTC = xorOpt;
    xorOpt = xorOpt ^ 0xFF;
    
    TCNT0 = 0x00;
}

int i =3;
int timerOneOverflow =0;
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{

    timerOneOverflow++;
    if(timerOneOverflow == 163){
        counter[3] += 1;

        while (i >= 0) {
            if(counter[i] == 10) {
                counter[i-1] += 1;
                counter[i] = 0;
            }
            
            i--;
        }

        i = 3;
        timerOneOverflow=0;
    }
    
    TCNT1H = 0xFF;
    TCNT1L = 0xF0;
}

void main(void)
{
    DDRD = 0xFF;
    DDRC = 0xFF;

    PORTD = 0x00;
    PORTC = 0b11101111;

    TIMSK = (0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

    TCCR0 = (0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
    TCNT0 = 0x00;
    OCR0 = 0x00;

    TCCR1A = (0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
    TCCR1B = (0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (1<<CS12) | (0<<CS11) | (1<<CS10);
    TCNT1H = 0xFF;
    TCNT1L = 0xF0;

    MCUCR = (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR = (0<<ISC2);

    #asm("sei") 
    
    while (1)
    {
    }
}

int getNumber(int number){
    switch(number){
        case 0:
            return ZERO;
            break;
        case 1:
            return ONE;
            break;
        case 2:
            return TWO;
            break;
        case 3:
            return THREE;
            break;
        case 4:
            return FOUR;
            break;
        case 5:
            return FIVE;
            break;
        case 6:
            return SIX;
            break;
        case 7:
            return SEVEN;
            break;
        case 8:
            return EIGHT;
            break;
        case 9:
            return NINE;
            break;
    }
}
