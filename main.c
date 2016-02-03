/* 
 * File:   main.c
 * Author: Michel
 *
 * Created on 7 novembre 2015, 17:58
 */

 #include <xc.h> 
#include "time.h"
#define _XTAL_FREQ 500000
 
 // CONFIG1 
 #pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin) 
 #pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled) 
 #pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled) 
 #pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR) 
 #pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled) 
 #pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled) 
 #pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin) 
 
 // CONFIG2 
 #pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off) 
 #pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset) 
 #pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.) 
 #pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled) 
 #pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming) 

unsigned char time[6]={0,0,0,0,0,0};


void afficher()
{
    LATC=time[0];
    LATCbits.LATC5=0;
    LATCbits.LATC4=0;
    LATAbits.LATA0=0;
    __delay_us(100);
    
    LATC=time[1];
    LATCbits.LATC5=0;
    LATCbits.LATC4=0;
    LATAbits.LATA0=1;
    __delay_us(100);
    
    LATC=time[2];
    LATCbits.LATC5=0;
    LATCbits.LATC4=1;
    LATAbits.LATA0=1;
    __delay_us(100);
    
    LATC=time[3];
    LATCbits.LATC5=0;
    LATCbits.LATC4=1;
    LATAbits.LATA0=0;
    __delay_us(100);
    
    LATC=time[4];
    LATCbits.LATC5=1;
    LATCbits.LATC4=1;
    LATAbits.LATA0=0;
    __delay_us(100);
    
    LATC=time[5];
    LATCbits.LATC5=1;
    LATCbits.LATC4=1;
    LATAbits.LATA0=1;
    __delay_us(100);

}

int timeIsNull(){
    int i=0;
    for(i=0;i<6;i++){
        if(time[0]!=0){
        return 0;
        }
    }
    return 1;
}

int removeSecond(){
    int carry=0;
    if(time[0]!=0){
        time[0]--;
    }
    else
    {
        time[0]=9;
        if(time[1]!=0){
            time[1]--;
        }
        else
        {
            time[1]=5;
            carry=1;
        }
    }
    return carry;
}

int removeMinute(int carry){
    if(carry!=0){
        if(time[2]!=0){
            time[2]--;
            carry=0;
        }
        else
        {
            time[2]=9;
            if(time[3]!=0){
                time[3]--;
                carry=0;
            }
            else
            {
                time[3]=5;
                carry=1;
            }
        }
    }
    return carry;
}

void removeHour(int carry){
    if(time[4]!=0){
        time[4]--;
    }
    else
    {
        time[4]=9;
        if(time[5]!=0){
            time[5]--;
        }
    }
}


void removeTime(){
    if (timeIsNull()==0){
        int carry=removeSecond();
        if(carry!=0){
            carry=removeMinute(carry);
            if(carry!=0){
                removeHour(carry);
            }
        }
    }
}
 
 main() 
 { 
     TRISC = 0x00;               // Port C all outputs 
     OPTION_REG=0b00000111;
     LATC = 0xb00111111;  
     TRISA=0b00111100;
     time[5]=4;//a enlever apres
     while (1) 
     { 
         if(TMR0IF==1)
         {
             TMR0IF=0;
             removeTime();
             afficher();
         } 
     } 
 
     return(0); 
 } 