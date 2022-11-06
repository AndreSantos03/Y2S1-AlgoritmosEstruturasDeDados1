/**
 * @file main.cpp
 * Inicializa todas as classes, da end do input e do output e processa os pedidos de trocas de turma
 */

#include <iostream>
#include "Class.h"
#include "Creator.h"
#include "Student.h"
#include "Uc.h"
#include <queue>

using namespace std;

/**
 * @brief
 * Adiciona os pedidos de troca, adição e remoção de uma turma ou UC a uma queue;
 * Efetua as mudanças se possível, caso não seja possível adiciona a outra queue;
 * Complexidade: n(tamanho da queue)
 * @param student referência do creator
 * @param queue queue com os pedidos
 * @return queue<request>
 */

queue<request> process_requests(Creator &student, queue<request> queue)
{
    ::queue<request> queue_fail;
    while (!queue.empty())
    {
        if (queue.front().type == "remove")
        {
            if (student.remove_class_uc(queue.front().student, queue.front().uccode, queue.front().classcode))
            {
                cout  << "Removed student " << q.front().student << " from UC " << q.front().uccode << " in Class " << queue.front().classcode << endl;
                queue.pop();
            }
            else
            {
                cout << "Unable to remove student " << queue.front().student << " from UC " << queue.front().ucCode << " in Class " << queue.front().classCode << endl;
                queue_fail.push(queue.front());
                queue.pop();
            }
        }
        else if (queue.front().Type == "add")
        {
            if (student.add_to(queue.front().Student, queue.front().UcCode, queue.front().ClassCode))
            {
                cout  << "Added student " << queue.front().Student << " to UC " << queue.front().UcCode << " in to Class " << queue.front().classCode << endl;
                queue.pop();
            }
            else
            {
                cout << "Unable to add student " << queue.front().Student << " to UC " << queue.front().UcCode << " into Class " << queue.front().classCode << endl;
                queue_fail.push(q.front());
                queue.pop();
            }
        }
        else if (queue.front().type == "change")
        {
            if (student.change_class(queue.front().student, queue.front().ucCode, queue.front().classCode, queue.front().newClasscode))
            {
                cout  << "Changed student " << queue.front().student << " in UC " << queue.front().ucCode << " to Class " << queue.front().newClasscode << endl;
                queue.pop();
            }
            else
            {
                cout << "Failed to change student " << queue.front().student << " in UC " << queue.front().ucCode << " to Class " << queue.front().newClasscode << endl;
                queue_fail.push(queue.front());
                queue.pop();
            }
        }
        else
        {
            queue.pop();
        }
    }
    return queue_fail;
}



/**
 * @brief
 * Imprime as opções para o utilizador escolher( view, request, process request);
 * Utiliza comandos vim para guardar e sair;
 * Lê o input colocado do utilizador, e dependendo dele, imprime mais opções para o utilizador escolher o que pretender;
 * No view, possibilita a visualização de forma ordenada de turmas, de alunos, da ocupação em UCs e dos horários quer do aluno, quer da Turma;
 * Em Requests, adiciona os pedidos de remoção, adição ou troca de turma de um aluno a uma queue;
 * Em Process requests, da para ou ver os pedidos, ou processar(aonde processa os requests possiveis, e mantem numa queue os que nao foram possiveis);
 * Complexidade: m(entre 1(se o utilizador der logo quit) e infinito (se o utilizador continuar a usar o programa))*n
 * @param argc
 * @param argv
 * @return int
 */

