/******************************************************************************
** File: sbn_constants.h
**
**      Copyright (c) 2004-2016, United States government as represented by the
**      administrator of the National Aeronautics Space Administration.
**      All rights reserved. This software(cFE) was created at NASA's Goddard
**      Space Flight Center pursuant to government contracts.
**
**      This software may be used only pursuant to a United States government
**      sponsored project and the United States government may not be charged
**      for use thereof.
**
** Purpose:
**      This header file contains prototypes for private functions and type
**      definitions for the Software Bus Network Application.
**
** Authors:   J. Wilmot/GSFC Code582
**            R. McGraw/SSI
**            C. Knight/ARC Code TI
******************************************************************************/
#include "cfe.h"

#ifndef _sbn_constants_h_
#define _sbn_constants_h_

#define SBN_SUCCESS                   0
#define SBN_ERROR                     (-1)
#define SBN_IF_EMPTY                  (-2)
#define SBN_NOT_IMPLEMENTED           (-3)

#define SBN_MAX_SUBS_PER_PEER       256 
#define SBN_DONT_CARE               0
#define SBN_MAX_PEER_PRIORITY       16
#define SBN_MAX_NETS                16
#define SBN_MAX_PEERS_PER_NET       32
#define SBN_MAX_PEERNAME_LENGTH     32
#define SBN_MAX_NET_NAME_LENGTH     16

/* at most process this many SB messages per peer per wakeup */
#define SBN_MAX_MSG_PER_WAKEUP        32

#define SBN_UDP                       1
#define SBN_TCP                       2
#define SBN_SPACEWIRE_RMAP            3
#define SBN_SPACEWIRE_PKT             4
#define SBN_SHMEM                     5
#define SBN_SERIAL                    6
#define SBN_1553                      7
#define SBN_DTN                       8

#define SBN_MAIN_LOOP_DELAY           200 /* milli-seconds */

/* A peer can either be disconnected (and we have it marked as "ANNOUNCING")
 * or it is connected and we expect traffic or if we don't see any in a period
 * of time, we send a heartbeat to see if the peer is alive.
 */

/* How many seconds to wait between announce messages. */
#define SBN_ANNOUNCE_TIMEOUT          10

/* If I don't send out traffic for a period of time, send out a heartbeat
 * so that my peer doesn't think I've disappeared. (This should be shorter
 * than the SBN_HEARTBEAT_TIMEOUT below!)
 */
#define SBN_HEARTBEAT_SENDTIME        5

/* How many seconds since I last saw a message from my peer do I mark it as
 * timed out?
 */
#define SBN_HEARTBEAT_TIMEOUT         10

#define SBN_PEER_PIPE_DEPTH           64
#define SBN_DEFAULT_MSG_LIM           8
#define SBN_ITEMS_PER_FILE_LINE       6
#define SBN_MSG_BUFFER_SIZE           (SBN_PEER_PIPE_DEPTH * 2) /* uint8 */

/* SBN States */
#define SBN_ANNOUNCING                0
#define SBN_HEARTBEATING              1

/* Message types definitions */
#define SBN_NO_MSG                    0x0000
#define SBN_ANNOUNCE_MSG              0x0010
#define SBN_HEARTBEAT_MSG             0x0020
#define SBN_SUBSCRIBE_MSG             0x0030
#define SBN_UN_SUBSCRIBE_MSG          0x0040
#define SBN_APP_MSG                   0x0050

#define SBN_IDENT           "$Id$"
#define SBN_IDENT_LEN       48 /**< \brief Id is always the same len, plus \0 */

#endif /* _sbn_constants_h_ */
/*****************************************************************************/
