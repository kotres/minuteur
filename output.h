/* 
 * File:   output.h
 * Author: Michel
 *
 * Created on 16 f�vrier 2016, 17:26
 */

#ifndef OUTPUT_H
#define	OUTPUT_H

#include "byte_union.h"
#include "software_timer.h"
#include <xc.h>


typedef struct{
    byte_union_t buffer[6];
    unsigned char output_enable;
}output_t;


void output_initialize(output_t *output);

void output_update(output_t *output,byte_union_t buffer[]);

#endif	/* OUTPUT_H */

