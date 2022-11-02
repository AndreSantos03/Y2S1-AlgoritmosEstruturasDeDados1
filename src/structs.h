#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Aulas
{
    string CodAula;
    string CodUc;
    string DiaSemana;
    string HoraComeco;
    string Duracao;
    string Tipo;
};

struct aulas_por_uc
{
    string CodUc;
    string CodAula;
};

struct estudantes_aulas
{
    string NomeEstudante;
    string CodEstudante;
    string CodUc;
    string CodAula;
};

struct pedido
{
    string tipo;
    string estudante;
    string coduc;
    string codaula;
    string novocodaula;
};

#endif