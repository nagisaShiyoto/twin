#define WIN32_LEAN_AND_MEAN

#include "serverHandler.h"
#include "SocketExceptions.h"

#define PING_COMMAND "PING"
#define PING_RESPONCE "PONG"
#define UNKOWN_COMMAND_RESPONCE "Unknown response"

serverHandler::serverHandler(const std::string& ipAddress, const std::string& port)
    : m_listeningSocket(port, ipAddress) {
    this->m_listeningSocket.listenCommunication();

}

void serverHandler::waitForClient() {
    socketInterface temp = this->m_listeningSocket.acceptCommunication();
    temp.setTemp(true);
    this->m_ClientSocket = temp;
}

void serverHandler::handleMessage(int maxDigitMessageSize) {
    std::string message = this->m_ClientSocket.recvMessage(maxDigitMessageSize);

    std::cout << message << std::endl;

    if (message == PING_COMMAND) {
        this->handlePingCommand();
    } else {
        this->handleUnkownCommand();
    }
}

void serverHandler::handleCommunication() {
    this->waitForClient();

    try {
        while (true) {
            this->handleMessage();
        }
    } catch (const SocketDisconnectedException& e) {
        std::cout << e.getError() << std::endl;
    }

}

void serverHandler::handlePingCommand() {
    this->m_ClientSocket.sendMessage(PING_RESPONCE);
}

void serverHandler::handleUnkownCommand() {
    this->m_ClientSocket.sendMessage(UNKOWN_COMMAND_RESPONCE);
}
