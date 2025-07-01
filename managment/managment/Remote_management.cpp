#include "Remote_management.h"
#include <Windows.h>
#include <iostream>
#define ERROR_SIZE 100
#define EXECUTABLE_PATH_VALUE "C:\\Users\\eylon\\OneDrive\\Desktop\\stuff\\twin\\managment\\x64\\Debug\\managment.exe"

void RemoteManagement::createPopUp() {
    MessageBoxA(NULL, "MANAGMENT PROGRAM IS UP", "", NULL);
}

void RemoteManagement::addToRegistry() {
    LSTATUS status = RegSetKeyValueA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", "test",
                                     REG_SZ, EXECUTABLE_PATH_VALUE, sizeof(char) * (strlen(EXECUTABLE_PATH_VALUE) + 1));
    if (status == ERROR_SUCCESS) {
        std::cout << "added to the autorun successfully" << std::endl;
    } else {
        char error[ERROR_SIZE] = {0};
        std::cout << "error accrued:" << std::endl;
        FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, NULL, NULL, error, ERROR_SIZE, NULL);
        std::cout << error << std::endl;
    }
}

RemoteManagement::RemoteManagement() {
    this->addToRegistry();
    this->createPopUp();
}
