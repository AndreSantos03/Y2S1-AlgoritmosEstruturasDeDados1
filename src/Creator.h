#ifndef _CREATOR_H_
#define _CREATOR_H_

#include "Sorter.h"
#include "Reader.h"
#include "Structs.h"
#include <climits>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Creator{
    public:
        void initialize();
        void initialize_classes_uc();
        void initialize_ocupation();

        vector<vector<string>> schedule(vector<vector<string>> p);

        void ocupacao();

        bool remove_class_uc(string studentcode, string uccode, string classcode);
        bool is_balanced(string uccode, string classcode);
        bool add_to(string studentcode, string uccode, string classcode);
        bool change_class(string studentcode, string uccode, string classcode, string newclasscode);
        bool esta_valido_turma_uc(string uccode, string classcode);
        bool is_valid_uc_class(string uccode, string classcode);
        bool is_valid_uc(string uccode);
        bool is_valid_class(string classcode);
        bool is_valid_schedule_change(string studentcode, string uc, string oldclass, string newclass);
        
        vector<classes> turmas;
        vector<classes_per_uc> turmas_por_uc;
        vector<students_classes> turmas_por_alunos;
        set<string> todas_turmas;
        vector<pair<string, vector<string>>> turmas_por_uc;
        map<string, vector<pair<string, int>>> ocupacao;
    }