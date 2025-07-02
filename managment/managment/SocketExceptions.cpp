#include "SocketExceptions.h"
#include <winsock2.h>
#include <ws2tcpip.h>

generalSocketException::generalSocketException(std::string error) : GeneralExceptionClass(error){
    this->m_errorMsg += " failed with error:" + WSAGetLastError();
	this->m_errorMsg +="\nyou can check the error code in this link:\n"
                        "https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2";
}

generalSocketException::~generalSocketException() {
	//empty code block
}

WsaException::WsaException(std::string error) : generalSocketException(error){
	//empty code block
}

WsaException::~WsaException() {
	//empty code block
}

PaddingException::PaddingException(std::string error) : GeneralExceptionClass(error) {
	//empty code block
}

PaddingException::~PaddingException() {
	//empty code block
}

BindingException::BindingException(std::string error) : generalSocketException(error) {
	//empty code block
}

BindingException::~BindingException() {
	//empty code block
}

AddressCreationException::AddressCreationException(std::string error) : generalSocketException(error) {
    // empty code block
}

AddressCreationException::~AddressCreationException() {
    // empty code block
}

ListenException::ListenException(std::string error) : generalSocketException(error) {
	//empty code block
}

ListenException::~ListenException() {
	//empty code block
}

AcceptClientException::AcceptClientException(std::string error) : generalSocketException(error){
	//empty code block
}

AcceptClientException::~AcceptClientException() {
	//empty code block
}
