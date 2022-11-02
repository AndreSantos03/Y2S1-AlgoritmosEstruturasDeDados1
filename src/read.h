#ifndef _READ_H_
#define _READ_H_

#include "structs.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Read
{
  public:
    vector<aulas_por_uc> ler_aulas_por_uc();
    vector<aulas> ler_aulas();
    vector<estudantes_aulas> ler_estudantes_aulas();
};

#endif
