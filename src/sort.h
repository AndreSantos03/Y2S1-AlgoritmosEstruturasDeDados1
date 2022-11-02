#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool ordenaAlfabeticamente(pair<string, string> s1, pair<string, string> s2);
bool ordenaNumericamente(pair<string, string> s1, pair<string, string> s2);
bool ordenaCrescenteUc(pair<string, vector<pair<string, int>>> s1, pair<string, vector<pair<string, int>>> s2);
bool ordenaDecrescenteUc(pair<string, vector<pair<string, int>>> s1, pair<string, vector<pair<string, int>>> s2);

#endif