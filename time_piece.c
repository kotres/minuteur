#include "time_piece.h"
#include <assert.h>



int time_piece_valid(const time_piece *tp)
{
    assert(tp!=NULL);
    if(time_type_valid(tp->type)==0)
        return 0;
    if(tp->value>60)
        return 0;
    if(tp->type==hour){
        if(tp->value>13)
            return 0;
    }
    return 1;
}


void time_piece_set(time_piece *tp,unsigned char value,time_type type)
{
#ifdef __DEBUG
    assert(tp!=NULL);
    assert(time_type_valid(type)==1);
    assert(value<60);
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
    time_piece_set(tp,0,second);
#ifdef __DEBUG
    assert(time_piece_valid(tp)==1);
#endif
}


void time_piece_set_hour(time_piece *tp,unsigned char val)
{
#ifdef __DEBUG
    assert(tp!=NULL);
    assert(val<13);
#endif
    time_piece_set(tp,val,hour);
#ifdef __DEBUG
    assert(time_piece_valid(tp)==1);
#endif
}
