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

typedef union {
	struct {
	u8 ISO8208X25PLP   ;
	u8 COMTCPIPPCK     ;
	u8 UNCOMTCPIPPCK   ;
	u8 SEGFRAG         ;
	u8 TEXDATAPROTOCOL ;
	u8 LINKQPROTOCOL   ;
	u8 APPLETALK       ;
	u8 APPLETALKARP    ;
	u8 APRAINPROTOCOL  ;
	u8 APRAADDRESO     ;
	u8 FLEXNET         ;
	u8 NETROM          ;
	u8 NOL3PROTOCOL    ;
	u8 ESCC            ;
	}ControlAccess;
	u8 ControlArray[14];
} IframeControl_ut;

typedef union {
	struct {
	u8 SRR    ;
	u8 SRNR   ;
	u8 SREJ   ;
	u8 SSREJ  ;
	}ControlAccess;
	u8 ControlArray[4];
} SframeControl_ut;

typedef union {
	struct {
	u8 SABM_CMD  ;
	u8 SABME_CMD ;
	u8 DISC_CMD  ;
	u8 XID_CMD   ;
	u8 XID_RES   ;
	u8 TEST_CMD  ;
	u8 TEST_RES  ;
	u8 UI_CMD    ;
	u8 UI_RES    ;
	u8 UACK_RES  ;
	u8 FRMR_RES  ;
	u8 DM_RES    ;
	}ControlAccess;
	u8 ControlArray[4];
} UframeControl_ut;

#endif /* AX25_PREDEFINE_H_ */
