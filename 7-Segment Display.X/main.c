#include <xc.h>
#define _XTAL_FREQ 48000000

void displayNum(int n)
{
    switch(n)
    {
        case 0:
            TRISB = 0b00000000;
            TRISC = 0b00000001;
            break;
        case 1:
            TRISB = 0b00111001;
            TRISC = 0b00000001;
            break;
        case 2:
            TRISB = 0b00100100;
            TRISC = 0b00000000;
            break;
        case 3:
            TRISB = 0b00110000;
            TRISC = 0b00000000;
            break;
        case 4:
            TRISB = 0b00011001;
            TRISC = 0b00000000;
            break;
        case 5:
            TRISB = 0b00010010;
            TRISC = 0b00000000;
            break;
        case 6:
            TRISB = 0b00000010;
            TRISC = 0b00000000;
            break;
        case 7:
            TRISB = 0b00111000;
            TRISC = 0b00000001;
            break;
        case 8:
            TRISB = 0b00000000;
            TRISC = 0b00000000;
            break;
        case 9:
            TRISB = 0b00010000;
            TRISC = 0b00000000;
            break;
    }
}

void displayClear()
{
    TRISB = 0b00111111;
    TRISC = 0b00000011;
}

void main()
{
    // Set up the LEDs
    PORTB = 0b00111111; //  pins 0-5 output
    PORTC = 0b00000011; //  pins 0-1 output

    int l = 0;
    while(l<5)
    {
        //  run 0-9, 1 second interval
        for(int i=0;i<=9;i++)
        {
            displayNum(i);
            for ( int x = 0; x < 100; x++ )
            {
                __delay_ms( 10 );
            }
        }
        l++;
    }

}