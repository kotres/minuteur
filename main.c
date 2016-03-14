/* 
 * File:   main.c
 * Author: Michel
 *
 * Created on 7 novembre 2015, 17:58
 */

#include <xc.h> 
#define _XTAL_FREQ 32768
#include "hardware_config.h"

#include "instance.h"

 main() 
 { 
     hardware_config_init();
     instance_loop();
     return(0); 
 } 