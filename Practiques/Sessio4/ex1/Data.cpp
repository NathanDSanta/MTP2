#include "Data.h"

const int Data::DIES_MES[Data::MESOS_ANY] = {31,28,31,30,31,30,31,31,30,31,30,31};


Data::Data(){
    a_dia = 1;
    a_mes = 1;
    a_any = 2001;
}

Data::Data(int d, int m, int a){
    a_dia = d;
    a_mes = m;
    a_any = a;
}

//Consultors
void Data::mostrar(int format) const{
    char simbol = '/';
    if(format == 2) simbol = '-';
    cout << a_dia << simbol << a_mes << simbol << a_any;
}


//Modificadors
void Data::llegir(int format) {
    if(format == 1){
        int data;
        cin >> data;
        a_dia = data % 100;
        data /= 100;
        a_mes = data % 100;
        data /= 100;
        a_any = data;
    }
    else{cin >> a_dia >> a_mes >> a_any;}
    while(!validar_data()){
        if(format == 1){
            int data;
            cin >> data;
            a_dia = data % 100;
            data /= 100;
            a_mes = data % 100;
            data /= 100;
            a_any = data;
        }
        else{cin >> a_dia >> a_mes >> a_any;}
    }
}

bool Data::validar_data() const{return a_dia > 0 && a_mes > 0 && a_any > 0 && a_mes <= MESOS_ANY && a_dia <= DIES_MES[a_mes];}

//Operadors
bool Data::operator< (const Data &d) const{
    bool es_menor = a_any < d.a_any;
    if(a_any == d.a_any) {
        es_menor = a_mes < d.a_mes;
        if(a_mes == d.a_mes) es_menor = a_dia < d.a_dia;
    }
    return es_menor;
}

bool Data::operator ==(const Data &d)const{return a_any == d.a_any && a_mes == d.a_mes && a_dia == d.a_dia;}