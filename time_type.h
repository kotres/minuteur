/* 
 * File:   time_type.h
 * Author: Michel
 *
 * Created on 4 février 2016, 05:02
 */

#ifndef TIME_TYPE_H
#define	TIME_TYPE_H
#include <stdio.h>
#include <stdlib.h>

/* time_type contains the names of divisions of time.
   We could add day and month if needed*/

typedef enum{
    second,
    minute,
    hour
}time_type_t;

/* time_type_valid:
   Checks wether the time type it is given is valid or not
   Needs:
   -time_type
   Gives:
   1 if the time_type is within the enum and 0 if not
*/

int time_type_valid(time_type_t type);

#endif	/* TIME_TYPE_H */

