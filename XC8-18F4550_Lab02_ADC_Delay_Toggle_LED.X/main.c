/*******************************************************************************
 *
 *          Lab02: Uso del ADC - Cambio de estado de LED
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC18F4550
 * Complier:        XC8 v2.36
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Uso basico del ADC, para cambio de estado de un LED con retardo
 *                  de tiempo controlado desde un potenciometro.
 *******************************************************************************
 * Rev.         Date            Comment
 *  v0.0.1      10/10/2022      - Creacion del firmware
 ******************************************************************************/

/************ I N C L U D E S *************************************************/
#include "main.h"
#include "device_config.h"

void main(void) {
    MCU_Initialize();
    while (1){
        IO_Task();
    }
    return;
}


