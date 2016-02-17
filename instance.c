#include "instance.h"

void instance_initialize(instance *in)
{
    timers_initialize();
    flag_array_initialise(&in->flags);
    time_initialize(&in->t);
    points_initialize(&in->points);
    music_select_initialize(&in->mus_select);
    in->deltaT=0;
    in->time_to_modify=second;
}

void instance_update_input(instance *in)
{
    input_update_flags_state(in->flags);
    in->deltaT=input_get_interrupt_variable();
}

void instance_update_state(instance *in)
{
    
}