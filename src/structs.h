/**
 * structs.h defines the structs used
 */

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

struct classes_per_uc
{
    string UcCode;
    string ClassCode;
};

struct students_classes
{
    string StudentCode;
    string StudentName;
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