/*
 * AX25_Architecture.h
 *
 *  Created on: Jul 2, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef AX25_ARCHITECTURE_H_
#define AX25_ARCHITECTURE_H_

/***********************************************************************************************************
 *  Unnumbered Information Frame
	+---------+-----------------------------------------------------------+-------------+----------+---------+
	|         |            AX.25 Transfer Frame Header                    |             |          |         |
	|         |-------------------------+-----------+---------------------|             |  Frame   |         |
	|   Flag  |        Address          |           |                     | Information |  Check   |   Flag  |
	|         |-------------+-----------|  Control  | Protocol Identifier |    Field    | Sequence |         |
	|         | Destination |   Source  |           |                     |             |  CRC=16  |         |
	+---------+-------------+-----------+-----------+---------------------+-------------+----------+---------+
	| 1 byte  |   7 bytes   |  7 bytes  | 1, 2 byte |       1 byte        |  up to 256  | 2 bytes  | 1 byte  |
	+---------+-------------+-----------+-----------+---------------------+-------------+----------+---------+
 */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   1.0.0 - Flag (8 bits)
   1- The flag field is one octet long. Because the flag delimits frames, it occurs at both the
      beginning and end of each frame.
   2- Two frames may share one flag, which would denote the end of the first frame and the start of the next
      frame. A flag consists of a zero followed by six ones followed by another zero, or 01111110 (0x7E). In
      order to ensure that the flag bit sequence mentioned above does not appear accidentally anywhere else
      in a frame, bit stuffing is applied.
   3- The sender monitors the bit sequence for a group of five or more contiguous '1' bits.
   4- Any time five contiguous '1' bits are sent, the sending station inserts a '0' bit after the fifth
      '1' bit. During frame reception, any time five contiguous '1' bits are received, a '0' bit immediately
      following five '1' bits is discarded.

   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   1.0.1 - Address (128 bits)
	+-------------------------------------------------------------------------------------------------------+
	|                                Destination Address (56 bits - 7 Bytes)                                |
	+-----------------------------------------------------------------------+-------------------------------+
	|                          Callsign (48 bits)                           |         SSID (8 bits)         |
	+-----------+-----------+-----------+-----------+-----------+-----------+---+---+---+---+---+---+---+---+
	|     C1    |     C2    |     C3    |     C4    |     C5    |     C6    |   |   |   | S | S | I | D |   |
	+-----------+-----------+-----------+-----------+-----------+-----------| 0 | 1 | 1 | S | S | I | D | 0 |
	| XXXX XXX0 | XXXX XXX0 | XXXX XXX0 | XXXX XXX0 | XXXX XXX0 | XXXX XXX0 |   |   |   | S | S | I | D |   |
	+-----------+-----------+-----------+-----------+-----------+-----------+---+---+---+---+---+---+---+---+

	+-------------------------------------------------------------------------------------------------------+
	|                                Source Address (56 bits - 7 Bytes)                                     |
	+-----------------------------------------------------------------------+-------------------------------+
	|                          Callsign (48 bits)                           |         SSID (8 bits)         |
	+-----------+-----------+-----------+-----------+-----------+-----------+---+---+---+---+---+---+---+---+
	|     C1    |     C2    |     C3    |     C4    |     C5    |     C6    |   |   |   | S | S | I | D |   |
	+-----------+-----------+-----------+-----------+-----------+-----------| 0 | 1 | 1 | S | S | I | D | 0 |
	| XXXX XXX0 | XXXX XXX0 | XXXX XXX0 | XXXX XXX0 | XXXX XXX0 | XXXX XXX0 |   |   |   | S | S | I | D |   |
	+-----------+-----------+-----------+-----------+-----------+-----------+---+---+---+---+---+---+---+---+

   1- The callsign is made up of 6 upper-case letters, numbers or space ASCII characters only (7 bits).
      The SSID is a four-bit integer that uniquely identifies multiple stations using the same amateur callsign.
   2- The 6 characters of the callsign are placed in the first 6 octets of the field (C1 to C6). Each character
      bits are shifted one bit on the left and the least significant bit is set to '0'.The SSID is placed in the
      bits 3-6. The other bits of the field have a fixed value.

   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   1.0.2 - Control Bits (8 bits)
    - The control field identifies the type of frame being passed and controls several attributes of
      the Layer 2 connection. For an AX.25 Unnumbered Information Frame, its value is always 00000011 (0x03).

   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   1.0.3 - Protocol Identifier (8 bits)
    - Shall be 11110000 (0xF0).

   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   1.0.4 - Information Field (0 to 2048 bits)
    - The Information Field contains the data specific to the usage of the AX.25 Transfer Frame.
      The maximum size of the Information Field is 2048 bits

    +----------------------------------------------------------------------------------------------------------+
	|                            AX.25 Transfer Frame Telemetry Information Field (0-2048)                     |
	+-----------------------------------------------------------------------+----------------------------------+
	|          Telemetry Transfer Frame Secondary Header         |        | Telemetry Transfer Frame Trailer   |
	|                                                            |        |            (8-72 bits)             |
	|                          (32 bits)                         |        +--------------------------+---------+
	+-------------------------------+--------+---------+---------+        |       Frame Status       |         |
	|								|		 |		   |		 |	      |          (8 bits)        |         |
	|     Frame Identification      |        | Virtual |         |  Data  +--------------------------+  Time   |
	|            (8 bits)           | Master | Channel | First   |  2008  |        |        |        | {Epoch} |
	+---------+------------+--------+ Frame  | Frame   | Header  |        |  Time  | Spare  | TC     | {  &  } |
	| Version |   Virtual  |  Spare | Count  | Count   | Pointer |        |  Flag  |        | Count  | {Unix } |
	| Number  | Channel ID |        |        |         |         |        |        |        |        |         |
	+---------+------------+--------+--------+---------+---------+--------+--------+--------+--------+---------+
	| 2 bits  |   3 bits   | 3 bits | 8 bits | 8 bits  | 8 bits  |  ~~~~  | 4 bits | 2 bits | 2 bits | 64 bits |
	+---------+------------+--------+--------+---------+---------+--------+--------+--------+--------+---------+

