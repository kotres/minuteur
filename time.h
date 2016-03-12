/* 
 * File:   time.h
 * Author: Michel
 *
 * Created on 3 f�vrier 2016, 11:04
 */

#ifndef TIME_H
#define	TIME_H
#include <stdio.h>
#include <stdlib.h>
#include "time_type.h"

/* time is a struct that contains time_types usualy arranged in increasing order*/

typedef struct{
   unsigned char time_second,time_minute,time_hour;
}time_t;

unsigned char* time_get_piece(time_t *t,time_type_t type);

/*time_set_piece:
  Sets the time_piece of the time struct named by the time_type type
  to the value of val
  Needs:
  -a valid time pointer
  -a valid value for the time_piece to be changed
  -a valid time_type
*/

void time_set_piece(time_t *t,unsigned char val,time_type_t type);

/*time_valid:
  Verifies weather a time structure is valid or not
  Needs:
  -a non null time pointer
  Returns:
  -1 if the time structure of the pointer is valid and 0 if not
*/

int time_valid(time_t *t);



/*time_initialize:
  initialises a time struct pointed by t to a valid  second/minute/hour type
  with all of the pieces initialised to 0
  Needs:
  -a non null time pointer
*/

void time_initialize(time_t *t);

void time_change_piece(time_t *t,char val,time_type_t type);

unsigned char time_is_zero(time_t *t);

unsigned char time_decrease(time_t *t);

#endif	/* TIME_H */

