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
    ignore_button,
    menu_active,
}flag_name;

typedef struct{
  bit_field flags;
  unsigned char flags_nuber;
}flag_array;


//int flag_name_valid(flag_name name);

void flag_set(array_array *flag_field,unsigned char val,unsigned char name);

unsigned char get_flag_state(flag_array *flag_field,unsigned char name);

void flag_array_initialise(flag_array *flag_field);

#endif	/* FLAG_H */

