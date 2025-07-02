#pragma once
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "WsaInitializer.h"

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

class socketInterface {
  public:
    /*
    * create the socket using certain address
    * 
    * @param ipAddress - the source ip address for this socket, default - callback("127.0.0.1")
    * @param port - the source port of this socket
    * @exceptions - bindingException is thrown when binding operation is unsuccessful
    *               AddressCreationException is thrown if address creation fails
    */
    socketInterface(const std::string& port, const std::string& ipAddress = "127.0.0.1");
    /*
     * create socket interface object using SOCKET object
     *
     * @param mySocket - the SOCKET object
     */
    socketInterface(SOCKET mySocket);
    /*
    * create default socket, an INVALID_SOCKET
    */
    socketInterface();
    /*
    * dtor for socket interface, close SOCKET object
    */
    ~socketInterface();
    /*
    * created a padded string from integer
    * 
    * @param number - the number to do the padding
    * @param maxDigit - amount of needed digits(including number's digits), default - 5
    * @return - padded string
    * @exceptions - when number is too big for padding(to many digits) padding exception is thrown
    */
    static std::string zeroPadding(int number, int const maxDigit = 5);
    /*
    * changing socket to temporary or not
    * 
    * @param isTemp:true - make it temporary
    *               false - make it not temporary 
    */
    void setTemp(const bool isTemp);
    /*
    * change the socket to a listening socket
    * exceptions - if listen fails throw ListenException
    */
    void listenCommunication();

    /*
    * wait and accept any user first interaction
    * 
    * @return - a socket connection to the client
    * @exceptions - AcceptClientException is thrown if accept operation fails
    */
    socketInterface acceptCommunication();
    /*
     * wait and accept specific user(with a specific address) first interaction
     *
     * @param ipAddress - the dst ip source(client ip) to wait to
     * @param port - the dst port(client port) to wait to
     * @return - a socket connection to the client
     * @exceptions - AcceptClientException is thrown if accept operation fails
     *               AddressCreationException is thrown if address creation fails
     */
    socketInterface acceptCommunication(const std::string& ipAddress, const std::string& port);

    /*
    * receiving message from user
    * 
    * @param maxDigitSizeBuffer - the max digit the message's size can be, default -5
    * @return - the user's message
    * @exceptions - when socket no longer active throw SocketDisconnectedException
    */
    std::string recvMessage(int const maxDigitSizeBuffer = 5);
    /*
     * sending message to user
     *
     * @param maxDigitSizeBuffer - the max digit the message's size can be, default - 5
     * @param message - the message to send to user
     * @exceptions - when number is too big for padding(to many digits) padding exception is thrown
     */
    void sendMessage(std::string message, int const maxDigitSizeBuffer = 5);

  private:
    SOCKET m_socket;
    bool m_tempSocket;
    WsaInitializer m_wsaObject;
};
