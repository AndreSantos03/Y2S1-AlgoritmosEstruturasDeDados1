#include <iostream>
#include "Class.h"
#include "Scheduler.h"
#include "Student.h"
#include "Uc.h"
#include <queue>
#define RESET "\033[0m"
#define BOLDWHITE "\033[1m\033[37m"
#define RED "\033[31m"
#define VIMERR "\e[38;5;015m\e[48;2;255;0;0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

using namespace std;

bool can_exit_clean = true;

queue<request> process_requests(Scheduler &s, queue<request> q)
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
            if (s.remove_uc_class(q.front().student, q.front().uccode, q.front().classcode))
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

void test(Scheduler &s, bool keep)
{
    vector<students_classes> tmp = s.students_classes_v;
    cout << "\nTesting..." << endl << endl;
    queue<request> t;
    cout << BOLDWHITE << "ADD TESTS" << endl;
    t.push({"add", "Iara", "L.EIC001", "1LEIC01", ""});
    t.push({"add", "Ronaldo", "L.EIC011", "2LEIC11", ""});
    t.push({"add", "Ronaldo", "L.EIC001", "1LEIC01", ""});
    t.push({"add", "Ronaldo", "L.EIC024", "3LEIC03", ""});
    t.push({"add", "202044867", "L.EIC003", "1LEIC06", ""});
    t.push({"add", "202044782", "L.EIC005", "1LEIC12", ""});
    t.push({"add", "Telmo", "L.EIC005", "1LEIC15", ""});
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
        s.students_classes_v = tmp;
    }
}

