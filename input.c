#include "input.h"
#include <assert.h>

volatile char interrupt_variable=0;

void input_initialize(input_t *input)
{
#ifdef __DEBUG
    assert(input!=NULL);
#endif
    software_timer_initialize(&input->button_timer);
    software_timer_set_preset(&input->button_timer,100);
    input->button_event=not_pressed;
    input->interrupt_buffer=0;
    interrupt_variable=0;
    input->ignore_button=NOT_SET;
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
    if(RB6==0){
        if(software_timer_get_enable_value(&input->button_timer)==SET){
            software_timer_set_enable(&input->button_timer,NOT_SET);
            if(software_timer_get_overflow_value(&input->button_timer)==SET)
                input->button_event=long_press;
            else
                input->button_event=short_press;
            software_timer_clear(&input->button_timer);
        }
        else
            input->button_event=not_pressed;
        input->ignore_button=NOT_SET;
    }
    else{
         if(software_timer_get_enable_value(&input->button_timer)==NOT_SET){
             if(input->ignore_button==SET){
                 input->button_event=not_pressed;
             }
             else{
                 software_timer_set_enable(&input->button_timer,SET);
                 input->button_event=pressed;
             }
         }
         else{
             if(software_timer_get_overflow_value(&input->button_timer)==SET){
                 software_timer_set_enable(&input->button_timer,NOT_SET);
                 input->ignore_button=SET;
                 software_timer_clear(&input->button_timer);
                 input->button_event=long_press;
             }
             else
                input->button_event=pressed; 
         }
    }
    software_timer_update(&input->button_timer);
}

void interrupt input_interrupt_function(void)
{
    
}
