#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

class AddrInfoWrapper {
  public:
    /*
     * creating a wrapper to the data structure, need to freeaddrinfo it after use
     *
     * @param ipAddress - the wanted ip address, default - callback(127.0.0.1)
     * @param port - the wanted port, default - 1234
     * @exceptions - AddressCreationException is thrown
     */
    AddrInfoWrapper(const std::string& ipAddress, const std::string& port);
    /*
    * dtor to the wrapper, free address struct
    */
    ~AddrInfoWrapper();

    addrinfo* m_addr;
};
