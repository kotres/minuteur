#include "instance.h"
#include <assert.h>

int instance_valid(instance_t *instance)
{
    if(instance->flags.no_flags==0)
        return 0;
    if(instance->flags.music_enable==SET&&instance->flags.segements_enable==NOT_SET)
        return 0;
    if(music_valid(&instance->music)==0)
        return 0;
    if(main_timer_valid(&instance->main_timer)==0)
        return 0;
    if(output_valid(&instance->output)==0)
        return 0;
    return 1;
}

void instance_init(instance_t *instance)
{
#ifdef __DEBUG
    assert(instance!=NULL);
#endif
    instance->flags.flag_byte=0;
    instance->flags.segements_enable=SET;
    music_init(&instance->music);
    main_timer_initialize(&instance->main_timer);
    main_timer_get_output_buffer(&instance->main_timer,instance->output_buffer);
    output_initialize(&instance->output);
#ifdef __DEBUG
    assert(instance_valid(instance)==1);
#endif
}

void instance_update(instance_t *instance)
{
#ifdef __DEBUG
    assert(instance!=NULL);
    assert(instance_valid(instance)==1);
#endif
    main_timer_update(&instance->main_timer);
    instance->flags.segements_enable=main_timer_get_segment_enable(&instance->main_timer);
    instance->flags.music_enable=main_timer_music_enable(&instance->main_timer);
    main_timer_get_output_buffer(&instance->main_timer,instance->output_buffer);
    output_update(&instance->output,instance->output_buffer,instance->flags.segements_enable);
    music_update(&instance->music,instance->flags.music_enable);
#ifdef __DEBUG
    assert(instance_valid(instance)==1);
#endif
}

void instance_loop(void)
{
    instance_t instance;
    instance_t *ptr_instance=&instance;
    instance_init(ptr_instance);
    while(1){
        instance_update(ptr_instance);
    }
}