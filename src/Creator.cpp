#include "Scheduler.h"

int CAP = 30;

void Creator::initialize()
{
    Read read;
    classes_per_uc_v = read.read_classes_per_uc();
    classes_v = read.read_classes();
    students_classes_v = read.read_students_classes();

    initialize_all_ucs_classes();
    initialize_ocupation();
}

void Creator::initialize_all_ucs_classes()
{
    int current_uc_index = -1;
    string current_uc = "";
    for (int i = 0; i < classes_per_uc_v.size(); i++)
    {
        if (current_uc != classes_per_uc_v[i].UcCode)
        {
            ucs_classes_v.push_back({classes_per_uc_v[i].UcCode, {classes_per_uc_v[i].ClassCode}});
            current_uc_index++;
            current_uc = classes_per_uc_v[i].UcCode;
        }
        else
        {
            ucs_classes_v[current_uc_index].second.push_back(classes_per_uc_v[i].ClassCode);
        }

        all_classes_v.insert(classes_per_uc_v[i].ClassCode);
    }
}

vector<pair<string, int>> c = {{"8", 0}, {"8.5", 2}, {"9", 4}, {"9.5", 6}, {"10", 8}, {"10.5", 10}, {"11", 12}, {"11.5", 14}, {"12", 16}, {"12.5", 18}, {"13", 20}, {"13.5", 22}, {"14", 24}, {"14.5", 26}, {"15", 28}, {"15.5", 30}, {"16", 32}, {"16.5", 34}, {"17", 36}, {"17.5", 38}, {"18", 40}, {"18.5", 42}, {"19", 44}, {"19.5", 46}};

map<string, int> d = {{"Monday", 0}, {"Tuesday", 1}, {"Wednesday", 2}, {"Thursday", 3}, {"Friday", 4}};

vector<vector<string>> Creator::schedule(vector<vector<string>> p)
{
    vector<vector<string>> a = {{"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "},
                                {"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "},
                                {"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "},
                                {"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "},
                                {"           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ",
                                 "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           ", "           "}};

    for (int i = 0; i < p.size(); i++)
    {
        int h = (stof(p.at(i).at(3)) - 8) * 4;
        if (p.at(i).at(5).size() > 1)
        {
            if (a.at(d[p.at(i).at(2)]).at(h) == "           ")
            {
                a.at(d[p.at(i).at(2)]).at(h) = "-----------";
            }
            if (p.at(i).at(4) == "1")
            {
                a.at(d[p.at(i).at(2)]).at(h + 1) = " " + p.at(i).at(0) + "  ";
                a.at(d[p.at(i).at(2)]).at(h + 2) = " " + p.at(i).at(1) + "   ";
                a.at(d[p.at(i).at(2)]).at(h + 3) = " " + p.at(i).at(5) + "        ";
                a.at(d[p.at(i).at(2)]).at(h + 4) = "-----------";
            }
            else if (p.at(i).at(4) == "1.5")
            {
                a.at(d[p.at(i).at(2)]).at(h + 1) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 2) = " " + p.at(i).at(0) + "  ";
                a.at(d[p.at(i).at(2)]).at(h + 3) = " " + p.at(i).at(1) + "   ";
                a.at(d[p.at(i).at(2)]).at(h + 4) = " " + p.at(i).at(5) + "        ";
                a.at(d[p.at(i).at(2)]).at(h + 5) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 6) = "-----------";
            }
            else
            {
                a.at(d[p.at(i).at(2)]).at(h + 1) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 2) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 3) = " " + p.at(i).at(0) + "  ";
                a.at(d[p.at(i).at(2)]).at(h + 4) = " " + p.at(i).at(1) + "   ";
                a.at(d[p.at(i).at(2)]).at(h + 5) = " " + p.at(i).at(5) + "        ";
                a.at(d[p.at(i).at(2)]).at(h + 6) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 7) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 8) = "-----------";
            }
        }
    }
    for (int i = 0; i < p.size(); i++)
    {
        int h = (stof(p.at(i).at(3)) - 8) * 4;
        if (p.at(i).at(5).size() == 1)
        {
            if (a.at(d[p.at(i).at(2)]).at(h) == "           ")
            {
                a.at(d[p.at(i).at(2)]).at(h) = "-----------";
            }

            bool die = false;
            for (float k = 1; k < (stof(p.at(i).at(4)) * 4); k++)
            {
                if (a.at(d[p.at(i).at(2)]).at(h + k) != "           ")
                {
                    die = true;
                }
            }
            if (die)
            {
                continue;
            }

            if (p.at(i).at(4) == "1")
            {
                a.at(d[p.at(i).at(2)]).at(h + 1) = " " + p.at(i).at(0) + "  ";
                a.at(d[p.at(i).at(2)]).at(h + 2) = " " + p.at(i).at(1) + "   ";
                a.at(d[p.at(i).at(2)]).at(h + 3) = " " + p.at(i).at(5) + "         ";
                a.at(d[p.at(i).at(2)]).at(h + 4) = "-----------";
            }
            else if (p.at(i).at(4) == "1.5")
            {
                a.at(d[p.at(i).at(2)]).at(h + 1) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 2) = " " + p.at(i).at(0) + "  ";
                a.at(d[p.at(i).at(2)]).at(h + 3) = " " + p.at(i).at(1) + "   ";
                a.at(d[p.at(i).at(2)]).at(h + 4) = " " + p.at(i).at(5) + "         ";
                a.at(d[p.at(i).at(2)]).at(h + 5) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 6) = "-----------";
            }
            else
            {
                a.at(d[p.at(i).at(2)]).at(h + 1) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 2) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 3) = " " + p.at(i).at(0) + "  ";
                a.at(d[p.at(i).at(2)]).at(h + 4) = " " + p.at(i).at(1) + "   ";
                a.at(d[p.at(i).at(2)]).at(h + 5) = " " + p.at(i).at(5) + "         ";
                a.at(d[p.at(i).at(2)]).at(h + 6) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 7) = "           ";
                a.at(d[p.at(i).at(2)]).at(h + 8) = "-----------";
            }
        }
    }
    return a;
}

