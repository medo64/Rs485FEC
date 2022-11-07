#include <xc.h>
#include <stdbool.h>
#include "timer0.h"

#if !defined(TMR0H)
    uint8_t postscaler = 0;
#endif

void timer0_init(void) {  // 24x per second
#if defined(TMR0H)
    TMR0H = 186;
    T0CON0bits.T016BIT = 0;       // Timer0 is an 8-bit timer
    T0CON0bits.T0OUTPS = 0b0110;  // 1:7 Postscaler
    T0CON1bits.T0CS = 0b010;      // FOSC/4
    T0CON1bits.T0ASYNC = 0;       // The input to the TMR0 counter is synchronized to FOSC/4
    T0CON1bits.T0CKPS = 0b1000;   // 1:256 Prescaler
    T0CON0bits.T0EN = 1;          // Timer0 Enable bit
#else  // try your best
    OPTION_REGbits.TMR0CS = 0;    // FOSC/4
    OPTION_REGbits.PSA = 0;       // Prescaler is assigned to the Timer0 module
    OPTION_REGbits.PS = 0b111;    // 1:256 Prescaler
    TMR0 = 96;
#endif
}

void timer0_reset(void) {
#if defined(TMR0H)
    TMR0L = 0;
#else
    TMR0 = 96;
    postscaler = 0;
#endif
}

bool timer0_wasTriggered(void) {  // 24x per second
#if defined(TMR0H)
    if (PIR0bits.TMR0IF) {
        PIR0bits.TMR0IF = 0;
        return true;
    }
    return false;
#else
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        postscaler++;
        if (postscaler == 8) { 
            postscaler = 0;
            TMR0 = 96;
            return true;
        }
    }
    return false;
#endif
}

void timer0_waitTick(void) {
    timer0_reset();
    while (!timer0_wasTriggered()) {
        asm("CLRWDT");
    }
}
