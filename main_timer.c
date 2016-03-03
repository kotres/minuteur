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
  
}

void main_timer_fill_output_buffer(main_timer_t *timer)
{
#ifdef __DEBUG
  assert(timer!=NULL);
#endif
  byte_union_t points=menu_get_points(&timer->menu);
  unsigned char t_piece= *time_get_piece(&timer->timer,second);
  unsigned char low=0,high=0;
  
}
