/* 
 * File:   time.h
 * Author: Michel
 *
 * Created on 3 février 2016, 11:04
 */

#ifndef TIME_H
#define	TIME_H
#define MAX_TIME_INDEX 2
#include <stdio.h>
#include <stdlib.h>
#include "time_piece.h"
#include "time_type.h"

/* time is a struct that contains time_types usualy arranged in increasing order*/

typedef struct{
    time_piece piece[MAX_TIME_INDEX];
}time;


time_piece* get_time_piece(time *t,time_type type);

const time_piece* get_time_piece_info(const time *t,time_type type);

void time_set_piece(time *t,unsigned char val,time_type type);

int time_valid(const time *t);

unsigned char time_get_value(const time *t,time_type type);

void time_initialize(time *t);

#endif	/* TIME_H */

