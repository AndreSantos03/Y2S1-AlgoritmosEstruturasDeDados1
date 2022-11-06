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

queue<request> process_requests(Creator &sched, queue<request> queue)
{
    ::queue<request> queue_fail;
    while (!queue.empty())
    {
        if (queue.front().Type == "remove")
        {
            if (sched.remove_class_from_uc(queue.front().Student, queue.front().UcCode, queue.front().ClassCode))
            {
                cout  << "Removed student " << queue.front().Student << " from UC " << queue.front().UcCode << " in Class " << queue.front().ClassCode << endl;
                queue.pop();
            }
            else
            {
                cout << "Unable to remove student " << queue.front().Student << " from UC " << queue.front().UcCode << " in Class " << queue.front().ClassCode << endl;
                queue_fail.push(queue.front());
                queue.pop();
            }
        }
        else if (queue.front().Type == "add")
        {
            if (sched.add_to(queue.front().Student, queue.front().UcCode, queue.front().ClassCode))
            {
                cout  << "Added student " << queue.front().Student << " to UC " << queue.front().UcCode << " in to Class " << queue.front().ClassCode << endl;
                queue.pop();
            }
            else
            {
                cout << "Unable to add student " << queue.front().Student << " to UC " << queue.front().UcCode << " into Class " << queue.front().ClassCode << endl;
                queue_fail.push(queue.front());
                queue.pop();
            }
        }
        else if (queue.front().Type == "change")
        {
            if (sched.class_changer(queue.front().Student, queue.front().UcCode, queue.front().ClassCode, queue.front().NewClasscode))
            {
                cout  << "Changed student " << queue.front().Student << " in UC " << queue.front().UcCode << " to Class " << queue.front().NewClasscode << endl;
                queue.pop();
            }
            else
            {
                cout << "Failed to change student " << queue.front().Student << " in UC " << queue.front().UcCode << " to Class " << queue.front().NewClasscode << endl;
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
    Creator sched;
    sched.initializion();
    string reply;
    queue<request> queue;
    Student stude(sched);
    Uc uc(sched);
    Class cClass(sched);
    Writer write(sched);
    while (true)
    {
        cout << "::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "1: Viewer    2: Request     3: Get Requests to be Processed\nq: Quit Application"<< endl;
        cin >> reply;
        if (reply == "1")
        {
            cout << "::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "1: View Classes    2:View Students    3: View Schedule    4: View Ocupation" << endl;
            cin >> reply;
            if (reply == "1")
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter UC Code (ex:L.EIC005):" << endl;
                string code;
                cin >> code;
                while (!sched.is_valid_uc(code))
                {
                    cout << "Invalid UC Code!" << endl;
                    cin >> code;
                }
                uc.get_classes(code);
            }
            else if (reply == "2")
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "From:\n1: UC    2: Class" << endl;
                cin >> reply;
                if (reply == "1")
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Enter UC Code (ex:L.EIC005):" << endl;
                    string code;
                    cin >> code;
                    while (!sched.is_valid_uc(code))
                    {
                        cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                        cout << "Invalid UC Code!" << endl;
                        cin >> code;
                    }
                    uc.get_students(code);
                }
                else if (reply == "2")
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Enter Class Code (ex:2LEIC07):" << endl;
                    string code;
                    cin >> code;
                    while (!sched.is_valid_class(code))
                    {
                        cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                        cout << "Invalid Class Code!" << endl;
                        cin >> code;
                    }
                    cClass.get_students(code);
                }
                else
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Invalid option!" << endl;
                    continue;
                }
            }
            else if (reply == "3")
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "From:\n1: Class    2: Student"  << endl;
                cin >> reply;
                if (reply == "1")
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Enter Class Code (ex:2LEIC01):" << endl;
                    string code;
                    cin >> code;
                    while (!sched.is_valid_class(code))
                    {cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                        cout << "Invalid Class Code!" << endl;
                        cin >> code;
                    }
                    cClass.get_schedule(code);
                }
                else if (reply == "2")
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Enter Name / Code (ex: Jose Leopoldo / 201964162):" << endl;
                    string studentcode;
                    cin >> studentcode;
                    cClass.get_schedule(studentcode);
                }
                else
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Invalid option!" << endl;
                    continue;
                }
            }
            else if (reply == "4")
            {
                sched.ocupation();
            }
            else
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Invalid option!" << endl;
                continue;
            }
        }
        else if (reply == "2")
        {
            cout << "::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "1: Remove Student from an UC    2: Add Student to an UC    3: Change Student to Another Class" << endl;
            cin >> reply;
            if (reply == "1")
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Name / Code (ex: Jose Leopoldo / 201964162):" << endl;
                string studentcode;
                cin >> studentcode;
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "UCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < sched.classes_per_students_new.size(); i++)
                {
                    if (sched.classes_per_students_new[i].StudentCode == studentcode || sched.classes_per_students_new[i].StudentName == studentcode)
                    {
                        c[sched.classes_per_students_new[i].UcCode] = sched.classes_per_students_new[i].ClassCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout << cc.first << endl;
                }
                string uccode;
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Original UC Code (ex: L.EIC001):" << endl;
                cin >> uccode;

                queue.push({"remove", studentcode, uccode, c[uccode], ""});
                cout << "Added to queue!" << endl;
            }
            else if (reply == "2")
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Name / Code (ex: Jose Leopoldo / 201964162):" << endl;
                string studentcode;
                cin >> studentcode;
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Destination UC Code (ex: L.EIC001):" << endl << endl;
                cin >> reply;
                if (!sched.is_valid_uc(reply))
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Invalid Uc Code!" << endl;
                    continue;
                }
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Original Classes:" << endl;
                for (int i = 0; i < sched.classes_per_uc_new.size(); i++)
                {
                    if (sched.classes_per_uc_new[i].UcCode == reply && sched.is_balanced(sched.classes_per_uc_new[i].UcCode, sched.classes_per_uc_new[i].ClassCode))
                    {
                        cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                        cout << sched.classes_per_uc_new[i].ClassCode << endl;
                    }
                }
                string destClass;
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Destination Class:" << endl << endl;
                cin >> destClass;
                if (!sched.is_valid_uc_class(reply, destClass))
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Invalid UC and/or Class combination!" << endl;
                    continue;
                }

                queue.push({"add", studentcode, reply, destClass, ""});
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Added to queue!" << endl;
            }
            else if (reply == "3")
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Name / Code (ex: Jose Leopoldo / 201964162):" << endl;
                string studentCode;
                cin >> studentCode;
                cout << "Enter UCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < sched.classes_per_students_new.size(); i++)
                {
                    if (sched.classes_per_students_new[i].StudentCode == studentCode || sched.classes_per_students_new[i].StudentName == studentCode)
                    {
                        c[sched.classes_per_students_new[i].UcCode] = sched.classes_per_students_new[i].ClassCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << cc.first << endl;
                }
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Class of UC to be Changed:" << endl;
                string uccode;
                cin >> uccode;
                if (!sched.is_valid_uc(uccode))
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout << "Invalid Uc Code!" << endl;
                    continue;
                }
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Original Classes:" << endl;
                for (int i = 0; i < sched.classes_per_uc_new.size(); i++)
                {
                    if (sched.classes_per_uc_new[i].UcCode == uccode && sched.is_balanced(sched.classes_per_uc_new[i].UcCode, sched.classes_per_uc_new[i].ClassCode))
                    {
                        cout << sched.classes_per_uc_new[i].ClassCode << endl;
                    }
                }
                string newClass;
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Enter Destination Class(ex: 2LEIC01):" << endl;
                cin >> newClass;
                if (!sched.is_valid_uc_class(uccode, newClass))
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout  << "Invalid UC/Class Combination!" <<  endl;
                    continue;
                }
                queue.push({"change", studentCode, uccode, c[uccode], newClass});
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout  << "Request has been to queue!" << endl;
            }
            else
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Invalid option!" << endl;
                continue;
            }
        }
        else if (reply == "3")
        {
            cout << "::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "1: View Unprocessed Requests    2 - View Process Requests" << endl;
            cin >> reply;
            if (reply == "1")
            {
                if (queue.size() == 0)
                {
                    cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                    cout  << "There are no queued requests!" << endl;
                    continue;
                }
                ::queue<request> qCopy = queue;
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout  << "There are" << qCopy.size() << " queued requests:" << endl;
                while (!qCopy.empty())
                {
                    cout << qCopy.front().Type << " " << qCopy.front().Student << " " << qCopy.front().UcCode << " " << qCopy.front().ClassCode << endl;
                    qCopy.pop();
                }
            }
            else if (reply == "2")
            {
                process_requests(sched, queue);
                std::queue<request>().swap(queue);
            }
            else
            {
                cout << "::::::::::::::::::::::::::::::::::::::" << endl;
                cout << "Invalid option!" << endl;
                continue;
            }
        }
        else if (reply == "q") {
            return 0;
        }
        else
        {
            cout << "::::::::::::::::::::::::::::::::::::::" << endl;
            cout << "Invalid option!" << endl;
            continue;
        }
    }
    return 0;
}