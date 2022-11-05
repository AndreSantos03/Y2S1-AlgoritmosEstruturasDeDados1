/**
 * @file Write.cpp
 * Funções para reescrever ficheiros
 */

#include "Writer.h"
#include <climits>

/**
 * @brief
 * Construtor de new Write:: Write object
 *
 * @param newStudent referência do writer
 */

Writer::Writer(Creator &newStudent) : student(newStudent)
{
}

/**
 * @brief
 * Abre o ficheiro se ele existir, escreve num ficheiro novo o vetor com nome do estudante, codigo,UC e class. Apaga o ficheiro antereior e da rename ao novo com o mesmo nome;
 * Complexidade: n
 * @return true
 * @return false se o ficheiro nao existir
 */

bool Writer::write()
{
    ofstream fileout;
    fileout.open("../students_classeso.csv");
    if (!fileout.is_open())
    {
        cout << "Could not open file!" << endl;
        return false;
    }
    fileout << "StudentCode,StudentName,UcCode,ClassCode\r\n";
    for (int i = 0; i < student.classes_per_students_new.size(); i++)
    {
        fileout << student.classes_per_students_new[i].StudentCode << "," << student.classes_per_students_new[i].StudentName << "," << student.classes_per_students_new[i].UcCode << "," << s.classes_per_students_new[i].ClassCode << "\r\n";
    }
    fileout.close();
    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");
    return true;
}