void Creator::initialize_ocupation()
{
    for (int i = 0; i < classes_per_uc_v.size(); i++)
    {
        ocupation_v[classes_per_uc_v[i].UcCode].push_back({classes_per_uc_v[i].ClassCode, 0});
    }

    for (int i = 0; i < students_classes_v.size(); i++)
    {
        int low = 0;
        int high = ocupation_v[students_classes_v[i].UcCode].size() - 1;
        while(low < high)
        {
            if (ocupation_v[students_classes_v[i].UcCode][ low + (high - low) / 2].first == students_classes_v[i].ClassCode)
            {
                break;
            }
            if (ocupation_v[students_classes_v[i].UcCode][low + (high - low) / 2].first > students_classes_v[i].ClassCode)
            {
                high = low + (high - low) / 2 - 1;
            }
            else
            {
                low = low + (high - low) / 2 + 1;
            }
        }
        ocupation_v[students_classes_v[i].UcCode][low + (high - low)  /2].second++;

    }
}

bool Creator::remove_uc_class(string studentcode, string uccode, string classcode)
{
    auto it = remove_if(students_classes_v.begin(), students_classes_v.end(), [uccode, classcode, studentcode](students_classes r) { return (r.UcCode == uccode && r.ClassCode == classcode && (r.StudentCode == studentcode || r.StudentName == studentcode)); });
    if (it != students_classes_v.end())
    {
        students_classes_v.erase(it, students_classes_v.end());
        for (int i = 0; i < ocupation_v[uccode].size(); i++)
        {
            if (ocupation_v[uccode][i].first == classcode)
            {
                ocupation_v[uccode][i].second--;
                break;
            }
        }
        return true;
    }
    return false;
}

bool Creator::is_balanced(string uccode, string classcode)
{
    auto o = ocupation_v[uccode];
    int min = INT_MAX;
    int cur = 0;
    for (int j = 0; j < o.size(); j++)
    {
        if (o[j].second < min)
        {
            min = o[j].second;
        }
        if (o[j].first == classcode)
        {
            cur = o[j].second;
        }
    }
    if (cur + 1 - min >= 4 && cur < CAP)
    {
        return false;
    }
    return true;
}

bool Creator::add_to(string studentcode, string uccode, string classcode)
{
    if (!is_valid_uc_class(uccode, classcode))
    {
        cout << RED << "Invalid UC / Class combination - ";
        return false;
    }
    if (!is_balanced(uccode, classcode))
    {
        cout << RED << "Classes would be unbalanced - ";
        return false;
    }
    if (!is_valid_schedule_change(studentcode, uccode, "", classcode))
    {
        cout << RED << "Overlapping classes - ";
        return false;
    }

    bool can_add = true;
    bool is_name = false;
    string other_code = "";
    for (int i = 0; i < students_classes_v.size(); i++)
    {
        if (students_classes_v[i].StudentCode == studentcode)
        {
            is_name = false;
            other_code = students_classes_v[i].StudentName;
            if (students_classes_v[i].UcCode == uccode && students_classes_v[i].ClassCode == classcode)
            {
                can_add = false;
            }
        }
        else if (students_classes_v[i].StudentName == studentcode)
        {
            is_name = true;
            other_code = students_classes_v[i].StudentCode;
            if (students_classes_v[i].UcCode == uccode && students_classes_v[i].ClassCode == classcode)
            {
                can_add = false;
            }
        }
    }
    if (can_add)
    {
        if (is_name)
        {
            students_classes_v.push_back({other_code, studentcode, uccode, classcode});
        }
        else
        {
            students_classes_v.push_back({studentcode, other_code, uccode, classcode});
        }

        for (int i = 0; i < ocupation_v[uccode].size(); i++)
        {
            if (ocupation_v[uccode][i].first == classcode)
            {
                ocupation_v[uccode][i].second++;
                break;
            }
        }

        return true;
    }
    return false;
}

