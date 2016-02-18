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

void instance_update_menu(instance *in)
{
  if(get_flag_state(&in->flags,menu_active)==SET){
    if(get_flag_state(&in->flags,button_pressed)==NOT_SET){
      flag_set(&in->flags,NOT_SET,ignore_button);
      time_change_piece(&in->t,in->deltaT,in->time_to_modify);
      in->deltaT=0;
    }
    else{
      if(get_flag_state(&in->flags,ignore_button)==NOT_SET){
	
}

void instance_update_state(instance *in)
{

}
