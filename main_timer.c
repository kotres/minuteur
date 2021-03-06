#include "main_timer.h"
#include <assert.h>

int main_timer_valid(main_timer_t *timer)
{
    assert(timer!=NULL);
    if(time_valid(&timer->time)==0)
        return 0;
    if(menu_valid(&timer->menu)==0)
        return 0;
    if(timer->flags.no_flags!=0)
        return 0;
    return 1;
}

void main_timer_initialize(main_timer_t *timer)
{
#ifdef __DEBUG
  assert(timer!=NULL);
#endif
  TMR1ON=NOT_SET;
  TMR1L=0;
  TMR1H=0;
  TMR1IF=0;
  time_initialize(&timer->time);
  timer->flags.flag_byte=0;
  timer->flags.segments_flag=SET;
  timer->flags.dont_reset=SET;
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
	unsigned char pause_status=menu_get_pause_value(&timer->menu);
	if(pause_status==SET){
		//to pause hardware timer
        TMR1ON=NOT_SET;
		if(time_is_zero(&timer->time)==1&&timer->flags.dont_reset==NOT_SET)
			main_timer_initialize(timer);
		else{
			time_change_piece(&timer->time,
					*menu_get_deltaT(&timer->menu),
					*menu_get_time_to_change(&timer->menu));
			timer->flags.segments_flag=SET;
		}
	}
	else
        TMR1ON=SET;/*to unpause hardware timer*/
    if(TMR1IF==SET){
        TMR1IF=NOT_SET;
        if(time_decrease(&timer->time)==SET){
            timer->flags.music_flag=SET;
            timer->flags.segments_flag=SET;
        }
    }
	main_timer_fill_output_buffer(timer);
}

unsigned char main_timer_get_segment_enable(main_timer_t *timer)
{
#ifdef __DEBUG
  assert(timer!=NULL);
  assert(main_timer_valid(timer)==1);
#endif
  return timer->flags.segments_flag;
}

unsigned char main_timer_music_enable(main_timer_t *timer)
{
#ifdef __DEBUG
  assert(timer!=NULL);
  assert(main_timer_valid(timer)==1);
#endif
  return timer->flags.music_flag;
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

void main_timer_get_output_buffer(main_timer_t *timer,byte_union_t buffer[])
{
#ifdef __DEBUG
  assert(timer!=NULL);
  assert(main_timer_valid(timer)==1);
#endif
  for(int i=0;i<6;i++){
      buffer[i]=timer->segments[i];
  }
#ifdef __DEBUG
  assert(main_timer_valid(timer)==1);
#endif
}
