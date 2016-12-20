/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "constants.h"          
#include "user.h"          /* User funct/params, such as InitApp */


/******************************************************************************/
/* Interrupt Routines                                                         */

/******************************************************************************/

void interrupt isr(void) {
    extern volatile long timer;
    extern volatile long sub_timer;
    extern volatile long tap_timer;

    extern volatile long baseline_delay_time;

    extern  int top_push_state;
    extern uint8_t feedback_start;
    extern volatile long mod_timer;    
    extern volatile long delay_time;       
    if (INTCONbits.TMR0IF == 1) {

        timer = timer + 1;
        sub_timer = sub_timer + 1;
        tap_timer = tap_timer + 1;
        mod_timer = mod_timer + 1;
        test_timer++;
        if (feedback_start == 1) {
            feedback_timer++;
            if (feedback_timer > long_press_limit) {feedback_timer = long_press_limit;}
        }
        if (longTap_start == 1) {
            longTap_timer++;
            if (longTap_timer > long_press_limit) {
                longTap_timer = long_press_limit;
            }
        }
         INTCONbits.TMR0IF = 0;       
    }

   /*
    if (test_timer >= 750) {  
        LED_tap_Aux = 1;
        test_timer = 0;
    } 
    
    if (test_timer >= 5) {  
        LED_tap_Aux = 0;
    }
    */
    
    if (longTap_state < 1 && doubleTap_state < 1) {

        if (baseline_delay_time == 750) {  
            LED_bypass_Aux = 1;
        } else {  
            LED_bypass_Aux = 0;
        }
        
        //Don't blink the tap if the tap is held down
        if (timer >= baseline_delay_time) { //delay_time

            //if (suspend_blink == 0) {
                LED_tap_A = 1;  
            //}
            timer = 0;
        }
        
        if (timer >= 20) { //delay_time
            //if (suspend_blink == 0) {
                LED_tap_A = 0;
            //}
        }
    } 

  
    if (sub_timer >= delay_time) { //sub_delay_time
        if (suspend_blink == 0) {
            set_leds_top(top_push_state, 1);
        }
        sub_timer = 0;
    }

    if (sub_timer >= 20) { //delay_time
        if (suspend_blink == 0) {
            set_leds_top(top_push_state, 0);
        }
    }


    if (preset_programmning_on == 1) {
        preset_blink++;
        
        if (preset_blink >= blink_delay) {
            LED_bypass_Aux = 1;
            if (preset_blink > blink_delay*2) {
                preset_blink = 0;
            }
            
        } else {
            LED_bypass_Aux = 0;
        }
        
    } else {
        if (preset_blink > 0) {
            preset_blink = 0;
            LED_bypass_Aux = 0;
        }
        
    }

}

