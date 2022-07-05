/*
 * ProcessingBuffer.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "ProcessingBuffer_Interface.h"

void Buff_ResetBuffer (u8 *Buffer, u8 BufferSize)
{
	u8 i=0;
	for(i=0; i<=BufferSize-1; i++)
	{
		Buffer[i] = '\n';
	}
}

s16 Buff_Define_u8BufferDataLength(u8 *Buffer)
{
	u8 i=0;
	s16 Ls16FrameLength =0;
	for(i=0; i<=STORE_BUFFER_SIZE; i++)
	{
		if('\n' == Buffer[i])
		{
			break;
		}
		else{	}
		Ls16FrameLength++;
	}
	//Ls16FrameLength = UNDEFINED_LENGTH;
	return Ls16FrameLength;
}

s8 Buff_Define_u8RxFlags(u8 *Buffer, u8 Lu8ActualLength)
{
	s8 Ls16FrameFlag =0;
	if((0x7E == Buffer[0]))
	{
		Ls16FrameFlag++;
		if(0x7E == Buffer[Lu8ActualLength-1])
		{
			Ls16FrameFlag++;
		}else{	}
	}
	else{
		Ls16FrameFlag =-1;
	}
	return Ls16FrameFlag;
}
