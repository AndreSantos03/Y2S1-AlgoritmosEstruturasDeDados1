#ifndef _SORTER_H_
#define _SORTER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool sortAlphabetically(pair<string, string> s1, pair<string, string> s2);
bool sortNumber(pair<string, string> s1, pair<string, string> s2);
bool sortUpwards(pair<string, vector<pair<string, int>>> s1, pair<string, vector<pair<string, int>>> s2);
bool sortDownwards(pair<string, vector<pair<string, int>>> s1, pair<string, vector<pair<string, int>>> s2);

#endif