/* 
 * File:   music.h
 * Author: Michel
 *
 * Created on 16 février 2016, 18:20
 */

#ifndef MUSIC_SELECT_H
#define	MUSIC_SELECT_H

#include "byte_union.h"

typedef enum{
    time_up,
            time_chane_enable,
            time_change_disable,
            change_time,
            start
}music_names;

void music_select_initialize(byte_union_t *mus);

void music_select_change(byte_union_t *mus,music_names name);

void music_select_start(byte_union_t *mus);

void music_select_stop(byte_union_t *mus);

#endif	/* MUSIC_H */

