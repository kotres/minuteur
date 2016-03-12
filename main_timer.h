#ifndef MAIN_TIMER_H
#define MAIN_TIMER_H

#include "flag_array.h"
#include "byte_union.h"
#include "time.h"
#include "menu.h"

#define MUSIC_FLAG 0
#define SEGMENTS_FLAG 1

typedef union{
	unsigned char flag_byte;
	struct{
		unsigned music_flag:1,segments_flag:1,no_flags:6;
	};
}main_timer_flags_t;

typedef struct{
    time_t time;
    main_timer_flags_t flags;
    byte_union_t segments[6];
    menu_t menu;
}main_timer_t;

int main_timer_valid(main_timer_t *timer);

void main_timer_initialize(main_timer_t *timer);

void main_timer_update(main_timer_t *timer);

unsigned char main_timer_get_segment_enable(main_timer_t *timer);

unsigned char main_timer_music_enable(main_timer_t *timer);

void main_timer_fill_output_buffer(main_timer_t *timer);

byte_union_t* main_timer_get_output_buffer(main_timer_t *timer);

#endif
