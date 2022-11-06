/**
 * @file Class.h
 * Funções que usam como base uma Class
 */

#ifndef _CLASS_H_
#define _CLASS_H_

#include "Creator.h"
#include "Sorter.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Class
{
  private:
    Creator &sched;
  public:
    Class(Creator &sched);
    void get_students(string classCode);
    void get_schedule(string classDode);
};

#endif