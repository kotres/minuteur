/* 
 * File:   instance.h
 * Author: Michel
 *
 * Created on 17 février 2016, 16:33
 */

#ifndef INSTANCE_H
#define	INSTANCE_H
#include "flag_array.h"
#include "byte_union.h"
#include "time.h"
#include "timers.h"
#include "music_select.h"
#include "points.h"
#include "input.h"

typedef struct{
    software_timer_t timer;
    output_t output;
}instance_t;

void instance_init(instance_t *instance);

void instance_update(instance_t *instance);

void instance_loop(void);

#endif	/* INSTANCE_H */

