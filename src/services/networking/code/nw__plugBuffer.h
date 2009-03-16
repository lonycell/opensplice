
#ifndef NW__PLUGBUFFER_H
#define NW__PLUGBUFFER_H

#include "nw_plugTypes.h"

#define nw_plugBuffer(o) ((nw_plugBuffer)(o))

/* nw_plugBuffer contains attributes common for all messages */

/* Important note: make sure that this message has the same memory layout on all
 *                 supported platforms. endianness may differ but alignment
 *                 needs to match */
NW_CLASS(nw_plugBuffer);
NW_STRUCT(nw_plugBuffer) {
    os_char version[4];
    /* flags for QoS-es */
    nw_flags flags;
    /* Id of the sending node */
    nw_seqNr sendingNodeId;
    /* The number of bytes within this fragment */
    nw_length length;
    /* Id of the receiving node in case of P2P communication */
    nw_seqNr receivingNodeId;
};
#define NW_CURRENT_PROTOCOL_VERSION '1'


#define nw_plugBufferGetSendingNodeId(buffer)                 nw_plugNetworkToHost(buffer->sendingNodeId)
#define nw_plugBufferSetSendingNodeId(buffer, value)          buffer->sendingNodeId = nw_plugHostToNetwork(value)

#define nw_plugBufferGetLength(buffer)                        nw_plugNetworkToHost(buffer->length)
#define nw_plugBufferSetLength(buffer, value)                 buffer->length = nw_plugHostToNetwork(value)

#define nw_plugBufferGetReceivingNodeId(buffer)               nw_plugNetworkToHost(buffer->receivinNodeId)
#define nw_plugBufferSetReceivingNodeId(buffer, value)        buffer->receivingNodeId = nw_plugHostToNetwork(value)


/* --------------------------- flag getters/setters ------------------------- */


#define NW_FLAGS_CLEAR     (0x0U)
#define NW_FLAG_CONTROL    (0x1U)
#define NW_FLAG_RELIABLE   (NW_FLAG_CONTROL    << 1)
#define NW_FLAG_FRAGMENTED (NW_FLAG_RELIABLE   << 1)
#define NW_FLAG_TERMINATOR (NW_FLAG_FRAGMENTED << 1)
#define NW_FLAG_P2P        (NW_FLAG_TERMINATOR << 1)


#define NW_PLUGBUFFER_SET_FLAG(buffer, flagValue, switchOn)                    \
    if (switchOn) {                                                            \
        *(unsigned char *)(&buffer->flags) =                                   \
            *(unsigned char *)(&buffer->flags) | (unsigned char)(flagValue);   \
    } else {                                                                   \
        *(unsigned char *)(&buffer->flags) =                                   \
            *(unsigned char *)(&buffer->flags) & (unsigned char)~(flagValue);  \
    }
    
#define NW_PLUGBUFFER_GET_FLAG(buffer, flagValue)                           \
    ((*(unsigned char *)&(buffer)->flags & (unsigned char)flagValue) != 0)

#define nw_plugBufferSetVersion(buffer,version_id)                              \
    (buffer)->version[0] = 'S';                                             \
    (buffer)->version[1] = 'P';                                             \
    (buffer)->version[2] = 'L';                                             \
    (buffer)->version[3] = version_id;  

#define nw_plugBufferCheckVersion(buffer,version_id)                           \
    (((buffer)->version[0] == 'S') &&                                       \
     ((buffer)->version[1] == 'P') &&                                       \
     ((buffer)->version[2] == 'L') &&                                       \
     ((buffer)->version[3] == version_id))  
    

#define nw_plugBufferClearFlags(buffer)                                     \
    (buffer)->flags = NW_FLAGS_CLEAR
    
#define nw_plugBufferSetControlFlag(buffer, control)                        \
    NW_PLUGBUFFER_SET_FLAG(buffer, NW_FLAG_CONTROL, control)
#define nw_plugBufferGetControlFlag(buffer)                                 \
    NW_PLUGBUFFER_GET_FLAG(buffer, NW_FLAG_CONTROL)
    
#define nw_plugBufferSetReliabilityFlag(buffer, reliability)                \
    NW_PLUGBUFFER_SET_FLAG(buffer, NW_FLAG_RELIABLE, reliability)
#define nw_plugBufferGetReliabilityFlag(buffer)                             \
    NW_PLUGBUFFER_GET_FLAG(buffer, NW_FLAG_RELIABLE)
    
#define nw_plugBufferSetFragmentedFlag(buffer, fragmented)                  \
    NW_PLUGBUFFER_SET_FLAG(buffer, NW_FLAG_FRAGMENTED, fragmented)
#define nw_plugBufferGetFragmentedFlag(buffer)                              \
    NW_PLUGBUFFER_GET_FLAG(buffer, NW_FLAG_FRAGMENTED)
    
#define nw_plugBufferSetTerminatorFlag(buffer, terminator)                  \
    NW_PLUGBUFFER_SET_FLAG(buffer, NW_FLAG_TERMINATOR, terminator)
#define nw_plugBufferGetTerminatorFlag(buffer)                              \
    NW_PLUGBUFFER_GET_FLAG(buffer, NW_FLAG_TERMINATOR)
    
#define nw_plugBufferSetP2PFlag(buffer, p2p)                                \
    NW_PLUGBUFFER_SET_FLAG(buffer, NW_FLAG_P2P, p2p)
#define nw_plugBufferGetP2PFlag(buffer)                                     \
    NW_PLUGBUFFER_GET_FLAG(buffer, NW_FLAG_P2P)

#endif /* NW__PLUGBUFFER_H */