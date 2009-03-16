#ifndef V_DURABILITY_H
#define V_DURABILITY_H

/** \file kernel/include/v_durability.h
 *  \brief This file defines the interface
 *
 */

#include "kernelModule.h"
#include "v_participantQos.h"

#if defined (__cplusplus)
extern "C" {
#endif
#include "os_if.h"

#ifdef OSPL_BUILD_KERNEL
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/**
 * \brief The <code>v_durability</code> cast method.
 *
 * This method casts an object to a <code>v_durability</code> object.
 * Before the cast is performed, if compiled with the NDEBUG flag not set,
 * the type of the object is checked to be <code>v_durability</code> or
 * one of its subclasses.
 */
#define v_durability(_this) (C_CAST(_this,v_durability))

OS_API v_durability
v_durabilityNew(
    v_serviceManager manager,
    const c_char *name,
    const c_char *extStateName,
    v_participantQos qos);

OS_API void
v_durabilityFree(
    v_durability _this);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif