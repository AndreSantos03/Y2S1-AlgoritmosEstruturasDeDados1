/**
 * @file Uc.h
 * Funções que usam como base uma UC
 */

#ifndef _UC_H_
#define _UC_H_

#include "Creator.h"
#include "Sorter.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Uc
{
  private:
    Creator &s;
  public:
    Uc(Creator &s);
    void get_students(string uccode);
    void get_classes(string uccode);
};

#endif