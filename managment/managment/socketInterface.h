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
    /*
    * create the socket using certain address
    * 
    * @param ipAddress - the source ip address for this socket, default - callback("127.0.0.1")
    * @param port - the source port of this socket, default "1234"
    * @exceptions - bindingException is thrown when binding operation is unsuccessful
    *               AddressCreationException is thrown if address creation fails
    */
    socketInterface(const std::string& ipAddress = "127.0.0.1", const std::string& port = "1234");
    /*
     * create socket interface object using SOCKET object
     *
     * @param mySocket - the SOCKET object
     */
    socketInterface(SOCKET mySocket);
    /*
    * dtor for socket interface, close SOCKET object
    */
    ~socketInterface();
    /*
     * initialize the wsa library, specify we use wsa2.2
     *
     * @exceptions - when initialization fail WsaException is thrown
     */
    static void initializeWSA();
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
     * creating a structure with all needed address info, need to freeaddrinfo it after use
     *
     * @param ipAddress - the wanted ip address, default - callback(127.0.0.1)
     * @param port - the wanted port, default - 1234
     * @exceptions - AddressCreationException is thrown
     */
    static addrinfo* createAddrInfo(const std::string& ipAddress = "127.0.0.1", const std::string& port = "1234");

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
};
