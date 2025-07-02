#define WIN32_LEAN_AND_MEAN

#include "WsaInitializer.h"

#include <Windows.h>
#include <ws2tcpip.h>
#include <winsock2.h>
#include "SocketExceptions.h"


int WsaInitializer::m_instanceCounter = 0;

WsaInitializer::WsaInitializer() {
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    if (WsaInitializer::m_instanceCounter == 0) {
        wVersionRequested = MAKEWORD(2, 2);
        err = WSAStartup(wVersionRequested, &wsaData);
        if (err != 0) {
            throw WsaException("WSAStartup");
        }
    }
    WsaInitializer::m_instanceCounter++;

}

WsaInitializer::~WsaInitializer() {
    WsaInitializer::m_instanceCounter--;
    if (WsaInitializer::m_instanceCounter == 0)
    {
        WSACleanup();
    }
}
