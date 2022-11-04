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

bool can_exit_clean = true;

/**
 * @brief
 * Adiciona os pedidos de troca, adição e remoção de uma turma ou UC a uma queue;
 * Efetua as mudanças se possível, caso não seja possível adiciona a outra queue;
 * Complexidade: n(tamanho da queue)
 * @param s referência do creator
 * @param q queue com os pedidos
 * @return queue<request>
 */

queue<request> process_requests(Creator &s, queue<request> q)
{
    if (!q.empty())
    {
        can_exit_clean = false;
    }
    queue<request> q_fail;
    while (!q.empty())
    {
        if (q.front().type == "remove")
        {
            if (s.remove_class_uc(q.front().student, q.front().uccode, q.front().classcode))
            {
                cout << GREEN << "Removed student " << q.front().student << " from UC:" << q.front().uccode << " / Class:" << q.front().classcode << endl;
                q.pop();
            }
            else
            {
                cout << RED << "Failed to remove student " << q.front().student << " from UC:" << q.front().uccode << " / Class:" << q.front().classcode << endl;
                q_fail.push(q.front());
                q.pop();
            }
        }
        else if (q.front().type == "add")
        {
            if (s.add_to(q.front().student, q.front().uccode, q.front().classcode))
            {
                cout << GREEN << "Added student " << q.front().student << " to UC:" << q.front().uccode << " / to Class:" << q.front().classcode << endl;
                q.pop();
            }
            else
            {
                cout << RED << "Failed to add student " << q.front().student << " to UC:" << q.front().uccode << " / to Class:" << q.front().classcode << endl;
                q_fail.push(q.front());
                q.pop();
            }
        }
        else if (q.front().type == "change")
        {
            if (s.change_class(q.front().student, q.front().uccode, q.front().classcode, q.front().newclasscode))
            {
                cout << GREEN << "Changed student " << q.front().student << " on UC:" << q.front().uccode << " to Class:" << q.front().newclasscode << endl;
                q.pop();
            }
            else
            {
                cout << RED << "Failed to change student " << q.front().student << " on UC:" << q.front().uccode << " to Class:" << q.front().newclasscode << endl;
                q_fail.push(q.front());
                q.pop();
            }
        }
        else
        {
            q.pop();
        }
    }
    return q_fail;
}

/**
 * @brief
 * Testes para verificação e demostração do programa;
 * @param s
 * @param keep
 */

