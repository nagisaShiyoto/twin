#pragma once
#include <iostream>
#include <Windows.h>

#include <Windows.h>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

class CommunicatorHandler {
  public:
    /*
    * initialize the wsa library, specify we use wsa2.2
    * 
    * @exceptions - 
    */
    static void initializeWSA();
    /*
    * creating a structure with all needed address info, need to freeaddrinfo it after use
    * 
    * @param ipAddress - the wanted ip address, default - callback(127.0.0.1)
    * @param port - the wanted port, default - 1234
    */
    static addrinfo* createAddrInfo(std::string const ipAddress = "127.0.0.1", 
                                    std::string const port = "1234");
    /*
    * create a listening socket with a certain address, need to use close socket after use
    * 
    * @param ipAddress - the ip the server will listen in, default - callback(127.0.0.1)
    * @param port - the port the server will listen in, default - 1234
    */
    static SOCKET createListeningSocket(std::string const serverIpAddress = "127.0.0.1",
                                        std::string const port = "1234");
    /*
    */
    static SOCKET acceptCommunication(SOCKET listeningSocket);
    /*
    accept specific entity
    */
    static SOCKET acceptCommunication(SOCKET listeningSocket, 
                                      std::string const server_ip_address,
                                      std::string const port);

    static std::string recvMessage(SOCKET clientSocket, int const maxDigitSizeBuffer);

    static std::string zeroPadding(int size, int const maxDigit = 5);

    static void sendMessage(SOCKET clientSocket, std::string message, int const maxDigitSizeBuffer = 5);
};
