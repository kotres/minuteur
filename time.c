#include "time.h"
#include <assert.h>

unsigned char* time_get_piece(time_t *t,time_type_t type)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_type_valid(type)==1);
#endif
  switch(type){
  case second:
    return &t->time_second;
  case  minute:
    return &t->time_minute;
  case hour:
    return &t->time_hour;
  }
  return NULL;
}

void time_set_piece(time_t *t,unsigned char val,time_type_t type)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_type_valid(type)==1);
  if(type==hour)
    assert(val<13);
  else
    assert(val<60);
#endif
  unsigned char *piece=time_get_piece(t,type);
  *piece=val;
}

int time_valid(time_t *t)
{
    assert(t!=NULL);
    if(t->time_hour>12)
        return 0;
    if(t->time_minute>59)
        return 0;
    if(t->time_second>59)
        return 0;
    return 1;
}

void time_initialize(time_t *t)
{
#ifdef __DEBUG
  assert(t!=NULL);
#endif
  time_set_piece(t,0,second);
  time_set_piece(t,4,minute);
  time_set_piece(t,0,hour);
#ifdef __DEBUG
  assert(time_valid(t)==1);
#endif
}

void time_change_piece(time_t *t,char val,time_type_t type)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_type_valid(type)==1);
  assert(time_valid(t)==1);
#endif
  unsigned char *piece=time_get_piece(t,type);
  char sum=*piece+val;
  char divider=0;
  if(type==hour)
    divider=13;
  else
    divider=60;
  char mod=0;
  mod=sum%divider;
  if(mod<0)
    *piece= divider-mod;
  else
    *piece= mod;
}

unsigned char time_is_zero(time_t *t)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_valid(t));
#endif
  if(t->time_second==0){
    if(t->time_minute==0){
      if(t->time_hour==0)
	return 1;
    }
  }
  else
    return 0;
  return -1;
}


unsigned char time_decrease(time_t *t)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_valid(t));
#endif
  if(time_is_zero(t)==0){
    time_change_piece(t,-1,second);
    if(t->time_second==59){
      time_change_piece(t,-1,minute);
      if(t->time_minute==59)
	time_change_piece(t,-1,hour);
    }
    return 0;
  }
  else
    return 1;
}
