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

Class::Class(Creator &new_student) : sched(new_student)
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
    for (int i = 0; i < sched.classes_per_students_new.size(); i++)
    {
        if (sched.classes_per_students_new.at(i).ClassCode == classCode)
        {
            bool a = true;
            for (int j = 0; j < studensListing.size(); j++)
            {
                if (sched.classes_per_students_new.at(i).StudentCode == studensListing.at(j).second)
                {
                    a = false;
                    break;
                }
            }
            if (a)
            {
                studensListing.push_back({sched.classes_per_students_new.at(i).StudentName, sched.classes_per_students_new.at(i).StudentCode});
            }
        }
    }

    if (typeOrder == "1")
    {
        sort(studensListing.begin(), studensListing.end(), sortAlphabetically);
    }
    else if (typeOrder == "2")
    {
        sort(studensListing.begin(),studensListing.end(), sortNumber);
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
    vector<classes> tempClass = sched.classes_new;
    cout << "The Class with the code " << classCode << " has the following classes:" << endl;
    for (int i = 0; i < tempClass.size(); i++)
    {
        if (tempClass.at(i).ClassCode == classCode)
        {
            string hours;
            if(tempClass.at(i).StartHour.find('.')!=string::npos){
                hours = tempClass.at(i).StartHour.substr(0,tempClass.at(i).StartHour.find('.')).append("::30 start");
            }
            else{
                hours=tempClass.at(i).StartHour.append("::00 start");
            }
            cout << "\t" << tempClass.at(i).WeekDay << "\t|\t  "<<  hours << "\t|\t " << tempClass.at(i).Duration << " hour duration\t|\t" << tempClass.at(i).Type<< endl;
        }
    }

    
}