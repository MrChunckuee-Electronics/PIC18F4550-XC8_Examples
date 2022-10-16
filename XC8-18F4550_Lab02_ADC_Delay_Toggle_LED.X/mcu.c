/*
 * File:   mcu.c
 * Author: mrchunckuee
 *
 * Created on 9 de octubre de 2022, 11:06 PM
 */

/************ I N C L U D E S *************************************************/
#include "main.h"

/******* V A R I A B L E S ****************************************************/
bool BUTON_Status;
uint8_t BUTON_Ticks;
uint16_t adc_Result;

void MCU_Initialize(void){
    // Config IO
    TRISA = 0x01;
    TRISE = 0b001;
    
    //Clear outputs
    LATA = 0x00;
    LATE = 0b000;
    PORTA = 0x00;
    PORTE = 0b000;

    // Config ADC
    ADC_Initialize(cofigurationADCON1_PCFG_A0); // Use AN0
    
    //Config OSC = 8MHz
    OSCCON = 0x72;
    
    //Clear variables
    BUTON_Ticks = 0;
    BUTON_Status = 0;
    adc_Result = 0;
}

void Delay_ms(uint16_t miliseconds){
    unsigned int j;
    for(j=0; j<miliseconds; j++){
        __delay_ms(1);
    }
}

void IO_Task(void){
    //Read ADC
    adc_Result = ADC_GetSingleConversion(channel_AN0_GetValue()) * 2;
    Delay_ms(100);
    
    // Toggle LED 
    Delay_ms(adc_Result + 1 ); 
    LED2_pinStatus_Toggle();
    
    // On-Off LED depending ADC value
    if(adc_Result < 512)
        LED3_pinStatus_SetHigh();
    else 
        LED3_pinStatus_SetLow();
    
}
