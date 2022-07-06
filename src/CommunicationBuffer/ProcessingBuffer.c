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


