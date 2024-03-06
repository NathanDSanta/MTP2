#include <iostream>
#include "Data.h"
using namespace std;

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

bool Data::es_menor(const Data &d) const{
    bool es_menor = a_any < d.a_any;
    if(a_any == d.a_any) {
        es_menor = a_mes < d.a_mes;
        if(a_mes == d.a_mes) es_menor = a_dia < d.a_dia;
    }
    return es_menor;
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

bool Data::validar_data() const{
    bool valid = a_mes <= 12 && a_dia < 31;
    if(!valid && (a_mes == 1 || a_mes == 3 || a_mes == 5 || a_mes == 7 || a_mes == 8 || a_mes == 10 || a_mes == 12) && a_dia == 31) valid = true;
    else if(a_mes == 2 && a_dia > 28) valid = false;
    return valid;
}