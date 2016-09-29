#ifndef _sbn_msg_h_
#define _sbn_msg_h_

#include "sbn_msgdefs.h"
#include "sbn_platform_cfg.h"
#include "sbn_constants.h"
#include "cfe.h"

/**
 * \brief No Arguments Command
 * For command details see #SBN_NOOP_CC, #SBN_RESET_CC
 * Also see #SBN_SEND_HK_CC
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} SBN_NoArgsCmd_t;

/**
 * \brief Reset Peer Command
 * For command details see #SBN_RESET_PEER_CC
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    uint8 PeerIdx;
} SBN_PeerIdxArgsCmd_t;

typedef struct {
    uint8 Idx, NetNum, QoS, ProtocolId, State; // 5 bytes
    uint8 Padding[3]; // 5 + 3 = 8 bytes
    char Name[SBN_MAX_PEERNAME_LENGTH]; // 8 + 32 = 40 bytes
    uint32 ProcessorId, SpacecraftId; // 40 + 8 = 48 bytes
    OS_time_t LastSent, LastReceived; // 48 + 8 = 56 bytes
    uint16 SentCount, RecvCount, // 56 + 4 = 60 bytes
        SentErrCount, RecvErrCount, SubCount; // 60 + 6 = 66 bytes
    uint8 Padding2[6]; // 66 + 6 = 72
    uint8 IFData[32]; /* opaque, dependent on the interface module */
} SBN_PeerStatus_t;

typedef struct {
    uint8 Idx; // 1 byte
    uint8 NetNum; // 1 + 1 = 2 bytes
    uint8 ProtocolId; // 2 + 1 = 3 bytes
    uint8 Padding; // 3 + 1 = 4 bytes
    uint32 SpacecraftId; // 4 + 4 = 8 bytes
    uint8 IFData[32]; /* opaque, dependent on the interface module */
} SBN_HostStatus_t;

/**
 * \brief Housekeeping packet structure
 */
typedef struct {
    uint8  TlmHeader[CFE_SB_TLM_HDR_SIZE];

    uint8 CC; // 1 byte

    uint8 CmdCount; // 1 + 1 = 2 bytes
    uint8 CmdErrCount; // 2 + 1 = 3 bytes

    uint8 Padding; // 3 + 1 = 4 bytes

    uint16 SubCount; // 4 + 2 = 6 bytes

    uint16 EntryCount; // 6 + 2 = 8 bytes
    uint16 HostCount; // 8 + 2 = 10 bytes
    uint16 PeerCount; // 10 + 2 = 12 bytes // want to 32-bit align below

    /* SBN Module Stats */
    SBN_PeerStatus_t PeerStatus[SBN_MAX_NETWORK_PEERS];
    SBN_HostStatus_t HostStatus[SBN_MAX_NETWORK_PEERS];
} SBN_HkPacket_t;

typedef struct {
    uint8  TlmHeader[CFE_SB_TLM_HDR_SIZE];

    uint8 CC;
    uint8 PeerIdx;
    uint16 SubCount;

    CFE_SB_MsgId_t Subs[SBN_MAX_SUBS_PER_PEER];
} SBN_HkSubsPkt_t;
/**
 * \brief Module status response packet structure
 */
typedef struct {
    uint8   TlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint32  ProtocolId;
    uint8   ModuleStatus[SBN_MOD_STATUS_MSG_SIZE];
} SBN_ModuleStatusPacket_t;

#endif /* _sbn_msg_h_ */
