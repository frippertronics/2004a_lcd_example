#ifndef GPIO_PINS_H
#define GPIO_PINS_H

#include <avr/io.h>

#include "kabeltester/i2c.h"

#define DDR_D_PTR (&DDRD)

#define PORT_D_PTR (&PORTD)

// Pin information. The bank has to be a volatile pointer as 
// it is set during compilation
typedef struct
{
    volatile uint8_t* ddr;
    volatile uint8_t* port;
    uint8_t number;
} GPIO_PIN_T;

static const GPIO_PIN_T TWI_PINS[NUM_I2C_PINS] = {
    {DDR_D_PTR, PORT_D_PTR, PIND0}, // TWI SCL
    {DDR_D_PTR, PORT_D_PTR, PIND1}, // TWI SDA
};

#endif //GPIO_PINS_H