/* 
 * File:   hardware_timers.c
 * Author: Michel
 *
 * Created on 18 février 2016, 20:13
 */

#include <stdio.h>
#include <stdlib.h>
#include "software_timer.h"
#include <xc.h>
#include <assert.h>

/*
 * 
*/

int software_timer_valid(software_timer_t *timer)
{
    assert(timer!=NULL);
    if(flag_array_valid(&timer->flags))
        return 0;
    if(timer->regi>timer->regi)
        return 0;
    return 1;
}

void software_timer_set_preset(software_timer_t *timer,unsigned short val)
{
#ifdef __DEBUG
    assert(timer!=NULL);
#endif
    timer->preset=val;
#ifdef __DEBUG
    assert(software_timer_valid(timer));
#endif  
}

void software_timer_set_enable(software_timer_t *timer,unsigned char state)
{
#ifdef __DEBUG
    assert(timer!=NULL);
    //assert(state==0 || state=1);
    assert(software_timer_valid(timer));
#endif
    flag_array_set_flag(&timer->flags,state,ENABLE_FLAG);
#ifdef __DEBUG
    assert(software_timer_valid(timer));
#endif 
}

void software_timer_clear_overflow(software_timer_t *timer)
{
#ifdef __DEBUG
    assert(timer!=NULL);
    assert(software_timer_valid(timer));
#endif
    flag_array_set_flag(&timer->flags,NOT_SET,OVERFLOW_FLAG);
#ifdef __DEBUG
    assert(software_timer_valid(timer));
#endif 
}

void software_timer_initialize(software_timer_t *timer)
{
#ifdef __DEBUG
    assert(timer!=NULL);
#endif
    flag_array_set_flag(&timer->flags,NOT_SET,OVERFLOW_FLAG);
    flag_array_set_flag(&timer->flags,NOT_SET,ENABLE_FLAG);
    timer->regi=0;
    timer->preset=0;
#ifdef __DEBUG
    assert(software_timer_valid(timer));
#endif 
}

unsigned char software_timer_get_enable_value(software_timer_t *timer)
{
#ifdef __DEBUG
    assert(timer!=NULL);
    assert(software_timer_valid(timer));
#endif
   unsigned char enable=flag_array_get_flag_state(&timer->flags,OVERFLOW_FLAG);
#ifdef __DEBUG
    assert(enable==NOT_SET || enable==SET);
    assert(software_timer_valid(timer));
#endif
    return enable;
}

unsigned char software_timer_get_overflow_value(software_timer_t *timer)
{
#ifdef __DEBUG
    assert(timer!=NULL);
    assert(software_timer_valid(timer));
#endif
   unsigned char overflow=flag_array_get_flag_state(&timer->flags,OVERFLOW_FLAG);
#ifdef __DEBUG
    assert(overflow==NOT_SET || overflow==SET);
    assert(software_timer_valid(timer));
#endif
    return overflow;
}

unsigned char software_timer_update(software_timer_t *timer)
{
#ifdef __DEBUG
    assert(timer!=NULL);
    assert(software_timer_valid(timer));
#endif
    if(flag_array_get_flag_state(&timer->flags,ENABLE_FLAG)==SET){
        if(timer->regi<timer->preset){
            timer->regi++;
        }
        else{
#ifdef __DEBUG
            assert(timer->regi==timer->preset);
#endif
            timer->regi=0;
            flag_array_set_flag(&timer->flags,SET,OVERFLOW_FLAG);
        }
    }
#ifdef __DEBUG
    assert(software_timer_valid(timer));
#endif
    return software_timer_get_overflow_value(timer);
}