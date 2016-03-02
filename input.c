#include "input.h"
#include <assert.h>

volatile char interrupt_variable=0;

int input_valid(input_t *input)
{
    return 1;
}

void input_initialize(input_t *input)
{
#ifdef __DEBUG
    assert(input!=NULL);
#endif
    input->interrupt_buffer=0;
    interrupt_variable=0;
    flag_array_initialise(&input->button_flags);
    flag_array_set_numbers(&input->button_flags,4);
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
        if(flag_array_get_flag_state(&input->button_flags,menu_button_ignore)==NOT_SET){
            flag_array_set_flag(&input->button_flags,SET,menu_button_state);
            flag_array_set_flag(&input->button_flags,SET,menu_button_ignore);
        }
        else{
            flag_array_set_flag(&input->button_flags,NOT_SET,menu_button_state);
        }
    }
    else{
        flag_array_set_flag(&input->button_flags,NOT_SET,menu_button_ignore);
        flag_array_set_flag(&input->button_flags,NOT_SET,menu_button_ignore);
    }
    if(RA3==0){
        if(flag_array_get_flag_state(&input->button_flags,time_button_ignore)==NOT_SET){
            flag_array_set_flag(&input->button_flags,SET,time_button_state);
            flag_array_set_flag(&input->button_flags,SET,time_button_ignore);
        }
        else{
            flag_array_set_flag(&input->button_flags,NOT_SET,time_button_state);
        }
    }
    else{
        flag_array_set_flag(&input->button_flags,NOT_SET,time_button_ignore);
        flag_array_set_flag(&input->button_flags,NOT_SET,time_button_ignore);
    }
}

void interrupt input_interrupt_function(void)
{
    
}

unsigned char input_get_button_event(input_t *input,unsigned char button)
{
#ifdef __DEBUG
    assert(input!=NULL);
    assert(input_valid(input));
    assert(button==PAUSE_BUTTON||button==MENU_BUTTON);
#endif
    if(button==PAUSE_BUTTON)
        return flag_array_get_flag_state(&input->button_flags,time_button_state);
    return flag_array_get_flag_state(&input->button_flags,menu_button_state);
}

char* input_get_interrupt_buffer(input_t *input)
{
#ifdef __DEBUG
    assert(input!=NULL);
    assert(input_valid(input));
#endif
    char* buffer=input->interrupt_buffer;
#ifdef __DEBUG
    assert(buffer!=NULL);
#endif
    return buffer;
}

const char* input_get_interrupt_buffer_info(const input_t *input)
{
#ifdef __DEBUG
    assert(input!=NULL);
    assert(input_valid(input));
#endif
    const char* buffer=input->interrupt_buffer;
#ifdef __DEBUG
    assert(buffer!=NULL);
#endif
    return buffer;
}