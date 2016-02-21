#include "hardware_config.h"

void putch(char data) {
 while( ! TXIF) // check buffer
 continue; // wait till ready
 TXREG = data; // send data
}

void hardware_config_uart(void)
{
    TXEN=1;
    SYNC=0;
    SPEN=1;
}

void hardware_config_pins(void)
{
    PORTA=0b00001100;
    PORTB=0b00000000;
    PORTC=0b00001110;
}


void hardware_config_init(void)
{
    hardware_config_uart();
    hardware_config_pins();
}