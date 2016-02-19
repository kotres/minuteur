/* 
 * File:   hardware_timers.c
 * Author: Michel
 *
 * Created on 18 février 2016, 20:13
 */

#include <stdio.h>
#include <stdlib.h>
#include "hardware_timers.h"
#include <xc.h>

/*
 * 
 */

void hardware_timers_timer_initialize(timer_name name)
{
    switch(name){
        case button:
            TMR2=0x0;
            T2CON=0b01111011;
            PIR1.TMR2IF=0;
            break;
        case output:
            TMR0=0x0;
            OPTION_REG=0b00000111;
            INTCON.TMR0IF=0;
            break;
        case main_timer:
            break;
    }
}

void hardware_timers_initialize(void)
{

}

