/* 
 * File:   music.h
 * Author: Michel
 *
 * Created on 12 mars 2016, 17:24
 */

#ifndef MUSIC_H
#define	MUSIC_H

#include <xc.h>

typedef struct{
    unsigned int milli;
}music_t;

int music_valid(music_t *music);

void music_init(music_t *music);

void music_update(music_t *music,unsigned char music_enable);

#endif	/* MUSIC_H */

