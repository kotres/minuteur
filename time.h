/* 
 * File:   time.h
 * Author: Michel
 *
 * Created on 3 février 2016, 11:04
 */

#ifndef TIME_H
#define	TIME_H
#include "segment.h"

struct time{
   struct segment segment[MAX_SEGMENT];
};

void change_segment_value(struct time *t,char high,char low,enum segment_names segment);
void time_init(struct time *t);

#endif	/* TIME_H */

