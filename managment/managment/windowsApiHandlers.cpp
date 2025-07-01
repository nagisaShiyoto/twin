#include "windowsApiHandlers.h"
#include <Windows.h>

void createPopUp(std::string const  message, std::string const  title) {
    MessageBoxA(NULL, message.c_str(), title.c_str(), NULL);
}