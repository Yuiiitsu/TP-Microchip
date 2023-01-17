#include "configbits.h" // Bits de configuration
#include <xc.h>         // Definition des registres specifiques au uC
#define _XTAL_FREQ 8000000
/* 
 * D1 : PORTD0
 * D2 : PORTD1
 * D3 : PORTD2
 * D4 : PORTD3
 * D5 : PORTB4
 * D6 : PORTB5
 * D7 : PORTB6
 * D8 : PORTB7

*/
    
void main(void) {
    
    TRISD &= 0xF0;      //TRISB = xxxx0000
    TRISB &= 0xF0;      //TRISB = xxxx0000
           
    while(1) {
        //Premier cas
        //Manipulation des bits de D
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;
        LATDbits.LATD3 = 0;
        
       //Manipulation des bits de B        
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 1;
        LATBbits.LATB2 = 1;
        LATBbits.LATB3 = 1;
        __delay_ms(500);
        
        //Manipulation des bits de D
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD3 = 1;
        //Manipulation des bits de B
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 0;
        LATBbits.LATB2 = 0;
        LATBbits.LATB3 = 0;
        __delay_ms(500);
        
        //06.01.23 11H57 ça fonctionne
}
}
