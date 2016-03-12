/* 
 * File:   instance.h
 * Author: Michel
 *
 * Created on 17 fevrier 2016, 16:33
 */

#ifndef INSTANCE_H
#define	INSTANCE_H
#include "flag_array.h"
#include "main_timer.h"
#include "output.h"
#include "music.h"

typedef union{
    unsigned char flag_byte;
    struct{
        unsigned music_enable:1,segements_enable:1,no_flags:6;
    };
}instance_flags_t;

typedef struct{
    instance_flags_t flags;
    main_timer_t main_timer;
    output_t output;
    music_t music;
}instance_t;

void instance_init(instance_t *instance);

void instance_update(instance_t *instance);

void instance_loop(void);

#endif	/* INSTANCE_H */

