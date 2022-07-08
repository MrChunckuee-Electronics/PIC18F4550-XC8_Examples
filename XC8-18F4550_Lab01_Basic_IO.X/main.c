/*******************************************************************************
 *
 *              Lab01: Basic IO 
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC18F4550
 * Complier:        XC8 v2.32
 * Company:         Industrias Alfatek
 * Author:          Pedro Sánchez Ramírez 
 * Description:
 *
 *******************************************************************************
 * Rev.         Date            Comment
 *  v0.0.1      08/07/2022      - Creacion del firmware
 ******************************************************************************/

#include <xc.h>
#include "device_config.h"

#define _XTAL_FREQ 8000000

#define LED1_pinStatus        LATBbits.LATB5
#define LED1_pinStatus_SetHigh()    do { LED1_pinStatus = 1; } while(0)
#define LED1_pinStatus_SetLow()     do { LED1_pinStatus = 0; } while(0)
#define LED1_pinStatus_Toggle()     do { LED1_pinStatus = ~LED1_pinStatus; } while(0)

#define BOTON1_pinState             PORTAbits.RA0
#define BOTON1_pinState_GetValue()  BOTON1_pinState

void MCU_Initialize(void);

void main(void) {
    MCU_Initialize();
    while (1){
        LED1_pinStatus_SetHigh();
    }
    return;
}

void MCU_Initialize(void){
    TRISA = 0b0000001;
    TRISD = 0x00;
    
    //Confif OSC
    OSCCONbits.SCS = 0b11;
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.IDLEN = 0;
    OSCCONbits.IOFS = 1;  
}
