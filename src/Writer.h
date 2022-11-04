/**
 * @file Write.h
 * Funções para reescrever ficheiros
 */

#ifndef _WRITER_H_
#define _WRITER_H_

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
    Creator &s;
  public:
    Writer(Creator &s);
    bool write();
};

#endif