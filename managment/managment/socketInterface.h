#pragma once
#include <Windows.h>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

class socketInterface {
  public:
    socketInterface(std::string const serverIpAddress = "127.0.0.1", std::string const port = "1234");

    static addrinfo* createAddrInfo(std::string const ipAddress = "127.0.0.1", std::string const port = "1234");
};
