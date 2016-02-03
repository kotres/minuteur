/* 
 * File:   segment.c
 * Author: Michel
 *
 * Created on 3 février 2016, 15:05
 */

#include <stdio.h>
#include <stdlib.h>
#include "segment.h"

void change_sub_value(struct segment *s,char val,enum sub_names sub)
{
    s->sub[sub]=val;
}

char get_sub_value(const struct segment *s,enum sub_names sub)
{
    return s->sub[sub];
}

void init_segment(struct segment *s)
{
    enum sub_names sub=low;
    change_sub_value(s,1,sub);
    sub=high;
    change_sub_value(s,1,sub);
}

void change_segment_value(struct segment *s,char val)
{
    enum sub_names sub=low;
    char lowval=val % 10;
    change_sub_value(s,lowval,sub);
    sub=high;
    if(val>=10){
        char hival=val - (val % 10);
        change_sub_value(s,hival,sub);
    }
    else
        change_sub_value(s,0,sub);
}

char get_segment_value(const struct segment *s)
{
    enum sub_names sub=low;
    char val=0;
    char lowv=0;
    char highv=0;
    lowv=get_sub_value(s,sub);
    sub=high;
    highv=get_sub_value(s,sub);
    val=lowv+10*highv;
    return val;
}
