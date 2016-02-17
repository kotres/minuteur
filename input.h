/* 
 * File:   input.h
 * Author: Michel
 *
 * Created on 16 février 2016, 20:04
 */

#ifndef INPUT_H
#define	INPUT_H


extern volatile char interrupt_variable;
extern volatile unsigned char *portA,*portB;

unsigned char input_get_button_state(void);

char input_get_interrupt_variable(void);



#endif	/* INPUT_H */

