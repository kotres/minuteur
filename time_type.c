#include "time_type.h"
#include <assert.h>

int time_type_valid(time_type type)
{
    if(type<3)
        return 1;
    return 0;
}
