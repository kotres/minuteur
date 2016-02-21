/* 
 * File:   bit_array.h
 * Author: Michel
 *
 * Created on 15 février 2016, 14:06
 */

#ifndef BYTE_UNION_H
#define	BYTE_UNION_H

#define NOT_SET 0
#define SET 1

#include <stdio.h>
#include <stdlib.h>

typedef union{
    unsigned char byte;
    struct{
        unsigned b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
    };
}byte_union_t;

unsigned char byte_union_get_bit_value(const byte_union_t *byte_u,unsigned char bit_nbr);

unsigned char *byte_union_get_byte(byte_union_t *byte_u);

const unsigned char *byte_union_get_byte_info(const byte_union_t *byte_u);

void byte_union_set_byte(byte_union_t *byte_u,unsigned char val);

void byte_union_set_bit(byte_union_t *byte_u, unsigned char state,unsigned char bit_nbr);

void byte_union_initialize(byte_union_t *byte_u);

#endif	/* BYTE_UNION_H */

