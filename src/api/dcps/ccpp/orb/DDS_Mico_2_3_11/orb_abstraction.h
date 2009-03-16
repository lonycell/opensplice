#ifndef CCPP_ORB_ABSTRACTION_H
#define CCPP_ORB_ABSTRACTION_H

#include "CORBA.h"
#include "mico/value.h"

  namespace DDS
  {
    #define LOCAL_REFCOUNTED_OBJECT CORBA::LocalObject
    #define LOCAL_REFCOUNTED_VALUEBASE ::CORBA::SimpleValueRefCountBase
    
    #define THROW_ORB_EXCEPTIONS 
    #define THROW_ORB_AND_USER_EXCEPTIONS(...)
    
    #define THROW_VALUETYPE_ORB_EXCEPTIONS
    #define THROW_VALUETYPE_ORB_AND_USER_EXCEPTIONS(...)
  };


#endif /* ORB_ABSTRACTION */
