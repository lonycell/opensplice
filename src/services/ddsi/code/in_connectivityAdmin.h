/*
 * in_connectivityAdmin.h
 *
 */

#ifndef IN_CONNECTIVITYADMIN_H_
#define IN_CONNECTIVITYADMIN_H_


#include "in_commonTypes.h"
#include "in_ddsiElements.h"
#include "in_connectivityListener.h"
#include "in_connectivityPeerReader.h"
#include "in_connectivityPeerWriter.h"
#include "in_connectivityPeerParticipant.h"
#include "in_connectivityWriterFacade.h"
#include "in_connectivityReaderFacade.h"
#include "in_connectivityParticipantFacade.h"

#if defined (__cplusplus)
extern "C" {
#endif

/* The usual cast-method for class in_connectivityAdsmin. Note that because
 * in_connectivityAdmin does not contain any metadata there is no type checking
 * performed.
 */
#define in_connectivityAdmin(admin) ((in_connectivityAdmin)admin)


in_connectivityAdmin
in_connectivityAdminGetInstance(
    );

in_result
in_connectivityAdminAddParticipant(
    in_connectivityAdmin _this,
    struct v_participantInfo *participant
    );

in_result
in_connectivityAdminAddReader(
    in_connectivityAdmin _this,
    struct v_subscriptionInfo *reader
    );

in_result
in_connectivityAdminAddWriter(
    in_connectivityAdmin _this,
    struct v_publicationInfo *writer
    );

in_connectivityParticipantFacade
in_connectivityAdminGetParticipant(
    in_connectivityAdmin _this,
    struct v_participantInfo *participant
    );

in_connectivityReaderFacade
in_connectivityAdminGetReader(
    in_connectivityAdmin _this,
    struct v_subscriptionInfo *reader
    );

in_connectivityWriterFacade
in_connectivityAdminGetWriter(
    in_connectivityAdmin _this,
    struct v_publicationInfo *writer
    );
Coll_Set*
in_connectivityAdminGetParticipants(
    in_connectivityAdmin _this);

Coll_Set*
in_connectivityAdminGetReaders(
    in_connectivityAdmin _this);

Coll_Set*
in_connectivityAdminGetWriters(
    in_connectivityAdmin _this);

in_result
in_connectivityAdminRemoveParticipant(
    in_connectivityAdmin _this,
    struct v_participantInfo *participant
    );

in_result
in_connectivityAdminRemoveReader(
    in_connectivityAdmin _this,
    struct v_subscriptionInfo *reader
    );

in_result
in_connectivityAdminRemoveWriter(
    in_connectivityAdmin _this,
    struct v_publicationInfo *writer
    );

in_result
in_connectivityAdminAddPeerParticipant(
    in_connectivityAdmin _this,
    in_connectivityPeerParticipant participant);

in_result
in_connectivityAdminAddPeerReader(
    in_connectivityAdmin _this,
    in_connectivityPeerReader reader);

in_result
in_connectivityAdminAddPeerWriter(
    in_connectivityAdmin _this,
    in_connectivityPeerWriter writer);

in_connectivityPeerParticipant
in_connectivityAdminGetPeerParticipant(
    in_connectivityAdmin _this,
    in_ddsiGuid guid);

in_connectivityPeerReader
in_connectivityAdminGetPeerReader(
    in_connectivityAdmin _this,
    in_ddsiGuid guid);

in_connectivityPeerWriter
in_connectivityAdminGetPeerWriter(
    in_connectivityAdmin _this,
    in_ddsiGuid guid);

in_result
in_connectivityAdminRemovePeerParticipant(
    in_connectivityAdmin _this,
    in_ddsiGuid guid);

in_result
in_connectivityAdminRemovePeerReader(
    in_connectivityAdmin _this,
    in_ddsiGuid guid);

in_result
in_connectivityAdminRemovePeerWriter(
    in_connectivityAdmin _this,
    in_ddsiGuid guid);

in_result
in_connectivityAdminAddListener(
    in_connectivityAdmin _this,
    in_connectivityListener listener);

in_result
in_connectivityAdminRemoveListener(
    in_connectivityAdmin _this,
    in_connectivityListener listener);


#if defined (__cplusplus)
}
#endif

#endif /* IN_CONNECTIVITYADMIN_H_ */