#define WIN32_LEAN_AND_MEAN

#include "socketInterface.h"
#include <string>
#include "SocketExceptions.h"
#include "AddrInfoWrapper.h"

socketInterface::socketInterface(const std::string& port, const std::string& ipAddress) : m_tempSocket(false){
    int iResult = 0;
    AddrInfoWrapper addr(ipAddress, port);
    this->m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    iResult = bind(this->m_socket, addr.m_addr->ai_addr, addr.m_addr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        throw BindingException("Binding");
    }
}

socketInterface::socketInterface(SOCKET mySocket) : m_socket(mySocket), m_tempSocket(false) {
    //empty code block
}

socketInterface::socketInterface() : m_socket(INVALID_SOCKET), m_tempSocket(false) {
    //empty code block
}

socketInterface::~socketInterface() {
    if (!this->m_tempSocket) {
        closesocket(this->m_socket);
    }
}

std::string socketInterface::zeroPadding(int number, int const maxDigit) {
    std::string padded_str = std::to_string(number);
    int zeroAmount = maxDigit - log10(number);
    if (0 > zeroAmount) {
        throw PaddingException("number to big, to many digits");
    }
    padded_str.insert(0, zeroAmount, '0');
    return padded_str;
}

void socketInterface::setTemp(const bool isTemp) {
    this->m_tempSocket = isTemp;
}

void socketInterface::listenCommunication() {
    if (listen(this->m_socket, SOMAXCONN) == SOCKET_ERROR) {
        throw ListenException("listen operation");
    }
    
}

socketInterface socketInterface::acceptCommunication() {
    SOCKET clientSocket = accept(this->m_socket, NULL, NULL);
    if (INVALID_SOCKET == clientSocket) {
        throw AcceptClientException("accept client operation");
    }
    return socketInterface(clientSocket);
}

socketInterface socketInterface::acceptCommunication(const std::string& ipAddress, const std::string& port) {
    AddrInfoWrapper addr(ipAddress, port);
    int* addrLen = (int*)&addr.m_addr->ai_addrlen;
    SOCKET clientSocket = accept(this->m_socket, addr.m_addr->ai_addr, addrLen);
    if (INVALID_SOCKET == clientSocket) {
        throw AcceptClientException("accept client operation");
    }
    return socketInterface(clientSocket);
}

std::string socketInterface::recvMessage(int const maxDigitSizeBuffer) {
    std::string sizeBuffer("", maxDigitSizeBuffer);
    std::string buffer = "";
    int size = 0;
    int byteReceived = recv(this->m_socket, const_cast<char*>(sizeBuffer.c_str()), maxDigitSizeBuffer, 0); 
    if (byteReceived == 0) {
        throw SocketDisconnectedException("socket disconnected abruptly");
    }
    size = stoi(sizeBuffer);
    buffer.resize(size);
    recv(this->m_socket, const_cast<char*>(buffer.c_str()), size, 0);
    return buffer;
}

void socketInterface::sendMessage(std::string message, int const maxDigitSizeBuffer) {
    int message_size = message.length();
    std::string fullMessage = zeroPadding(message_size, maxDigitSizeBuffer) + message;
    int iResult = send(this->m_socket, fullMessage.c_str(), message_size + maxDigitSizeBuffer, 0);
    if (SOCKET_ERROR == iResult) {
        throw sendSocketException("sending");
    }
}
