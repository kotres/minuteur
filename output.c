#include "output.h"
#include <assert.h>

#include "hardware_config.h"

int output_valid(output_t *output)
{
    return 1;
}

void output_refresh_pins(output_t *output)
{
#ifdef __DEBUG
    assert(output!=NULL);
    assert(output_valid(output));
#endif
    adress_t adr=output->adress;
    byte_union_t segments=output->buffer[adr];
    RC0=adr.a0;
    RC1=adr.a1;
    RC2=adr.a2;
}

void output_initialize(output_t *output,byte_union_t buffer[])
{
#ifdef __DEBUG
    assert(output!=NULL);
    assert(buffer!=NULL);
#endif
    output->buffer=buffer;
    output->adress.adress_byte=0;
}

void output_update(output_t *output,byte_union_t buffer[])
{
    
}
