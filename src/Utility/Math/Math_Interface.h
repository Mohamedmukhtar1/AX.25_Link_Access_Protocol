/*
 * Math_Interface.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef APP_UTILITY_MATH_MATH_INTERFACE_H_
#define APP_UTILITY_MATH_MATH_INTERFACE_H_

#include "..\APP_Utility.h"
#include "Math_Private.h"

/**ROUND_CONFIG options [ _1_FLOAT_POINT , _2_FLOAT_POINT ]*/
#define ROUND_CONFIG	_2_FLOAT_POINT
f32 AMath_f32RoundNumber (f32 Lf32_Number);

#endif /* APP_UTILITY_MATH_MATH_INTERFACE_H_ */
