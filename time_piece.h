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

/* time_piece is a division of time containing its type and its value
 */

typedef struct{
    time_type type;
    unsigned char value;
}time_piece;

/* time_piece_valid:
   Verifies weather a time_piece is valid or not.For a time_piece to be valid, its time_type must be within
   the enum, its value must be less than 60 for a second or minute type, its value must be less
   than 13 for an hour type
   Needs: 
   -an initialised const time_piece pointer
   Gives: 
   -1 if the time_piece is valid and 0 if not
*/

int time_piece_valid(const time_piece *tp);

/* time_piece_set:
   Sets a time_piece to the time_type and value given to the function. the type and value need to be valid.
   Needs:
   -an initialised  time_piece pointer for the time_piece to be set
   -an unsigned char for the time value that is valid for the time_type
   -a valid time_type
*/

void time_piece_set(time_piece *tp,unsigned char value,time_type type);

/*time_piece_initialize:
  initialises the time_piece given to it via pointer to a valid  second type with 0 value
  Needs:
  -an initialised time_piece pointer of the time_piece to be initialised
*/

void time_piece_initalize(time_piece *tp);

/*time_piece_set_hour:
  sets a time piece to a valid hour
  Needs:
  -an initialised time_piece pointer
  -an unsigned char less than 13
*/

void time_piece_set_hour(time_piece *tp,unsigned char val);

#endif	/* TIME_PIECE_H */

