#include "bit_array.h"
#include <assert.h>

unsigned char *bit_array_get_bit_value(bit_array *array,unsigned char bit_nbr)
{
#ifdef __DEBUG
    assert(array!=NULL);
    assert(bit_nbr<8);
#endif
    unsigned char val=0;
    switch(bit_nbr){
        case 0:
            val=array->b0;
            break;
        case 1:
            val=array->b1;
            break;
        case 2:
            val=array->b2;
            break;
        case 3:
            val=array->b3;
            break;
        case 4:
            val=array->b4;
            break;
        case 5:
            val=array->b5;
            break;
        case 6:
            val=array->b6;
            break;
        case 7:
            val=array->b7;
            break;
    }
#ifdef __DEBUG
    assert(val==NOT_SET || val==SET);
#endif
    return val;
}

unsigned char *bit_array_get_value(bit_array *array)
{
#ifdef __DEBUG
    assert(array!=NULL);
#endif
    return &array->byte;
}

const unsigned char *bit_array_get_value_info(bit_array *array)
{
#ifdef __DEBUG
    assert(array!=NULL);
#endif
    return &array->byte;
}

void bit_array_set_value(bit_array *array,unsigned char val)
{
#ifdef __DEBUG
    assert(array!=NULL);
#endif 
    unsigned char *ptval=bit_array_get_value(array);
    *ptval=val;
}

void bit_array_set_bit(bit_array *array, unsigned char state,unsigned char bit_nbr)
{
#ifdef __DEBUG
    assert(array!=NULL);
    assert(state==NOT_SET || state==SET);
    assert(bit_nbr<8);
#endif 
    switch(bit_nbr){
        case 0:
            array->b0=state;
            break;
        case 1:
            array->b1=state;
            break;
        case 2:
            array->b2=state;
            break;
        case 3:
            array->b3=state;
            break;
        case 4:
            array->b4=state;
            break;
        case 5:
            array->b5=state;
            break;
        case 6:
            array->b6=state;
            break;
        case 7:
            array->b7=state;
            break;
    }
}

void bit_array_initialize(bit_array *array)
{
#ifdef __DEBUG
    assert(array!=NULL);
#endif
    bit_array_set_value(array,0);
}