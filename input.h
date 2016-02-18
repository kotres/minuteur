/* 
 * File:   input.h
 * Author: Michel
 *
 * Created on 16 février 2016, 20:04
 */

#ifndef INPUT_H
#define	INPUT_H
#include "flag_array.h"
#include "timers.h"

extern volatile char interrupt_variable;
extern volatile unsigned char *portA,*portB;

typedef enum{
  button_pressed,
  ignore_button,
  button_timer_active,
  button_timer_overflow,
}input_flags;

typedef struct{
  char interrupt_buffer;
  flag_array flags;
  unsigned char button_event;
}input_t;

void input_initialize(input_t input);

void input_update_flags_state(bit_array *f);

char input_get_interrupt_variable(void);

void input_update(input_t *input);

unsigned char* input_get_button_event(input_t *input);

const unsigned char* input_get_button_event_info(const input_t *input);

char* input_get_interrupt_buffer(input_t *input);

const char* input_get_interrupt_buffer_info(const input_t *input);

#endif	/* INPUT_H */

