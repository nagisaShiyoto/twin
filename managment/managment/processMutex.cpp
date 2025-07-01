#include "processMutex.h"
#define MUTEX_DEFULT_NAME "myMutex"
processMutex::processMutex(std::string const mutexName) {
    this->m_mutex = CreateMutexA(NULL, FALSE, mutexName.c_str());

    if (WaitForSingleObject(this->m_mutex, 0) == WAIT_TIMEOUT) {
        throw std::exception("other process use this mutex");
    }
}

processMutex::processMutex() : processMutex(MUTEX_DEFULT_NAME) {
    // clear code
}

processMutex::~processMutex() {
    CloseHandle(this->m_mutex);
}

MutexError::MutexError(std::string const errorMessage) : GeneralErrorClass(errorMessage) {
    //empty code block
}

MutexError::~MutexError() {
    //empty code block
}
