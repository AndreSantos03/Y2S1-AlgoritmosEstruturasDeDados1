/**
 * @file Write.cpp
 * Funções para reescrever ficheiros
 */

#include "Writer.h"
#include <climits>

#define RESET "\033[0m"
#define RED "\033[31m"

/**
 * @brief
 * Construtor de new Write:: Write object
 *
 * @param new_s referência do writer
 */

Writer::Writer(Creator &new_s) : s(new_s)
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
        cout << "\nCould not open file" << endl;
        return false;
    }
    fileout << "StudentCode,StudentName,UcCode,ClassCode\r\n";
    for (int i = 0; i < s.classes_per_students_new.size(); i++)
    {
        fileout << s.classes_per_students_new[i].StudentCode << "," << s.classes_per_students_new[i].StudentName << "," << s.classes_per_students_new[i].UcCode << "," << s.classes_per_students_new[i].ClassCode << "\r\n";
    }
    fileout.close();
    remove("../students_classes.csv");
    rename("../students_classeso.csv", "../students_classes.csv");
    return true;
}