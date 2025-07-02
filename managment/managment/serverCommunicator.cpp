#include "serverCommunicator.h"
#include <Windows.h>
#include <iostream>
void serverCommunicator::initializeWSA() {
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        throw std::exception("WSAStartup failed with error: %d\n", err);
    }
}
