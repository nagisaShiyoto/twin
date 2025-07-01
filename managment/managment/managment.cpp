#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "Remote_management.h"
#define DEFULT_PORT "1234"
#define MAX_MESSAGE_SIZE_DIGITS 5
// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")


int main() {
    char sizeInput[MAX_MESSAGE_SIZE_DIGITS] = {0}; 
    int size = 0;
    char* buffer = (char*)malloc(sizeof(char)*10);

    //HANDLE mutex = CreateMutexA(NULL, FALSE, "my_mutex");
    //if (WaitForSingleObject(mutex, 0) == WAIT_TIMEOUT) {
    //    std::cout << "used by another" << std::endl;
    //    return 1;
    //}
    //RemoteManagement manager;
    //return 0;

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        /* Tell the user that we could not find a usable */
        /* Winsock DLL.                                  */
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }
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
    recv(clientSocket, buffer, size, 0);
    std::cout << buffer << std::endl;


    closesocket(clientSocket);
    closesocket(listeningSocket);
    freeaddrinfo(addr);
    WSACleanup();
}
