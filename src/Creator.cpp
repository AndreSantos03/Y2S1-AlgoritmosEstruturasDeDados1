/**
 * @file Creator.cpp
 * Inicializa todos os vetores
 */

#include "Creator.h"

int CAP = 30;

/**
 * @brief
 * inicializa vetores e cria vetores a partir da leitura de ficheiros
 */

void Creator::initializion()
{
    Reader r;
    classes_per_uc_new = r.read_classes_per_uc();
    classes_new = r.read_classes();
    classes_per_students_new = r.read_students_class();
    classes_initialization();
    ocupation_initialization();
}

/**
 * @brief
 * cria um vetor com todas as turmas
 * Complexidade: n
 */

void Creator::classes_initialization()
{
    int current_uc_index = -1;
    string current_uc = "";
    for (int i = 0; i < classes_per_uc_new.size(); i++)
    {
        if (current_uc != classes_per_uc_new[i].UcCode)
        {
            uc_classes_new.push_back({classes_per_uc_new[i].UcCode, {classes_per_uc_new[i].ClassCode}});
            current_uc_index++;
            current_uc = classes_per_uc_new[i].UcCode;
        }
        else
        {
            uc_classes_new[current_uc_index].second.push_back(classes_per_uc_new[i].ClassCode);
        }
        all_classes_new.insert(classes_per_uc_new[i].ClassCode);
    }
}


/**
 * @brief
 * inicializa o vetor ocupation com a ocupação das turmas por UC;
 * Complexidade: n*n*log(n) (n*log(n) vem da binary search)
 */

void Creator::ocupation_initialization()
{
    for (int i = 0; i < classes_per_uc_new.size(); i++)
    {
        ocupation_new[classes_per_uc_new[i].UcCode].push_back({classes_per_uc_new[i].ClassCode, 0});
    }

    for (int i = 0; i < classes_per_students_new.size(); i++)
    {
        int low = 0;
        int high = ocupation_new[classes_per_students_new[i].UcCode].size() - 1;
        while(low < high)
        {
            if (ocupation_new[classes_per_students_new[i].UcCode][ low + (high - low) / 2].first == classes_per_students_new[i].ClassCode)
            {
                break;
            }
            if (ocupation_new[classes_per_students_new[i].UcCode][low + (high - low) / 2].first > classes_per_students_new[i].ClassCode)
            {
                high = low + (high - low) / 2 - 1;
            }
            else
            {
                low = low + (high - low) / 2 + 1;
            }
        }
        ocupation_new[classes_per_students_new[i].UcCode][low + (high - low)  /2].second++;

    }
}

/**
 * @brief
 * Da cout da ocupação de alunos de todas as turmas ou de todas as UCs ou de uma UC;
 * Complexidade: n*m
 */

void Creator::ocupation()
{
    cout  << "Type:\n\"all\" for all UCs    UC Code for a specific: " << endl;
    string ucAnswer;
    cin >> ucAnswer;
    for (auto ocup : ocupation_new)
    {
        if (ucAnswer == "all" || ucAnswer == ocup.first)
        {
            cout << ocup.first << endl;
            for (int j = 0; j < ocup.second.size(); j++)
            {
                cout << ocup.second[j].first << " - " << ocup.second[j].second << endl;
            }
        }
    }
}

/**
 * @brief
 * Remove um aluno de uma UC;
 * Complexidade: n(remove_if)*m
 * @param studentcode
 * @param uccode
 * @param classcode
 * @return true remove um aluno de uma UC e turma
 * @return false nao conseguiu remover o aluno de uma UC
 */

bool Creator::remove_class_from_uc(string studentcode, string uccode, string classcode)
{
    auto iterator = remove_if(classes_per_students_new.begin(), classes_per_students_new.end(), [uccode, classcode, studentcode](classes_per_students r) { return (r.UcCode == uccode && r.ClassCode == classcode && (r.StudentCode == studentcode || r.StudentName == studentcode)); });
    if (iterator != classes_per_students_new.end())
    {
        classes_per_students_new.erase(iterator, classes_per_students_new.end());
        for (int i = 0; i < ocupation_new[uccode].size(); i++)
        {
            if (ocupation_new[uccode][i].first == classcode)
            {
                ocupation_new[uccode][i].second--;
                break;
            }
        }
        return true;
    }
    return false;
}

