#include "menu.h"
#include <assert.h>

int menu_valid(menu_t *menu)
{
    return 1;
}

void menu_initialize(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
#endif
    menu->deltaT=0;
    input_initialize(&menu->input);
    menu->time_type_to_change=minute;
    flag_array_initialise(&menu->status);
    flag_array_set_numbers(&menu->status,3);
    flag_array_set_flag(&menu->status,SET,pause_status);
    flag_array_set_flag(&menu->status,SET,segments_enable);
    menu->points.byte=0;
#ifdef __DEBUG
    assert(menu_valid(menu)==1);
#endif
}

void menu_update(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
    assert(menu_valid(menu)==1);
#endif
    input_update(&menu->input);
    menu->deltaT=*input_get_interrupt_buffer_info(menu->input);
    if(flag_array_get_flag_state(&menu->status,menu_status)==NOT_SET)
        menu->deltaT=0;
    if(flag_array_get_flag_state(&menu->status,pause_status)==NOT_SET)
      flag_array_set_flag(&menu->status,NOT_SET,segments_enable);
    unsigned char m_button=input_get_button_event(&menu->input,MENU_BUTTON);
    unsigned char p_button=input_get_button_event(&menu->input,PAUSE_BUTTON);
    if(p_button==SET){
      flag_array_set_flag(&menu->status,SET,segments_enable);
        if(flag_array_get_flag_state(&menu->status,pause_status)==SET){
            flag_array_set_flag(&menu->status,NOT_SET,pause_status);
            flag_array_set_flag(&menu->status,NOT_SET,menu_status);
        }
        else{
            flag_array_set_flag(&menu->status,SET,pause_status);
	    
	}
    }
    if(m_button==SET){
      flag_array_set_flag(&menu->status,SET,segments_enable);
      if(flag_array_get_flag_state(&menu->status,pause_status)==SET){
        if(flag_array_get_flag_state(&menu->status,menu_status)==NOT_SET){
	  flag_array_set_flag(&menu->status,SET,menu_status);
            menu->time_type_to_change=minute;
        }
        else{
	  if(menu->time_type_to_change==hour)
	      menu->time_type_to_change=second;
            else
	      menu->time_type_to_change++;
        }
      }
    }
    menu_update_points(menu);
}

void menu_update_points(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
#endif
    byte_union_t *pt=&menu->points;
    pt->byte=0;
    if(flag_array_get_flag_state(&menu->status,menu_status)==SET){
            switch(menu->time_type_to_change){
            case second:
                pt->b0=SET;
                pt->b1=SET;
            break;
            case minute:
                pt->b2=SET;
                pt->b3=SET;
            break;
            case hour:
                pt->b4=SET;
                pt->b5=SET;
            break;
        }
    }
}


char *menu_get_deltaT(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
    assert(menu_valid(menu)==1);
#endif
    return &menu->deltaT;
}

unsigned char menu_get_pause_value(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
    assert(menu_valid(menu)==1);
#endif
   return  flag_array_get_flag_state(&menu->status,pause_status);
}

unsigned char menu_get_segment_enable_value(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
    assert(menu_valid(menu)==1);
#endif
    return  flag_array_get_flag_state(&menu->status,segments_enable);
}

byte_union_t menu_get_points(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
    assert(menu_valid(menu)==1);
#endif
    return menu->points;
}

time_type_t* menu_get_time_to_change(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
    assert(menu_valid(menu)==1);
#endif
    return menu->time_type_to_change;
}
