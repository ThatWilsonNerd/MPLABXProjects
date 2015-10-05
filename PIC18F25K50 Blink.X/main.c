#include <xc.h>
#define _XTAL_FREQ 48000000


#define LED_GREEN(v) { TRISB7 = !(v); }
#define LED_YELLOW(v) { TRISB6 = !(v); }
#define LED_RED(v) { TRISC6 = !(v); }

#define LED_B3(v) { TRISB3 = !(v); }
#define LED_B5(v) { TRISB5 = (v); }


void main()
{
    // Set up the LEDs
    LATB3 = 1;
    LATB5 = 1;
    LATB6 = 1;
    LATC6 = 0;    
    LATB7 = 1;

    /* Enable Timer 0 as a 16-bit timer with 1:256 prescaler: since
       the instruction speed is 12 MHz, this overflows about every 1.4
     seconds. */
    T0CON = 135; //0b10000111;
    while(1)
    {
        TMR0L; // trigger an update of TMR0H

        /*// Blink the green LED with a period of 1.4 s
        LED_GREEN(TMR0H >> 7 & 1);
        // Blink the yellow LED with a period of 0.7 s
        LED_YELLOW(TMR0H >> 6 & 1);
        // Blink the red LED with a period of 0.35 s
        LED_RED(TMR0H >> 5 & 1);*/

        //  alternate LEDs on B3, B5, .7s
        LED_B3(TMR0H >> 7 & 1);
        LED_B5(TMR0H >> 7 & 1);
    }
}