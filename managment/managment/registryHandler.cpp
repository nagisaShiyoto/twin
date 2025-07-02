#include "registryHandler.h"
#include <Windows.h>
#include "remoteMangerExceptions.h"

#define ERROR_SIZE 100
#define AUTORUN_REGISTRY_PATH "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define AUTORAN_NAME "remote_manager"

std::string RegistryHandler::getProccessPath(int size) {
    std::string executablePath("", size);
    DWORD pathSize = size;
    QueryFullProcessImageNameA(GetCurrentProcess(), 0, const_cast<char*>(executablePath.c_str()), &pathSize);
    if (pathSize == size)
    {
        throw ShortPathException("couldn't get process path\npath size too small");
    }
    return executablePath;
}

void RegistryHandler::addToRegistry(std::string const executablePath, std::string const autoranName) {
    char error[ERROR_SIZE] = {0};

    LSTATUS status = RegSetKeyValueA(HKEY_CURRENT_USER, AUTORUN_REGISTRY_PATH, autoranName.c_str(), REG_SZ,
                                     executablePath.c_str(), sizeof(char) * (executablePath.length() + 1));
    
    if (status != ERROR_SUCCESS) {
        FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, NULL, NULL, error, ERROR_SIZE, NULL);
        throw RegistryException(error);
    }
}

void RegistryHandler::addProcessRegistry(int size) {
    std::string executablePath = RegistryHandler::getProccessPath(size);
    RegistryHandler::addToRegistry(executablePath);
}

