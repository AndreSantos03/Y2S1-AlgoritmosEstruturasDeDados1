/**
 * @file Student.h
 * Funções que usam student como base
 */

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Creator.h"
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
    Creator &s;
  public:
    Student(Creator &s);
    void get_schedule(string studentcode);
};

#endif