int main(int argc, char **argv)
{
    Scheduler s;
    s.initialize();
    string r;
    queue<request> q;
    Student student(s);
    Uc uc(s);
    Class class_(s);
    Write write(s);
    while (true)
    {
        cout << BOLDWHITE << "\n------\n1 - View\n2 - Request\n3 - Process Requests" << RESET << "\n\nTo Save / Quit, use vim-like commands" << BOLDWHITE << endl << endl;
        cin >> r;
        if (r == "1")
        {
            cout << "---\n1 - Get Classes\n2 - Get Students\n3 - Get Schedule\n4 - Get ocupation" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                cout << "---\nFrom:\n\n1 - UC" << endl << endl;
                cin >> r;
                if (r == "1")
                {
                    cout << "---\nUC Code (ex: L.EIC001):" << endl << endl;
                    string code;
                    cin >> code;
                    while (!s.is_valid_uc(code))
                    {
                        cout << RED << "---\nInvalid UC Code." << RESET << endl;
                        cin >> code;
                    }
                    uc.get_classes(code);
                }
                else
                {
                    cout << RED << "---\nInvalid choice." << RESET << endl;
                    continue;
                }
            }
            else if (r == "2")
            {
                cout << "---\nFrom:\n\n1 - UC\n2 - Class" << endl << endl;
                cin >> r;
                if (r == "1")
                {
                    cout << "---\nUC Code (ex: L.EIC001):" << endl << endl;
                    string code;
                    cin >> code;
                    while (!s.is_valid_uc(code))
                    {
                        cout << RED << "---\nInvalid UC Code." << RESET << endl;
                        cin >> code;
                    }
                    uc.get_students(code);
                }
                else if (r == "2")
                {
                    cout << "---\nClass Code (ex: 1LEIC01):" << endl << endl;
                    string code;
                    cin >> code;
                    while (!s.is_valid_class(code))
                    {
                        cout << RED << "---\nInvalid Class Code." << RESET << endl;
                        cin >> code;
                    }
                    class_.get_students(code);
                }
                else
                {
                    cout << RED << "---\nInvalid choice." << RESET << endl;
                    continue;
                }
            }
            else if (r == "3")
            {
                cout << "---\nFrom:\n\n1 - Class\n2 - Student" << endl << endl;
                cin >> r;
                if (r == "1")
                {
                    cout << "---\nClass Code (ex: 1LEIC01):" << endl << endl;
                    string code;
                    cin >> code;
                    while (!s.is_valid_class(code))
                    {
                        cout << RED << "---\nInvalid Class Code." << RESET << endl;
                        cin >> code;
                    }
                    class_.get_schedule(code);
                }
                else if (r == "2")
                {
                    cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                    string code;
                    cin >> code;
                    student.get_schedule(code);
                }
                else
                {
                    cout << RED << "---\nInvalid choice." << RESET << endl;
                    continue;
                }
            }
            else if (r == "4")
            {
                s.ocupation();
            }
            else
            {
                cout << RED << "---\nInvalid choice." << RESET << endl;
                continue;
            }
        }
        else if (r == "2")
        {
            cout << "---\n1 - Remove Student from UC\n2 - Add Student to UC\n3 - Change Student's Class" << endl << endl;
            cin >> r;
            if (r == "1")
            {
                cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                string code;
                cin >> code;
                cout << "\n---\nUCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < s.students_classes_v.size(); i++)
                {
                    if (s.students_classes_v[i].StudentCode == code || s.students_classes_v[i].StudentName == code)
                    {
                        c[s.students_classes_v[i].UcCode] = s.students_classes_v[i].ClassCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout << RESET << cc.first << endl;
                }
                string uccode;
                cout << "\n---\nUC Code:" << endl << endl;
                cin >> uccode;

                q.push({"remove", code, uccode, c[uccode], ""});
                cout << BLUE << "\nAdded to queue" << endl;
            }
            else if (r == "2")
            {
                cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                string code;
                cin >> code;
                cout << "---\nTo UC (ex: L.EIC001):" << endl << endl;
                cin >> r;
                if (!s.is_valid_uc(r))
                {
                    cout << RED << "---\nInvalid Uc Code." << RESET << endl;
                    continue;
                }
                cout << "\n---\nClasses:" << endl;
                for (int i = 0; i < s.classes_per_uc_v.size(); i++)
                {
                    if (s.classes_per_uc_v[i].UcCode == r && s.is_balanced(s.classes_per_uc_v[i].UcCode, s.classes_per_uc_v[i].ClassCode))
                    {
                        cout << RESET << s.classes_per_uc_v[i].ClassCode << endl;
                    }
                }
                string rr;
                cout << "\n---\nTo Class:" << endl << endl;
                cin >> rr;
                if (!s.is_valid_uc_class(r, rr))
                {
                    cout << RED << "---\nInvalid UC / Class combination." << endl;
                    continue;
                }

                q.push({"add", code, r, rr, ""});
                cout << BLUE << "\nAdded to queue" << endl;
            }
            else if (r == "3")
            {
                cout << "---\nStudent Name / Code (ex: Ronaldo / 202045037):" << endl << endl;
                string code;
                cin >> code;
                cout << "\n---\nUCs:" << endl;
                map<string, string> c;
                for (int i = 0; i < s.students_classes_v.size(); i++)
                {
                    if (s.students_classes_v[i].StudentCode == code || s.students_classes_v[i].StudentName == code)
                    {
                        c[s.students_classes_v[i].UcCode] = s.students_classes_v[i].ClassCode;
                    }
                }
                for (pair<string, string> cc : c)
                {
                    cout << RESET << cc.first << endl;
                }
                cout << "\n---\nChange Class of UC:" << endl << endl;
                string uccode;
                cin >> uccode;
                if (!s.is_valid_uc(uccode))
                {
                    cout << RED << "---\nInvalid Uc Code." << RESET << endl;
                    continue;
                }
                cout << "\n---\nClasses:" << endl;
                for (int i = 0; i < s.classes_per_uc_v.size(); i++)
                {
                    if (s.classes_per_uc_v[i].UcCode == uccode && s.is_balanced(s.classes_per_uc_v[i].UcCode, s.classes_per_uc_v[i].ClassCode))
                    {
                        cout << RESET << s.classes_per_uc_v[i].ClassCode << endl;
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
                cout << RED << "---\nInvalid choice." << RESET << endl;
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
                cout << RED << "---\nInvalid choice." << RESET << endl;
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
        else if (r == ":q!")
        {
            return 0;
        }
        else if (r == ":test")
        {
            test(s, false);
        }
        else if (r == ":testkeep")
        {
            test(s, true);
        }
        else
        {
            cout << RED << "---\nInvalid choice." << RESET << endl;
            continue;
        }
    }
    return 0;
}