#include "registryHandler.h"
#include <Windows.h>

#define ERROR_SIZE 100
#define AUTORUN_REGISTRY_PATH "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define AUTORAN_NAME "remote_manager"

std::string RegistryHandler::getProccessPath(int size) {
    char* executablePath = new char[size];
    DWORD pathSize = size;
    std::string strPath = "";
    QueryFullProcessImageNameA(GetCurrentProcess(), 0, executablePath, &pathSize);
    if (pathSize == size)
    {
        delete[] executablePath;
        throw ShortPassError("couldn't get process path");
    }
    strPath.assign(executablePath);
    delete[] executablePath;
    return strPath;
}

void RegistryHandler::addToRegistry(std::string const executablePath, std::string const autoranName) {
    char error[ERROR_SIZE] = {0};

    LSTATUS status = RegSetKeyValueA(HKEY_CURRENT_USER, AUTORUN_REGISTRY_PATH, autoranName.c_str(), REG_SZ,
                                     executablePath.c_str(), sizeof(char) * (executablePath.length() + 1));
    
    if (status != ERROR_SUCCESS) {
        FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, NULL, NULL, error, ERROR_SIZE, NULL);
        throw RegistryError(error);
    }
}

void RegistryHandler::addProcessRegistry(int size) {
    std::string executablePath = RegistryHandler::getProccessPath(size);
    RegistryHandler::addToRegistry(executablePath);
}

RegistryError::RegistryError(std::string errorMessage) : GeneralErrorClass(errorMessage) {
    //empty code block
}

RegistryError::~RegistryError() {
    //empty code block
}

ShortPassError::ShortPassError(std::string errorMessage) : GeneralErrorClass(errorMessage) {
    //empty code block
}

ShortPassError::~ShortPassError() {
    //empty code block
}

