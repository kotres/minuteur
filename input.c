#include "input.h"
#include "byte_union.h"
#include <assert.h>

volatile char interrupt_variable=0;
#ifdef __GNU_BUILD
    unsigned char RA2=0,RA3=0;
#endif

int input_valid(input_t *input)
{
	if(input->flags.no_flags!=0)
		return 0;
    return 1;
}

void input_initialize(input_t *input)
{
#ifdef __DEBUG
    assert(input!=NULL);
#endif
    input->interrupt_buffer=0;
    interrupt_variable=0;
    input->flags.flag_byte=0;
#ifdef __DEBUG
    assert(input_valid(input));
#endif
}

void input_update(input_t *input)
{
#ifdef __DEBUG
    assert(input!=NULL);
    assert(input_valid(input));
#endif
    input->interrupt_buffer=interrupt_variable;
    interrupt_variable=0;
    if(RA2==0){
        if(input->flags.menu_button_ignore==NOT_SET){
        	input->flags.menu_button_state=SET;
        	input->flags.menu_button_ignore=SET;
        }
        else
        	input->flags.menu_button_state=NOT_SET;
    }
    else{
    	input->flags.menu_button_state=NOT_SET;
    	input->flags.menu_button_ignore=NOT_SET;
    }
    if(RA3==0){
        if(input->flags.pause_button_state==NOT_SET){
        	input->flags.pause_button_state=SET;
        	input->flags.pause_button_ignore=SET;
        }
        else
        	input->flags.pause_button_state=NOT_SET;
    }
    else{
    	input->flags.pause_button_ignore=NOT_SET;
    	input->flags.pause_button_state=NOT_SET;
    }
}

#ifndef __GNU_BUILD
void interrupt input_interrupt_function(void)
{
    
}
#endif

unsigned char input_get_button_event(input_t *input,unsigned char button)
{
#ifdef __DEBUG
    assert(input!=NULL);
    assert(input_valid(input));
    assert(button==PAUSE_BUTTON||button==MENU_BUTTON);
#endif
    if(button==PAUSE_BUTTON)
        return input->flags.pause_button_state;
    return input->flags.menu_button_state;
}

char input_get_interrupt_buffer(input_t *input)
{
#ifdef __DEBUG
    assert(input!=NULL);
    assert(input_valid(input));
#endif
    return input->interrupt_buffer;
}

