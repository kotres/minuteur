/* 
 * File:   timer.h
 * Author: Michel
 *
 * Created on 10 février 2016, 14:31
 */

#ifndef TIMERS_H
#define	TIMERS_H

#include <stdio.h>
#include <stdlib.h>
#include "byte_union.h"

typedef enum{
    button,
    output,
    main
}timer_name;

#define EIGHT_BIT_MODE 0
#define SIXTEEN_BIT_MODE 1

typedef union{
    unsigned short full;
    struct{
        unsigned char lower;
        unsigned char upper;
    };
}sixteen_bit_timer_register;

extern volatile unsigned char *button_timer;
extern volatile unsigned char *output_timer;
extern volatile sixteen_bit_timer_register *main_timer;
unsigned char main_timer_mode;
extern bit_array *timer_enable_register;
extern volatile bit_array *timer_flag_register;

int timers_valid(void);

void timers_initialize(void);

void timers_set_enable(timer_name name,unsigned char val);

unsigned char timers_get_overflow_value(timer_name name);

void timers_clear_overflow(timer_name name);

void timers_clear(timer_name name);

void timers_change_main_timer_mode(unsigned char mode);

#endif	/* TIMERS_H */

