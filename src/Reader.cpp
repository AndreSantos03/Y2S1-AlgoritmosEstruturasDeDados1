#include "Ler.h"

#define RESET "\033[0m"

vector<classes_per_uc> Reader::read_classes_per_uc()
{
    vector<classes_per_uc> v;
    ifstream filein;
    filein.open("../classes_per_uc.csv");
    if (!filein.is_open())
    {
        return v;
    }

    string buffer;
    getline(filein, buffer, '\n');
    while (getline(filein, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        classes_per_uc p;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, '\r');
        p.ClassCode= buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}


vector<classes> Reader::read_classes()
{
    vector<classes> v;
    ifstream filein;
    filein.open("../classes.csv");
    if (!filein.is_open())
    {
        return v;
    }

    string buffer;
    getline(filein, buffer);
    while (getline(filein, buffer))
    {
        stringstream line(buffer);
        string buf;
        classes p;
        getline(line, buf, ',');
        p.ClassCode = buf;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, ',');
        p.WeekDay = buf;
        getline(line, buf, ',');
        p.StartHour = buf;
        getline(line, buf, ',');
        p.Duration = buf;
        getline(line, buf, '\r');
        p.Type = buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}


vector<students_classes> Reader::read_students_classes()
{
    vector<students_classes> v;
    ifstream filein;
    filein.open("../students_classes.csv");
    if (!filein.is_open())
    {
        return v;
    }

    string buffer;
    getline(filein, buffer, '\n');
    while (getline(filein, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        students_classes p;
        getline(line, buf, ',');
        p.StudentCode = buf;
        getline(line, buf, ',');
        p.StudentName = buf;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, '\r');
        p.ClassCode = buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}