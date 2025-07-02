#define WIN32_LEAN_AND_MEAN
#include "socketInterface.h"
#include <string>

socketInterface::socketInterface(std::string const serverIpAddress, std::string const port) {
    int iResult = 0;
    addrinfo* addr = createAddrInfo(serverIpAddress, port);
    this->m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    iResult = bind(this->m_socket, addr->ai_addr, addr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        throw "Asd";
    }
    freeaddrinfo(addr);
}

socketInterface::socketInterface(SOCKET mySocket) {
    this->m_socket = mySocket;
}

socketInterface::~socketInterface() {
    closesocket(this->m_socket);
}

void socketInterface::initializeWSA() {
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        std::cout << "awitsch !!";
        throw std::exception("WSAStartup failed with error: %d\n", err);
    }
}

std::string socketInterface::zeroPadding(int size, int const maxDigit) {
    std::string padded_str = std::to_string(size);
    int zeroAmount = maxDigit - log10(size);
    padded_str.insert(0, zeroAmount, '0');
    return padded_str;
}

addrinfo* socketInterface::createAddrInfo(std::string const ipAddress, std::string const port) {
    addrinfo* addr;
    int iResult = getaddrinfo(ipAddress.c_str(), port.c_str(), NULL, &addr);
    if (iResult != 0) {
        throw "Asd";
    }
    return addr;
}

void socketInterface::listenCommunication() {
    if (listen(this->m_socket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Listen failed with error: %ld\n", WSAGetLastError());
        throw "Asd";
    }
    
}

socketInterface socketInterface::acceptCommunication() {
    SOCKET clientSocket = accept(this->m_socket, NULL, NULL);
    if (INVALID_SOCKET == clientSocket) {
        throw "Asd";
    }
    return socketInterface(clientSocket);
}

socketInterface socketInterface::acceptCommunication(std::string const server_ip_address, std::string const port) {
    addrinfo* addr = createAddrInfo(server_ip_address, port);
    int* addrLen = (int*)&addr->ai_addrlen;
    SOCKET clientSocket = accept(this->m_socket, addr->ai_addr, addrLen);
    if (INVALID_SOCKET == clientSocket) {
        throw "Asd";
    }
    freeaddrinfo(addr);
    return socketInterface(clientSocket);
}

std::string socketInterface::recvMessage(int const maxDigitSizeBuffer) {
    std::string sizeBuffer("", maxDigitSizeBuffer);
    std::string buffer = "";
    int size = 0;
    recv(this->m_socket, const_cast<char*>(sizeBuffer.c_str()), maxDigitSizeBuffer, 0);
    size = stoi(sizeBuffer);
    buffer.resize(size);
    recv(this->m_socket, const_cast<char*>(buffer.c_str()), size, 0);
    return buffer;
}

void socketInterface::sendMessage(std::string message, int const maxDigitSizeBuffer) {
    int message_size = message.length();
    std::string fullMessage = zeroPadding(message_size, maxDigitSizeBuffer) + message;
    send(this->m_socket, fullMessage.c_str(), message_size + maxDigitSizeBuffer, 0);
}
