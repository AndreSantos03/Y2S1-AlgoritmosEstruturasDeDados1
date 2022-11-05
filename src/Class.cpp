/**
 * @file Class.cpp
 * Funções que usam como base uma Class
 */

#include "Class.h"

#define RESET "\033[0m"
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
                if (student.classes_per_students_new.at(i).StudentCode == studensListing.at(j).second)
                {
                    a = false;
                    break;
                }
            }
            if (a)
            {
                studensListing.push_back({student.classes_per_students_new.at(i).StudentName, student.classes_per_students_new.at(i).StudentCode});
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
    cout  << "Schedule from class " << classCode << ": " << endl;
    vector<vector<string>> p;
    for (int i = 0; i < tempClass.size(); i++)
    {
        if (tempClass.at(i).classCode == classCode)
        {
            studensListing.push_back({tempClass.at(i).UcCode, tempClass.at(i).classCode, tempClass.at(i).WeekDay, tempClass.at(i).StartHour, tempClass.at(i).Duration, tempClass.at(i).Type});
        }
    }

    vector<vector<string>> listScheduele = student.schedule(p);
    //Per day
    vector<string> Monday = listScheduele.at(0); 
    vector<string> Tuesday = listScheduele.at(1);
    vector<string> Wednesday = listScheduele.at(2);
    vector<string> Thursday = listScheduele.at(3);
    vector<string> Friday = listScheduele.at(4);

    //May god be with us
    cout << "               |   Monday    |   Tuesday   |  Wednesday |  Thursday  |   Friday   |" << endl;
    cout << "_______________|_____________|_____________|____________|____________|____________|" << endl;
    cout << " 08:00 - 08:30 |" << Monday.at(1) << "|" << Tuesday.at(1) << "|" << Wednesday.at(1) << "|" << Thursday.at(1) << "|" << Friday.at(1) << "|" << endl;
    cout << "_______________|" << Monday.at(2) << "|" << Tuesday.at(2) << "|" << Wednesday.at(2) << "|" << Thursday.at(2) << "|" << Friday.at(2) << "|" << endl;
    cout << " 08:30 - 09:00 |" << Monday.at(3) << "|" << Tuesday.at(3) << "|" << Wednesday.at(3) << "|" << Thursday.at(3) << "|" << Friday.at(3) << "|" << endl;
    cout << "_______________|" << Monday.at(4) << "|" << Tuesday.at(4) << "|" << Wednesday.at(4) << "|" << Thursday.at(4) << "|" << Friday.at(4) << "|" << endl;
    cout << " 09:00 - 09:30 |" << Monday.at(5) << "|" << Tuesday.at(5) << "|" << Wednesday.at(5) << "|" << Thursday.at(5) << "|" << Friday.at(5) << "|" << endl;
    cout << "_______________|" << Monday.at(6) << "|" << Tuesday.at(6) << "|" << Wednesday.at(6) << "|" << Thursday.at(6) << "|" << Friday.at(6) << "|" << endl;
    cout << " 09:30 - 10:00 |" << Monday.at(7) << "|" << Tuesday.at(7) << "|" << Wednesday.at(7) << "|" << Thursday.at(7) << "|" << Friday.at(7) << "|" << endl;
    cout << "_______________|" << Monday.at(8) << "|" << Tuesday.at(8) << "|" << Wednesday.at(8) << "|" << Thursday.at(8) << "|" << Friday.at(8) << "|" << endl;
    cout << " 10:00 - 10:30 |" << Monday.at(9) << "|" << Tuesday.at(9) << "|" << Wednesday.at(9) << "|" << Thursday.at(9) << "|" << Friday.at(9) << "|" << endl;
    cout << "_______________|" << Monday.at(10) << "|" << Tuesday.at(10) << "|" << Wednesday.at(10) << "|" << Thursday.at(10) << "|" << Friday.at(10) << "|" << endl;
    cout << " 10:30 - 11:00 |" << Monday.at(11) << "|" << Tuesday.at(11) << "|" << Wednesday.at(11) << "|" << Thursday.at(11) << "|" << Friday.at(11) << "|" << endl;
    cout << "_______________|" << Monday.at(12) << "|" << Tuesday.at(12) << "|" << Wednesday.at(12) << "|" << Thursday.at(12) << "|" << Friday.at(12) << "|" << endl;
    cout << " 11:00 - 11:30 |" << Monday.at(13) << "|" << Tuesday.at(13) << "|" << Wednesday.at(13) << "|" << Thursday.at(13) << "|" << Friday.at(13) << "|" << endl;
    cout << "_______________|" << Monday.at(14) << "|" << Tuesday.at(14) << "|" << Wednesday.at(14) << "|" << Thursday.at(14) << "|" << Friday.at(14) << "|" << endl;
    cout << " 11:30 - 12:00 |" << Monday.at(15) << "|" << Tuesday.at(15) << "|" << Wednesday.at(15) << "|" << Thursday.at(15) << "|" << Friday.at(15) << "|" << endl;
    cout << "_______________|" << Monday.at(16) << "|" << Tuesday.at(16) << "|" << Wednesday.at(16) << "|" << Thursday.at(16) << "|" << Friday.at(16) << "|" << endl;
    cout << " 12:00 - 12:30 |" << Monday.at(17) << "|" << Tuesday.at(17) << "|" << Wednesday.at(17) << "|" << Thursday.at(17) << "|" << Friday.at(17) << "|" << endl;
    cout << "_______________|" << Monday.at(18) << "|" << Tuesday.at(18) << "|" << Wednesday.at(18) << "|" << Thursday.at(18) << "|" << Friday.at(18) << "|" << endl;
    cout << " 12:30 - 13:00 |" << Monday.at(19) << "|" << Tuesday.at(19) << "|" << Wednesday.at(19) << "|" << Thursday.at(19) << "|" << Friday.at(19) << "|" << endl;
    cout << "_______________|" << Monday.at(20) << "|" << Tuesday.at(20) << "|" << Wednesday.at(20) << "|" << Thursday.at(20) << "|" << Friday.at(20) << "|" << endl;
    cout << " 13:00 - 13:30 |" << Monday.at(21) << "|" << Tuesday.at(21) << "|" << Wednesday.at(21) << "|" << Thursday.at(21) << "|" << Friday.at(21) << "|" << endl;
    cout << "_______________|" << Monday.at(22) << "|" << Tuesday.at(22) << "|" << Wednesday.at(22) << "|" << Thursday.at(22) << "|" << Friday.at(22) << "|" << endl;
    cout << " 13:30 - 14:00 |" << Monday.at(23) << "|" << Tuesday.at(23) << "|" << Wednesday.at(23) << "|" << Thursday.at(23) << "|" << Friday.at(23) << "|" << endl;
    cout << "_______________|" << Monday.at(24) << "|" << Tuesday.at(24) << "|" << Wednesday.at(24) << "|" << Thursday.at(24) << "|" << Friday.at(24) << "|" << endl;
    cout << " 14:00 - 14:30 |" << Monday.at(25) << "|" << Tuesday.at(25) << "|" << Wednesday.at(25) << "|" << Thursday.at(25) << "|" << Friday.at(25) << "|" << endl;
    cout << "_______________|" << Monday.at(26) << "|" << Tuesday.at(26) << "|" << Wednesday.at(26) << "|" << Thursday.at(26) << "|" << Friday.at(26) << "|" << endl;
    cout << " 14:30 - 15:00 |" << Monday.at(27) << "|" << Tuesday.at(27) << "|" << Wednesday.at(27) << "|" << Thursday.at(27) << "|" << Friday.at(27) << "|" << endl;
    cout << "_______________|" << Monday.at(28) << "|" << Tuesday.at(28) << "|" << Wednesday.at(28) << "|" << Thursday.at(28) << "|" << Friday.at(28) << "|" << endl;
    cout << " 15:00 - 15:30 |" << Monday.at(29) << "|" << Tuesday.at(29) << "|" << Wednesday.at(29) << "|" << Thursday.at(29) << "|" << Friday.at(29) << "|" << endl;
    cout << "_______________|" << Monday.at(30) << "|" << Tuesday.at(30) << "|" << Wednesday.at(30) << "|" << Thursday.at(30) << "|" << Friday.at(30) << "|" << endl;
    cout << " 15:30 - 16:00 |" << Monday.at(31) << "|" << Tuesday.at(31) << "|" << Wednesday.at(31) << "|" << Thursday.at(31) << "|" << Friday.at(31) << "|" << endl;
    cout << "_______________|" << Monday.at(32) << "|" << Tuesday.at(32) << "|" << Wednesday.at(32) << "|" << Thursday.at(32) << "|" << Friday.at(32) << "|" << endl;
    cout << " 16:00 - 16:30 |" << Monday.at(33) << "|" << Tuesday.at(33) << "|" << Wednesday.at(33) << "|" << Thursday.at(33) << "|" << Friday.at(33) << "|" << endl;
    cout << "_______________|" << Monday.at(34) << "|" << Tuesday.at(34) << "|" << Wednesday.at(34) << "|" << Thursday.at(34) << "|" << Friday.at(34) << "|" << endl;
    cout << " 16:30 - 17:00 |" << Monday.at(35) << "|" << Tuesday.at(35) << "|" << Wednesday.at(35) << "|" << Thursday.at(35) << "|" << Friday.at(35) << "|" << endl;
    cout << "_______________|" << Monday.at(36) << "|" << Tuesday.at(36) << "|" << Wednesday.at(36) << "|" << Thursday.at(36) << "|" << Friday.at(36) << "|" << endl;
    cout << " 17:00 - 17:30 |" << Monday.at(37) << "|" << Tuesday.at(37) << "|" << Wednesday.at(37) << "|" << Thursday.at(37) << "|" << Friday.at(37) << "|" << endl;
    cout << "_______________|" << Monday.at(38) << "|" << Tuesday.at(38) << "|" << Wednesday.at(38) << "|" << Thursday.at(38) << "|" << Friday.at(38) << "|" << endl;
    cout << " 17:30 - 18:00 |" << Monday.at(39) << "|" << Tuesday.at(39) << "|" << Wednesday.at(39) << "|" << Thursday.at(39) << "|" << Friday.at(39) << "|" << endl;
    cout << "_______________|" << Monday.at(40) << "|" << Tuesday.at(40) << "|" << Wednesday.at(40) << "|" << Thursday.at(40) << "|" << Friday.at(40) << "|" << endl;
    cout << " 18:00 - 18:30 |" << Monday.at(41) << "|" << Tuesday.at(41) << "|" << Wednesday.at(41) << "|" << Thursday.at(41) << "|" << Friday.at(41) << "|" << endl;
    cout << "_______________|" << Monday.at(42) << "|" << Tuesday.at(42) << "|" << Wednesday.at(42) << "|" << Thursday.at(42) << "|" << Friday.at(42) << "|" << endl;
    cout << " 18:30 - 19:00 |" << Monday.at(43) << "|" << Tuesday.at(43) << "|" << Wednesday.at(43) << "|" << Thursday.at(43) << "|" << Friday.at(43) << "|" << endl;
    cout << "_______________|" << Monday.at(44) << "|" << Tuesday.at(44) << "|" << Wednesday.at(44) << "|" << Thursday.at(44) << "|" << Friday.at(44) << "|" << endl;
    cout << " 19:00 - 19:30 |" << Monday.at(45) << "|" << Tuesday.at(45) << "|" << Wednesday.at(45) << "|" << Thursday.at(45) << "|" << Friday.at(45) << "|" << endl;
    cout << "_______________|" << Monday.at(46) << "|" << Tuesday.at(46) << "|" << Wednesday.at(46) << "|" << Thursday.at(46) << "|" << Friday.at(46) << "|" << endl;
}