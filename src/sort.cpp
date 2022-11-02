#include "Sort.h"


bool sortAlphabetically(pair<string,string> s1, pair<string,string> s2)
{
    return s1.first < s2.first;
}


bool ordenaNumericamente(pair<string,string> s1, pair<string,string> s2)
{
    return s1.second < s2.second;
}


bool ordenaCrescenteUc(pair<string, vector<pair<string,int>>> s1, pair<string, vector<pair<string,int>>> s2)
{
    return s1.first < s2.first;
}


ordenaDecrescenteUc(pair<string, vector<pair<string,int>>> s1, pair<string, vector<pair<string,int>>> s2)
{
    return s1.first > s2.first;
}