/*
 * AX25.c
 *
 *  Created on: Jul 6, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "AX25.h"

static AX25Information_ut Information;

static u8 Gu8UniteDeviveAddress[7]= {0xAA, 0xAB, 0x55, 0x12, 0x16, 0xFF, 0xB3};
static u8 Gu8Device_1_Address[7]  = {0x16, 0xFF, 0xB3, 0xAA, 0xAB, 0x11, 0x11};
static u8 Gu8Device_2_Address[7]  = {0x16, 0xFF, 0xB3, 0xAA, 0x21, 0x21, 0x21};
static u8 Gu8Device_3_Address[7]  = {0x16, 0xFF, 0xB3, 0xAA, 0x35, 0x35, 0x35};


AX25_Header_ut* AXConvertBuffertoAXHeader(u8 *Lu8ReceiverBuffer)
{
	AX25_Header_ut *ptrReceiverHeader;
	ptrReceiverHeader = AXAllocate_axheaderFrame();
	if(ptrReceiverHeader != NULL)
	{
		AXStructe_vFrame(ptrReceiverHeader, Lu8ReceiverBuffer);
	}
	else{/*ERROR*/}
	return ptrReceiverHeader;
}

u32 AXGetInformation(AX25_Header_ut *AxReceiverHeader)
{
	if(AXDestinationAddress_u8Validation(AxReceiverHeader, Gu8UniteDeviveAddress))
	{
		Information.InformationAccess.UniteDevice = 0b1111;
	}
	else{Information.InformationAccess.UniteDevice = 0b0000;}

	if(AXSourceAddress_u8Validation(AxReceiverHeader, Gu8Device_1_Address))
	{
		Information.InformationAccess.SourceDevice= 0x01;
	}
	else if(AXSourceAddress_u8Validation(AxReceiverHeader, Gu8Device_2_Address))
	{
		Information.InformationAccess.SourceDevice= 0x02;
	}
	else if(AXSourceAddress_u8Validation(AxReceiverHeader, Gu8Device_3_Address))
	{
		Information.InformationAccess.SourceDevice= 0x03;
	}
	else{Information.InformationAccess.SourceDevice= 0;}



	return Information.ValueAccess;
}

u8 AXMissionExecute(void)
{
	AXExecute_vFrameAddress(&Information);



	return 1;
}

