#include "flag.h"
#include <assert.h>

int flag_state_valid(flag_state state)
{
    if(state!=TRUE&&state!=FALSE)
        return 0;
    return 1;
}

int flag_name_valid(flag_name name)
{
    if(name<0 || name>FLAG_NBR-1)
        return 0;
    return 1;
}

int flag_valid(flag *f)
{
    assert(f!=NULL);
    if(flag_state_valid(f->state)==0)
        return 0;
    if(flag_name_valid(f->name)==0)
        return 0;
    return 1;
}

void flag_set(flag *f,flag_state state,flag_name name)
{
#ifdef __DEBUG
    assert(f!=NULL);
    assert(flag_state_valid(state));
    assert(flag_name_valid(name));
#endif
    f->name=name;
    f->state=state;
#ifdef __DEBUG
    assert(flag_valid(f));
#endif
}

void flag_initialise(flag *f)
{
#ifdef __DEBUG
    assert(f!=NULL);
#endif 
    flag_set(*f,FALSE,output_enable);
#ifdef __DEBUG
    assert(flag_valid(f));
#endif 
}

