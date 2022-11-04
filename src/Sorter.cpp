/**
 * @file Sort.cpp
 * Funções para ordenar vetores
 */

#include "Sorter.h"

/**
 * @brief
 * ordena por ordem alfabética;
 * complexidade: nlogn
 * @param s1 par composto de (nome do aluno, codigo do aluno)
 * @param s2
 * @return true se o nome do aluno em s1 for menor(número das letras na tabela ASCII) que o nome do aluno de s2
 * @return false caso contrário
 */

bool sortAlphabetically(pair<string,string> s1, pair<string,string> s2)
{
    return s1.first < s2.first;
}

/**
 * @brief
 * ordena por ordem dos códigos dos alunos
 * complexidade: nlogn
 * @param s1 par composto de (nome do aluno, codigo do aluno)
 * @param s2
 * @return true se o código do aluno s1 for menor que o código do auno s2
 * @return false caso contrário
 */

bool sortNumber(pair<string,string> s1, pair<string,string> s2)
{
    return s1.second < s2.second;
}

/**
 * @brief
 * ordena por orden crescente do UcCode
 * complexidade: nlogn
 * @param s1 par composto pelo UcCode e por um par (Class code, int nº de estudantes por class)
 * @param s2
 * @return true se o UCcode de s1 for menor que de s2
 * @return false caso contrário
 */

bool sortUpwards(pair<string, vector<pair<string,int>>> s1, pair<string, vector<pair<string,int>>> s2)
{
    return s1.first < s2.first;
}

/**
 * @brief
 * ordena por ordem decrescente do UCcode
 * complexidade: n*log(n)
 * @param s1 par composto pelo UcCode e por um par (Class code, int nº de estudantes por class)
 * @param s2
 * @return true se o UcCode de s1 for maior que de s2
 * @return false caso contrário
 */

bool sortDownwards(pair<string, vector<pair<string,int>>> s1, pair<string, vector<pair<string,int>>> s2)
{
    return s1.first > s2.first;
}