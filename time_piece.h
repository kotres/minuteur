/* 
 * File:   time_piece.h
 * Author: Michel
 *
 * Created on 4 février 2016, 05:09
 */

#ifndef TIME_PIECE_H
#define	TIME_PIECE_H
#include <stdio.h>
#include <stdlib.h>
#include "time_type.h"

typedef struct{
    time_type type;
    unsigned char value;
}time_piece;

unsigned char get_time_piece_value(const time_piece *tp);

int time_piece_valid(const time_piece *tp);

int time_piece_value_valid(unsigned char value);

void time_piece_define(time_piece *tp,unsigned char value,time_type type);

void time_piece_initalize(time_piece *tp);

void time_piece_define_second(time_piece *tp);

void time_piece_define_minute(time_piece *tp);

void time_piece_define_hour(time_piece *tp);

#endif	/* TIME_PIECE_H */

