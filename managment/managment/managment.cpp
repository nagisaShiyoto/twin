#include <iostream>
#include "Remote_management.h"
#include <windows.h>

int main()
{
    HANDLE mutex = CreateMutexA(NULL, FALSE, "my_mutex");
    if (WaitForSingleObject(mutex, 0) == WAIT_TIMEOUT) {
        std::cout << "used by another" << std::endl;
        return 1;
    }
    RemoteManagement manager;
    return 0;
}
