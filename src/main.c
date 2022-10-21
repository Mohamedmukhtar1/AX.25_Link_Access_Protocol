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
							 0x16, 0xFF, 0xB3, 0xAA, 0x35, 0x35, 0x35,\
							 0x03,0xF0,\
							 0x7E,'\n'}\

u8 Gu8_RXBuffer[SIMULATION_RX_BUFFER] = RXBUFFER_VALUES ; //Only For simulation
u8 Gu8FrameLength =0;


int main(void)
{
	/*********************************************************************************/

	Buff_ResetBuffer(Gu8_ReceiverBuffer, STORE_BUFFER_SIZE);
	ReceiverSimulator(Gu8_ReceiverBuffer, Gu8_RXBuffer, SIMULATION_RX_BUFFER);

	/*********************************************************************************/

	Gu8FrameLength = Buff_Define_u8BufferDataLength(Gu8_ReceiverBuffer);
	APrintRxBufferInfo(Gu8_ReceiverBuffer, Gu8FrameLength);
	printf("Flag Valid = %d\n",  AXDefineFlags_u8Validation(Gu8_ReceiverBuffer, Gu8FrameLength));
	printf("FrameLength = %d\n", Gu8FrameLength);

	/*********************************************************************************/

	// s8 AXDefineFlags_s8Validation(u8 *Buffer, u8 Lu8ActualLength)

	AX25_Header_ut *ptrReceiverHeader;
	ptrReceiverHeader = AXConvertBuffertoAXHeader(Gu8_ReceiverBuffer);
	APrintFrameHeaderInfo(ptrReceiverHeader);
	printf("Information = 0x%X\n",AXGetInformation(ptrReceiverHeader));

	AXMissionExecute();


	//printf("DeviceIDConfirmation Valid = %d\n", DeviceIDConfirmation);




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
		printf("0x%X\t", Frame[i]);
		if(shifter == 5)
		{
			printf("\n");
			shifter =0;
		}
		else{	}
	}
	printf("\n");
}


void APrintFrameHeaderInfo(AX25_Header_ut *Frame)
{
	u8 i=0;
	printf("\n\n\t\tStartFlag = 0x%X >>>>>>>>>>>>>>>>>>>>>>>>>\n", Frame->HeaderAccess.StartFlag);
	for(i=0; i<=5; i++)
	{
		printf("Frame->DestinAddress.C[%d] = 0x%X\n",i+1, Frame->HeaderAccess.DestinAddress.C[i]);
	}

	printf("\t\tFrame->DestinAddress.SSID = 0x%X\n", Frame->HeaderAccess.DestinAddress.SSID);
	i=0;
	for(i=0; i<=5; i++)
	{
		printf("Frame->SourceAddress.C[%d] = 0x%X\n",i+1, Frame->HeaderAccess.SourceAddress.C[i]);
	}
	printf("\t\tFrame->SourceAddress.SSID = 0x%X\n", Frame->HeaderAccess.SourceAddress.SSID);
	printf("ControlField = 0x%X\n", Frame->HeaderAccess.ControlField);
	printf("Protocol_ID = 0x%X\n\n", Frame->HeaderAccess.Protocol_ID);
}

