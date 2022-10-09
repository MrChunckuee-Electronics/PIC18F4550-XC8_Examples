/*******************************************************************************
 *
 *          Lab01: Basic IO 
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC18F4550
 * Complier:        XC8 v2.36
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     
 *******************************************************************************
 * Rev.         Date            Comment
 *  v0.0.1      08/10/2022      - Creacion del firmware
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
#define BUTON1_pinState             PORTEbits.RE0
#define BUTON1_pinState_GetValue()  BUTON1_pinState

#define LED2_pinStatus              LATEbits.LATE1
#define LED2_pinStatus_SetHigh()    do { LED2_pinStatus = 1; } while(0)
#define LED2_pinStatus_SetLow()     do { LED2_pinStatus = 0; } while(0)
#define LED2_pinStatus_Toggle()     do { LED2_pinStatus = ~LED2_pinStatus; } while(0)

#define LED3_pinStatus              LATEbits.LATE2
#define LED3_pinStatus_SetHigh()    do { LED3_pinStatus = 1; } while(0)
#define LED3_pinStatus_SetLow()     do { LED3_pinStatus = 0; } while(0)
#define LED3_pinStatus_Toggle()     do { LED3_pinStatus = ~LED3_pinStatus; } while(0)

/******* V A R I A B L E S ****************************************************/
bool BUTON_Status;
uint8_t BUTON_Ticks;

/*********** P R O T O T Y P E S **********************************************/
void MCU_Initialize(void);
void IO_Task(void);

void main(void) {
    MCU_Initialize();
    LED3_pinStatus_SetHigh();
    while (1){
        IO_Task();
    }
    return;
}

void MCU_Initialize(void){
    // Config IO
    TRISE = 0b001;
    
    //Clear output E
    PORTE = 0b000;

    //Digital input
    ADCON1 = 0x0F;
    
    //Config OSC = 8MHz
    OSCCON = 0x72;
    
    //Clear variables
    BUTON_Ticks = 0;
    BUTON_Status = 0;
}

void IO_Task(void){
    // Read button status
    if(BUTON1_pinState_GetValue()){
        BUTON_Ticks++;
        if(BUTON_Ticks>20){
            BUTON_Ticks = 0;
            BUTON_Status ^= 1;
        }
        __delay_ms(10);
    }
    
    // Toggle LED depending BOTON_Status
    if(BUTON_Status){
        LED2_pinStatus_SetHigh();
    }
    else{
        LED2_pinStatus_SetLow();
    }
}
