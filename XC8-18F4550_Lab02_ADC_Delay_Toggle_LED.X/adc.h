/* 
 * File:   adc.h
 * Author: mrchu
 *
 * Created on 9 de octubre de 2022, 11:10 PM
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
   
/*********** A N A L O G   P O R T   D E F I N E S ***************************/
// PCFG3:PCFG0: A/D Port Configuration Control bits
#define cofigurationADCON1_PCFG_A0_to_A12   0b0000
#define cofigurationADCON1_PCFG_A0_to_A1    0b1101
#define cofigurationADCON1_PCFG_A0          0b1110
    
//  Analog Channel    
#define channel_AN0_GetValue()     0b0000
#define channel_AN1_GetValue()     0b0001
#define channel_AN2_GetValue()     0b0010
#define channel_AN3_GetValue()     0b0011
#define channel_AN4_GetValue()     0b0100
#define channel_AN5_GetValue()     0b0101
#define channel_AN6_GetValue()     0b0110
#define channel_AN7_GetValue()     0b0111
#define channel_AN8_GetValue()     0b1000   
#define channel_AN9_GetValue()     0b1001
#define channel_AN10_GetValue()    0b1010
#define channel_AN11_GetValue()    0b1011
#define channel_AN12_GetValue()    0b1100

/*********** P R O T O T Y P E S **********************************************/
void ADC_Initialize(uint8_t PortConfig);
void ADC_Start(void);
void ADC_Close(void);
uint16_t ADC_GetSingleConversion(uint8_t Channel);


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

