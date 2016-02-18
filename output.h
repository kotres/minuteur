/* 
 * File:   output.h
 * Author: Michel
 *
 * Created on 16 février 2016, 17:26
 */

#ifndef OUTPUT_H
#define	OUTPUT_H

#include "byte_union.h"

typedef enum{
            second_low,
            second_high,
            minute_low,
            minute_high,
            hour_low,
            hour_high,
            points_and_enable,
            music         
}output_adress;

extern volatile bit_array *latA,*latB;

typedef struct{
    unsigned char buffer[8];
    unsigned char portA,portB;
    flag_array change_flags;
}output_t;

void output_transfer_buffer_to_port(void);

void output_initialize(output_t *output);

void output_value_to_adress(unsigned char val,output_adress adr);

void output_refresh(void);

#endif	/* OUTPUT_H */

