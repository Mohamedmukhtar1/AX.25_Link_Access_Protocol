/*
 * AX25_Interface.h
 *
 *  Created on: Jul 5, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef AX25_STRUCTURE_AX25_INTERFACE_H_
#define AX25_STRUCTURE_AX25_INTERFACE_H_

/***************_STD_INCLUDES_*****************************/
#include <stdio.h>
#include <stdlib.h>

/***************_APP_INCLUDES_*****************************/
#include "../../src/Utility/APP_Utility.h"

/***************_AX25_INCLUDES_****************************/
#include "AX25_Structure.h"
#include "AX25_PreDefine.h"

/***************_AX25_BUILD_PROTOTYPES_****************************/
AX25_Header *AXAllocate_axheaderFrame(void);
void AXConfig_vFrame(AX25_Header *Frame, u8 *Destin, u8 *Source, u8 Control, u8 PID);
void AXDelete_vAllocatedFrame(AX25_Header *Frame);

/***************_AX25_DEFINE_PROTOTYPES_****************************/
void AXResetBuffer (u8 *Buffer, u8 BufferSize);
s16 AXDefine_u8FrameLength(u8 *Buffer);
s8 AXDefine_u8FrameFlag(u8 *Buffer, u8 Lu8ActualLength);
void AXStructed_vFrame(AX25_Header *FrameHeader, u8 *Buffer);

/***************_AX25_EXECUTE_PROTOTYPES_****************************/


#endif /* AX25_STRUCTURE_AX25_INTERFACE_H_ */
