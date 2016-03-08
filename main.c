/*
 * File:   main.c
 * Author: josefonseca
 *
 * Created on February 15, 2016, 4:18 PM
 */

#include "PIC16F1825_config.h"
#include "PIC16F1825_utils.h"

uint8_t ON_TIME_PRX  = 0;
uint8_t OFF_TIME_PRX = 0;

#define DUTY_CYCLE 0.2
#define PRESCALER  16
#define POSTSCALER 64

void interrupt ISR() {
    if (PIR1bits.TMR2IF == 1) {
        if (LATCbits.LATC0 == 1)
            PR2 = OFF_TIME_PRX;
        else
            PR2 = ON_TIME_PRX;
        LATCbits.LATC0 = ~LATCbits.LATC0;
        PIR1bits.TMR2IF = 0;
    }
}

void main(void) {
    
    int period = 100;
    
    // Initializes the system
    pic16f1825_init();
    
    // Sets PORT C as output
    TRISC = 0x00;
    
    // Sets the buzzer to on
    LATCbits.LATC0 = 1;
    
    // Configures the DutyCycle
    ON_TIME_PRX  = (uint8_t)(0.2441*period*DUTY_CYCLE     - 1);
    OFF_TIME_PRX = (uint8_t)(0.2441*period*(1-DUTY_CYCLE) - 1);
    
    // Configures the TIMER2
    configTimer2();
    
    while(TRUE);
}
