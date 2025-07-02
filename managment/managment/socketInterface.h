#pragma once
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")
class socketInterface {
  public:
    socketInterface(std::string const serverIpAddress = "127.0.0.1", std::string const port = "1234");
    socketInterface(SOCKET mySocket);
    ~socketInterface();
    /*
     * initialize the wsa library, specify we use wsa2.2
     *
     * @exceptions -
     */
    static void initializeWSA();

    static std::string zeroPadding(int size, int const maxDigit = 5);
    /*
     * creating a structure with all needed address info, need to freeaddrinfo it after use
     *
     * @param ipAddress - the wanted ip address, default - callback(127.0.0.1)
     * @param port - the wanted port, default - 1234
     */
    static addrinfo* createAddrInfo(std::string const ipAddress = "127.0.0.1", std::string const port = "1234");
    

    void listenCommunication();

    socketInterface acceptCommunication();
    socketInterface acceptCommunication(std::string const server_ip_address, std::string const port);

    std::string recvMessage(int const maxDigitSizeBuffer = 5);
    void sendMessage(std::string message, int const maxDigitSizeBuffer = 5);

  private:
    SOCKET m_socket;
};
