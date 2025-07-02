#pragma once
#include <iostream>
#include "remoteMangerExceptions.h"
class RegistryHandler {
  public:
    /*
     * get the process path
     * 
     * @param pathMaxSize - the max size of the path(default 150), throw error if size is too small
     * @return the path in std::string format
     * @exception - throw ShortPassError exception if the size too small
     */
    static std::string getProccessPath(int pathMaxSize = 150);
    /*
     * add the process executable to the autorun registry
     * 
     * @param executablePath - the path of executable to add to the autorun registry
     * @param autoranName - the registry key name
     * @exception - throw RegistryError exception if addToRegistry not worked
     */
    static void addToRegistry(std::string executablePath, std::string autoranName = "autoRun");
    /*
    * add the running process to the autorun registry
    * 
    * @param pathMaxSize - the max size of the process(default 150)
    * @exception - throw RegistryError exception if addToRegistry not worked
    *              throw ShortPassError exception if the size too small
    */
    static void addProcessRegistry(int pathMaxSize = 150);
};