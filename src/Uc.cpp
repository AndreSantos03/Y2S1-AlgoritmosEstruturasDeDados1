/**
 * @file Uc.cpp
 * Funções que usam como base uma UC
 */

#include "Uc.h"

using namespace std;

/**
 * @brief
 * Construtor de new Uc:: Uc object
 *
 * @param newStudent referência do creator
 */

Uc::Uc(Creator &newStudent) : student(newStudent)
{
}

/**
 * @brief
 * cria um vetor de pares com (Nome do aluno, codigo do aluno) de uma UC e ordena o de acordo com o que o utilizador escolhe(1 para ordem alfabética e 2 para ordem numérica);
 * Complexidade: n*m
 * @param ucCode numero da uc de qual se quer os alunos
 */

void Uc::get_students(string ucCode)
{
    string typeOrder;
    cout << "Choose Order:\n1: Alphabetically\t2: Numerically" << endl;
    cin >> typeOrder;
    cout << "The students with said UC  " << ucCode << " are as followed: " << endl;
    vector<pair<string, string>> studentVector;
    for (int i = 0; i < student.classes_per_students_new.size(); i++)
    {
        if (student.classes_per_students_new.at(i).UcCode == ucCode)
        {
            bool a = true;
            for (int j = 0; j < studentVector.size(); j++)
            {
                if (student.classes_per_students_new.at(i).StudentCode == studentVector.at(j).second)
                {
                    a = false;
                    break;
                }
            }
            if (a)
            {
                studentVector.push_back({student.classes_per_students_new.at(i).StudentName, student.classes_per_students_new.at(i).StudentCode});
            }
        }
    }

    if (typeOrder == "1")
    {
        sort(studentVector.begin(), studentVector.end(), sortAlphabetically);
    }
    else if (typeOrder == "2")
    {
        sort(studentVector.begin(), studentVector.end(), sortNumber);
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    for (int i = 0; i < studentVector.size(); i++)
    {
        cout << studentVector.at(i).first << "  " << studentVector.at(i).second << endl;
    }
}

/**
 * @brief
 * vai buscar todas as Classes que tem uma Uc;
 * Complexidade: n
 * @param ucCode codigo da uc
 */

void Uc::get_classes(string ucCode)
{
    cout << "The classes with the UC " << ucCode << " are as followed: " << endl << endl;
    for (int i = 0; i < student.classes_per_uc_new.size(); i++)
    {
        if (student.classes_per_uc_new.at(i).UcCode == ucCode)
        {
            cout << student.classes_per_uc_new.at(i).ClassCode << endl;
        }
    }
}