#include "GeneralErrorClass.h"

GeneralErrorClass::GeneralErrorClass(std::string const errorMsg) {
    this->m_errorMsg = errorMsg;
}

std::string GeneralErrorClass::getError() const {
    return this->m_errorMsg;
}

GeneralErrorClass::~GeneralErrorClass() {
}
