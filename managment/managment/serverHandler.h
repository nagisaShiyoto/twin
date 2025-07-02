#pragma once
#include "socketInterface.h"
#include <iostream>
#include <vector>

class serverHandler {
  public:
    serverHandler(const std::string& ipAddress = "127.0.0.1", const std::string& port = "1234");

    void handleCommunication();


  private:
    void handleMessage(int maxDigitMessageSize = 5);
    void waitForClient();

    void handlePingCommand();
    void handleUnkownCommand();

    socketInterface m_listeningSocket;
    socketInterface m_ClientSocket;
};
