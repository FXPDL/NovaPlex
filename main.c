//REV 8

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */      
#include <stdbool.h>       /* For true/false definition */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "memory.h"
#include "constants.h"      /* program constants */ 

#include "user.h"          /* User funct/params, such as InitApp */
#include "LEDs.h"          /* LED controlling functions */
#include "tactiles.h"          /* LED controlling functions */
#include "modulation.h"    /* Modulation constants*/

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/




volatile long timer = 0;
volatile long sub_timer = 0;
volatile long tap_timer = 0;
volatile long mod_timer = 0;
int mod_counter = 0;
int tap_iteration = 1;
volatile long delay_time = 2000;
int mod_delay_time = 2000;
volatile long baseline_delay_time = 2000;
signed int mod_value = 0;
int SPI_Value = 0;
int delayfound = 0;
int delay_counter = 0;


long tap1 = 0;
long tap2 = 0;
long tap3 = 0;
long tap4 = 0;
long tap5 = 0;
long tap6 = 0;
long tap7 = 0;
long tap8 = 0;
long tap9 = 0;
long tap10 = 0;
long tap_total = 0;
int num_taps = 4;
long tap_history [5];
int preset = 0;
int incoming_data = 1;

int iCnt = 0;


int knob_1_pos = 0;
int knob_2_pos = 0;
int knob_3_pos = 0;
int knob_4_pos = 0;
int knob_5_pos = 0;
int knob1_prev = 2000;
int knob2_prev = 2000;
int knob3_prev = 2000;
int knob4_prev = 2000;
int knob5_prev = 2000;





int delay[] = {2082, 2044, 2008, 1973, 1939, 1906, 1874, 1844, 1814, 1785, 1757, 1730, 1704, 1679, 1654, 1630, 1607, 1584, 1562, 1541, 1520, 1500, 1480, 1461, 1443, 1424, 1407, 1389, 1372, 1356, 1340, 1324, 1309, 1294, 1279, 1265, 1250, 1237, 1223, 1210, 1197, 1185, 1172, 1160, 1149, 1137, 1126, 1114, 1104, 1093, 1082, 1072, 1062, 1052, 1042, 1033, 1023, 1014, 1005, 996, 988, 979, 971, 962, 954, 946, 938, 930, 923, 915, 908, 901, 894, 887, 880, 873, 866, 860, 853, 847, 840, 834, 828, 822, 816, 810, 804, 799, 793, 787, 782, 777, 771, 766, 761, 756, 751, 746, 741, 736, 731, 727, 722, 717, 713, 708, 704, 700, 695, 691, 687, 683, 678, 674, 670, 666, 663, 659, 655, 651, 647, 644, 640, 636, 633, 629, 626, 622, 619, 615, 612, 609, 606, 602, 599, 596, 593, 590, 587, 584, 581, 578, 575, 572, 569, 566, 563, 560, 558, 555, 552, 549, 547, 544, 542, 539, 536, 534, 531, 529, 526, 524, 522, 519, 517, 514, 512, 510, 507, 505, 503, 501, 498, 496, 494, 492, 490, 488, 486, 483, 481, 479, 477, 475, 473, 471, 469, 467, 466, 464, 462, 460, 458, 456, 454, 452, 451, 449, 447, 445, 444, 442, 440, 438, 437, 435, 433, 432, 430, 428, 427, 425, 424, 422, 420, 419, 417, 416, 414, 413, 411, 410, 408, 407, 405, 404, 402, 401, 400, 398, 397, 395, 394, 393, 391, 390, 389, 387, 386, 385, 383, 382, 381, 379, 378, 377, 376, 374, 373, 372, 371, 369, 368, 367, 366};
int B25k[] = {255, 255, 255, 223, 174, 142, 120, 103, 91, 80, 72, 66, 60, 55, 51, 48, 45, 42, 39, 37, 35, 33, 32, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 21, 20, 19, 15, 11, 7, 7};
int iB25k[] = {7, 7, 11, 15, 19, 20, 21, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 33, 35, 37, 39, 42, 45, 48, 51, 55, 60, 66, 72, 80, 91, 103, 120, 142, 174, 223, 255, 255, 255};



/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/