1- Telemetry Transfer Frame Secondary Header (32 bits)
    1.1- Frame Identification (8 bits)
    	1.1.1- Version Number (2 bits)
    		- reserved for potential evolution of the Transfer Frame structure. In this standard, only
              one version number (version 1) is recognized, which specifies the Transfer Frame
              structure described herein. This number is '00'.
        1.1.2- Virtual Channel ID (3 bits)
        	- This 3-bit field enables up to eight Virtual Channels to be run concurrently by a particular
              spacecraft on a particular physical data channel.
            - This 3-bit field enables up to eight Virtual Channels to be run concurrently by a particular
              spacecraft on a particular physical data channel.
        1.1.3- Spare (3 bits)
            - This 3-bit field is reserved for future application. It is required that the field be set to
              the value '000'.
    1.2- Master Frame Count (8 bits)
    	- The purpose of the Master Channel Frame Count field is to provide an 8-bit sequential upcount
    	  (modulo 256) of each Transfer Frame generated by the spacecraft on a given physical data channel
    	  (the Master Channel). It allows the ground to detect the loss of a frame during the transmission.
    1.3- Virtual Channel Frame Count (8 bits)
    	- The purpose of the Virtual Channel Frame Count field is to provide individual accountability
          for each of the Virtual Channels. The 8-bit field represents a sequential up-count (modulo 256)
          of the frames assigned to each of the Virtual Channels. It is used in association with the Virtual
          Channel ID field to maintain a separate counter for each of up to eight separate Virtual Channels.
          Together with the Master Frame Count, it allows the ground to detect from which Virtual Channel the
          lost frame was.
    1.4- First Header Pointer (8 bits)
    	- The First Header Pointer specifies the octet number within the data field (the first byte location
    	  in the frame). It allows knowing where the first packets header is in the frame even if the previous
		  frame(s) were lost.

	Important Notes:
	- If no packet header starts in the data field, the First Header Pointer shall be set
	  to ‘11111111’ (all ones, 0xFF).
	- If the frame doesn’t contains any packet fragment, the First Header Pointer shall be
	  set to ‘11111110’ (all ones minus one, 0xFE).

