#ifndef _WRITE_H_
#define _WRITE_H_

#include "Creator.h"
#include "structs.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Writer
{
  private:
    Scheduler &s;
  public:
    Write(Scheduler &s);
    bool write();
};

#endif