/* 
 * File:   modulation.h
 * Author: Nancy
 *
 * Created on October 9, 2016, 5:21 PM
 */

#ifndef MODULATION_H
#define	MODULATION_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MODULATION_H */
//30 samples
//signed int mod1[] = {0, 21, 41, 59, 74, 87, 95, 99, 99, 95, 87, 74, 59, 41, 21,    0, -21, -41, -59, -74, -87, -95, -99, -99, -95, -87, -74, -59, -41, -21, 0}; //sin wave
//signed int mod2[] = {0, 13, 27, 40, 53, 67, 80, 93, 93, 80, 67, 53, 40, 27, 13,    0, -13, -27, -40, -53, -67, -80, -93, -93, -80, -67, -53, -40, -27, -13, 0}; //triangle wave
//signed int mod3[] = {0,  7, 13, 20, 27, 33, 40, 47, 53, 60, 67, 73, 80, 87, 93, -100, -93, -87, -80, -73, -67, -60, -53, -47, -40, -33, -27, -20, -13,  -7, 0}; //saw wave
//signed int mod4[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, 100}; //square wave
//signed int mod5[] = {0, 10, 20, 30, 40, 50, 58, 66, 74, 80, 86, 91, 95, 97, 99, 100, 99, 97, 95, 91, 86, 80, 74, 66, 58, 50, 40, 30, 20, 10, 0, -10, -20, -30, -40, -50, -58, -66, -74, -80, -86, -91, -95, -97, -99, -100, -99, -97, -95, -91, -86, -80, -74, -66, -58, -50, -40, -30, -20, -10, 0};

//60 samples
//sin
signed char mod1[] = {0, 10, 20, 30, 40, 50, 58, 66, 74, 80, 86, 91, 95, 97, 99, 100, 99, 97, 95, 91, 86, 80, 74, 66, 58, 50, 40, 30, 20, 10, 0, -10, -20, -30, -40, -50, -58, -66, -74, -80, -86, -91, -95, -97, -99, -100, -99, -97, -95, -91, -86, -80, -74, -66, -58, -50, -40, -30, -20, -10, 0}; //sin wave
//triangle
//signed char mod2[] = {0, 7, 13, 20, 27, 33, 40, 47, 53, 60, 67, 73, 80, 87, 93, 100, 93, 87, 80, 73, 67, 60, 53, 47, 40, 33, 27, 20, 13, 7, 0, -7, -13, -20, -27, -33, -40, -47, -53, -60, -67, -73, -80, -87, -93, -100, -93, -87, -80, -73, -67, -60, -53, -47, -40, -33, -27, -20, -13, -7, 0};  //triangle wave
//reverse sawtooth
signed char mod2[] = {0, -3, -7, -10, -13, -17, -20, -23, -27, -30, -33, -37, -40, -43, -47, -50, -53, -57, -60, -63, -67, -70, -73, -77, -80, -83, -87, -90, -93, -97, -100, 97, 93, 90, 87, 83, 80, 77, 73, 70, 67, 63, 60, 57, 53, 50, 47, 43, 40, 37, 33, 30, 27, 23, 20, 17, 13, 10, 7, 3, 0}; //Reverse Sawtooth
//sawtooth
signed char mod3[] = {0, 3, 7, 10, 13, 17, 20, 23, 27, 30, 33, 37, 40, 43, 47, 50, 53, 57, 60, 63, 67, 70, 73, 77, 80, 83, 87, 90, 93, 97, 100, -97, -93, -90, -87, -83, -80, -77, -73, -70, -67, -63, -60, -57, -53, -50, -47, -43, -40, -37, -33, -30, -27, -23, -20, -17, -13, -10, -7, -3, 0}; //saw wave
//square
//signed int mod4[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100}; //square wave

//int modSin(double, double);
