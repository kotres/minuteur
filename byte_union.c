#include "byte_union.h"
#include <assert.h>

unsigned char byte_union_get_bit_value(byte_union_t *byte_u,unsigned char bit_nbr)
{
#ifdef __DEBUG
    assert(byte_u!=NULL);
    assert(bit_nbr<8);
#endif
    unsigned char val=0;
    switch(bit_nbr){
        case 0:
            val=byte_u->b0;
            break;
        case 1:
            val=byte_u->b1;
            break;
        case 2:
            val=byte_u->b2;
            break;
        case 3:
            val=byte_u->b3;
            break;
        case 4:
            val=byte_u->b4;
            break;
        case 5:
            val=byte_u->b5;
            break;
        case 6:
            val=byte_u->b6;
            break;
        case 7:
            val=byte_u->b7;
            break;
    }
#ifdef __DEBUG
    assert(val==NOT_SET || val==SET);
#endif
    return val;
}

unsigned char *byte_union_get_byte(byte_union_t *byte_u)
{
#ifdef __DEBUG
    assert(byte_u!=NULL);
#endif
    unsigned char *ptb=&byte_u->byte;
#ifdef __DEBUG
    assert(ptb!=NULL);
#endif 
    return ptb;
}

const unsigned char *byte_union_get_byte_info(const byte_union_t *byte_u)
{
#ifdef __DEBUG
    assert(byte_u!=NULL);
#endif
    const unsigned char *ptb=&byte_u->byte;
#ifdef __DEBUG
    assert(ptb!=NULL);
#endif 
    return ptb;
}


void byte_union_set_byte(byte_union_t *byte_u,unsigned char val)
{
#ifdef __DEBUG
    assert(byte_u!=NULL);
#endif 
    unsigned char *ptb=byte_union_get_byte(byte_u);
#ifdef __DEBUG
    assert(ptb!=NULL);
#endif 
    *ptb=val;
}

void byte_union_set_bit(byte_union_t *byte_u, unsigned char state,unsigned char bit_nbr)
{
#ifdef __DEBUG
    assert(array!=NULL);
    assert(state==NOT_SET || state==SET);
    assert(bit_nbr<8);
#endif 
    switch(bit_nbr){
        case 0:
            byte_u->b0=state;
            break;
        case 1:
            byte_u->b1=state;
            break;
        case 2:
            byte_u->b2=state;
            break;
        case 3:
            byte_u->b3=state;
            break;
        case 4:
            byte_u->b4=state;
            break;
        case 5:
            byte_u->b5=state;
            break;
        case 6:
            byte_u->b6=state;
            break;
        case 7:
            byte_u->b7=state;
            break;
    }
}

void byte_union_initialize(byte_union_t *byte_u)
{
#ifdef __DEBUG
    assert(byte_u!=NULL);
#endif
    byte_union_set_byte(byte,0);
}