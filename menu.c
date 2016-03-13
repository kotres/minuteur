#include "menu.h"
#include <assert.h>

int menu_valid(menu_t menu)
{
	assert(menu!=NULL);
	if(menu->flags.no_flags!=0)
		return 0;
	if(menu->flags.menu_status==SET&&menu->flags.pause_status==NOT_SET)
		return 0;
	if(time_type_valid(menu->time_type_to_change)==0)
		return 0;
	if(input_valid(menu->input)==0)
		return 0;
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
    menu->flags.flag_byte=0;
    menu->flags.pause_status=SET;
    menu->flags.segments_enable=SET;
    menu->points.byte=0;
#ifdef __DEBUG
    assert(menu_valid(menu)==1);
#endif
}

void menu_update(menu_t *menu)
{
    input_update(&menu->input);
    menu->deltaT=*input_get_interrupt_buffer(menu->input);
    if(menu->flags.menu_status==NOT_SET)
        menu->deltaT=0;
    if(menu->flags.pause_status==NOT_SET)
      menu->flags.segments_enable=NOT_SET;
    unsigned char m_button=input_get_button_event(&menu->input,MENU_BUTTON);
    unsigned char p_button=input_get_button_event(&menu->input,PAUSE_BUTTON);
    if(p_button==SET){
      menu->flags.segments_enable=SET;
        if(menu->flags.pause_status==SET){
        	menu->flags.pause_status=NOT_SET;
            menu->flags.menu_status=NOT_SET;
        }
        else
        	menu->flags.pause_status=SET;
    }
    if(m_button==SET){
      menu->flags.segments_enable=SET;
      if(menu->flags.pause_status==SET){
        if(menu->flags.menu_status==NOT_SET){
        	menu->flags.menu_status=SET;
            menu->time_type_to_change=minute;
        }
        else{
        	menu->time_type_to_change++;
            menu->time_type_to_change=menu->time_type_to_change%TIME_TYPE_NBR;
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
    if(menu->flags.menu_status==SET){
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
   return  menu->flags.pause_status;
}

unsigned char menu_get_segment_enable_value(menu_t *menu)
{
#ifdef __DEBUG
    assert(menu!=NULL);
    assert(menu_valid(menu)==1);
#endif
    return  menu->flags.segments_enable;
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
