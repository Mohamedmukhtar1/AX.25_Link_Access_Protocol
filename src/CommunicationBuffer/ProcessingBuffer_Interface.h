/*
 * ProcessingBuffer_Interface.h
 *
 *  Created on: Jul 5, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef COMMUNICATIONBUFFER_PROCESSINGBUFFER_INTERFACE_H_
#define COMMUNICATIONBUFFER_PROCESSINGBUFFER_INTERFACE_H_

/***************_STD_INCLUDES_*****************************/
#include <stdio.h>
#include <stdlib.h>

/***************_APP_INCLUDES_*****************************/
#include "../../src/Utility/APP_Utility.h"

/***************_BUFFER_INCLUDES_**************************/
#include "ProcessingBuffer_Private.h"
#include "ProcessingBuffer_Config.h"

/***************_AX25_INCLUDES_****************************/
#include "../../src/AX25_Structure/AX25_PreDefine.h"


void Buff_ResetBuffer (u8 *Buffer, u8 BufferSize);
s16 Buff_Define_u8BufferDataLength(u8 *Buffer);
s8 Buff_Define_u8RxFlags(u8 *Buffer, u8 Lu8ActualLength);

#endif /* COMMUNICATIONBUFFER_PROCESSINGBUFFER_INTERFACE_H_ */
