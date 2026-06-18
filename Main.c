/**
 * PIC16F18345 - LED on/off with pushbutton
 *
 * Hardware:
 *   LED    : RC0 (active high, LED + resistor to GND)
 *   BUTTON : RA2 (active low, connects pin to GND; internal WPU enabled)
 *
 * Compiler: MPLAB XC8
 */

// CONFIG1
#pragma config FEXTOSC  = OFF
#pragma config RSTOSC   = HFINT1
#pragma config CLKOUTEN = OFF
#pragma config CSWEN    = ON
#pragma config FCMEN    = OFF

// CONFIG2
#pragma config MCLRE    = ON
#pragma config PWRTE    = OFF
#pragma config WDTE     = OFF
#pragma config LPBOREN  = OFF
#pragma config BOREN    = ON
#pragma config BORV     = LOW
#pragma config PPS1WAY  = ON
#pragma config STVREN   = ON
#pragma config DEBUG    = OFF

// CONFIG3
#pragma config WRT      = OFF
#pragma config LVP      = OFF

// CONFIG4
#pragma config CP       = OFF
#pragma config CPD      = OFF

#include <xc.h>
#include <stdint.h>

#define LED_PIN     RC0
#define BUTTON_PIN  RA2

void main(void)
{
    ANSELA = 0x00;
    ANSELC = 0x00;

    TRISAbits.TRISA2 = 1;   // RA2 input  (button)
    TRISCbits.TRISC0 = 0;   // RC0 output (LED)

    WPUAbits.WPUA2 = 1;
    OPTION_REGbits.nWPUEN = 0;

    LATC = 0x00;

    while (1)
    {
        if (BUTTON_PIN == 0)
            LATCbits.LATC0 = 1;
        else
            LATCbits.LATC0 = 0;
    }
}
