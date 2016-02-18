/* 
 * File:   instance.h
 * Author: Michel
 *
 * Created on 17 février 2016, 16:33
 */

#ifndef INSTANCE_H
#define	INSTANCE_H
#include "flag.h"
#include "bit_array.h"
#include "time.h"
#include "timers.h"
#include "music_select.h"
#include "points.h"
#include "input.h"

typedef struct{
    time t;
    bit_array flags;
    bit_array points;
    bit_array mus_select;
    unsigned char deltaT;
    time_type time_to_modify;
    
}instance;

void instance_initialize(instance *in);

void instance_update_input(instance *in);

void instance_update_menu(instance *in);

void instance_update_state(instance *in);

void instance_update_output(instance *in);


#endif	/* INSTANCE_H */

