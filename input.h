/* 
 * File:   input.h
 * Author: Michel
 *
 * Created on 16 février 2016, 20:04
 */

#ifndef INPUT_H
#define	INPUT_H

extern volatile char interrupt_variable;
extern volatile char interrupt_buffer;

void input_get_button_state(void);



#endif	/* INPUT_H */

