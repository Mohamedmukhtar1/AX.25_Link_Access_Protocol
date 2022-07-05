/*
 ============================================================================
 Name        : AX25_Link_Access_Protocol
 Author      : Eng/ Mohamed Mokhtar Tammam
 Version     : v1.00.1
 Copyright   : copyright notice.
 Description : AX.25 Telemetry and Telecommand Transfer Frames Format using data structure.
 ============================================================================
 */

#include "main.h"

u8 Gu8_ReceiverBuffer[STORE_BUFFER_SIZE] ={0};  //for serial communication(UART, SPI, I2C)

#define RXBUFFER_VALUES		{0x7E,\
							 0xAA, 0xAB, 0x55, 0x12, 0x16, 0xFF, 0xB3,\
							 0x16, 0xFF, 0xB3, 0xAA, 0xAB, 0x55, 0x12,\
							 0x03,0xF0,\
							 0x7E,'\n'}\

u8 Gu8_RXBuffer[SIMULATION_RX_BUFFER] = RXBUFFER_VALUES ; //Only For simulation

u8 Dest [7]= {0xAA, 0xAB, 0x55, 0x12, 0x16, 0xFF, 0xB3};
u8 Sorc [7]= {0x16, 0xFF, 0xB3, 0xAA, 0xAB, 0x55, 0x12};

u8 Gu8FrameLength =0;
int main(void)
{
	Buff_ResetBuffer(Gu8_ReceiverBuffer, STORE_BUFFER_SIZE);
	ReceiverSimulator(Gu8_ReceiverBuffer, Gu8_RXBuffer, SIMULATION_RX_BUFFER);

	Gu8FrameLength = Buff_Define_u8BufferDataLength(Gu8_ReceiverBuffer);
	printf("FrameLength = %d\n", Gu8FrameLength);
	APrintRxBufferInfo(Gu8_ReceiverBuffer, Gu8FrameLength);
	printf("Valid = %d\n",  Buff_Define_u8RxFlags(Gu8_ReceiverBuffer, Gu8FrameLength));


	AX25_Header *ptrReceiverHeader;
	ptrReceiverHeader = AXAllocate_axheaderFrame();
	AXStructed_vFrame(ptrReceiverHeader, Gu8_ReceiverBuffer);
	APrintFrameHeaderInfo(ptrReceiverHeader);

	return 0;
}


void ReceiverSimulator (u8 *StoreBuffer, u8 *RxBuffer, u8 Length)
{
	u8 i=0;
	for(i=0; i<Length; i++)
	{
		if('\n' == RxBuffer[i])
		{
			break;
		}
		else{	}
		StoreBuffer[i] = RxBuffer[i];
	}
}

void APrintRxBufferInfo(u8 *Frame, u8 Length)
{
	u8 i=0;
	u8 shifter =0;
	printf("\n");
	for(i=0; i<Length; i++)
	{
		shifter++;
		printf("[%d]=%X\t", i+1, Frame[i]);
		if(shifter == 10)
		{
			printf("\n");
			shifter =0;
		}
		else{	}
	}
	printf("\n");
}


void APrintFrameHeaderInfo(AX25_Header *Frame)
{
	u8 i=0;
	printf("\n\n\t\tStartFlag = 0x%X >>>>>>>>>>>>>>>>>>>>>>>>>\n", Frame->StartFlag);
	for(i=0; i<=5; i++)
	{
		printf("Frame->DestinAddress.C[%d] = 0x%X\n",i+1, Frame->DestinAddress.C[i]);
	}

	printf("\t\tFrame->DestinAddress.SSID = 0x%X\n", Frame->DestinAddress.SSID);
	i=0;
	for(i=0; i<=5; i++)
	{
		printf("Frame->SourceAddress.C[%d] = 0x%X\n",i+1, Frame->SourceAddress.C[i]);
	}
	printf("\t\tFrame->SourceAddress.SSID = 0x%X\n", Frame->SourceAddress.SSID);
	printf("ControlField = 0x%X\n", Frame->ControlField);
	printf("Protocol_ID = 0x%X\n\n", Frame->Protocol_ID);
}





/*********
 *  Debuging unite
printf("Size of DestinAddress_st %d \n", sizeof(DestinAddress_st));
printf("Size of SourceAddress_st %d \n", sizeof(SourceAddress_st));
printf("Size of Info8_FrameControl_ut %d \n", sizeof(Info8_FrameControl_ut));
printf("Size of Super8_FrameControl_ut %d \n", sizeof(Super8_FrameControl_ut));
printf("Size of Unnum8_FrameControl_ut %d \n", sizeof(Unnum8_FrameControl_ut));
printf("Size of Info16_FrameControl_ut %d \n", sizeof(Info16_FrameControl_ut));
printf("Size of Super16_FrameControl_ut %d \n", sizeof(Super16_FrameControl_ut));
printf("Size of AX25_Header_8Control_st %d \n", sizeof(AX25_Header_8Control_st));
printf("Size of AX25_Header_16Control_st %d \n", sizeof(AX25_Header_16Control_st));
 * ****/
