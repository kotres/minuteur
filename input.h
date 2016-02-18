/* 
 * File:   input.h
 * Author: Michel
 *
 * Created on 16 février 2016, 20:04
 */

#ifndef INPUT_H
#define	INPUT_H
#include "bit_array.h"
#include "flag.h"
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
}input_t;

void input_update_flags_state(bit_array *f);

char input_get_interrupt_variable(void);

void input_update(input_t *input);

#endif	/* INPUT_H */

