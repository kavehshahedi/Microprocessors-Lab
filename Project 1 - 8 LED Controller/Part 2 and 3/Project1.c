/*******************************************************
Project : 8 LED Controller
Version : 
Date    : 2020-12-10
Author  : Kaveh Shahedi - Roozbeh Aghili
Company : Kharazmi University
Comments: Controlls 8 LEDs connected to an ATMega16 chipset.


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
*******************************************************/

#include <mega16.h>
#include <delay.h>

int counter = 0;
int started = 0;

void main(void)
{
    DDRB = 0xFF;
    DDRA = 0x00;
    
    PORTB.0 = 1;
    PORTB.1 = 1;
    PORTB.2 = 1;
    PORTB.3 = 1;
    PORTB.4 = 1;
    PORTB.5 = 1;
    PORTB.6 = 1;
    PORTB.7 = 1;
         
    started = 0;

    while (1)
    {
        if(PINA.0 == 1)
        {
            if(started == 0)
            {
                started = 1;
                counter = 0;
                
                PORTB.0 = 1;
                PORTB.1 = 1;
                PORTB.2 = 1;
                PORTB.3 = 1;
                PORTB.4 = 1;
                PORTB.5 = 1;
                PORTB.6 = 1;
                PORTB.7 = 1;

                while(1)
                {
                    switch(counter)
                    {     
                        case 0:
                            PORTB.0 = 0;
                            PORTB.7 = 1;
                            break;     
                        case 1:
                            PORTB.1 = 0;
                            PORTB.0 = 1;
                            break;     
                        case 2:
                            PORTB.2 = 0;
                            PORTB.1 = 1;
                            break;     
                        case 3:
                            PORTB.3 = 0;
                            PORTB.2 = 1;
                            break;     
                        case 4:
                            PORTB.4 = 0;
                            PORTB.3 = 1;
                            break;     
                        case 5:
                            PORTB.5 = 0;
                            PORTB.4 = 1;
                            break;     
                        case 6:
                            PORTB.6 = 0;
                            PORTB.5 = 1;
                            break;     
                        case 7:
                            PORTB.7 = 0;
                            PORTB.6 = 1;
                            break;
                    }
                    
                    counter++;
                    if(counter > 7)
                        counter = 0;
                        
                    delay_ms(50);
                }
            }
        }else if(PINA.0 == 0)
        {
            started = 0;
        }
    }
}
