/**
 * @file structs.h
 * defines the structs used
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
    string WeekDay;
    string StartHour;
    string Duration;
    string Type;
};

struct classes_per_uc
{
    string UcCode;
    string ClassCode;
};

struct classes_per_students
{
    string UcCode;
    string ClassCode;
    string StudentName;
    string StudentCode;
};

struct request
{
    string Type;
    string ClassCode;
    string NewClasscode;
    string Student;
    string UcCode;
};

#endif