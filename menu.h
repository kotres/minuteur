#ifndef MENU_H
#define MENU_H

#include "flag_array.h"
#include "input.h"
#include "points.h"
#include "time.h"

typedef struct{
  bit_array points;
  flag_array flags;
  time_type time_type_to_change;
  char deltaT;
  bit_array mus_sel;
  input_t input;
}menu_t;

void menu_init(menu_t *menu);

void menu_update(menu_t *menu);

char *menu_get_deltaT(menu_t *menu);

unsigned char *menu_get_music_select(menu_t *menu);

unsigned char menu_get_menu_status_value(menu_t *menu);

unsigned char menu_get_segment_enable_value(menu_t *menu);

unsigned char menu_get_points(menu_t *menu);
#endif
