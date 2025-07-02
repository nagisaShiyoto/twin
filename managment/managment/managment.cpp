#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>

#include "remoteMangerExceptions.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include "Remote_management.h"
#define DEFULT_PORT "1234"
#define MAX_MESSAGE_SIZE_DIGITS 6

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")


int main() {
    try {
        RemoteManagement manager;
    } catch (const MutexException e) {
        std::cout << "couldn't create mutex:" << std::endl;
        std::cout << e.getError() << std::endl;
    } catch (const ShortPathException e) {
        std::cout << e.getError() << std::endl;
    } catch (const RegistryException e) {
        std::cout << "registry error:" << std::endl;
        std::cout << e.getError() << std::endl;
    }

    char* buffer = (char*)malloc(sizeof(char) * 10);
    char sizeInput[MAX_MESSAGE_SIZE_DIGITS] = {0};
    int size = 0;

    addrinfo* addr;
    getaddrinfo("127.0.0.1", DEFULT_PORT, NULL, &addr);
    SOCKET listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int iResult = bind(listeningSocket,addr->ai_addr, addr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        return 1;
    }
    if (listen(listeningSocket, SOMAXCONN) == SOCKET_ERROR) {
        printf("Listen failed with error: %ld\n", WSAGetLastError());
        closesocket(listeningSocket);
        WSACleanup();
        return 1;
    }
    SOCKET clientSocket = accept(listeningSocket, NULL, NULL);
    recv(clientSocket, sizeInput, MAX_MESSAGE_SIZE_DIGITS, 0);
    size = atoi(sizeInput);
    realloc(buffer, sizeof(char) * size);
    recv(clientSocket, buffer, size, 0);
    buffer[size] = NULL;
    std::cout << buffer << std::endl;


    closesocket(clientSocket);
    closesocket(listeningSocket);
    freeaddrinfo(addr);
    WSACleanup();
}
