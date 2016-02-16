/* 
 * File:   flag.h
 * Author: Michel
 *
 * Created on 10 février 2016, 10:45
 */


#ifndef FLAG_H
#define	FLAG_H

#define FLAG_NBR 3

#include <stdio.h>
#include <stdlib.h>
#include "bit_array.h"

typedef enum{
    segments_enable,
    button_pressed,
    time_changeable,
    ignore_button
}flag_name;

extern bit_array flags;


int flag_name_valid(flag_name name);

void flag_set(flag_name name);

unsigned get_flag_state(flag_name name);

void flag_array_initialise(void);

#endif	/* FLAG_H */

