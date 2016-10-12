/* 
 * File:   constants.h
 * Author: Nancy
 *
 * Created on October 9, 2016, 7:08 PM
 */

#ifndef CONSTANTS_H
#define	CONSTANTS_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONSTANTS_H */

#include <stdint.h>        /* For uint8_t definition */      
#include <stdbool.h>       /* For true/false definition */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "memory.h"



#define bottom_tactile PORTDbits.RD6
#define top_tactile PORTDbits.RD5
#define LED_tap_A LATBbits.LATB4
#define LED_tap_B LATBbits.LATB5
#define LED_bypass_A LATBbits.LATB2
#define LED_bypass_B LATBbits.LATB3
#define LED_bypass_Aux LATBbits.LATB1
#define LED_tap_Aux LATBbits.LATB0
#define Relay_1 LATGbits.LATG1
#define Relay_2 LATGbits.LATG2
#define switch_bypass PORTEbits.RE1
#define switch_tap PORTEbits.RE0
#define exp_mode PORTAbits.RA4
#define mode_2 PORTCbits.RC0
#define mode_1 PORTDbits.RD7
#define chorus PORTCbits.RC4



extern uint8_t bypass_state = 0;
extern uint8_t mode1_state = 0;
extern uint8_t mode2_state = 0;
extern uint8_t blink_state = 1;

extern uint8_t suspend_blink = 1; // 0;  //Stop the tap blink for debugging

extern uint8_t preset_programmning_on = 0;
extern uint8_t preset_blink = 0;

extern int blink_delay = 100;

volatile uint8_t top_push_state = 6;
extern uint8_t bottom_push_state = 6;

uint16_t myBuf[ERASE_FLASH_BLOCKSIZE];

int delay_time_changed = 1;

extern long tap[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

extern int debounce_count = 0;
extern int debounce_bypass = 0;
extern int debounce_mode1 = 0;
extern int debounce_mode2 = 0;
