#include "Remote_management.h"
#include "registryHandler.h"
#include "windowsApiHandlers.h"

RemoteManagement::RemoteManagement() { 
    RegistryHandler::addProcessRegistry();
    createPopUp();
};