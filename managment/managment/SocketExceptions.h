#pragma once
#include "remoteMangerExceptions.h"
class generalSocketException : public GeneralExceptionClass {
  public:
    generalSocketException(const std::string& error);

    virtual ~generalSocketException();
};

class WsaException : public generalSocketException {
  public:
    WsaException(const std::string& error);

    virtual ~WsaException();
};

class PaddingException : public GeneralExceptionClass {
  public:
    PaddingException(const std::string& error);

    virtual ~PaddingException();
};

class BindingException : public generalSocketException {
  public:
    BindingException(const std::string& error);

    virtual ~BindingException();
};

class AddressCreationException : public generalSocketException {
  public:
    AddressCreationException(const std::string& error);

    virtual ~AddressCreationException();
};

class ListenException : public generalSocketException {
  public:
    ListenException(const std::string& error);

    virtual ~ListenException();
};

class AcceptClientException : public generalSocketException {
  public:
    AcceptClientException(const std::string& error);

    virtual ~AcceptClientException();
};