void test(Creator &s, bool keep)
{
    vector<classes_per_students> tmp = s.classes_per_students_new;
    cout << "\nTesting..." << endl << endl;
    queue<request> t;
    cout << BOLDWHITE << "ADD TESTS" << endl;
    t.push({"add", "Beatriz", "L.EIC004", "1LEIC04", ""});
    t.push({"add", "António", "L.EIC009", "2LEIC09", ""});
    t.push({"add", "António", "L.EIC005", "1LEIC05", ""});
    t.push({"add", "António", "L.EIC026", "3LEIC02", ""});
    t.push({"add", "202074767", "L.EIC003", "1LEIC06", ""});
    t.push({"add", "202035927", "L.EIC005", "1LEIC12", ""});
    t.push({"add", "Ricardo", "L.EIC004", "1LEIC13", ""});
    process_requests(s, t);
    queue<request>().swap(t);
    cout << BOLDWHITE << endl << "CHANGE TESTS" << endl;
    t.push({"change", "202044017", "L.EIC014", "2LEIC05", "2LEIC11"});
    t.push({"change", "Telmo", "L.EIC012","2LEIC03","2LEIC05"});
    t.push({"change", "202044017", "L.EIC014", "2LEIC03", "2LEIC07"});
    t.push({"change", "202044017", "L.EIC014", "2LEIC03", "2LEIC11"});
    t.push({"change", "Ronaldo", "L.EIC011", "2LEIC15", "2LEIC04"});
    t.push({"change", "Ludovico", "L.EIC021","3LEIC04", "3LEIC01"});
    t.push({"change", "202071557", "L.EIC022", "3LEIC02", "3LEIC11"});
    t.push({"change", "202071557", "L.EIC022", "3LEIC02", "3LEIC05"});
    process_requests(s, t);
    queue<request>().swap(t);
    cout << BOLDWHITE << endl << "REMOVE TESTS" << endl;
    t.push({"remove", "Ronaldo", "L.EIC014","2LEIC15", ""});
    t.push({"remove", "202028972","L.EIC012","2LEIC12",""});
    t.push({"remove", "Rosario", "L.EIC014", "2LEIC09", ""});
    t.push({"remove", "Rosaria", "L.EIC014", "2LEIC10", ""});
    process_requests(s, t);
    if (!keep)
    {
        s.classes_per_students_new = tmp;
    }
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
    Creator s;
    s.initialize();
    string reply;
    queue<request> q;
    Student student(s);
    Uc uc(s);
    Class class_(s);
    Writer write(s);
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
                while (!s.is_valid_uc(code))
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
                    while (!s.is_valid_uc(code))
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
                    while (!s.is_valid_class(code))
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
                    while (!s.is_valid_class(code))
                    {
                        cout << "Invalid Class Code!" << endl;
                        cin >> code;
                    }
                    class_.get_schedule(code);
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
                s.ocupation();
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
                for (int i = 0; i < s.classes_per_students_new.size(); i++)
                {
                    if (s.classes_per_students_new[i].StudentCode == studentcode || s.classes_per_students_new[i].StudentName == studentcode)
                    {
                        c[s.classes_per_students_new[i].UcCode] = s.classes_per_students_new[i].ClassCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout << cc.first << endl;
                }
                string uccode;
                cout << "Enter Original UC Code (ex: L.EIC007):" << endl;
                cin >> uccode;

                q.push({"remove", studentcode, uccode, c[uccode], ""});
                cout << "Added to queue!" << endl;
            }
            else if (reply == "2")
            {
                cout << "Enter Name / Code (ex: Jonas / 202000000):" << endl;
                string studentcode;
                cin >> studentcode;
                cout << "Enter Destination UC Code (ex: L.EIC007):" << endl << endl;
                cin >> reply;
                if (!s.is_valid_uc(r))
                {
                    cout << "Invalid Uc Code!" << endl;
                    continue;
                }
                cout << "Enter Original Classes:" << endl;
                for (int i = 0; i < s.classes_per_uc_new.size(); i++)
                {
                    if (s.classes_per_uc_new[i].UcCode == r && s.is_balanced(s.classes_per_uc_new[i].UcCode, s.classes_per_uc_new[i].ClassCode))
                    {
                        cout << s.classes_per_uc_new[i].ClassCode << endl;
                    }
                }
                string rr;
                cout << "Enter Destination Class:" << endl << endl;
                cin >> rr;
                if (!s.is_valid_uc_class(reply, rr))
                {
                    cout << "Invalid UC and/or Class combination!" << endl;
                    continue;
                }

                q.push({"add", studentcode, reply, rr, ""});
                cout << "Added to queue!" << endl;
            }
            else if (reply == "3")
            {
                cout << "Enter Name / Code (ex: Jonas / 202000000):" << endl;
                string code;
                cin >> code;
                cout << "Enter UCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < s.classes_per_students_new.size(); i++)
                {
                    if (s.classes_per_students_new[i].StudentCode == code || s.classes_per_students_new[i].StudentName == code)
                    {
                        c[s.classes_per_students_new[i].UcCode] = s.classes_per_students_new[i].ClassCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout << cc.first << endl;
                }
                cout << "Enter Class of UC to be Changed:" << endl;
                string uccode;
                cin >> uccode;
                if (!s.is_valid_uc(uccode))
                {
                    cout << "Invalid Uc Code!" << endl;
                    continue;
                }
                cout << "Enter Original Classes:" << endl;
                for (int i = 0; i < s.classes_per_uc_new.size(); i++)
                {
                    if (s.classes_per_uc_new[i].UcCode == uccode && s.is_balanced(s.classes_per_uc_new[i].UcCode, s.classes_per_uc_new[i].ClassCode))
                    {
                        cout << s.classes_per_uc_new[i].ClassCode << endl;
                    }
                }
                string newclass;
                cout << "---\nTo Class (ex: 1LEIC01):" << endl << endl;
                cin >> newclass;
                if (!s.is_valid_uc_class(uccode, newclass))
                {
                    cout << RED << "---\nInvalid UC / Class Combination." << RESET << endl;
                    continue;
                }
                q.push({"change", code, uccode, c[uccode], newclass});
                cout << BLUE << "\nAdded to queue" << endl;
            }
            else
            {
                cout << RED << "---\nInvalid option!" << RESET << endl;
                continue;
            }
        }
        else if (r == "3")
        {
            cout << "---\n1 - View Requests\n2 - Process Requests" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                if (q.size() == 0)
                {
                    cout << RESET << "\n0 queued requests" << endl;
                    continue;
                }
                queue<request> q_copy = q;
                cout << RESET << "\n" << q_copy.size() << " queued requests:" << endl;
                while (!q_copy.empty())
                {
                    cout << q_copy.front().type << " " << q_copy.front().student << " " << q_copy.front().uccode << " " << q_copy.front().classcode << endl;
                    q_copy.pop();
                }
            }
            else if (r == "2")
            {
                process_requests(s, q);
                std::queue<request>().swap(q);
            }
            else
            {
                cout << RED << "---\nInvalid option!" << RESET << endl;
                continue;
            }
        }
        else if (r == ":w")
        {
            can_exit_clean = true;
            if (write.write())
            {
                cout << GREEN << "---\nSaved!" << RESET << endl;
            }
            if (!q.empty())
            {
                cout << YELLOW << "\nThe queue is not empty. You should process the requests." << RESET << endl;
            }
        }
        else if (r == ":wq")
        {
            if (write.write())
            {
                cout << GREEN << "---\nSaved!" << RESET << endl;
            }
            if (!q.empty())
            {
                cout << VIMERR << "\nE69: Queue is not empty (add ! to override)" << RESET << endl;
                continue;
            }
            return 0;
        }
        else if (r == ":q")
        {
            if (!can_exit_clean)
            {
                cout << VIMERR << "\nE37: No write since last change (add ! to override)" << RESET << endl;
                continue;
            }
            if (!q.empty())
            {
                cout << VIMERR << "\nE69: Queue is not empty (add ! to override)" << RESET << endl;
                continue;
            }
            return 0;
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