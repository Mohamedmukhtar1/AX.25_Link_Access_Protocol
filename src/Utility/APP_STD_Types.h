/*
 * APP_STD_Types.h
 *
 *  Created on: May 13, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_APP_UTILITY_APP_STD_TYPES_H_
#define INC_APP_UTILITY_APP_STD_TYPES_H_

/* Pointer Typedef *********************************************************************/
#define NULL				((void *)0)
/* Signed Number Typedef ***************************************************************/
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long s64;
/* Unsigned Number Typedef *************************************************************/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long u64;
/* Floating-Point Number Typedef *******************************************************/
typedef float f32;		// 4_Byte	6  decimal places floating point
typedef double f64;		// 8_Byte	14 decimal places floating point
typedef long double f96;		// 12_Byte	19 decimal places floating point

#endif /* INC_APP_UTILITY_APP_STD_TYPES_H_ */
