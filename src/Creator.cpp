#inlcude "scheduler.h"

int CLASS_CAP = 30;

void Creator::initializer(){
    Reader read;
    turmas= read.;
    turmas_por_uc = Ler.ler_cadeiras_por_uc();
    
    initialize_classes_uc();
    initialize_ocupation()
}

void Creator::inicializar_classes_uc(){
    string uc_temp = "":
    int index = -1;
    for(int i = 0; i < turmas_por_uc.size();i++){
        if (current_uc != classes_per_uc_v[i].codUc)
        {
            turmas_por_uc.push_back({turmas_por_uc[i].codUC, {turmas_por_uc[i].codAula}});
            current_uc_index++;
            current_uc = aulas_por_uc[i].UcCode;
        }
        else
        {
            ucs_classes_v[current_uc_index].second.push_back(classes_per_uc_v[i].ClassCode);
        }
        
        all_classes_v.insert(classes_per_uc_v[i].ClassCode);
    }
}
