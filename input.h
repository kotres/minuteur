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

extern volatile char interrupt_variable;

typedef enum{
  not_pressed,
  pressed,
  short_press,
  long_press
}button_event_t;

typedef struct{
  char interrupt_buffer;
  unsigned char ignore_button;
  button_event_t button_event;
  software_timer_t button_timer;
}input_t;

int input_valid(input_t *input);

void interrupt input_interrupt_function(void);

void input_initialize(input_t *input);

void input_update(input_t *input);

button_event_t* input_get_button_event(input_t *input);

button_event_t* input_get_button_event_info(const input_t *input);

char* input_get_interrupt_buffer(input_t *input);

const char* input_get_interrupt_buffer_info(const input_t *input);

#endif	/* INPUT_H */

