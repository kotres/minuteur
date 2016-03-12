#ifndef MENU_H
#define MENU_H

#include "input.h"
#include "byte_union.h"
#include "time_type.h"

typedef union{
	unsigned char flag_byte;
	struct{
		unsigned pause_status:1,menu_status:1,segments_enable:1,no_flags:5;
	};
}menu_flags_t;

typedef struct{
  menu_flags_t flags;
  byte_union_t points;
  time_type_t time_type_to_change;
  char deltaT;
  input_t input;
}menu_t;

int menu_valid(menu_t *menu);

void menu_initialize(menu_t *menu);

void menu_update(menu_t *menu);

void menu_update_points(menu_t *menu);

char *menu_get_deltaT(menu_t *menu);

unsigned char menu_get_pause_value(menu_t *menu);

unsigned char menu_get_segment_enable_value(menu_t *menu);

byte_union_t menu_get_points(menu_t *menu);

time_type_t* menu_get_time_to_change(menu_t *menu);

#endif
