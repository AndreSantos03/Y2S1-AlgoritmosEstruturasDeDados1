#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct classes
{
    string ClassCode;
    string UcCode;
    string Weekday;
    string StartHour;
    string Duration;
    string Type;
};

struct classes_for_uc
{
    string UcCode;
    string ClassCode;
};

struct classes_per_students
{
    string StudentName;
    string StudentCode;
    string UcCode;
    string ClassCode;
};

struct request
{
    string type;
    string student;
    string uccode;
    string classcode;
    string newclasscode;
};

#endif