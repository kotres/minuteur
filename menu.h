#ifndef MENU_H
#define MENU_H

#include "input.h"
#include "byte_union.h"
#include "flag_array.h"
#include "time_type.h"

typedef enum{
    pause_status,
    menu_status,
    segments_enable
}menu_flags;

typedef struct{
  flag_array_t status;
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
