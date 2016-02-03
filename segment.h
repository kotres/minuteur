/* 
 * File:   segment.h
 * Author: Michel
 *
 * Created on 3 février 2016, 15:07
 */

#ifndef SEGMENT_H
#define	SEGMENT_H
#define MAX_SEGMENT 3

enum sub_names{
    low,
    high
};

struct segment{
    char sub[2];
};


enum segment_names{
    second,
    minute,
    hour
};

void change_sub_value(struct segment *s,char val,enum sub_names sub);

char get_sub_value(const struct segment *s,enum sub_names sub);

void init_segment(struct segment *s);

void change_segment_value(struct segment *s,char val);

char get_segment_value(const struct segment *s);

#endif	/* SEGMENT_H */

