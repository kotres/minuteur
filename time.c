#include "time.h"
#include <assert.h>


time_piece* get_time_piece(time *t,time_type type)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_type_valid(type)==1);
#endif
  time_piece *tp=time.piece[type];
#ifdef __DEBUG
  assert(tp!=NULL);
#endif
  return tp;
}

const time_piece* get_time_piece_info(const time *t,time_type type)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_type_valid(type)==1);
#endif
  const time_piece *tp=t->piece[type];
#ifdef __DEBUG
  assert(tp!=NULL);
#endif
  return tp;
}

void time_set_piece(time *t,unsigned char val,time_type type)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_type_valid(type)==1);
  assert(val<60);
#endif
  time_piece *tp=get_time_piece(t,type);
#ifdef __DEBUG
  assert(tp!=NULL);
#endif
  if(type!=hour)
      time_piece_set(tp,val,type);
  else
      time_piece_set_hour(tp,val);
#ifdef __DEBUG
  assert(time_piece_valid(tp)==1);
#endif
}

int time_valid(const time *t)
{
    assert(t!=NULL);
    int i=0;
    for (i=0;i<MAX_TIME_INDEX;i++){
        const time_piece tp*= get_time_piece_info(t,i);
        assert(t!=NULL);
        if(time_piece_valid(tp)==0)
            return 0;
        if(tp->type!=i)
            return 0;
    }
    return 1;
}

unsigned char time_get_value(const time *t,time_type type)
{
#ifdef __DEBUG
  assert(t!=NULL);
  assert(time_type_valid(type)==1);
  assert(time_valid(t));
#endif
  const time_piece tp*= get_time_piece_info(t,type);
#ifdef __DEBUG
  assert(tp!=NULL);
  assert(time_piece_valid(tp)==1);
#endif
  return tp->value;
}

void time_initialize(time *t)
{
#ifdef __DEBUG
  assert(t!=NULL);
#endif
  int i=0;
  for(i=0;i<MAX_TIME_INDEX;i++){
      time_piece tp*= get_time_piece(t,i);
#ifdef __DEBUG
      assert(tp!=NULL);
#endif
      time_set_piece(t,10,i);
  }
#ifdef __DEBUG
      assert(time_valid(t)==1);
#endif
}