
#ifndef NW_CHANNELREADER_H
#define NW_CHANNELREADER_H

#include "nw_commonTypes.h" /* for NW_CLASS  */
#include "nw_channel.h" /* for sendChannel */
#include "u_networkReader.h" /* for u_networkReader */

NW_CLASS(nw_channelReader); /* extends from nw_channelUser */

nw_channelReader  nw_channelReaderNew(
                      const char *pathName,
                      nw_receiveChannel receiveChannel,
                      u_networkReader reader);

#endif /* NW_CHANNELREADER_H */
