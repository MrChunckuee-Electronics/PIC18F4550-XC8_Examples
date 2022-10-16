/* 
 * File:   mcu.h
 * Author: mrchunckuee
 *
 * Created on 9 de octubre de 2022, 11:06 PM
 */

#ifndef MCU_H
#define	MCU_H

#ifdef	__cplusplus
extern "C" {
#endif

/*********** P R O T O T Y P E S **********************************************/
void MCU_Initialize(void);
void Delay_ms(uint16_t miliseconds);
void IO_Task(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MCU_H */

