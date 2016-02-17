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


int flag_name_valid(flag_name name);

void flag_set(bit_field *flag_field,flag_name name);

unsigned char get_flag_state(bit_field *flag_field,flag_name name);

void flag_array_initialise(bit_field flag_field);

#endif	/* FLAG_H */

