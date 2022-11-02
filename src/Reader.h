#ifndef _READER_H_
#define _READER_H_

#include "Structs.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Reader
{
  public:
    vector<> read_classes_per_uc();
    vector<classes> read_classes();
    vector<classes_per_students> read_students_class();
};

#endif
