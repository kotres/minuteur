/* 
 * File:   debug_main.c
 * Author: Michel
 *
 * Created on 4 février 2016, 05:51
 */

#include <stdio.h>
#include <stdlib.h>
#include "time_piece.h"

/*
 * 
 */
int main(int argc, char** argv) {
    time_piece piece;
    time_piece *tp=&piece;
    time_piece_initalize(tp);
    time_piece_define_hour(tp);
    printf("%d",get_time_piece_value(tp));
    return (EXIT_SUCCESS);
}

