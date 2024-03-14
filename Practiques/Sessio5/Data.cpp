#include "Data.h"

Data::Data(bool cin2, int any, int mes, int dia){
    if(cin2){
        cin >> a_any >> a_mes >> a_dia;
    } else{
        a_any = any;
        a_mes = mes;
        a_dia = dia;
    }
}

Data::Data(ifstream& fin){
    fin >> a_any >> a_mes >> a_dia;
}

void Data::mostrar() const{
    cout << a_dia << "/"
         << a_mes << "/"
         << a_any;
}

bool Data::operator <(const Data& d) const{
    bool es_menor = a_any < d.a_any;
    if(a_any == d.a_any){ 
        es_menor = a_mes < d.a_mes;
        if(a_mes == d.a_mes) es_menor = a_dia < d.a_dia;
    }
    return es_menor;
}

bool Data::operator ==(const Data& d) const{return a_any == d.a_any && a_mes == d.a_mes && a_dia == d.a_dia;}