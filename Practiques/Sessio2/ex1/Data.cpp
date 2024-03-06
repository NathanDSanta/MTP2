#include <iostream>
#include "Data.h"
using namespace std;

Data::Data(){
    dia = 0;
    mes = 0;
    any = 0;
}

Data::Data(int d){
    dia = d%100;
    d/=100;
    mes = d%100;
    d/=100;
    any = d;
}


int Data::obtenir_dia() const {return dia;}
int Data::obtenir_mes() const {return mes;}
int Data::obtenir_any() const {return any;}

bool Data::validar_data() const {
    bool valid = mes <= 12 && dia < 31;
    if(!valid && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia == 31) valid = true;
    else if(mes == 2 && dia > 28) valid = false;
    return valid;
}

bool Data::es_menor(Data d) const {
    bool es_menor = any < d.any;
    if(any == d.any){
        es_menor = mes < d.mes;
        if(mes == d.mes) es_menor = dia < d.dia;
    }
    return es_menor;
}

bool Data::es_aniversari(Data d) const {return mes == d.mes && dia == d.dia;}

int Data::calcular_edat(Data d) const {
    int edat = any - d.any;
    d.any = any;
    if(es_menor(d)) edat--;
    return edat;
}