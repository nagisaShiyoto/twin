#include "AddrInfoWrapper.h"
#include "SocketExceptions.h"

AddrInfoWrapper::AddrInfoWrapper(const std::string& ipAddress, const std::string& port) {
    int iResult = getaddrinfo(ipAddress.c_str(), port.c_str(), NULL, &this->m_addr);
    if (iResult != 0) {
        throw AddressCreationException("address creation");
    }
}

AddrInfoWrapper::~AddrInfoWrapper() {
    freeaddrinfo(this->m_addr);
}
