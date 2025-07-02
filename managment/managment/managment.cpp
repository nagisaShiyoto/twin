#include "Remote_management.h"
#include <iostream>
#include <windows.h>
#include "remoteMangerExceptions.h"

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
    return 1;
}
