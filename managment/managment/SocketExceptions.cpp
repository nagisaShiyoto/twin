#include "SocketExceptions.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

generalSocketException::generalSocketException(const std::string& error) : GeneralExceptionClass(error){
    this->m_errorMsg += " failed with error:" + std::to_string(WSAGetLastError());
	this->m_errorMsg +="\nyou can check the error code in this link:\n"
                        "https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2";
}

generalSocketException::~generalSocketException() {
	//empty code block
}

WsaException::WsaException(const std::string& error) : generalSocketException(error){
	//empty code block
}

WsaException::~WsaException() {
	//empty code block
}

PaddingException::PaddingException(const std::string& error) : GeneralExceptionClass(error) {
	//empty code block
}

PaddingException::~PaddingException() {
	//empty code block
}

BindingException::BindingException(const std::string& error) : generalSocketException(error) {
	//empty code block
}

BindingException::~BindingException() {
	//empty code block
}

AddressCreationException::AddressCreationException(const std::string& error) : generalSocketException(error) {
    // empty code block
}

AddressCreationException::~AddressCreationException() {
    // empty code block
}

ListenException::ListenException(const std::string& error) : generalSocketException(error) {
	//empty code block
}

ListenException::~ListenException() {
	//empty code block
}

AcceptClientException::AcceptClientException(const std::string& error) : generalSocketException(error){
	//empty code block
}

AcceptClientException::~AcceptClientException() {
	//empty code block
}

SocketDisconnectedException::SocketDisconnectedException(const std::string& error) : GeneralExceptionClass(error){
    // empty code block
}

SocketDisconnectedException::~SocketDisconnectedException() {
    // empty code block
}

sendSocketException::sendSocketException(const std::string& error) : generalSocketException(error) {
	// empty code block
}

sendSocketException::~sendSocketException() {
	// empty code block
}
