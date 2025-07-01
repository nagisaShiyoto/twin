#pragma once
class serverCommunicator {
    void initializeWSA();
    SOCKET createListeningSocket(std::string ip_addr, std::string port);
};
