#ifndef MENU_H
#define MENU_H

#include "flags.h"
#include "input.h"
#include "points.h"

typedef struct{
  flag_array points;
  flag_array flags;
}menu_t

void menu_update(menu_t *menu,input_t *input);

unsigned char menu_get_points(menu_t *menu);

#endif
