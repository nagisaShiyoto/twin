#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include "remoteMangerExceptions.h"
#include "Remote_management.h"
#include "serverHandler.h"

int main() {
    try {
        RemoteManagement manager;
        serverHandler handler;
        handler.handleCommunication();

    } catch (const GeneralExceptionClass e) {
        std::cout << e.getError() << std::endl;
    }
}
