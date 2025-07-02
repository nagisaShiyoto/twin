#include "MessageBoxUtils.h"
#include <Windows.h>

void createPopUp(const std::string& message, const std::string& title) {
    MessageBoxA(NULL, message.c_str(), title.c_str(), NULL);
}