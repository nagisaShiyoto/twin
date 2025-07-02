#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include "remoteMangerExceptions.h"
#include "Remote_management.h"
#include "socketInterface.h"



int main() {
    try {
        RemoteManagement manager;
    } catch (const GeneralExceptionClass e) {
        std::cout << e.getError() << std::endl;
    }

    socketInterface::initializeWSA();
    socketInterface listeningSocket;
    listeningSocket.listenCommunication();
    socketInterface clientSocket = listeningSocket.acceptCommunication();
    std::cout << clientSocket.recvMessage() << std::endl;
    clientSocket.sendMessage("asdasdasd");

    



    WSACleanup();
}
