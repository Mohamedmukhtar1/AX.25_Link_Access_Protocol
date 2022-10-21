/*
 * AX25_Structure.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef AX25_STRUCTURE_H_
#define AX25_STRUCTURE_H_

/***************_APP_INCLUDES_*****************************/
#include "../../src/Utility/APP_Utility.h"

typedef struct
{
	u8 C[6] ;
	u8 SSID;
} DestinAds_st;

typedef struct
{
	u8 C[6] ;
	u8 SSID;
} SourceAds_st;

typedef union {
	struct {
		u8 Reserved_0 :1; // Always set to 0;
		u8 Ns_        :3; // Send sequence number
		u8 Poll       :1; // When not used set to “0”, command (poll) mode to request an immediate reply "1"
		u8 Nr_        :3; // Receive sequence number
	} BitAccess;
	u8 ControlAccess;
} Info8_FrameControl_ut;

typedef union {
	struct {
		u8 Reserved_1   :1; // Always set to 1;
		u8 Reserved_0   :1; // Always set to 0;
		u8 Supervisory  :2; // The supervisory function bits
		u8 Poll_Final   :1; // The reply to poll is indicated by setting response (final) bit in the appropriate frame
		u8 Nr_          :3; // Receive sequence number
	} BitAccess;
	u8 ControlAccess;
} Super8_FrameControl_ut;

typedef union {
	struct {
		u8 Reserved_11  :2; // Always set to 11;
		u8 Modifier12   :2;
		u8 Poll_Final   :1; // The reply to poll is indicated by setting response (final) bit in the appropriate frame
		u8 Modifier345  :3;
	} BitAccess;
	u8 ControlAccess;
} Unnum8_FrameControl_ut;

typedef union {
	struct {
	u8 StartFlag ;
	DestinAds_st DestinAddress ;
	SourceAds_st SourceAddress ;
	u8 Protocol_ID ;
	u8 ControlField ;
	}HeaderAccess;
	u8 BufferAccess[17];
} AX25_Header_ut;


#endif /* AX25_STRUCTURE_H_ */

/******************  would be updated in V2.0.0
 typedef union {
	struct {
		u16 Reserved_0 :1;
		u16 Ns_        :7;
		u16 Poll       :1;
		u16 Nr_        :7;
	} BitAccess;
	u16 ControlAccess;
} Info16_FrameControl_ut;

typedef union {
	struct {
		u16 Reserved_1    :1;
		u16 Reserved_0    :1;
		u16 Supervisory   :2;
		u16 Reserved_0000 :4; // Always set to 0000;
		u16 Poll_Final    :1;
		u16 Nr_           :7;
	} BitAccess;
	u16 ControlAccess;
} Super16_FrameControl_ut;
 * **/
