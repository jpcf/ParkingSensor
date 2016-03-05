/*
 * File:   main.c
 * Author: josefonseca
 *
 * Created on February 15, 2016, 4:18 PM
 */

#include "PIC16F1825_config.h"
#include "PIC16F1825_utils.h"

#define DUTY_CYCLE 0.5

void interrupt ISR() {
    if (PIR1bits.TMR2IF == 1) {
        LATCbits.LATC0 = ~LATCbits.LATC0;
        PIR1bits.TMR2IF = 0;
    }
}

void main(void) {
    
    // Initializes the system
    pic16f1825_init();
    
    // Sets PORT C as output
    TRISC = 0x00;
    
    // Configures the TIMER2
    configTimer2();
    
    LATCbits.LATC0 = 0;
    
    while(TRUE);
}
