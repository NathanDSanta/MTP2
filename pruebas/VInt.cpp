#include "Vint.h"

Vint::Vint(){
    a_inici = NULL;
}

Vint::~Vint(){

    while (a_inici != NULL){

    }  
    
}

istream& operator >>(istream& i, Vint& vector){

    int valor;
    i >> valor;

    while(valor != -1){
        Node *ptr = vector.a_inici;
        Node *ant = NULL;
        bool fiCerca= false;
        bool trobat = false;
        while(ptr != NULL && !fiCerca){
            if(ptr->valor >= valor){
            fiCerca = true; trobat = valor == ptr->valor;
            } else {
                ant = ptr;
                ptr = ptr->seg;
            }   
        }
        if(!trobat){
        }
    }

}

ostream& operator <<(ostream& o, const Vint& vector){
    Node *i = vector.a_inici;
    while(i != NULL){
        o << i->valor << " ";
        i = i->seg;
    }
}

