/**
 * @file Read.cpp
 * Funções para ler ficheiros
 */

#include "Reader.h"

/**
 * @brief
 * abre o ficheiro classes_per_uc, verifica se não está aberto(se existe), e cria uma vetor com a informação;
 * Complexidade: n
 * @return vector<classes_per_uc> devolve um vetor com a informação, se nao existir ficheiro devolve um vetor vazio
 */

vector<classes_per_uc> Reader::read_classes_per_uc()
{
    vector<classes_per_uc> r_vector;
    ifstream filein;
    filein.open("../classes_per_uc.csv");
    if (!filein.is_open())
    {
        return r_vector;
    }

    string buffer;
    getline(filein, buffer, '\n');
    while (getline(filein, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        classes_per_uc rrrr;
        getline(line, buf, ',');
        rrrr.UcCode = buf;
        getline(line, buf, '\r');
        rrrr.ClassCode= buf;
        r_vector.push_back(rrrr);
    }

    filein.close();
    return r_vector;
}

/**
 * @brief
 * abre o ficheiro classes, verifica se não está aberto(se existe), e cria uma vetor com a informação;
 * Complexidade: n
 * @return vector<classes> devolve um vetor com a informação, se nao existir ficheiro devolve um vetor vazio
 */

vector<classes> Reader::read_classes()
{
    vector<classes> r_vector;
    ifstream filein;
    filein.open("../classes.csv");
    if (!filein.is_open())
    {
        return r_vector;
    }

    string buffer;
    getline(filein, buffer);
    while (getline(filein, buffer))
    {
        stringstream line(buffer);
        string buf;
        classes rrrr;
        getline(line, buf, ',');
        rrrr.ClassCode = buf;
        getline(line, buf, ',');
        rrrr.UcCode = buf;
        getline(line, buf, ',');
        rrrr.WeekDay = buf;
        getline(line, buf, ',');
        rrrr.StartHour = buf;
        getline(line, buf, ',');
        rrrr.Duration = buf;
        getline(line, buf, '\r');
        rrrr.Type = buf;
        r_vector.push_back(rrrr);
    }

    filein.close();
    return r_vector;
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
    vector<classes_per_students> r_vector;
    ifstream filein;
    filein.open("../students_classes.csv");
    if (!filein.is_open())
    {
        return r_vector;
    }

    string buffer;
    getline(filein, buffer, '\n');
    while (getline(filein, buffer, '\n'))
    {
        stringstream line(buffer);
        string buf;
        classes_per_students rrrr;
        getline(line, buf, ',');
        rrrr.StudentCode = buf;
        getline(line, buf, ',');
        rrrr.StudentName = buf;
        getline(line, buf, ',');
        rrrr.UcCode = buf;
        getline(line, buf, '\r');
        rrrr.ClassCode = buf;
        r_vector.push_back(rrrr);
    }

    filein.close();
    return r_vector;
}