/* 
 * File:   input.h
 * Author: Michel
 *
 * Created on 16 février 2016, 20:04
 */

#ifndef INPUT_H
#define	INPUT_H
#include "flag_array.h"
#include "software_timer.h"
#include <xc.h>

#define PAUSE_BUTTON 0
#define MENU_BUTTON 1


extern volatile char interrupt_variable;

typedef enum{
    time_button_state,
            time_button_ignore,
            menu_button_state,
            menu_button_ignore
}button_flags_names;

typedef struct{
  flag_array_t button_flags;
  char interrupt_buffer;
}input_t;

int input_valid(input_t *input);

void interrupt input_interrupt_function(void);

void input_initialize(input_t *input);

void input_update(input_t *input);

unsigned char input_get_button_event(input_t *input,unsigned char button);

char* input_get_interrupt_buffer(input_t *input);

const char* input_get_interrupt_buffer_info(const input_t *input);

#endif	/* INPUT_H */

