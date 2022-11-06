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

Student::Student(Creator &new_student) : student(new_student)
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
    for (int i = 0; i < student.classes_per_students_new.size(); i++)
    {
        if (student.classes_per_students_new.at(i).StudentCode == studentCode || student.classes_per_students_new.at(i).StudentName == studentCode)
        {
            temp_map[student.classes_per_students_new.at(i).UcCode] = student.classes_per_students_new.at(i).ClassCode;
        }
    }
    for (int i = 0; i < student.classes_new.size(); i++)
    {
        cout << "The Class with the code " << classCode << " has the following schedule:" << endl;
        if (student.classes_new.at(i).ClassCode == temp_map[student.classes_new.at(i).UcCode])
        {
            cout << "----" << tempClass.at(i).WeekDay << "  |  "<<  tempClass.at(i).StartHour << "  |  " << tempClass.at(i).Duration << " hour duration  |  " << tempClass.at(i).Type << "----" << endl
        }
    }
}