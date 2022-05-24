///***************************************************************************

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

DigitalOut bLed4(A3); /* “Blinkdiode” */
DigitalOut bLed1(D3);
DigitalIn bInput(D8);

/***************************************************************************
*   Defines und Makros                                                  
***************************************************************************/
Ticker stSysTick;

static enum{
    enOff,
    enShort,
    enLongL,
    enLongR,
    
    
    }bZustand= enOff;

/***************************************************************************
*   Variablen
***************************************************************************/
byte bLocalFoo;
volatile char bStandby;
byte bBlinkState;
int i=0;
int j=5;
/***************************************************************************
*   lokale Funktionen
***************************************************************************/
void vTimer(){
    bStandby = 1;
    }
void vTaste(){
  int tasteLang=10;

  if(pinSW2 == 1){
      tasteLang--;
      if(tasteLang >0){    
      bZustand = enLongL;
        tasteLang = 10;
        }
      else if(tasteLang==0){
       bZustand = enShort;
       Green1=!Green1;
       }  
       }
   else if(pinSW5 == 1){
       
       bZustand = enLongR;    
      } 
    else{
            Red1=!Red1;
             bZustand = enOff;

       }   
       
  
  
  }  

void vBlink()
{
    int bBlink = 10;

    switch(bZustand) {
        case enOff:
            bLedBus=0x00;

            break;
        case enLongL:
            bLedBus=0x00;

            bLedBus[i]=!bLedBus[i+1];
            i++;

            if(i>3) {

                i=0;
                bLedBus=7;

            }
          

            break;
        case enLongR:
            bLedBus=0x00;
            bLedBus[j]=!bLedBus[j];
            j--;

            if(j<2) {

                j=5;
                bLedBus=120;

            }

            break;
    
            case enShort:
            bLedBus=255;
            bBlink--;
            if(bBlink==0){
                bZustand=enOff;
            }
            break;
}
}

int main( void )
{
    byte bBlinkTime = 15;
    stSysTick.attach_us(&vTimer, 20000); /* Background-APP initialisieren */
    while(1) { /* endless loop */
    
        vTaste(); /* APP 1 */
        bBlinkTime--;
        if(bBlinkTime==0){
        vBlink(); /* APP 2 */
        bBlinkTime = 15;
        }
        while(bStandby == 0); /* Standby-Zeit */
        bStandby = 0;
    }
}
