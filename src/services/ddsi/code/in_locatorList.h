/*
 * in_locatorList.h
 *
 *  Created on: Mar 9, 2009
 *      Author: frehberg
 */

#ifndef IN_LOCATORLIST_H_
#define IN_LOCATORLIST_H_

#include "in_locator.h"
#include "Coll_List.h"


#if defined (__cplusplus)
extern "C" {
#endif

/** */
typedef Coll_List in_locatorList;

/** */
os_boolean
in_locatorListInit(in_locatorList *_this);

/** */
void
in_locatorListDeinit(in_locatorList *_this);


/** */
os_boolean
in_locatorListPushBack(in_locatorList *_this,
        in_locator newElem);

/** */
in_locator
in_locatorListPopBack(in_locatorList *_this);


#if defined (__cplusplus)
}
#endif


#endif /* IN_LOCATORLIST_H_ */