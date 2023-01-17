/*
 * File:   TP1b.c
 * Author: thoma
 *
 * Created on 6 janvier 2023, 12:00
 */

#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#define _XTAL_FREQ 8000000


void horloge(void){
    //TMR0CS à 1 car on utilise l'horloge interne FOSC/4
    //On utilise le prescaler pour gérer la fréquence, on divise l'horloge, on prend 110 : 128
    // Pour flag, il faut mettre à 1 le Bit 2 : TMR0IF du registre INTCON
   while(INTCONbits.TMR0IF == 1){
            INTCONbits.TMR0IF = 0; //on redescend le flag
            TMR0 = 6; // on lui donne la nouvelle valeur d'initialisation. 
        }
        
    }

void main(void){
    
    TRISD &= 0xF0;      //TRISB = xxxx0000
    TRISB &= 0xF0;      //TRISB = xxxx0000
    // = 0x0; // Pour activer le PSA dans le registre OPTION REG
    OPTION_REGbits.nWPUEN=0;
    OPTION_REGbits.INTEDG=0;
    OPTION_REGbits.TMR0CS=0;
    OPTION_REGbits.TMR0SE=0;
    OPTION_REGbits.PSA=0;
    OPTION_REGbits.PS=0x02;     //110 pour 128, pour diviser la fréquence d'horloge 
    //OPTION_REG |= 0x02; // 0000 0010 
    
    TMR0 = 6; //valeur d'initialisation pour se raprocher à la valeur de départ de l'overflow
    

while(1){
        /* Code a executer dans une boucle infinie */
        LATD = 0x00; //En sortie
        
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD3 = 1;
        LATDbits.LATD4 = 0;
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 0;
        LATBbits.LATB2 = 0;
        LATBbits.LATB3 = 0;
        
        horloge();
        
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;
        LATDbits.LATD3 = 0;
        LATDbits.LATD4 = 1;
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 1;
        LATBbits.LATB3 = 1;

        horloge();

        }
 }