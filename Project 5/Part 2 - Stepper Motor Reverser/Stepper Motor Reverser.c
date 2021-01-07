/*******************************************************
Project : Kaveh Shahedi
Version : 1.0.0
Date    : 1/8/2021
Author  : Kaveh Shahedi
Company : Kharazmi University
Comments: Reverse stepper motor if PINC.2 toggles

Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>

int stepperMotorInputs[4] = {0b00001001 , 0b00001010 , 0b00000110 , 0b00000101};
int stepperMotorCurrentInput = 0;

enum controllerStatus {
    Run, 
    Wait,
    Zero
} status;

int timerZeroOverflow = 0;

int reverse;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    timerZeroOverflow++;
    if(timerZeroOverflow == 10)
    {
        if(status == Run)
        {
            PORTA = stepperMotorInputs[stepperMotorCurrentInput];
            
            if(reverse == 1)
            {
                stepperMotorCurrentInput--;
                            
                if(stepperMotorCurrentInput == -1)
                    status = Zero;
                else 
                    status = Wait;
            }else {
                stepperMotorCurrentInput++;
                            
                if(stepperMotorCurrentInput == 4)
                    status = Zero;
                else 
                    status = Wait;
            }
        }else if(status == Wait)
            status = Run;    
        else
        {
            PORTA = 0b00000000;
            status = Run;
            
            if(reverse == 1)
                stepperMotorCurrentInput = 3;
            else stepperMotorCurrentInput = 0;   
        }
        
        timerZeroOverflow = 0;
    }
    
    TCNT0 = 0x00;                   
}

void main(void)
{
    status = Run;

    DDRA = 0xFF;
    DDRC = 0x00;

    TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
    TCNT0 = 0x00;
    OCR0 = 0x00;
    TIMSK = (0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
    MCUCR = (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR = (0<<ISC2);
    
    #asm("sei")

    while (1)
    {
        if(PINC.2 == 1)
            reverse = 1;
        else
            reverse = 0;
    }
}

