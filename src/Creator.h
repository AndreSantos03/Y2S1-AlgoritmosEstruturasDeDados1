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
        void initialize_uc_classes();
        void initialize_ocupation();
        vector<vector<string>> schedule(vector<vector<string>> p);
        void ocupation();
        bool remove_class_uc(string studentcode, string uccode, string classcode);
        bool is_balanced(string uccode, string classcode);
        bool add_to(string studentcode, string uccode, string classcode);
        bool change_class(string studentcode, string uccode, string classcode, string newclasscode);
        bool is_valid_uc_class(string uccode, string classcode);
        bool is_valid_uc(string uccode);
        bool is_valid_class(string classcode);
        bool is_valid_schedule_change(string studentcode, string uc, string oldclass, string newclass);
        
        vector<classes> classes_new;
        vector<classes_per_uc> classes_per_uc_new;
        vector<classes_per_students> classes_per_students_new;
        set<string> all_classes_new;
        vector<pair<string,vector<string>>> uc_classes_new;
        map<string, vector<pair<string,int>>> ocupation_new;
    };

#endif