/**
 * @brief
 * verifica se as turmas ficam equilibradas com a troca pedida;
 * Complexidade: n
 * @param uccode
 * @param classcode
 * @return true permite a troca de turma
 * @return false nao permite a troca de turma
 */

bool Creator::is_balanced(string uccode, string classcode)
{
    auto ocup = ocupation_new[uccode];
    int min = INT_MAX;
    int cur = 0;
    for (int j = 0; j < ocup.size(); j++)
    {
        if (ocup[j].second < min)
        {
            min = ocup[j].second;
        }
        if (ocup[j].first == classcode)
        {
            cur = ocup[j].second;
        }
    }
    if (cur + 1 - min >= 4 && cur < CAP)
    {
        return false;
    }
    return true;
}

/**
 * @brief
 * verifica se a uc e valida, se a de turma nao provoca desiquilibrios e se não se sobrepõem aulas no horario do aluno;
 * verifica se e possivel adicionar(se já nao pertence a turma);
 * Complexidade: n
 * @param studentcode
 * @param uccode
 * @param classcode
 * @return adiciona um aluno a uma UC e turma
 * @return false ou a uc nao e valida, ou a adição prova desiquilibrio, ou iria ter aulas sobrepostas ou
 */

bool Creator::add_to(string studentcode, string uccode, string classcode)
{
    if (!is_valid_uc_class(uccode, classcode))
    {
        cout << "Invalid UC and Class combination!" << endl;
        return false;
    }
    if (!is_balanced(uccode, classcode))
    {
        cout << "Classes would be unbalanced!";
        return false;
    }
    if (!is_valid_schedule_change(studentcode, uccode, "", classcode))
    {
        cout << "Overlapping classes!" << endl;
        return false;
    }

    bool is_addable = true;
    bool is_name = false;
    string tmpCode = "";
    for (int i = 0; i < classes_per_students_new.size(); i++)
    {
        if (classes_per_students_new[i].StudentCode == studentcode)
        {
            is_name = false;
            tmpCode = classes_per_students_new[i].StudentName;
            if (classes_per_students_new[i].UcCode == uccode && classes_per_students_new[i].ClassCode == classcode)
            {
                is_addable = false;
            }
        }
        else if (classes_per_students_new[i].StudentName == studentcode)
        {
            is_name = true;
            tmpCode = classes_per_students_new[i].StudentCode;
            if (classes_per_students_new[i].UcCode == uccode && classes_per_students_new[i].ClassCode == classcode)
            {
                is_addable = false;
            }
        }
    }
    if (is_addable)
    {
        if (is_name)
        {
            classes_per_students_new.push_back({tmpCode, studentcode, uccode, classcode});
        }
        else
        {
            classes_per_students_new.push_back({studentcode, tmpCode, uccode, classcode});
        }

        for (int i = 0; i < ocupation_new[uccode].size(); i++)
        {
            if (ocupation_new[uccode][i].first == classcode)
            {
                ocupation_new[uccode][i].second++;
                break;
            }
        }

        return true;
    }
    return false;
}

/**
 * @brief
 * verifica se a uc e valida, se a troca de turma nao provoca desiquilibrios e se não se sobrepõem aulas no horario do aluno;
 * troca o aluno de turma;
 * Complexidade: n*m
 * @param studentcode
 * @param uccode
 * @param classcode turma aonde o aluno está inscrito
 * @param newclasscode turma para que o aluno quer mudar
 * @return true troca o aluno de turma
 * @return false nao foi possível trocar o aluno de turma
 */