void main(void) {
    ConfigureOscillator();
    InitApp();

    
    InitializeTaps();

    
   // showBootSequence();    
    ReadSavedSettings();

    while (1) {

        read_bottom_tactile();
        read_top_tactile();
        

        update_mode();
        
        if (mode_1 == 0) {
            debounce_mode1++;
            if (debounce_mode1 > 25) {
                debounce_mode1 = 25;
                //Save button
               // preset_programmning_on =  !preset_programmning_on;
                
                showBootSequence(); 
                //showSave();

                while (mode_1 == 0) {
                }
            }
        } else {
            debounce_mode1 = 0;
        }
        

        //bypass button ------------------------------------
        //  1) toggle state
        //  2) toggle relay pins
        //  3) toggle bypass LED
        //  4) freeze program until button released
        //--------------------------------------------------
        if (switch_bypass == 0) {
            debounce_bypass++;
            if (debounce_bypass > 25) {
                bypass_state = !bypass_state;
                Relay_1 = !bypass_state;
                Relay_2 = bypass_state;
                LED_bypass_A = bypass_state;
                LED_bypass_B = !bypass_state;
                while (switch_bypass == 0) {
                }
            }
        } else {
            debounce_bypass = 0;
        }




        //tap button ------------------------------------
        //  1) look to see if x sec has passed between switches
        //  1a) if condition is met then reset the counter to zero and reset matrix, timer
        //  1b) delay until button released
        //  2) if timing is less then x sec then store time to matrix
        //  3) add all entry's to matrix and divide by number of iterations
        //  4) subroutine to apply subdivisions to the newly tapped tempo
        //  5) calculate new modulation interval for timing
        //  6) reset tap timer
        //  7) iterate the tap counter
        //  8) delay until button release
        //-----------------------------------------------

        if (switch_tap == 0) {
            debounce_count++;
            if (debounce_count > 25) {
                if (tap_timer >= 1563) {
                    tap_timer = 0;
                    tap_iteration = 1;
                    tap_total = 0;
                    delay_time_changed = 0;
                    //LED_RJ45_Yellow = 1;
                    //LED_RJ45_Green = 1;
                    for (iCnt = 1; iCnt <= num_taps; iCnt++) {
                        tap_history[iCnt] = 0;
                    }
                    while (switch_tap == 0) {
                    }
                } else if (tap_timer < 1563) {
                    if (tap_iteration <= 4) {
                        if (tap_timer >= 1172) {
                            tap_timer = 1172;
                        }
                        int tapCntDivisor = num_taps;
                        if (tap_iteration <= num_taps) {
                            tap_total += tap_timer;
                            tap_history[tap_iteration] = tap_timer;
                            tapCntDivisor = tap_iteration;
                        } else {
                            tap_total = 0;
                            for (iCnt = 1; iCnt < num_taps; iCnt++) {
                                tap_history[iCnt] = tap_history[iCnt + 1];
                                tap_total += tap_history[iCnt];
                            }
                            tap_history[num_taps] = tap_timer;
                            tap_total += tap_timer;
                        }

                        //tap_total += tap_timer;
                        baseline_delay_time = tap_total / tapCntDivisor;
                        delay_time_changed = 1;
                        tap_timer = 0;

                        //                        if (tap_iteration  % 2 == 0) {
                        //                            LED_RJ45_Yellow = 1;
                        //                            LED_RJ45_Green = 0;
                        //                        } else {
                        //                            LED_RJ45_Yellow = 0;
                        //                            LED_RJ45_Green = 1;                           
                        //                        }
                        tap_iteration++;
                    }
                    while (switch_tap == 0) {
                    }
                }
            }
        } else {
            debounce_count = 0;
        }



        //read pots---------------------------------------
        knob_1_pos = adc_convert(0);
        knob_2_pos = adc_convert(1);
        knob_3_pos = adc_convert(2);
        knob_4_pos = adc_convert(3);
        knob_5_pos = adc_convert(4);



        //knob 1 action ----------------------------------
        //Delay Time PWM1 CCPR1
        //  1) Look to see if knob has changed by more then 0.2%
        //  2) Map knob to 0-255 PWM range
        //  3) subroutine to map knob range
        //  4) subroutine to apply subdivisions
        //  5) recalculate mod timer
        //  6) set output of dthelay
        //--------------------------------------------------
        if (knob_1_pos - knob1_prev >= 4 || knob_1_pos - knob1_prev <= -4) {
            knob1_prev = knob_1_pos;
            int i = map(knob1_prev, 0, 1023, 0, 255);
            baseline_delay_time = map(knob1_prev, 0, 1023, 1172, 200);
            delay_time_changed = 1;
        }


        //knob 2 action ----------------------------------
        //Delay MIX U8 U7 PWM2 PWM3
        //  1) Look to see if knob has changed by more then 0.2%
        //  2) Map knob to 0-39 for array
        //  3) Set CCP to calibrated value
        //------------------------------------------------
        if (knob_2_pos - knob2_prev >= 4 || knob_2_pos - knob2_prev <= -4) {
            knob2_prev = knob_2_pos;
            int i = map(knob2_prev, 0, 1023, 0, 39);
            CCPR2 = iB25k[i];
            CCPR3 = B25k[i];
        }



        //knob 3 action ----------------------------------
        //Delay FB U9 U10 PWM4 PWM5
        //  1) Look to see if knob has changed by more then 0.2%
        //  2) Map knob to 0-39 for array
        //  3) Set CCP to calibrated value
        //------------------------------------------------
        if (knob_3_pos - knob3_prev >= 4 || knob_3_pos - knob3_prev <= -4) {
            knob3_prev = knob_3_pos;
            int i = map(knob3_prev, 0, 1023, 16, 0);
            CCPR4 = iB25k[i];
            CCPR5 = B25k[i];
        }



        //knob 4 action ----------------------------------
        //Delay MOD SPEED U11 U12 PWM6 PWM7
        //  1) Look to see if knob has changed by more then 0.2%
        //  2) Map knob to 20-1000 for array
        //  3) Set new time interval for modulation
        //------------------------------------------------
        if (knob_4_pos - knob4_prev >= 4 || knob_4_pos - knob4_prev <= -4) {
            knob4_prev = knob_4_pos;
            mod_delay_time = map(knob4_prev, 0, 1023, 60, 1000);
        }



        //knob 5 action ----------------------------------
        //Delay MOD DEPTH U13 U14 PWM8 PWM9
        //  1) Look to see if knob has changed by more then 0.2%
        //------------------------------------------------
        if (knob_5_pos - knob5_prev >= 4 || knob_5_pos - knob5_prev <= -4) {
            knob5_prev = knob_5_pos;
        }

        //1 tick = 0.5119ms!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        //increment modulation -----------------------------
        //  1) Read counter to see if more then 30 steps
        //  1a) If > 31, reset counter to zero
        //  2) based on modulation state, determine which array to reference
        //  3) call array and map it to the counter to develop a value
        //  4) subroutine to calculate PWM cycle depending on mod value and depth pot
        //  5) write CCP value U14 CCPR9
        //  6) reset timer
        //--------------------------------------------------
        if (mod_timer >= mod_delay_time) {
            //LED_RJ45_Yellow = !LED_RJ45_Yellow;
            mod_counter = mod_counter + 1;
            mod_timer = 0;

            if (bottom_push_state == 1 || bottom_push_state == 5) {
                if (mod_counter >= 61) {
                    mod_counter = 0;
               }                
            } else {
                if (mod_counter > 31) {
                    mod_counter = 0;
                }
            } 


            signed int adjusted_pot_value = map(knob5_prev, 0, 1023, 1275, 0);
            switch (bottom_push_state) {
                case 1:
                    mod_value = mod5[mod_counter];
                    chorus = 0;
                    break;
                case 2:
                    mod_value = mod2[mod_counter];
                    chorus = 0;
                    break;
                case 3:
                    mod_value = mod3[mod_counter];
                    chorus = 0;
                    break;
                case 4:
                    mod_value = mod4[mod_counter];
                    chorus = 0;
                    break;
                case 5:
                    mod_value = mod5[mod_counter];
                    adjusted_pot_value = 1275;
                    chorus = 1;
                    break;
                case 6:
                    mod_value = 0;
                    chorus = 0;
                    break;
            }
            mod_value = modulation(mod_value, adjusted_pot_value);
            CCPR9 = mod_value / 2;
            mod_timer = 0;
        }



        //subroutine to calculate led interval and PWM value if delay time has changed
        if (delay_time_changed == 1) {
            delay_time = baseline_delay_time;
            delay_time = set_subdivision(baseline_delay_time, top_push_state);
            delayfound = 0;
            delay_counter = 0;
            while (delayfound == 0) {
                if (delay[delay_counter] <= delay_time * 2) {
                    delayfound = 1;
                    CCPR1 = delay_counter;
                } else {
                    delay_counter++;
                }
            }
            mod_delay_time = delay_time / 7.5;

            delay_time_changed = 0;
        }
 
    }
}
