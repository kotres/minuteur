/* 
 * File:   timer.h
 * Author: Michel
 *
 * Created on 10 février 2016, 14:31
 */

#ifndef TIMER_H
#define	TIMER_H

#include <stdio.h>
#include <stdlib.h>
#include <xc.h> 


typedef enum{
    button_timer,
    output_enable_timer,
    main_timer
}timer_name;

typedef struct{
  timer_name name;
  unsigned char *register;
  

void timer_reset(timer_name name);



#endif	/* TIMER_H */

