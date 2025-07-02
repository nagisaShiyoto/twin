#pragma once

class WsaInitializer {
  public:
    /*
     * if it is the first instance initialize the wsa library, specify we use wsa2.2
     *
     * @exceptions - when initialization fail WsaException is thrown
     */
    WsaInitializer();
    /*
    * dtor to a specific instance, if it is the last instance use wsaCleanup 
    */
    ~WsaInitializer();

    static int m_instanceCounter;
};
