/*
 * ISU_CtrlPID_Field.h
 *
 *  Created on: Jul 6, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef AX25_STRUCTURE_ISU_CTRLPID_FIELD_H_
#define AX25_STRUCTURE_ISU_CTRLPID_FIELD_H_

/******************************************************************
 * I frame control field
 */
//  ISO8208X25PLP            0X01               /// ISO_8208_CCTTT_X.25_PLP
//  COMTCPIPPCK              0X06               /// COMPRESSED_TCP_IP_PACKET
//  UNCOMTCPIPPCK            0x07               /// UNCOMPRESSED_TCP_IP_PACKET
//  SEGFRAG                  0x08               /// SEGMENTATION_FRAGMENT
//  TEXDATAPROTOCOL          0xC3               /// TEXNET_DATAGRAM_PROTOCOL
//  LINKQPROTOCOL            0xC4               /// LINK_QUALITY_PROTOCOL
//  APPLETALK                0xCA               /// APPLETALK
//  APPLETALKARP             0xC8               /// Appletalk ARP
//  APRAINPROTOCOL           0xCC               /// ARPA_INTERNET_PROTOCAL
//  APRAADDRESO              0xCD               /// ARPA_ADDRESS_RESOLUTION
//  FLEXNET                  0xCE               /// FLEXNET
//  NETROM                   0xCF               /// NET_ROM
//  NOL3PROTOCOL             0xF0               /// NO_LAYER_3_PROTOCOL_IMPLEMENTED
//  ESCC                     0xFF               /// ESCAPE_CHARACTER

/******************************************************************
 * S frame control field
 */
//  SRR                      0x01
//  SRNR                     0x05
//  SREJ                     0x09
//  SSREJ                    0x0D

/******************************************************************
 * U frame control field
 */
//  SABM_CMD                 0x2F    /// [CMD]
//  SABME_CMD                0x6F    /// [CMD]
//  DISC_CMD                 0x43    /// [CMD]
/// ---------------------------------------------------------------------------------------------------------------
//  XID_CMD                  0xAF    /// [CMD]
//  XID_RES                  0xBF    /// [RES]
//  TEST_CMD                 0xE3    /// [CMD]
//  TEST_RES                 0xF3    /// [RES]
//  UI_CMD                   0x03    /// [CMD]
//  UI_RES                   0x13    /// [RES]
/// ---------------------------------------------------------------------------------------------------------------
//  UACK_RES                 0x73    /// [RES]
//  FRMR_RES                 0x97    /// [RES]
//  DM_RES                   0x1F    /// [RES]

#endif /* AX25_STRUCTURE_ISU_CTRLPID_FIELD_H_ */
