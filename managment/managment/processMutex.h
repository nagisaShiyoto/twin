#pragma once
#include <Windows.h>
#include <iostream>
class processMutex {
  public:
    /*
    * creating mutex and trying top lock it
    * 
    * @param mutexName - the name of the mutex
    * @exceptions - throw exception if it could not lock the mutex
    */
    processMutex(std::string mutexName);
    processMutex();

    /*
    * free the mutex
    */
    ~processMutex();
  private:
    HANDLE m_mutex;
};
