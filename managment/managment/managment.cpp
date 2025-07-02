#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include "remoteMangerExceptions.h"
#include "Remote_management.h"
#include "socketInterface.h"



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

    socketInterface::initializeWSA();
    socketInterface listeningSocket;
    listeningSocket.listenCommunication();
    socketInterface clientSocket = listeningSocket.acceptCommunication();
    std::cout << clientSocket.recvMessage() << std::endl;
    clientSocket.sendMessage("asdasdasd");

    



    WSACleanup();
}
