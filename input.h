/* 
 * File:   input.h
 * Author: Michel
 *
 * Created on 16 f�vrier 2016, 20:04
 */

#ifndef INPUT_H
#define	INPUT_H
#include "bit_array.h"
#include "flag.h"

extern volatile char interrupt_variable;
extern volatile unsigned char *portA,*portB;

void input_update_flags_state(bit_array *f);

char input_get_interrupt_variable(void);



#endif	/* INPUT_H */

