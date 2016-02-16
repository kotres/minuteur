/* 
 * File:   flag.h
 * Author: Michel
 *
 * Created on 10 février 2016, 10:45
 */


#ifndef FLAG_H
#define	FLAG_H

#define FLAG_NBR 4

#include <stdio.h>
#include <stdlib.h>
#include "bit_array.h"



typedef struct{
    bit_array state;
    unsigned char name[8];
    unsigned char nbr;
}flag_array;



int flag_valid(flag_array *f,flag_name name);

int flag_array_valid(flag_array *f);

void flag_set(flag_array *f,bit_state state,flag_name name);

unsigned get_flag_state(flag_array *f,flag_name name);

void flag_array_initialise(flag_array *f);

#endif	/* FLAG_H */

