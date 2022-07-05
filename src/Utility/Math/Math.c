/*
 * Math.c
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "Math_Interface.h"

f32 AMath_f32RoundNumber (f32 Lf32_Number)
{
	u32 Lu32_CastedHolder = Lf32_Number;
	f32 Lf32_FloatHolder = Lf32_Number - Lu32_CastedHolder;
	if ((Lf32_FloatHolder*10) > 5)
	{
#if 	ROUND_CONFIG	== _1_FLOAT_POINT
#elif   ROUND_CONFIG	== _2_FLOAT_POINT
		if((Lf32_FloatHolder*100) > 56)
		{
			Lu32_CastedHolder++;
		}
		else{	}
#else
	#error "You choosed wrong ROUND_CONFIG"
#endif
	}
	else{	}
	return Lu32_CastedHolder;
}
