
#include "PIC16F1825_utils.h"
#include "PIC16F1825_config.h"

// Source file with utility functions for the PIC16F1825
void pic16f1825_init(void){
    OSCCONbits.SCS = 0; /* clear SCS bits <1:0> */ 
    OSCCONbits.IRCF = 0b1011; /* Set IRCF<3:0> to 1011 ( bits 3-6 of OSCCON) f = 1MHz */
    while(OSCSTATbits.HFIOFR == 0 || OSCSTATbits.HFIOFS == 0); /* wait for clock to get stable */ 
    TRISC = 0x00;  //Sets PORTC pins as digital outputs
}

void configTimer2(void) {
    // Configures the postscaler -- 0b1111 = 1:16 postscaler
    T2CONbits.T2OUTPS = 0b1111;
    
    // Configures the prescaler  -- 0b11 = 1:64 prescaler
    T2CONbits.T2CKPS = 0b11;
    
    // Configures the Compare register PR2
    PR2 = 121;
    
    // Enables the associated interrupt
    PIE1bits.TMR2IE = 1;
    
    // Enables the timer
    T2CONbits.TMR2ON = 1;
}

void enableInterrupts(void) {
    INTCONbits.GIE  = 1;
    INTCONbits.PEIE = 1;
}