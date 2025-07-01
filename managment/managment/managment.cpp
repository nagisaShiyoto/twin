#include "Remote_management.h"
#include <iostream>
#include <windows.h>
#include "processMutex.h"
#include "registryHandler.h"

int main() {

    try {
        RemoteManagement manager;
    } catch (const MutexError e) {
        std::cout << "couldn't create mutex:" << std::endl;
        std::cout << e.getError() << std::endl;
    } catch (const ShortPathError e) {
        std::cout << e.getError() << std::endl;
    } catch (const RegistryError e) {
        std::cout << "registry error:" << std::endl;
        std::cout << e.getError() << std::endl;
    }
    return 0;
}
