/* 
 * File:   bit_array.h
 * Author: Michel
 *
 * Created on 15 février 2016, 14:06
 */

#ifndef BIT_ARRAY_H
#define	BIT_ARRAY_H

#define NOT_SET 0
#define SET 1

#include <stdio.h>
#include <stdlib.h>

typedef union{
    unsigned char byte;
    struct{
        unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
    };
}bit_array;

unsigned char bit_array_get_bit_value(bit_array *array,unsigned char bit_nbr);

unsigned char *bit_array_get_value(bit_array *array);

const unsigned char *bit_array_get_value_info(bit_array *array);

void bit_array_set_value(bit_array *array,unsigned char val);

void bit_array_set_bit(bit_array *array, unsigned char state,unsigned char bit_nbr);

void bit_array_initialize(bit_array *array);

#endif	/* BIT_ARRAY_H */

