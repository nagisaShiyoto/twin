#pragma once
#define PATH_SIZE 100
#include <Windows.h>

class RemoteManagement {
  public:
    RemoteManagement();
    ~RemoteManagement();

    /*
    * check if the mutex is looked, if not lock it
    * 
    * @return: true -> other process use this mutex, false -> mutex locked by you
    */
    bool checkLocked();

  private:
    /*
    * change the m_processPath param to the path of the process
    */
    void updateProccessPath();
    /*
    * create an important popup message
    */
    void createPopUp();
    /*
    * add the process executable to the autorun registry
    */
    void addToRegistry();

    /*
    * print the status after setting registry key
    * 
    * @param status -  the status return bt the RegSetKeyValueA function
    */
    void printSetKeyStatus(LSTATUS status);

    HANDLE m_mutex;
    char m_processPath[PATH_SIZE];
};