2- Data (0 to 2008 bits)
	- The maximum length of the frame data field is the maximum size of the I-Field (2048 bits)
	  minus the length of the header and trailer fields, therefore 1952 to 2008 bits (244 to 251
	  octets) depending of the value of Time Flag.

3- Telemetry Transfer Frame Trailer (0 to 72 bits)
	3.1- Frame Status (8 bits)
    	3.1.1- Time Flag (4 bits)
    		- This 4-bit field gives the size of the Time Field located there after at the end of the
              Information Field.
              '0' No Time field (bits 1-3 shall be set to '000')
              '1' Bits 1-3 provide the size of the Time field in octets + 1.
        3.1.2- Spare (2 bits)
        	- This 3-bit field is reserved for future application. It is required that the field be set to
              the value '00'.
              Ideas to use them as: *Last TC Frame Corrupted Flag, *Safe-Mode Enabled Flag
        3.1.3- TC Counter (2 bits)
            - This 2-bit field contains a sequential up-count (modulo 4) of each Telecommand Transfer
	          Frame received and declared valid. It allows the ground to detect if a Telecommand
              Transfer Frame was received on-board or lost/corrupted during transmission.
            - For the detection to work properly, the Telemetry Transfer Frame generation rate must be greater
              than the Telecommand Transfer Frame generation rate.
    3.2- Time (0 to 64 bits)
    	- This field contains the onboard time that corresponds to moment the End Flag of the
	      previous frame was transmitted across all Virtual Channels.

    +------------------------------------------------------+
	| AX.25 Transfer Frame Telecommand Information Field   |
	|                      (0-2048)                        |
	+---------------------------------------------+--------+
	| Telecommand Transfer Frame Secondary Header |        |
	|                 (8 bits)                    | 	   |
	+---------------------------------------------+  Data  |
	|          Segment Header (8 bits)            |  2040  |
	+------------------------+--------------------+        |
	|      Sequence Flag     |        Spare       |        |
	+------------------------+--------------------+--------+
	|          2 bits        |     6 bits         |  ~~~~  |
	+------------------------+--------------------+--------+

1- Telecommand Transfer Frame Secondary Header (8 bits)
	1.1 Segment Header (8 bits)
		1.1.1 Sequence Flag (2 bits)
			- These two bits (which occupy the two most significant bits of the 8-bit field) indicate the
              type of frame in a sequence of segments.
              '0' '1' First Segment: the frame contains the first segment of a telecommand.
              ‘0’ ‘0’ Continuing Segment: the frame contains an intermediate segment of a telecommand.
              ‘1’ ‘0’ Last Segment: the frame contains the last segment of a telecommand.
              ‘1’ ‘1’ No Segmentation: the frame contains one complete telecommand without segmentation
        1.1.2 Spare (6 bits)
			- This 6-bit field is reserved for future application. It is required that the field be set to the
			  value '000000'.
2- Data (0 to 2040 bits)
	- The maximum length of the frame data field is the maximum size of the I-Field (2048 bits)
	  minus the length of the header fields, therefore 2040 bits (255 octets).

	Important Notes:
		- If the secondary header is not used in Telecommand Transfer Frames, there can be only one
		  Telecommand Packet per Telecommand Transfer Frame and it must fit in the Information Field
		  of one frame. Therefore the maximum size of a Telecommand Packet is 2048 bits (256 octets).
		  In this configuration, the Telecommand Transfer Frame does not contain any additional field.
		  Instead the telecommand data is put directly inside the Information Field of the AX.25 Transfer
		  Frame.

   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   1.0.5 - Information Field (0 to 2048 bits)
    - The Frame-Check Sequence is a 16-bit number calculated by both the sender and the receiver of a frame.
      It ensures that the frame was not corrupted by the transmission medium. The Frame-Check Sequence is a
      CRC calculated using polynomial x16 + x12 + x5 + 1 (also called CRC-CITT).
 */

#endif /* AX25_ARCHITECTURE_H_ */
