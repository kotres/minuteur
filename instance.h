/* 
 * File:   instance.h
 * Author: Michel
 *
 * Created on 17 f�vrier 2016, 16:33
 */

#ifndef INSTANCE_H
#define	INSTANCE_H
#include "flag_array.h"
#include "main_timer.h"
#include "software_timer.h"
#include "output.h"

typedef struct{
    main_timer_t main_timer;
    output_t output;
}instance_t;

void instance_init(instance_t *instance);

void instance_update(instance_t *instance);

void instance_loop(void);

#endif	/* INSTANCE_H */

