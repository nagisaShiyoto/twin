#pragma once
#include <iostream>

class registryHandler {
  public:
    /*
     * get the process path
     * 
     * @param pathMaxSize - the max size of the path(default 150), throw error if size is too small
     * @return the path in std::string format
     */
    static std::string getProccessPath(int pathMaxSize = 150);
    /*
     * add the process executable to the autorun registry
     * 
     * @param executablePath - the path of executable to add to the autorun registry
     * @param autoranName - the registry key name
     */
    static void addToRegistry(std::string executablePath, std::string autoranName = "autoRun");
    /*
    * add the running process to the autorun registry
    * 
    * @param pathMaxSize - the max size of the process(default 150)
    */
    static void addProcessRegistry(int pathMaxSize = 150);
};
