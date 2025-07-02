#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include "remoteMangerExceptions.h"
#include "Remote_management.h"
#include "CommunicatorHandler.h"



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

    CommunicatorHandler::initializeWSA();
    SOCKET listeningSocket = CommunicatorHandler::createListeningSocket();
    SOCKET clientSocket = CommunicatorHandler::acceptCommunication(listeningSocket);
    std::cout << CommunicatorHandler::recvMessage(clientSocket, 5);
    CommunicatorHandler::sendMessage(clientSocket, "asdasdasd");

    


    closesocket(clientSocket);
    closesocket(listeningSocket);
    WSACleanup();
}
