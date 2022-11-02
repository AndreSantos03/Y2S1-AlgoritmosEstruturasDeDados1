#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct classes
{
    string codAula;
    string codUc;
    string diaSemana;
    string horaComeco;
    string duracao;
    string tipo;
};

struct classes_for_uc
{
    string codUc;
    string codAula;
};

struct classes_per_students
{
    string nomeEstudante;
    string codEstudante;
    string codUc;
    string codAula;
};

struct request
{
    string tipo;
    string estudante;
    string coduc;
    string codaula;
    string novocodaula;
};

#endif