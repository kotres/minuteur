#ifndef MAIN_TIMER_H
#define MAIN_TIMER_H

#include "timers.h"
#include "flag_array.h"
#include "time.h"
#include "menu.h"

typedef struct{
    time_t time;
    flag_array flags;
    menu_t menu;
}main_timer_t;

void software_timer_initialize(software_timer_t *timer);

void software_timer_update(software_timer_t *timer);

void software_timer_get_segment_enable(software_timer_t *timer);

void software_timer_fill_output_buffer(software_timer_t *timer,unsigned char B[]);

#endif
