

#include "PIC16F1825_utils.h"
#include "PIC16F1825_config.h"

// Source file with utility functions for the PIC16F1825
void pic16f1825_init(void){
    /* 16 mhz clock */
    OSCCONbits.SCS = 0; /* clear SCS bits <1:0> */ 
    OSCCONbits.IRCF = 0b1111; /* Set IRCF<3:0> to 1111 ( bits 3-6 of OSCCON) */
    while(OSCSTATbits.HFIOFR == 0 || OSCSTATbits.HFIOFS == 0); /* wait for clock to get stable */ 
    TRISC = 0x00;  //Sets PORTC pins as digital outputs
}