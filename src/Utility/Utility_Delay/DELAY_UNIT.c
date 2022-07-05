/*
 * DELAY_UNIT.c
 *
 *  Created on: May 19, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "DELAY_UNIT.h"

extern void Delay_vMilliSecond16MHzoscillator(u16 copy_u16mSTime) {
	volatile u16 u16Local_Count1 = 0;
	volatile u16 u16Local_Count2 = 0;
	for (u16Local_Count1 = 0; u16Local_Count1 < copy_u16mSTime;
			u16Local_Count1++)
		for (u16Local_Count2 = 0; u16Local_Count2 < 3180; u16Local_Count2++) {/* Do nothing for 1 ms*/
		}
}

extern void Delay_vMicroSecond16MHzoscillator(u16 copy_u16uSTime) {
	volatile u16 u16Local_Count1 = 0;
	volatile u16 u16Local_Count2 = 0;
	for (u16Local_Count1 = 0; u16Local_Count1 < copy_u16uSTime;
			u16Local_Count1++)
		for (u16Local_Count2 = 0; u16Local_Count2 < 3; u16Local_Count2++) {/* Do nothing for 1 us*/
		}
}
