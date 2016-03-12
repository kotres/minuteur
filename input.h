/* 
 * File:   input.h
 * Author: Michel
 *
 * Created on 16 f�vrier 2016, 20:04
 */

#ifndef INPUT_H
#define	INPUT_H
#ifndef __GNU_BUILD
#include <xc.h>
#endif

#define PAUSE_BUTTON 0
#define MENU_BUTTON 1


extern volatile char interrupt_variable;
#ifdef __GNU_BUILD
   extern unsigned char RA2,RA3;
#endif

typedef union{
	unsigned char flag_byte;
	struct{
		unsigned pause_button_state:1,pause_button_ignore:1,
				 menu_button_state:1,menu_button_ignore:1,no_flags:4;
	};
}input_flags_t;

typedef struct{
  input_flags_t flags;
  char interrupt_buffer;
}input_t;

int input_valid(input_t *input);

#ifndef __GNU_BUILD
void interrupt input_interrupt_function(void);
#endif

void input_initialize(input_t *input);

void input_update(input_t *input);

unsigned char input_get_button_event(input_t *input,unsigned char button);

char* input_get_interrupt_buffer(input_t *input);

#endif	/* INPUT_H */

