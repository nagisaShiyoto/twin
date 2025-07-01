#include "processMutex.h"

processMutex::processMutex(std::string mutexName) {
    this->m_mutex = CreateMutexA(NULL, FALSE, mutexName.c_str());

    if (WaitForSingleObject(this->m_mutex, 0) == WAIT_TIMEOUT) {
        throw std::exception("other process use this mutex");
    }
}

processMutex::processMutex() : processMutex("myMutex") {
    // clear code
}

processMutex::~processMutex() {
    CloseHandle(this->m_mutex);
}
