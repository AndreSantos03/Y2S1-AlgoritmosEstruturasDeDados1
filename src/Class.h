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
    Creator &s;
  public:
    Class(Creator &s);
    void get_students(string classcode);
    void get_schedule(string classcode);
};

#endif