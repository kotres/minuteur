#include "output.h"
#include <assert.h>

#include "hardware_config.h"

int output_valid(output_t *output)
{
    assert(output!=NULL);
    if(output->buffer==NULL)
        return 0;
    if(output->enable!=NOT_SET&&output->enable!=SET)
        return 0;
    if(output->adress.no_adress!=0)
        return 0;
    return 1;
}

void output_refresh_pins(output_t *output)
{
#ifdef __DEBUG
    assert(output!=NULL);
    assert(output_valid(output));
#endif
    adress_t adr=output->adress;
    byte_union_t segments=output->buffer[adr.adress_byte];
    if(output->enable==NOT_SET){
        RC0=SET;
        RC1=SET;
        RC2=SET;
    }
    else{
        RC0=adr.a0;
        RC1=adr.a1;
        RC2=adr.a2;
    }
    RC7=segments.b0;
    RC6=segments.b1;
    RC3=segments.b2;
    RC4=segments.b3;
    RC5=segments.b7;
#ifdef __DEBUG
    assert(output_valid(output));
#endif
}

void output_initialize(output_t *output)
{
#ifdef __DEBUG
    assert(output!=NULL);
    assert(buffer!=NULL);
#endif
    TMR3IF=0;
    for(int i=0;i<6;i++){
        output->buffer[i].byte=0;
    }
    output->adress.adress_byte=0;
    output->enable=SET;
    output->output_timer=0;
    output_refresh_pins(output);
}

void output_update(output_t *output,byte_union_t buffer[],unsigned char output_enable)
{
    #ifdef __DEBUG
    assert(output!=NULL);
    assert(buffer!=NULL);
    assert(output_valid(output));
#endif
    for(int i=0;i<6;i++){
        output->buffer[i]=buffer[i];
    }
    if(TMR3IF==SET){
       TMR3IF=NOT_SET;
       if(output_enable==NOT_SET){
           output->output_timer++;
           if(output->output_timer>=4000){
               output->output_timer=0;
               output->enable=NOT_SET;
           }
       }
       else{
           output->enable=SET;
           output->output_timer=0;
       }
       output->adress.adress_byte++;
       output->adress.adress_byte=output->adress.adress_byte%6;
       output_refresh_pins(output);
    }
#ifdef __DEBUG
    assert(output_valid(output));
#endif
}
