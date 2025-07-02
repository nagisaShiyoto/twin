#define WIN32_LEAN_AND_MEAN
#include "CommunicatorHandler.h"
#include <string>


void CommunicatorHandler::initializeWSA() {
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

addrinfo* CommunicatorHandler::createAddrInfo(std::string const ipAddress, std::string const port) {
    addrinfo* addr;
    int iResult = getaddrinfo(ipAddress.c_str(), port.c_str(), NULL, &addr);
    if (iResult != 0) {
        throw "Asd";
    }
    return addr;
}

SOCKET CommunicatorHandler::createListeningSocket(std::string const serverIpAddress, std::string const port) {
    
    int iResult = 0;
    SOCKET listeningSocket = INVALID_SOCKET;
    addrinfo* addr = CommunicatorHandler::createAddrInfo(serverIpAddress, port);

    listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    iResult = bind(listeningSocket, addr->ai_addr, addr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        throw "Asd";
    }
    if (listen(listeningSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Listen failed with error: %ld\n", WSAGetLastError());
        closesocket(listeningSocket);
        WSACleanup();
        throw "Asd";
    }
    freeaddrinfo(addr);
    return listeningSocket;
}

SOCKET CommunicatorHandler::acceptCommunication(SOCKET listeningSocket) {
    SOCKET client_socket = accept(listeningSocket, NULL, NULL);
    if (INVALID_SOCKET == client_socket) {
        throw "Asd";
    }
    return client_socket;
}

SOCKET CommunicatorHandler::acceptCommunication(SOCKET listeningSocket, 
                                                std::string const server_ip_address,
                                                std::string const port) {
    addrinfo* addr = CommunicatorHandler::createAddrInfo(server_ip_address, port);
    int* addrLen = (int*)&addr->ai_addrlen;
    SOCKET client_socket = accept(listeningSocket, addr->ai_addr, addrLen);
    if (INVALID_SOCKET == client_socket) {
        throw "Asd";
    }
    freeaddrinfo(addr);
    return client_socket;
}

std::string CommunicatorHandler::recvMessage(SOCKET clientSocket, int const maxDigitSizeBuffer) {
    std::string sizeBuffer("", maxDigitSizeBuffer);
    std::string buffer = "";
    int size = 0;
    recv(clientSocket, const_cast<char*>(sizeBuffer.c_str()), maxDigitSizeBuffer, 0);
    size = stoi(sizeBuffer);
    buffer.resize(size);
    recv(clientSocket, const_cast<char*>(buffer.c_str()), size, 0);
    return buffer;
}

std::string CommunicatorHandler::zeroPadding(int size, int const maxDigit) {
    std::string padded_str = std::to_string(size);
    int zeroAmount= maxDigit - log10(size);
    padded_str.insert(0, zeroAmount, '0');
    return padded_str;
}

void CommunicatorHandler::sendMessage(SOCKET clientSocket, std::string message, int const maxDigitSizeBuffer) {
    int message_size = message.length();
    std::string fullMessage = zeroPadding(message_size, maxDigitSizeBuffer) + message;
    send(clientSocket, fullMessage.c_str(), message_size + maxDigitSizeBuffer, 0);
}
