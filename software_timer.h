/* 
 * File:   timer.h
 * Author: Michel
 *
 * Created on 10 février 2016, 14:31
 */

#ifndef SOFTWARE_TIMER_H
#define	SOFTWARE_TIMER_H

#include <stdio.h>
#include <stdlib.h>
#include "flag_array.h"

#define ENABLE_FLAG 0
#define OVERFLOW_FLAG 1

typedef struct{
  unsigned short regi,preset;
  flag_array_t flags;
}software_timer_t;

int software_timer_valid(software_timer_t *timer);

void software_timer_initialize(software_timer_t *timer);

void software_timer_set_enable(software_timer_t *timer,unsigned char state);

unsigned char software_timer_get_enable_value(software_timer_t *timer);

unsigned char software_timer_get_overflow_value(software_timer_t *timer);

unsigned char software_timer_update(software_timer_t *timer);

void software_timer_clear_overflow(software_timer_t *timer);

void software_timer_clear(software_timer_t *timer);

void software_timer_set_preset(software_timer_t *timer,unsigned short val);

#endif	/* SOFTWARE_TIMER_H */

