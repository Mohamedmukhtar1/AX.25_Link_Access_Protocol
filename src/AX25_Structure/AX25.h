/*
 * AX25.h
 *
 *  Created on: Jul 6, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef AX25_STRUCTURE_AX25_H_
#define AX25_STRUCTURE_AX25_H_

/***************_APP_INCLUDES_*****************************/
#include "../../src/Utility/APP_Utility.h"

/***************_AX25_INCLUDES_****************************/
#include "AX25_Interface.h"
#include "AX25_Structure.h"
#include "AX25_PreDefine.h"

/***************_AX25_Sheet_INCLUDES_**********************/
#include "ISU_CtrlPID_Field.h"

AX25_Header_ut* AXConvertBuffertoAXHeader(u8 *Lu8_ReceiverBuffer);
u32 AXGetInformation(AX25_Header_ut *AxReceiverHeader);
u8 AXMissionExecute(void);



#endif /* AX25_STRUCTURE_AX25_H_ */
