#pragma once
#include <iostream>
#include "GeneralErrorClass.h"
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

class RegistryError : public GeneralErrorClass{
  public:
    /*
     * create registry error object(inherit from general error class)
     *
     * @param errorMessage - the error description
     */
    RegistryError(std::string const errorMessage);
    /*
     * distructor for the object,
     * do nothing, mostly for inheritance
     */
    ~RegistryError();
};

class ShortPathError : public GeneralErrorClass {
  public:
    /*
     * create short pass error object(inherit from general error class)
     *
     * @param errorMessage - the error description
     */
    ShortPathError(std::string const errorMessage);
    /*
     * distructor for the object,
     * do nothing, mostly for inheritance
     */
    ~ShortPathError();
};