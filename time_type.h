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

typedef enum{
    second,
    minute,
    hour
}time_type;

int time_type_valid(time_type type);

#endif	/* TIME_TYPE_H */

