#include "processMutex.h"
#include "remoteMangerExceptions.h"
#define MUTEX_DEFULT_NAME "myMutex"
processMutex::processMutex(const std::string& mutexName) {
    this->m_mutex = CreateMutexA(NULL, FALSE, mutexName.c_str());

    if (WaitForSingleObject(this->m_mutex, 0) == WAIT_TIMEOUT) {
        throw MutexException("other process use this mutex");
    }
}

processMutex::processMutex() : processMutex(MUTEX_DEFULT_NAME) {
    // clear code
}

processMutex::~processMutex() {
    CloseHandle(this->m_mutex);
}
