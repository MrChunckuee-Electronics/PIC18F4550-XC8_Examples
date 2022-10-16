/* 
 * File:   main.h
 * Author: MrChunckuee
 *
 * Created on 9 de octubre de 2022, 11:00 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

/************ I N C L U D E S *************************************************/
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <stdint.h>
#include <stdbool.h>
#include "mcu.h"
#include "adc.h"
    
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


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

