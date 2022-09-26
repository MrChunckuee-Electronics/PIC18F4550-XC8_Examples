/*******************************************************************************
 *
 *              Lab01: Basic IO 
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC12F675
 * Complier:        XC8 v2.36
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     
 *******************************************************************************
 * Rev.         Date            Comment
 *  v0.0.1      26/09/2022      - Creacion del firmware
 ******************************************************************************/

/************ I N C L U D E S *************************************************/
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <stdint.h>
#include <stdbool.h>
#include "device_config.h"

/********* G E N E R A L   D E F I N I T I O N S ******************************/
#define _XTAL_FREQ 8000000

/*********P O R T   D E F I N I T I O N S *************************************/
#define LED1_pinStatus        LATEbits.LATE0
#define LED1_pinStatus_SetHigh()    do { LED1_pinStatus = 1; } while(0)
#define LED1_pinStatus_SetLow()     do { LED1_pinStatus = 0; } while(0)
#define LED1_pinStatus_Toggle()     do { LED1_pinStatus = ~LED1_pinStatus; } while(0)
#define BUTON1_pinState             PORTAbits.RA0
#define BUTON1_pinState_GetValue()  BUTON1_pinState

/******* V A R I A B L E S ****************************************************/
bool BUTON_Status;
uint8_t BUTON_Ticks;

/*********** P R O T O T Y P E S **********************************************/
void MCU_Initialize(void);
void IO_Task(void);

void main(void) {
    MCU_Initialize();
    while (1){
        IO_Task();
    }
    return;
}

void MCU_Initialize(void){
    // Config IO
    TRISE = 0b001;
    PORTE = 0b000;
    
    //Confif OSC
    OSCCONbits.SCS = 0b11;
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.IDLEN = 0;
    OSCCONbits.IOFS = 1;  
    
    BUTON_Status = 0;
    BUTON_Ticks = 0;
}

void IO_Task(void){
    // Read button status
    while(BUTON1_pinState_GetValue()){
        BUTON_Ticks++;
        if(BUTON_Ticks>20){
            BUTON_Ticks = 0;
            BUTON_Status^=1;
        }
        __delay_ms(10);
    }
    
    // Toggle LED depending BOTON_Status
    if(BUTON_Status){
        LED1_pinStatus_SetHigh();
    }
    else{
        LED1_pinStatus_SetLow();
    }
}
