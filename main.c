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
    if (PIR1bits.TMR2IF) {
        PORTCbits.RC0 = !PORTCbits.RC0;
        PIR1bits.TMR2IF = 0;
    }
    
    PIE1bits.TMR2IE = 1;
    return;
}

void main(void) {
    
    // Initializes the system
    pic16f1825_init();
    
    // Sets PORT C as output
    TRISC = 0x00;
    
    // Configures the TIMER2
    enableInterrupts();
    configTimer2();
    
    PORTCbits.RC0 = 1;
    
    while(TRUE);
}
