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
    string classCode;
    string ucCode;
    string WeekDay;
    string StartHour;
    string Duration;
    string Type;
};

struct classes_per_uc
{
    string ucCode;
    string classCode;
};

struct classes_per_students
{
    string ucCode;
    string classCode;
    string studentName;
    string studentCode;
};

struct request
{
    string type;
    string classCode;
    string newClasscode;
    string student;
    string ucCode;
};

#endif