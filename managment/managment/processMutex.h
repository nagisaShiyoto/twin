#pragma once
#include <Windows.h>
#include <iostream>
#include "remoteMangerExceptions.h"
class processMutex {
  public:
    /*
    * creating mutex and trying top lock it
    * 
    * @param mutexName - the name of the mutex
    * @exceptions - throw MutexException exception if it could not lock the mutex with the same name
    */
    processMutex(std::string const mutexName);
    /*
     * creating mutex with the name myMutex and trying top lock it
     *
     * @param mutexName - the name of the mutex
     * @exceptions - throw MutexException exception if it could not lock the mutex with the same name
     */
    processMutex();

    /*
    * free the mutex
    */
    ~processMutex();
  private:
    HANDLE m_mutex;
};

