#include "windowsApiHandlers.h"
#include <Windows.h>

void createPopUp(std::string message, std::string title) {
    MessageBoxA(NULL, message.c_str(), title.c_str(), NULL);
}