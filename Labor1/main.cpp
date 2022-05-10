//***************************************************************************

//Description  : MPRO - Labor 1
//Revision List:
//  --------------------------------------------------------------------------
//  Date     | Author          | Change
// --------------------------------------------------------------------------
//  10.05.22 | Gruppe6.2 Markus Stein,...    | Ersterstellung
// --------------------------------------------------------------------------
  
//****************************************************************************
#include "mbed.h"
#include "cdef.h"

/* Vereinbarungen zu den Tasteneingängen */
DigitalIn   pinSW1(D8);
DigitalIn   pinSW2(D9);
DigitalIn   pinSW3(D10);
DigitalIn   pinSW4(D11);
DigitalIn   pinSW5(D12);



/* Ausgänge als "BUS" konfigurieren */

BusOut      bLedBus(A3,A4,D2, D5, D4, D3); 
BusOut      bLedBus2(D3,D4,D5,D2,A4,A3);
/* Ausgänge als Einzelleitung festlegen */
DigitalOut  Red1(A3);
DigitalOut  Yellow1(A4);
DigitalOut  Green1(D2);
DigitalOut  Yellow2(D5);
DigitalOut  Green2(D4);
DigitalOut  Red2(D3);






/***************************************************************************
*   Defines und Makros                                                  
***************************************************************************/



/***************************************************************************
*   Variablen
***************************************************************************/
byte bLocalFoo;
float n=0.3;
float iLeds = 0.0;
float rLedPwm = 0.05;

/***************************************************************************
*   lokale Funktionen
***************************************************************************/


void POR(float n) {
   
   bLedBus=255;
    wait(n);
    bLedBus=0;
    wait(n);
  
}
 void fSW2(float n) { //forward
    for(int i=0; i<6; i++) {
        bLedBus=0x01;
        bLedBus=bLedBus<<i;
        wait(n);
    }
    bLedBus=0x00;
}
 void bSW2(float n) { //backward
    for(int i=0; i<6; i++) {
        bLedBus2=0x01;
        bLedBus2=bLedBus2<<i;
        wait(n);
    }
    bLedBus=0x00;
}
void SW3(float n) {
             while(pinSW3 == 1){
                Red1 = !Red1;
                wait(n);
                Yellow1 = !Yellow1;
                wait(n);
                Green1 = !Green1;
                wait(n);
                Yellow2 = !Yellow2;
                wait(n);
                Green2 = !Green2;
                wait(n);
                Red2 = !Red2;
                wait(n);
                Red2 = !Red2;
                wait(n);
                Green2 = !Green2;
                wait(n);
                Yellow2 = !Yellow2;
                wait(n);
                Green1 = !Green1;
                wait(n);
                Yellow1 = !Yellow1;
                wait(n);
                Red1 = !Red1;
                wait(n);
    }}
    

int main()
{
    while(1) {
    
        if(pinSW5 == 1) {
         n=2;

        } 
        if(pinSW5 == 0){
         n=0.3;   
        }


        if(pinSW2 == 1 && pinSW1 == 1) {
            fSW2(n);

        }
        else if(pinSW2 == 1 && pinSW1 == 0){
             bSW2(n);
            
            }

        if(pinSW3 == 1) {
            SW3(n);
}

        
        POR(n);
           


    }


    

}
