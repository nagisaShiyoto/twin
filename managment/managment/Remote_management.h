#pragma once
#define PATH_SIZE 100
#include <Windows.h>
#include "processMutex.h"

class RemoteManagement {
  public:

    RemoteManagement();

  private:
    processMutex m_mutex;
};
