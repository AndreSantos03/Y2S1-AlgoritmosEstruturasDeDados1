#include "Read.h"


vector<aulas_por_uc> Read::ler_aulas_por_uc()
{
    vector<aulas_por_uc> v;
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
        aulas_por_uc p;
        getline(line, buf, ',');
        p.CodUc = buf;
        getline(line, buf, '\r');
        p.CodAula = buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}


vector<aulas> Read::ler_aulas()
{
    vector<aulas> v;
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
        aulas p;
        getline(line, buf, ',');
        p.CodAula = buf;
        getline(line, buf, ',');
        p.CodUc = buf;
        getline(line, buf, ',');
        p.DiaSemana = buf;
        getline(line, buf, ',');
        p.HoraComeco = buf;
        getline(line, buf, ',');
        p.Duracao = buf;
        getline(line, buf, '\r');
        p.Tipo = buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}


vector<estudantes_aulas> Read::ler_estudantes_aulas()
{
    vector<estudantes_aulas> v;
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
        estudantes_aulas p;
        getline(line, buf, ',');
        p.CodEstudante = buf;
        getline(line, buf, ',');
        p.NomeEstudante = buf;
        getline(line, buf, ',');
        p.CodUc = buf;
        getline(line, buf, '\r');
        p.CodAula = buf;
        v.push_back(p);
    }

    filein.close();
    return v;
}