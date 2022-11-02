#include "Sorter.h"


bool sortAlphabetically(pair<string,string> s1, pair<string,string> s2)
{
    return s1.first < s2.first;
}


bool sortNumber(pair<string,string> s1, pair<string,string> s2)
{
    return s1.second < s2.second;
}


bool sortUpwards(pair<string, vector<pair<string,int>>> s1, pair<string, vector<pair<string,int>>> s2)
{
    return s1.first < s2.first;
}


bool sortDownwards(pair<string, vector<pair<string,int>>> s1, pair<string, vector<pair<string,int>>> s2)
{
    return s1.first > s2.first;
}