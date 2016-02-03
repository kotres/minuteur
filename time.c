#include "time.h"


struct segment* get_segment(struct time *t,enum segment_names segment)
{
    return &t->segment[segment];
}

const struct segment* get_segment_info(const struct time *t,enum segment_names segment)
{
    return &t->segment[segment];
}

void time_init(struct time *t)
{
    int i=0;
    for(i=0;i<MAX_SEGMENT-1;i++){
      struct segment* s=0;
      s=get_segment(*t,i);
      init_segment(s);
    }
}


char increase_second_or_minute(const struct time *t,char val,enum segment_names segment)
{
    int carry=0;
    char segment_val=0;
    struct segment *s=get_segment(t,segment);
    segment_val=get_segment_value(s);
    segment_val+=val;
    while(segment_val>60){
        segment_val-=60;
        carry++;
    }
    change_segment_value(s,segment_val);
    return carry;
}


char increase_hour(const struct time *t,char val)
{
    enum segment_names h=hour;
    struct segment *s=get_segment(t,h);
    int carry=0;
    char segment_val=0;
    segment_val=get_segment_value(s);
    segment_val+=val;
    while(segment_val>12){
        segment_val-=12;
        carry++;
    }
    change_segment_value(s,segment_val);
    return carry;
}