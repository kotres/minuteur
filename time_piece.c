#include "time_piece.h"
#include <assert.h>


unsigned char get_time_piece_value(const time_piece *tp)
{
#ifdef __DEBUG
  assert(tp!=NULL);
#endif
    return tp->value;
}

int time_piece_valid(const time_piece *tp)
{
    assert(tp!=NULL);
    if(time_type_valid(tp->type)==0)
        return 0;
    if(time_piece_value_valid(tp->value)==0)
        return 0;
    return 1;
}

int time_piece_value_valid(unsigned char value)
{
    if(value>60)
        return 0;
    return 1;
}

void time_piece_define(time_piece *tp,unsigned char value,time_type type)
{
#ifdef __DEBUG
    assert(tp!=NULL);
    assert(time_type_valid(type)==1);
    assert(time_piece_value_valid(value)==1);
#endif
    tp->type=type;
    tp->value=value;
#ifdef __DEBUG
    assert(time_piece_valid(tp)==1);
#endif
}

void time_piece_initalize(time_piece *tp)
{
#ifdef __DEBUG
    assert(tp!=NULL);
#endif
    time_piece_define(tp,0,second);
#ifdef __DEBUG
    assert(time_piece_valid(tp)==1);
#endif
}

void time_piece_define_second(time_piece *tp)
{
#ifdef __DEBUG
    assert(tp!=NULL);
#endif
    time_piece_define(tp,0,second);
#ifdef __DEBUG
    assert(time_piece_valid(tp)==1);
#endif
}

void time_piece_define_minute(time_piece *tp)
{
#ifdef __DEBUG
    assert(tp!=NULL);
#endif
    time_piece_define(tp,0,minute);
#ifdef __DEBUG
    assert(time_piece_valid(tp)==1);
#endif
}

void time_piece_define_hour(time_piece *tp)
{
#ifdef __DEBUG
    assert(tp!=NULL);
#endif
    time_piece_define(tp,0,hour);
#ifdef __DEBUG
    assert(time_piece_valid(tp)==1);
#endif
}
