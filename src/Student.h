#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Scheduler.h"
#include "Sorter.h"
#include "Writer.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Student
{
  private:
    Scheduler &s;
  public:
    Student(Scheduler &s);
    void get_schedule(string studentcode);
};

#endif