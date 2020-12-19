/*******************************************************
Project : Multiple 7 Segment Counter
Version : 1.0.0
Date    : 2020-12-19
Author  : Kaveh Shahedi
Company : Kharazmi University
Comments: Display a counter on four 7 segment displays

Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>

#define ZERO 0b01000000;
#define ONE 0b01111001;
#define TWO 0b00100100;
#define THREE 0b00110000;
#define FOUR 0b00011001;
#define FIVE 0b00010010;
#define SIX 0b00000010;
#define SEVEN 0b01111000;
#define EIGHT 0b00000000;
#define NINE 0b00011000;

int getNumber(int number);

int counter = 0;

void main(void){
    DDRC = 0xFF;
    DDRD = 0xFF;
    
   
	while(1){
        PORTD = getNumber(counter);
        delay_ms(100);
        
        counter++;
        if(counter > 9)
            counter = 0;
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
