#include "flag.h"
#include <assert.h>


int flag_name_valid(flag_name name)
{
    if(name<0 || name>FLAG_NBR-1)
        return 0;
    return 1;
}


int flag_array_valid(flag_array *f)
{
    assert(f!=NULL);
    if(f->nbr>8)
        return 0;
    int i=0;
    for(i=0;i<7;i++){
        if(flag_name_valid(f->name[i])==0)
        return 0;
    }
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

