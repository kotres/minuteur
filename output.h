/* 
 * File:   output.h
 * Author: Michel
 *
 * Created on 16 f�vrier 2016, 17:26
 */

#ifndef OUTPUT_H
#define	OUTPUT_H

#include "byte_union.h"
#include "hardware_config.h"
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

typedef union{
    unsigned char adress_byte;
    struct{
        unsigned a0:1,a1:1,a2:1,no_adress:5;
    };
}adress_t;

typedef struct{
    byte_union_t buffer[6];
    adress_t adress;
    unsigned short output_timer;
    unsigned char enable;
}output_t;

int output_valid(output_t *output);

void output_refresh_pins(output_t *output);

void output_initialize(output_t *output);

void output_update(output_t *output,byte_union_t buffer[],unsigned char output_enable);

#endif	/* OUTPUT_H */

