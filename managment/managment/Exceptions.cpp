#include "remoteMangerExceptions.h"

GeneralExceptionClass::GeneralExceptionClass(std::string const errorMsg) : m_errorMsg(errorMsg){
    //empty code block 
}

std::string GeneralExceptionClass::getError() const{
    return this->m_errorMsg;
}

GeneralExceptionClass::~GeneralExceptionClass() {
}

MutexException::MutexException(std::string const errorMessage) : GeneralExceptionClass(errorMessage) {
    // empty code block
}

MutexException::~MutexException() {
    // empty code block
}

RegistryException::RegistryException(std::string errorMessage) : GeneralExceptionClass(errorMessage) {
    // empty code block
}

RegistryException::~RegistryException() {
    // empty code block
}

ShortPathException::ShortPathException(std::string errorMessage) : GeneralExceptionClass(errorMessage) {
    // empty code block
}

ShortPathException::~ShortPathException() {
    // empty code block
}
