/*
 * File:   main.c
 * Author: josefonseca
 *
 * Created on February 15, 2016, 4:18 PM
 */

#include "PIC16F1825_config.h"
#include "PIC16F1825_utils.h"

#define SOUND_TIME 0.25
int PERIOD = 500 // in milliseconds

void main(void) {
    
    // Initializes the system
    pic16f1825_init();
    
    // Sets PORT C as output
    TRISC = 0x00;
    
    while(TRUE) {
        PORTCbits.RC0 = 1;
        __delay_ms(period*SOUND_TIME);
        PORTCbits.RC0 = 0;

    }
    
    return;
}
