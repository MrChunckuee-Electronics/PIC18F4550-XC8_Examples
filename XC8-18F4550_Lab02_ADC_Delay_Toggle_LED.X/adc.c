/*
 * File:   adc.c
 * Author: mrchu
 *
 * Created on 9 de octubre de 2022, 11:10 PM
 */

/************ I N C L U D E S *************************************************/
#include "main.h"

void ADC_Initialize(uint8_t PortConfig){
    //Configuracion del ADC
    ADCON1bits.VCFG0 = 0;   // Voltage Reference VDD
    ADCON1bits.VCFG1 = 0;   // Voltage Reference VSS
    ADCON1bits.PCFG = PortConfig;   // A/D Port Configuration Control bits
    ADCON2bits.ADFM = 1;     // Result Format justified 
    ADCON2bits.ADCS  = 0b100; // FOSC/4 Conversion Clock 
    ADCON2bits.ACQT  = 0b010; // 4 TAD - Acquisition Time
    ADC_Start();
}

void ADC_Start(void){
    ADCON0bits.ADON = 1;//Turn ADC on
}

void ADC_Close(void){
    ADCON0bits.ADON = 0;//Turn ADC off
}

uint16_t ADC_GetSingleConversion(uint8_t Channel){
    uint16_t RESULT_ADC = 0;
    ADCON0bits.CHS  = Channel; 
    ADCON0bits.GO = 1;  //Start ADC
    while(ADCON0bits.GO);
    RESULT_ADC = (uint16_t)((ADRESH << 8) | ADRESL);
    return (RESULT_ADC);//Return ADC value
}