bool Creator::change_class(string studentcode, string uccode, string classcode, string newclasscode)
{
    if (!is_valid_uc_class(uccode, newclasscode))
    {
        cout << RED << "Invalid UC / Class combination - ";
        return false;
    }
    if (!is_balanced(uccode, newclasscode))
    {
        cout << RED << "Classes would be unbalanced - ";
        return false;
    }
    if (!is_valid_schedule_change(studentcode, uccode, classcode, newclasscode))
    {
        cout << RED << "Overlapping classes - ";
        return false;
    }

    for (int i = 0; i < students_classes_v.size(); i++)
    {
        if (students_classes_v[i].UcCode == uccode && (students_classes_v[i].StudentCode == studentcode || students_classes_v[i].StudentName == studentcode))
        {
            students_classes_v[i].ClassCode = newclasscode;
            for (int i = 0; i < ocupation_v[uccode].size(); i++)
            {
                if (ocupation_v[uccode][i].first == classcode)
                {
                    ocupation_v[uccode][i].second--;
                }
                if (ocupation_v[uccode][i].first == newclasscode)
                {
                    ocupation_v[uccode][i].second++;
                }
            }
            return true;
        }
    }
    return false;
}

void Creator::ocupation()
{
    cout << BOLDWHITE << endl << "All UCs: all\nSpecific UC: L.EIC___" << endl << endl;
    string ci;
    cin >> ci;
    for (auto o : ocupation_v)
    {
        if (ci == "all" || ci == o.first)
        {
            cout << BOLDWHITE << endl << o.first << RESET << endl;
            for (int j = 0; j < o.second.size(); j++)
            {
                cout << o.second[j].first << " - " << o.second[j].second << endl;
            }
        }
    }
}

bool Creator::is_valid_uc_class(string uccode, string classcode)
{
    for (int i = 0; i < classes_per_uc_v.size(); i++)
    {
        if (classes_per_uc_v[i].UcCode == uccode && classes_per_uc_v[i].ClassCode == classcode)
        {
            return true;
        }
    }
    return false;
}

bool Scheduler::is_valid_uc(string uccode)
{
    for (int i = 0; i < ucs_classes_v.size(); i++)
    {
        if (ucs_classes_v[i].first == uccode)
        {
            return true;
        }
    }
    return false;
}

bool Creator::is_valid_class(string classcode)
{
    if (all_classes_v.find(classcode) != all_classes_v.end())
    {
        return true;
    }
    return false;
}

bool Creator::is_valid_schedule_change(string studentcode, string uc, string oldclass, string newclass)
{
    vector<pair<string, string>> student_ucs_classes_v;
    for (int i = 0; i < students_classes_v.size(); i++)
    {
        if ((students_classes_v[i].StudentCode == studentcode || students_classes_v[i].StudentName == studentcode) && !(students_classes_v[i].UcCode == uc && students_classes_v[i].ClassCode == oldclass))
        {
            student_ucs_classes_v.push_back({students_classes_v[i].UcCode, students_classes_v[i].ClassCode});
        }
    }
    string weekday;
    float start = 0;
    float duration = 0;
    for (int i = 0; i < classes_v.size(); i++)
    {
        if (classes_v[i].UcCode == uc && classes_v[i].ClassCode == newclass && classes_v[i].Type.size() > 1)
        {
            weekday = classes_v[i].Weekday;
            start = stof(classes_v[i].StartHour);
            duration = stof(classes_v[i].Duration);
            break;
        }
    }
    for (int i = 0; i < classes_v.size(); i++)
    {
        if (weekday == classes_v[i].Weekday && classes_v[i].Type.size() > 1)
        {
            for (int j = 0; j < student_ucs_classes_v.size(); j++)
            {
                if (classes_v[i].UcCode == student_ucs_classes_v[j].first && classes_v[i].ClassCode == student_ucs_classes_v[j].second)
                {
                    if ((start < stof(classes_v[i].StartHour) && start + duration >= stof(classes_v[i].StartHour)) || (start > stof(classes_v[i].StartHour) && start < stof(classes_v[i].StartHour) + stof(classes_v[i].Duration)) || (start == stof(classes_v[i].StartHour)))
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}