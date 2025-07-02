#include "remoteMangerExceptions.h"

GeneralExceptionClass::GeneralExceptionClass(const std::string& errorMsg) : m_errorMsg(errorMsg) {
    // empty code block 
}

std::string GeneralExceptionClass::getError() const{
    return this->m_errorMsg;
}

GeneralExceptionClass::~GeneralExceptionClass() {
    // empty code block
}

MutexException::MutexException(const std::string& errorMessage) : GeneralExceptionClass(errorMessage) {
    // empty code block
}

MutexException::~MutexException() {
    // empty code block
}

RegistryException::RegistryException(const std::string& errorMessage) : GeneralExceptionClass(errorMessage) {
    // empty code block
}

RegistryException::~RegistryException() {
    // empty code block
}

ShortPathException::ShortPathException(const std::string& errorMessage) : GeneralExceptionClass(errorMessage) {
    // empty code block
}

ShortPathException::~ShortPathException() {
    // empty code block
}