int main(int argc, char **argv)
{
    Creator student;
    student.initializion();
    string reply;
    queue<request> queue;
    Student student(student);
    Uc uc(student);
    Class class_(student);
    Writer write(student);
    while (true)
    {
        cout << "1: Viewer\t2: Request\t3: Get Requests to be Processed\nq: Quit Application"<< endl;
        cin >> reply;
        if (reply == "1")
        {
            cout << "1: View Classes\t2:iew Students\t3: View Schedule\t4: View Ocupation" << endl;
            cin >> reply;
            if (reply == "1")
            {
                cout << "UC" << endl << endl;
                cin >> reply;
                cout << "Enter UC Code (ex:L.EIC005):" << endl << endl;
                string code;
                cin >> code;
                while (!student.is_valid_uc(code))
                {
                    cout << "Invalid UC Code!" << endl;
                    cin >> code;
                }
                uc.get_classes(code);
            }
            else if (reply == "2")
            {
                cout << "From:\n1: UC\t2: Class" << endl;
                cin >> reply;
                if (reply == "1")
                {
                    cout << "Enter UC Code (ex:L.EIC005):" << endl;
                    string code;
                    cin >> code;
                    while (!student.is_valid_uc(code))
                    {
                        cout << "Invalid UC Code!" << endl;
                        cin >> code;
                    }
                    uc.get_students(code);
                }
                else if (reply == "2")
                {
                    cout << "Enter Class Code (ex:2LEIC07):" << endl;
                    string code;
                    cin >> code;
                    while (!student.is_valid_class(code))
                    {
                        cout << "Invalid Class Code!" << endl;
                        cin >> code;
                    }
                    class_.get_students(code);
                }
                else
                {
                    cout << "Invalid option!" << endl;
                    continue;
                }
            }
            else if (reply == "3")
            {
                cout << "From:\n1: Class\t2: Student"  << endl;
                cin >> reply;
                if (reply == "1")
                {
                    cout << "Enter Class Code (ex:7LEIC07):" << endl;
                    string code;
                    cin >> code;
                    while (!student.is_valid_class(code))
                    {
                        cout << "Invalid Class Code!" << endl;
                        cin >> code;
                    }
                    class_.get_schedule(code,);
                }
                else if (reply == "2")
                {
                    cout << "Enter Name / Code (ex: Jonas / 202000000):" << endl;
                    string studentcode;
                    cin >> studentcode;
                    student.get_schedule(studentcode);
                }
                else
                {
                    cout << "Invalid option!" << endl;
                    continue;
                }
            }
            else if (reply == "4")
            {
                student.ocupation();
            }
            else
            {
                cout << "Invalid option!" << endl;
                continue;
            }
        }
        else if (reply == "2")
        {
            cout << "1: Remove Student from an UC\t2: Add Student to an UC\t3: Change Student to Another Class" << endl;
            cin >> reply;
            if (reply == "1")
            {
                cout << "Enter Name / Code (ex: Jonas / 202000000):" << endl;
                string studentcode;
                cin >> studentcode;
                cout << "UCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < student.classes_per_students_new.size(); i++)
                {
                    if (student.classes_per_students_new[i].studentCode == studentcode || student.classes_per_students_new[i].studentName == studentcode)
                    {
                        c[student.classes_per_students_new[i].ucCode] = student.classes_per_students_new[i].classCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout << cc.first << endl;
                }
                string uccode;
                cout << "Enter Original UC Code (ex: L.EIC007):" << endl;
                cin >> uccode;

                queue.push({"remove", studentcode, uccode, c[uccode], ""});
                cout << "Added to queue!" << endl;
            }
            else if (reply == "2")
            {
                cout << "Enter Name / Code (ex: Jonas / 202000000):" << endl;
                string studentcode;
                cin >> studentcode;
                cout << "Enter Destination UC Code (ex: L.EIC007):" << endl << endl;
                cin >> reply;
                if (!student.is_valid_uc(r))
                {
                    cout << "Invalid Uc Code!" << endl;
                    continue;
                }
                cout << "Enter Original Classes:" << endl;
                for (int i = 0; i < student.classes_per_uc_new.size(); i++)
                {
                    if (student.classes_per_uc_new[i].UcCode == r && student.is_balanced(student.classes_per_uc_new[i].UcCode, student.classes_per_uc_new[i].ClassCode))
                    {
                        cout << student.classes_per_uc_new[i].classCode << endl;
                    }
                }
                string destClass;
                cout << "Enter Destination Class:" << endl << endl;
                cin >> destClass;
                if (!student.is_valid_uc_class(reply, destClass))
                {
                    cout << "Invalid UC and/or Class combination!" << endl;
                    continue;
                }

                queue.push({"add", studentcode, reply, destClass, ""});
                cout << "Added to queue!" << endl;
            }
            else if (reply == "3")
            {
                cout << "Enter Name / Code (ex: Jonas / 202000000):" << endl;
                string studentCode;
                cin >> studentCode;
                cout << "Enter UCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < student.classes_per_students_new.size(); i++)
                {
                    if (student.classes_per_students_new[i].StudentCode == studentCode || student.classes_per_students_new[i].StudentName == studentCode)
                    {
                        c[student.classes_per_students_new[i].ucCode] = student.classes_per_students_new[i].classCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout << cc.first << endl;
                }
                cout << "Enter Class of UC to be Changed:" << endl;
                string uccode;
                cin >> uccode;
                if (!student.is_valid_uc(uccode))
                {
                    cout << "Invalid Uc Code!" << endl;
                    continue;
                }
                cout << "Enter Original Classes:" << endl;
                for (int i = 0; i < student.classes_per_uc_new.size(); i++)
                {
                    if (student.classes_per_uc_new[i].UcCode == uccode && student.is_balanced(student.classes_per_uc_new[i].UcCode, student.classes_per_uc_new[i].classCode))
                    {
                        cout << student.classes_per_uc_new[i].classCode << endl;
                    }
                }
                string newClass;
                cout << "Enter Destination Class(ex: 7LEIC07):"  endl;
                cin >> newClass;
                if (!student.is_valid_uc_class(uccode, newClass))
                {
                    cout  << "Invalid UC/Class Combination!" <<  endl;
                    continue;
                }
                queue.push({"change", code, uccode, c[uccode], newClass});
                cout  << "Request has been to queue!" << endl;
            }
            else
            {
                cout << "Invalid option!" << endl;
                continue;
            }
        }
        else if (reply == "3")
        {
            cout << "1: View Unprocessed Requests\t2 - View Process Requests" << endl;
            cin >> reply;
            if (reply == "1")
            {
                if (queue.size() == 0)
                {
                    cout  << "There are no queued requests!" << endl;
                    continue;
                }
                ::queue<request> qCopy = q;
                cout  << "There are" << qCopy.size() << " queued requests:" << endl;
                while (!qCopy.empty())
                {
                    cout << qCopy.front().type << " " << qCopy.front().student << " " << qCopy.front().ucCode << " " << qCopy.front().classCode << endl;
                    qCopy.pop();
                }
            }
            else if (reply == "2")
            {
                process_requests(student, queue);
                std::queue<request>().swap(q);
            }
            else
            {
                cout << "Invalid option!" << endl;
                continue;
            }
        }
        else if (r == "q") {
            return 0;
        }
        else
        {
            cout << "Invalid option!" << endl;
            continue;
        }
    }
    return 0;
}