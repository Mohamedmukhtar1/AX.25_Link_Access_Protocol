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

/***************_AX25_Sheet_INCLUDES_**********************/
#include "ISU_CtrlPID_Field.h"


/***************_AX25_BUILD_PROTOTYPES_****************************/
AX25_Header_ut *AXAllocate_axheaderFrame(void);
void AXConfig_vFrame(AX25_Header_ut *Frame, u8 *Destin, u8 *Source, u8 Control, u8 PID);
void AXDelete_vAllocatedFrame(AX25_Header_ut *Frame);
void AXStructe_vFrame(AX25_Header_ut *FrameHeader, u8 *Buffer);

/***************_AX25_DEFINE_PROTOTYPES_****************************/
u8 AXDefineFlags_u8Validation(u8 *Buffer, u8 Lu8ActualLength);
u8 AXDestinationAddress_u8Validation(AX25_Header_ut *FrameHeader, u8 *DestinAddress);
u8 AXSourceAddress_u8Validation(AX25_Header_ut *FrameHeader, u8 *SourceAddress);

/***************_AX25_EXECUTE_PROTOTYPES_****************************/
void AXSystemControlConfiguration(void);
void AXExecute_vFrameAddress(AX25Information_ut *ExeInformation);




#endif /* AX25_STRUCTURE_AX25_INTERFACE_H_ */
