#include "flag_array.h"
#include <assert.h>



int flag_array_valid(flag_array_t *flag_array)
{
    assert(f!=NULL);
    if(flag_array->flags_number>8)
        return 0;
    return 1;
}

void flag_set(flag *f,flag_state state,flag_name name)
{
#ifdef __DEBUG
    assert(f!=NULL);
    assert(flag_name_valid(name));
#endif
    
#ifdef __DEBUG
    assert(flag_array_valid(f));
#endif
}

void flag_initialise(flag *f)
{
#ifdef __DEBUG
    assert(f!=NULL);
#endif 
    flag_set(*f,not_set,output_enable);
#ifdef __DEBUG
    assert(flag_valid(f));
#endif 
}

