/*
 * AX25_PreDefine.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef AX25_PREDEFINE_H_
#define AX25_PREDEFINE_H_

/***************_Macros_Configuration_*********************/
#define STORE_BUFFER_SIZE		100
#define SIMULATION_RX_BUFFER	100
#define AX25_FLAG		0x7E

#define UNDEFINED_LENGTH	-2

typedef union {
	struct {
	u32 Flags		  :3;
	u32 UniteDevice   :4;
	u32 SourceDevice  :8;
	u32 ControlDefine :4;
	u32 PIDDefine	  :2;
	u32 AckCRC		  :1;
	u32 Reserved      :10;
	}InformationAccess;
	u32 ValueAccess;
} AX25Information_ut;

#endif /* AX25_PREDEFINE_H_ */
