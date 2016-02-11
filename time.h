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

/*get_time_piece:
  returns a pointer of the time_piece named by the time_type given to
  the function
  Needs:
  -a valid time pointer
  -a valid time_type
  Returns:
  a valid time_piece pointer
*/

time_piece* get_time_piece(time *t,time_type type);

/*get_time_piece_info:
  returns a const pointer of the time_piece named by the time_type given
  to the function
  Needs:
  -a valid const time pointer
  -a valid time_type
  Returns:
  a valid const time_piece pointer
*/

const time_piece* get_time_piece_info(const time *t,time_type type);

/*time_set_piece:
  Sets the time_piece of the time struct named by the time_type type
  to the value of val
  Needs:
  -a valid time pointer
  -a valid value fo the time_piece to be changed
  -a valid time_type
*/

void time_set_piece(time *t,unsigned char val,time_type type);

/*time_valid:
  Verifies weather a time structure is valid or not
  Needs:
  -a non null time pointer
  Returns:
  -1 if the time structure of the pointer is valid and 0 if not
*/

int time_valid(const time *t);

/*time_get_piece_value_info:
  gives the value of a time_piece of the time struct.
  Needs:
  -a valid const time pointer
  -a valid time_type
  Returns:
  -an unsigned char corresponding to the valid time_piece value
*/ 

unsigned char time_get_piece_value_info(const time *t,time_type type);

/*time_initialize:
  initialises a time struct pointed by t to a valid  second/minute/hour type
  with all of the pieces initialised to 0
  Needs:
  -a non null time pointer
*/

void time_initialize(time *t);

#endif	/* TIME_H */

