#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "Remote_management.h"
#define DEFULT_PORT "1234"
// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")


int main() {
    HANDLE mutex = CreateMutexA(NULL, FALSE, "my_mutex");
    if (WaitForSingleObject(mutex, 0) == WAIT_TIMEOUT) {
        std::cout << "used by another" << std::endl;
        return 1;
    }
    RemoteManagement manager;
    return 0;
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
    getaddrinfo(NULL, DEFULT_PORT, NULL, &addr);
    SOCKET listeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int result = bind(listeningSocket,addr->ai_addr, addr->ai_addrlen);
    std::cout << "asdasd" << std::endl;
}
