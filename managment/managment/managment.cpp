#include "Remote_management.h"
#include <iostream>
#include <windows.h>
#include "remoteMangerExceptions.h"

int main() {
    try {
        RemoteManagement manager;
    } catch (const GeneralExceptionClass e) {
        std::cout << e.getError() << std::endl;
    }
    return 0;
}
