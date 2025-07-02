#pragma once
#include <iostream>

class GeneralExceptionClass {
  public:
    /*
    *  create general errors 
    * 
    * @param errorMessage - the error description
    */
    GeneralExceptionClass(std::string const errorMessage);
    /*
    * returning the error description
    * 
    * @return - the error description
    */
    virtual std::string getError() const;
    /*
    * function dtor for inheritance
    */
    virtual ~GeneralExceptionClass();

  protected:
    std::string m_errorMsg;
};

class MutexException : public GeneralExceptionClass {
  public:
    /*
     * create mutex error object(inherit from general error class)
     *
     * @param errorMessage - the error description
     */
    MutexException(std::string const errorMessage);
    /*
     * distructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~MutexException();
};

class RegistryException : public GeneralExceptionClass {
  public:
    /*
     * create registry error object(inherit from general error class)
     *
     * @param errorMessage - the error description
     */
    RegistryException(std::string const errorMessage);
    /*
     * distructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~RegistryException();
};

class ShortPathException : public GeneralExceptionClass {
  public:
    /*
     * create short pass error object(inherit from general error class)
     *
     * @param errorMessage - the error description
     */
    ShortPathException(std::string const errorMessage);
    /*
     * distructor for the object,
     * do nothing, mostly for inheritance
     */
    virtual ~ShortPathException();
};