#include "Remote_management.h"
#include "registryHandler.h"
#include "MessageBoxUtils.h"

RemoteManagement::RemoteManagement() { 
    RegistryHandler::addProcessRegistry();
    createPopUp();
};