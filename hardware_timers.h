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
#include "flags.h"

#define ENABLE_FLAG 0
#define OVERFLOW_FLAG 1

typedef struct{
  unsigned short register,maximum;
  flag_array_t flags;
}software_timer_t;

void software_timer_initialize(software_timer_t *timer);

void software_timer_set_enable(software_timer_t *timer,unsigned char val);

unsigned char software_timer_get_overflow_value(software_timer_t *timer);

unsigned char software_timer_update(software_timer_t *timer);

void software_timer_clear_overflow(software_timer_t *timer);

void software_timer_clear(software_timer_t *timer);


#endif	/* HARDWARE_TIMERS_H */