bool Creator::class_changer(string studentcode, string uccode, string classcode, string newclasscode)
{
    if (!is_valid_uc_class(uccode, newclasscode))
    {
        cout << "Invalid UC and Class combination - ";
        return false;
    }
    if (!is_balanced(uccode, newclasscode))
    {
        cout << "Classes would be unbalanced!";
        return false;
    }
    if (!is_valid_schedule_change(studentcode, uccode, classcode, newclasscode))
    {
        cout << "Overlapping classes!";
        return false;
    }

    for (int i = 0; i < classes_per_students_new.size(); i++)
    {
        if (classes_per_students_new[i].UcCode == uccode && (classes_per_students_new[i].StudentCode == studentcode || classes_per_students_new[i].StudentName == studentcode))
        {
            classes_per_students_new[i].ClassCode = newclasscode;
            for (int i = 0; i < ocupation_new[uccode].size(); i++)
            {
                if (ocupation_new[uccode][i].first == classcode)
                {
                    ocupation_new[uccode][i].second--;
                }
                if (ocupation_new[uccode][i].first == newclasscode)
                {
                    ocupation_new[uccode][i].second++;
                }
            }
            return true;
        }
    }
    return false;
}

/**
 * @brief
 * Verifica se turma existe dentro da UC;
 * Complexidade: n
 * @param uccode
 * @param classcode
 * @return true a turma existe
 * @return false a turma não existe
 */

bool Creator::is_valid_uc_class(string uccode, string classcode)
{
    for (int i = 0; i < classes_per_uc_new.size(); i++)
    {
        if (classes_per_uc_new[i].UcCode == uccode && classes_per_uc_new[i].ClassCode == classcode)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief
 * Verifica se a UC existe;
 * Complexidade: n
 * @param uccode
 * @return true se a UC existe
 * @return false se a UC não existe
 */

bool Creator::is_valid_uc(string uccode)
{
    for (int i = 0; i < uc_classes_new.size(); i++)
    {
        if (uc_classes_new[i].first == uccode)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief
 * Verifica se a turma existe:
 * Complexidade: log(n)
 * @param classcode
 * @return true se a turma existe
 * @return false se a turma não existe
 */

bool Creator::is_valid_class(string classcode)
{
    if (all_classes_new.find(classcode) != all_classes_new.end())
    {
        return true;
    }
    return false;
}

/**
 * @brief
 * Verifica se há para sobreposições com a troca de turma de aulas que não sejam do tipo T;
 * Complexidade: n*m
 * @param studentcode
 * @param uc
 * @param oldclass
 * @param newclass
 * @return true nao há sobreposiçôes, ou as sobreposiçôes for entre uma aula do tipo T e outra
 * @return false há sobreposiçôes
 */

bool Creator::is_valid_schedule_change(string studentcode, string uc, string oldclass, string newclass)
{
    vector<pair<string, string>> student_ucs_classes;
    for (int i = 0; i < classes_per_students_new.size(); i++)
    {
        if ((classes_per_students_new[i].StudentCode == studentcode || classes_per_students_new[i].StudentName == studentcode) && !(classes_per_students_new[i].UcCode == uc && classes_per_students_new[i].ClassCode == oldclass))
        {
            student_ucs_classes.push_back({classes_per_students_new[i].UcCode, classes_per_students_new[i].ClassCode});
        }
    }
    string day;
    float start = 0;
    float duration = 0;
    for (int i = 0; i < classes_new.size(); i++)
    {
        if (classes_new[i].UcCode == uc && classes_new[i].ClassCode == newclass && classes_new[i].Type.size() > 1)
        {
            day = classes_new[i].WeekDay;
            start = stof(classes_new[i].StartHour);
            duration = stof(classes_new[i].Duration);
            break;
        }
    }
    for (int i = 0; i < classes_new.size(); i++)
    {
        if (day == classes_new[i].WeekDay && classes_new[i].Type.size() > 1)
        {
            for (int j = 0; j < student_ucs_classes.size(); j++)
            {
                if (classes_new[i].UcCode == student_ucs_classes[j].first && classes_new[i].ClassCode == student_ucs_classes[j].second)
                {
                    if ((start < stof(classes_new[i].StartHour) && start + duration >= stof(classes_new[i].StartHour)) || (start > stof(classes_new[i].StartHour) && start < stof(classes_new[i].StartHour) + stof(classes_new[i].Duration)) || (start == stof(classes_new[i].StartHour)))
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}