/*
 * main.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef MAIN_H_
#define MAIN_H_

/***************_STD_INCLUDES_*****************************/
#include <stdio.h>
#include <stdlib.h>

/***************_APP_INCLUDES_*****************************/
#include "../src/Utility/APP_Utility.h"

/***************_BUFFER_INCLUDES_**************************/
#include "../src/CommunicationBuffer/ProcessingBuffer_Interface.h"

/***************_AX25_INCLUDES_****************************/
#include "../src/AX25_Structure/AX25_Interface.h"

/***************_main.c_FUNCTION_PROTOTYPE_****************/
void APrintFrameHeaderInfo(AX25_Header *Frame);
void ReceiverSimulator (u8 *StoreBuffer, u8 *RxBuffer, u8 Length);
void APrintRxBufferInfo(u8 *Frame, u8 Length);


#endif /* MAIN_H_ */
