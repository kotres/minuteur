/* 
 * File:   timer.h
 * Author: Michel
 *
 * Created on 10 février 2016, 14:31
 */

#ifndef HARDWARE_TIMERS_H
#define	HARDWARE_TIMERS_H

#include <stdio.h>
#include <stdlib.h>
#include "byte_union.h"

typedef enum{
    button,
    output,
    main_timer
}timer_name;

void hardware_timers_initialize(void);

void hardware_timers_timer_initialize(timer_name name);

void hardware_timers_set_enable(timer_name name,unsigned char val);

unsigned char hardware_timers_get_overflow_value(timer_name name);

void hardware_timers_clear_overflow(timer_name name);

void hardware_timers_clear(timer_name name);


#endif	/* HARDWARE_TIMERS_H */

