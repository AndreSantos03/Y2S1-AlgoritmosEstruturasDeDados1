/**
 * @file Read.cpp
 * Funções para ler ficheiros
 */

#include "Reader.h"

#define RESET "\033[0m"

/**
 * @brief
 * abre o ficheiro classes_per_uc, verifica se não está aberto(se existe), e cria uma vetor com a informação;
 * Complexidade: n
 * @return vector<classes_per_uc> devolve um vetor com a informação, se nao existir ficheiro devolve um vetor vazio
 */

vector<classes_per_uc> Reader::read_classes_per_uc()
{
    vector<classes_per_uc> v;
    ifstream filein;
    filein.open("../classes_per_uc.csv");
    if (!filein.is_open())
    {
        return v;
    }

    string buffer;
    getline(filein, buffer, '\n');
    while (getline(filein, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        classes_per_uc p;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, '\r');
        p.ClassCode= buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}

/**
 * @brief
 * abre o ficheiro classes, verifica se não está aberto(se existe), e cria uma vetor com a informação;
 * Complexidade: n
 * @return vector<classes> devolve um vetor com a informação, se nao existir ficheiro devolve um vetor vazio
 */

vector<classes> Reader::read_classes()
{
    vector<classes> v;
    ifstream filein;
    filein.open("../classes.csv");
    if (!filein.is_open())
    {
        return v;
    }

    string buffer;
    getline(filein, buffer);
    while (getline(filein, buffer))
    {
        stringstream line(buffer);
        string buf;
        classes p;
        getline(line, buf, ',');
        p.ClassCode = buf;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, ',');
        p.WeekDay = buf;
        getline(line, buf, ',');
        p.StartHour = buf;
        getline(line, buf, ',');
        p.Duration = buf;
        getline(line, buf, '\r');
        p.Type = buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}

/**
 * @brief
 * abre o ficheiro classes_per_students, verifica se não está aberto(se existe), e cria uma vetor com a informação
 * Complexidade: n
 * @return vector<classes_per_students> vector<classes> devolve um vetor com a informação, se nao existir ficheiro devolve
 * um vetor vazio
 */

vector<classes_per_students> Reader::read_students_class()
{
    vector<classes_per_students> v;
    ifstream filein;
    filein.open("../students_classes.csv");
    if (!filein.is_open())
    {
        return v;
    }

    string buffer;
    getline(filein, buffer, '\n');
    while (getline(filein, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        classes_per_students p;
        getline(line, buf, ',');
        p.StudentCode = buf;
        getline(line, buf, ',');
        p.StudentName = buf;
        getline(line, buf, ',');
        p.UcCode = buf;
        getline(line, buf, '\r');
        p.ClassCode = buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}