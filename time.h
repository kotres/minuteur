/* 
 * File:   time.h
 * Author: Michel
 *
 * Created on 3 février 2016, 11:04
 */

#ifndef TIME_H
#define	TIME_H
#define LOW 0
#define HIGH 1
#include <stdio.h>
#include <stdlib.h>
#include "time_type.h"

/* time is a struct that contains time_types usualy arranged in increasing order*/

typedef struct{
   unsigned char second,minute,hour;
}time;


unsigned char get_time_piece_value(time *t,time_type type);


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

int time_valid(time *t);



/*time_initialize:
  initialises a time struct pointed by t to a valid  second/minute/hour type
  with all of the pieces initialised to 0
  Needs:
  -a non null time pointer
*/

void time_initialize(time *t);

unsigned char time_change_piece(time *t,char val,time_type type);

unsigned char time_is_zero(time *t);

#endif	/* TIME_H */

