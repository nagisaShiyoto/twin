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
    * function dtor for inheritance
    */
    ~GeneralErrorClass();

  protected:
    std::string m_errorMsg;
};
