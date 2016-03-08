// Some useful defines
#ifndef UTILS_H
#define UTILS_H

#include <xc.h>
#include <stdint.h>

#define TRUE 1

// Performs the needed initial configurations on the PIC16F1825
void pic16f1825_init(void);
void configTimer2(void);

#endif