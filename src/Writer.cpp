#include "Writer.h"
#include <climits>

#define RESET "\033[0m"
#define RED "\033[31m"

Writer::Write(Scheduler &new_s) : s(new_s)
{
}

bool Writer::write()
{
    ofstream fileout;
    fileout.open("../students_classeso.csv");
    if (!fileout.is_open())
    {
        cout << "\nCould not open file" << endl;
        return false;
    }
    fileout << "StudentCode,StudentName,UcCode,ClassCode\r\n";
    for (int i = 0; i < s.students_classes_v.size(); i++)
    {
        fileout << s.students_classes_v[i].StudentCode << "," << s.students_classes_v[i].StudentName << "," << s.students_classes_v[i].UcCode << "," << s.students_classes_v[i].ClassCode << "\r\n";
    }
    fileout.close();
    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");
    return true;
}