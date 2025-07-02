#pragma once
#include "remoteMangerExceptions.h"
class generalSocketException : public GeneralExceptionClass {
  public:
    generalSocketException(std::string error);

    virtual ~generalSocketException();
};

class WsaException : public generalSocketException {
  public:
    WsaException(std::string error);

    virtual ~WsaException();
};

class PaddingException : public GeneralExceptionClass {
  public:
    PaddingException(std::string error);

    virtual ~PaddingException();
};

class BindingException : public generalSocketException {
  public:
    BindingException(std::string error);

    virtual ~BindingException();
};

class AddressCreationException : public generalSocketException {
  public:
    AddressCreationException(std::string error);

    virtual ~AddressCreationException();
};

class ListenException : public generalSocketException {
  public:
    ListenException(std::string error);

    virtual ~ListenException();
};

class AcceptClientException : public generalSocketException {
  public:
    AcceptClientException(std::string error);

    virtual ~AcceptClientException();
};