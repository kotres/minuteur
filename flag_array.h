/* 
 * File:   flag.h
 * Author: Michel
 *
 * Created on 10 février 2016, 10:45
 */


#ifndef FLAG_H
#define	FLAG_H


#include <stdio.h>
#include <stdlib.h>
#include "byte_union.h"


typedef struct{
  byte_union_t flags;
  unsigned char flags_number;
}flag_array_t;


//int flag_name_valid(flag_name name);

void flag_array_set_flag(flag_array_t *flag_array,unsigned char val,unsigned char name);

unsigned char flag_array_get_flag_state(flag_array_t *flag_array,unsigned char name);

void flag_array_initialise(flag_array_t *flag_array);

int flag_array_valid(flag_array_t *flag_array);

#endif	/* FLAG_H */

