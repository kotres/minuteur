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

extern bit_array music_select;

void music_select_initialize(void);

void music_select_change(music_names name);

void music_select_start();

void music_select_stop();

#endif	/* MUSIC_H */

