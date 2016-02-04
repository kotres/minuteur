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


int time_piece_valid(const time_piece *tp);

void time_piece_set(time_piece *tp,unsigned char value,time_type type);

void time_piece_initalize(time_piece *tp);

void time_piece_set_hour(time_piece *tp,unsigned char val);

#endif	/* TIME_PIECE_H */

