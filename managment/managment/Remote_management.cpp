#include "Remote_management.h"
#include <Windows.h>
#include <iostream>

#define ERROR_SIZE 100
#define AUTORUN_REGISTRY_PATH "Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define AUTORAN_NAME "remote_manager"
#define MUTEX_NAME "my_mutex"

void RemoteManagement::createPopUp() {
    MessageBoxA(NULL, "MANAGMENT PROGRAM IS UP", "", NULL);
}
void RemoteManagement::updateProccessPath() {
    DWORD size = PATH_SIZE;
    QueryFullProcessImageNameA(GetCurrentProcess(), 0, this->m_processPath, &size);
}
void RemoteManagement::addToRegistry() {
    LSTATUS status = RegSetKeyValueA(HKEY_CURRENT_USER, AUTORUN_REGISTRY_PATH, AUTORAN_NAME,
                                     REG_SZ, this->m_processPath, sizeof(char) * (strlen(this->m_processPath) + 1));
    this->printSetKeyStatus(status);
}

void RemoteManagement::printSetKeyStatus(LSTATUS status) {
    char error[ERROR_SIZE] = {0};
    if (status == ERROR_SUCCESS) {
        std::cout << "added to the autorun successfully" << std::endl;
    } else {
        FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, NULL, NULL, error, ERROR_SIZE, NULL);
        
        std::cout << "error accrued:" << std::endl;
        std::cout << error << std::endl;
    }
}

RemoteManagement::RemoteManagement() {
    this->m_mutex = CreateMutexA(NULL, FALSE, MUTEX_NAME);
    if (this->checkLocked()) {
        throw std::exception("other process use this mutex");
    }

    this->updateProccessPath();
    this->addToRegistry();
    this->createPopUp();
}

RemoteManagement::~RemoteManagement() {
    CloseHandle(this->m_mutex);
}

bool RemoteManagement::checkLocked() {
    return (WaitForSingleObject(this->m_mutex, 0) == WAIT_TIMEOUT);
}
