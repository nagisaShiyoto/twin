#pragma once
#include <Windows.h>
#include "processMutex.h"

#define PATH_SIZE 100

class RemoteManagement {
  public:
    /*
    * create remote management object
    * 
    * @exceptions - throw MutexException exception if it could not lock the mutex with the same name
    *               throw RegistryError exception if addToRegistry not worked
    *               throw ShortPassError exception if the size too small
    */
    RemoteManagement();

  private:
    processMutex m_mutex;
};
