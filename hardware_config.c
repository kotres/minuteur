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
    TRISA=0b00001111;
    TRISB=0b00000000;
    TRISC=0b00000000;
}

void hardware_config_timer1(void)
{
    SOSCPWR=0;
    T1CON=0b100010100;
    TMR1L=0;
    TMR1H=0;
}

void hardware_config_timer3(void)
{
    T3CON=0b00000001;
}

void hardware_config_interrupt(void)
{
    GIE=1;
    INTE=1;
    INTEDG=0;
    INTPPS=0b00001;
}

void hardware_config_init(void)
{
    hardware_config_uart();
    hardware_config_pins();
    hardware_config_timer1();
    hardware_config_timer3();
    hardware_config_interrupt();
}