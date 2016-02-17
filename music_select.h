/* 
 * File:   music.h
 * Author: Michel
 *
 * Created on 16 février 2016, 18:20
 */

#ifndef MUSIC_SELECT_H
#define	MUSIC_SELECT_H

#include "bit_array.h"

typedef enum{
    time_up,
            time_chane_enable,
            time_change_disable,
            change_time,
            start
}music_names;


void music_select_initialize(bit_array *mus);

void music_select_change(bit_array *mus,music_names name);

void music_select_start(bit_array *mus);

void music_select_stop(bit_array *mus);

#endif	/* MUSIC_H */

