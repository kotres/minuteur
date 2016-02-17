/* 
 * File:   points.h
 * Author: Michel
 *
 * Created on 17 février 2016, 17:14
 */

#ifndef POINTS_H
#define	POINTS_H
#include "time_type.h"
#include "bit_array.h"

void points_initialize(bit_array *p);

void points_set(bit_array *p,unsigned char val);

void points_set_point(bit_array *p,unsigned char val,time_type type);

#endif	/* POINTS_H */

