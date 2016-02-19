#include "flag_array.h"
#include <assert.h>



int flag_array_valid(flag_array_t *flag_array)
{
    assert(f!=NULL);
    if(flag_array->flags_number>8)
        return 0;
    return 1;
}

void flag_array_set_flag(flag_array_t *flag_array,unsigned char state,unsigned char name)
{
#ifdef __DEBUG
    assert(flag_array!=NULL);
    assert(flag_array_valid(flag_array));
    assert(val==NOT_SET || val==SET);
    assert(name<8);
#endif
    byte_union_set_bit(&flag_array->flags,state,name);
#ifdef __DEBUG
    assert(flag_array_valid(flag_array));
#endif
}

void flag_array_initialise(flag_array_t *flag_array)
{
#ifdef __DEBUG
    assert(flag_array!=NULL);
#endif 
    byte_union_initialize(&flag_array->flags);
    flag_array->flags_number=0;
#ifdef __DEBUG
    assert(flag_valid(f));
#endif 
}

void flag_array_set_numbers(flag_array_t *flag_array,unsigned char nbr)
{
#ifdef __DEBUG
    assert(flag_array!=NULL);
    assert(nbr<=8);
#endif 
    flag_array->flags_number=nbr;
#ifdef __DEBUG
    assert(flag_valid(f));
#endif 
}