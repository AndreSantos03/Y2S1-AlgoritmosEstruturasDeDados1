/**
 * @file Student.cpp
 * Funções que usam student como base
 */

#include "Student.h"

/**
 * @brief
 * Construtor de new Student:: Student object
 *
 * @param new_student referência do creator
 */

Student::Student(Creator &new_student) : sched(new_student)
{}

/**
 * @brief
 * cria um vetor com o UcCode, o dia da semana, a que horas começa, quanto tempo dura, e o tipo;
 * cria um vetor para cada dia da semana com espaços vazios, separações, UcCode e o tipo;
 * Imprime no terminal o horario de um aluno;
 * Complexidade: n
 * @param studentCode
 */

void Student::get_schedule(string studentCode)
{
    map<string, string> temp_map;
    for (int i = 0; i < sched.classes_per_students_new.size(); i++)
    {
        if (sched.classes_per_students_new.at(i).StudentCode == studentCode || sched.classes_per_students_new.at(i).StudentName == studentCode)
        {
            temp_map[sched.classes_per_students_new.at(i).UcCode] = sched.classes_per_students_new.at(i).ClassCode;
        }
    }
    for (int i = 0; i < sched.classes_new.size(); i++)
    {
        cout << "The Class with the code " << studentCode << " has the following schedule:" << endl;
        if (sched.classes_new.at(i).ClassCode == temp_map[sched.classes_new.at(i).UcCode])
        {
            cout << "----" << sched.classes_new.at(i).WeekDay << "  |  "<<  sched.classes_new.at(i).StartHour << "  |  " << sched.classes_new.at(i).Duration << " hour duration  |  " << sched.classes_new.at(i).Type << "----" << endl;
        }
    }
}