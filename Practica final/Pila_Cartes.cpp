#include "Pila_Cartes.h"

//Constructors - Destructor

Pila_Cartes::Pila_Cartes(){
//Pre: --; Post: pila buida
    a_cim = NULL;
}

Pila_Cartes::Pila_Cartes(const Pila_Cartes &p){
//Pre: --; Post: pila és còpia de p
    copia(p);
}

Pila_Cartes::Pila_Cartes(Baralla &b){
//Pre: --; Post: pila formades per les cartes de b
    a_cim = NULL;
    while(!b.buit()){
        *this += b--;
    } 
}

Pila_Cartes::~Pila_Cartes(){
//Pre: --; Post: memòria alliberada
    allibera();
}

void Pila_Cartes::allibera(){
//Pre: --; Post: memòria alliberada
    while(a_cim != NULL){
        Node* aux = a_cim;
        a_cim = a_cim->seg;
        delete aux;
    }
}

//Mètodes privats

void Pila_Cartes::copia(const Pila_Cartes &p){
//Pre: --; Post: pila és còpia de p
    Node *i = a_cim, *j = p.a_cim;
    a_cim = new Node{j->valor, NULL};
    i = a_cim->seg; 
    j = j->seg;
    while(j != NULL){
        i = new Node{j->valor, NULL};
        i = i->seg; j = j->seg;
    }
}



//Operadors

Pila_Cartes& Pila_Cartes::operator=(const Pila_Cartes& p){
//Pre: --; Post: pila és còpia de p
    if(this != &p){
        allibera();
        copia(p);
    }
    return *this;
}

Pila_Cartes& Pila_Cartes::operator=(Baralla& b){
//Pre: --; Post: pila formada per les cartes de b
    allibera();
    *this = Pila_Cartes(b);
    return *this;
}

void Pila_Cartes::operator+=(const Carta& c){
//Pre: --; Post: c afegida a pila
    Node *aux = new Node{c, a_cim};
    a_cim = aux;
}

ostream& operator<<(ostream& o, const Pila_Cartes& p){
    if(p.a_cim != NULL) o << p.a_cim->valor;
    else o << "   ";
    return o;
}