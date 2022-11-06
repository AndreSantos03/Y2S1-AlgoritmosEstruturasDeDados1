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
    cout << "The Student with the code " << studentCode << " has the following schedule:" << endl;
    for (int i = 0; i < sched.classes_new.size(); i++)
    {
        string hours;
        if(sched.classes_new.at(i).StartHour.find('.')!=string::npos){
            hours = sched.classes_new.at(i).StartHour.substr(0,sched.classes_new.at(i).StartHour.find('.')).append("::30 start");
        }
        else{
            hours=sched.classes_new.at(i).StartHour.append("::00 start");
        }
        if (sched.classes_new.at(i).ClassCode == temp_map[sched.classes_new.at(i).UcCode])
        {
            cout << "\t"<<  hours << "\t" << sched.classes_new.at(i).Duration << " hour duration\t" << sched.classes_new.at(i).Type << '\t' << sched.classes_new.at(i).WeekDay << endl;
        }
    }
}