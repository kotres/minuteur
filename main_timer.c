#include "main_timer.h"
#include <assert.h>

int main_timer_valid(main_timer_t *timer)
{
  return 1;
}

void main_timer_initialize(main_timer_t *timer)
{
#ifdef __DEBUG
  assert(timer!=NULL);
#endif
  time_initialize(&timer->time);
  flag_array_initialise(&timer->flags);
  flag_array_set_numbers(&timer->flags,2);
  flag_array_set_flag(&timer->flags,SET,SEGMENTS_FLAG);
  main_timer_fill_output_buffer(timer);
  menu_initialize(&timer->menu);
#ifdef __DEBUG
  assert(main_timer_valid(timer)==1);
#endif
}

void main_timer_update(main_timer_t *timer)
{
#ifdef __DEBUG
  assert(timer!=NULL);
  assert(main_timer_valid(timer)==1);
#endif
	menu_update(&timer->menu);
	unsigned char menu_status=menu_get_pause_value(&timer->menu);
	unsigned char segment_staus=menu_get_segment_enable_value(&timer->menu);

}

void main_timer_fill_output_buffer(main_timer_t *timer)
{
#ifdef __DEBUG
  assert(timer!=NULL);
#endif
  byte_union_t points=menu_get_points(&timer->menu);
  for(int i=0;i<2;i++){
	  unsigned char t_piece= *time_get_piece(&timer->time,i);
	  unsigned char low=t_piece%10;
	  unsigned char high=t_piece-low;
	  timer->segments[2*i].byte=low;
	  timer->segments[2*i+1].byte=high;
  }
  timer->segments[0].b7=points.b0;
  timer->segments[1].b7=points.b1;
  timer->segments[2].b7=points.b2;
  timer->segments[3].b7=points.b3;
  timer->segments[4].b7=points.b4;
  timer->segments[5].b7=points.b5;
}
