#pragma once
#include "remoteMangerExceptions.h"
class generalSocketException : public GeneralExceptionClass {
  public:
    /*
     * create general socket exceptions
     *
     * @param error - the error description
     */
    generalSocketException(const std::string& error);
    /*
     * destructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~generalSocketException();
};

class WsaException : public generalSocketException {
  public:
    /*
     * create WsaException object(inherit from general socket error class)
     *
     * @param error - the error description
     */
    WsaException(const std::string& error);
    /*
     * destructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~WsaException();
};

class PaddingException : public GeneralExceptionClass {
  public:
    /*
     * create PaddingException object(inherit from general socket error class)
     *
     * @param error - the error description
     */
    PaddingException(const std::string& error);
    /*
     * destructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~PaddingException();
};

class BindingException : public generalSocketException {
  public:
    /*
     * create BindingException object(inherit from general socket error class)
     *
     * @param error - the error description
     */
    BindingException(const std::string& error);
    /*
     * destructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~BindingException();
};

class AddressCreationException : public generalSocketException {
  public:
    /*
     * create AddressCreationException object(inherit from general socket error class)
     *
     * @param error - the error description
     */
    AddressCreationException(const std::string& error);
    /*
     * destructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~AddressCreationException();
};

class ListenException : public generalSocketException {
  public:
    /*
     * create ListeningException object(inherit from general socket error class)
     *
     * @param error - the error description
     */
    ListenException(const std::string& error);
    /*
     * destructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~ListenException();
};

class AcceptClientException : public generalSocketException {
  public:
    /*
     * create AcceptClientException object(inherit from general socket error class)
     *
     * @param error - the error description
     */
    AcceptClientException(const std::string& error);
    /*
     * destructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~AcceptClientException();
};

class SocketDisconnectedException : public GeneralExceptionClass {
  public:
    /*
     * create SocketDisconnectedException object(inherit from general socket error class)
     *
     * @param error - the error description
     */
    SocketDisconnectedException(const std::string& error);
    /*
     * destructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~SocketDisconnectedException();
};