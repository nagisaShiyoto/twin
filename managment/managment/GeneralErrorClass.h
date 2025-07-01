#pragma once
#include <iostream>

class GeneralErrorClass {
  public:
    /*
    *  create general errors 
    * 
    * @param errorMessage - the error description
    */
    GeneralErrorClass(std::string const errorMessage);
    /*
    * returning the error description
    * 
    * @return - the error description
    */
    std::string getError() const;
    /*
    * pure virtual function dtor for inheritance
    */
    virtual ~GeneralErrorClass() = 0;

  protected:
    std::string m_errorMsg;
};
