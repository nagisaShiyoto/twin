#include "Remote_management.h"
#include <iostream>
#include <windows.h>

int main() {

    try {
        RemoteManagement manager;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
