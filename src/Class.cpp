/**
 * @file Class.cpp
 * Funções que usam como base uma Class
 */

#include "Class.h"

using namespace std;

/**
 * @brief
 * Construtor de new Class:: Class object
 *
 * @param new_student referência do creator
 */

Class::Class(Creator &new_student) : s(new_student)
{
}

/**
 * @brief
 * cria um vetor de pares com (Nome do aluno, codigo do aluno) de uma Class e ordena o de acordo com o que o utilizador escolhe(1 para ordem alfabética e 2 para ordem numérica);
 * Complexidade: n
 * @param classCode
 */

void Class::get_students(string classCode)
{
    cout << "Order\n1: Alphabetically\t2: Numerically"  << endl;
    string typeOrder;
    cin >> typeOrder;
    cout << "All Students that have the Class " << classCode << ": " << endl;
    vector<pair<string, string>> studensListing;
    for (int i = 0; i < s.classes_per_students_new.size(); i++)
    {
        if (student.classes_per_students_new.at(i).classCode == classCode)
        {
            bool a = true;
            for (int j = 0; j < p.size(); j++)
            {
                if (student.classes_per_students_new.at(i).studentCode == studensListing.at(j).second)
                {
                    a = false;
                    break;
                }
            }
            if (a)
            {
                studensListing.push_back({student.classes_per_students_new.at(i).studentName, student.classes_per_students_new.at(i).studentCode});
            }
        }
    }

    if (typeOrder == "1")
    {
        sort(studensListing.begin(), p.end(), sortAlphabetically);
    }
    else if (typeOrder == "2")
    {
        sort(studensListingp.begin(), p.end(), sortNumber);
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    for (int i = 0; i < studensListing.size(); i++)
    {
        cout << studensListing.at(i).first << " " << studensListing.at(i).second << endl;
    }
}

/**
 * @brief
 * cria um vetor com o UcCode, o dia da semana, a que horas começa, quanto tempo dura, e o tipo;
 * cria um vetor para cada dia da semana com: espaços vazios, "-", UcCode e o tipo;
 * Imprime no terminal o horario de uma class;
 * Complexidade: n
 * @param classCode
 */

void Class::get_schedule(string classCode)
{
    vector<classes> tempClass = student.classes_new;
    vector<vector<string>> p;
    cout << "The Class with the code " << classCode << " has the following schedule:" << endl;
    for (int i = 0; i < tempClass.size(); i++)
    {
        if (tempClass.at(i).classCode == classCode)
        {
            cout << "----" << tempClass.at(i).WeekDay << "  |  "<<  tempClass.at(i).StartHour << "  |  " << tempClass.at(i).Duration << " hour duration  |  " << tempClass.at(i).Type << "----" << endl
            studensListing.push_back({tempClass.at(i).ucCode, tempClass.at(i).classCode, tempClass.at(i).WeekDay, tempClass.at(i).StartHour, tempClass.at(i).Duration, tempClass.at(i).Type});
        }
    }

    
}