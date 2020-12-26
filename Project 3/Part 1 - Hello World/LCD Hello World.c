/*******************************************************
Project : LCD Hello World
Version : 1.0.0
Date    : 2020-12-26
Author  : Kaveh Shahedi
Company : Kharazmi University
Comments: Shows "Hello World" on a LCD

Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <alcd.h>

void main(void)
{
    lcd_init(20);   
    
    while (1)
    {
        lcd_gotoxy(0,0);
        lcd_putsf("Hello World");
    }
}
