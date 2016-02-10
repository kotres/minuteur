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

typedef enum{
    TRUE,
    FALSE
}flag_state;

typedef enum{
    output_enable,
    interrupt_enable,
    change_output,
    input_enable
}flag_name;

typedef struct{
    flag_state state;
    flag_name name;
}flag;

int flag_state_valid(flag_state state);

int flag_name_valid(flag_name name);

int flag_valid(flag *f);

void flag_set(flag *f,flag_state state,flag_name name);

void flag_initialise(flag *f);

#endif	/* FLAG_H */

