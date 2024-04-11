#include "Magatzem.h"


//Constructors -- Destructor
Magatzem::Magatzem(){
    a_inici = NULL;
}

Magatzem::Magatzem(const Magatzem& m){
    
}

Magatzem::~Magatzem(){
    while(a_inici != NULL){
        Node* aux = a_inici;
        a_inici = a_inici->seg;
        delete aux;
    }
}

//Mètodes consultors
void Magatzem::consultar_aliment() const{
    cout << "[ CONSULTAR ALIMENT: ]" << endl;
    string nom;
    cin >> nom;
    bool existeix;
    Node* pos;
    cerca_aliment(Aliment(nom), &pos, existeix);
    if(pos != NULL) cout << "[ No tenim " << nom << " al magatzem! ]" << endl;
    else cout << pos->valor;
}

//Mètodes modificadors


//Metodes privats
void Magatzem::cerca_aliment(const Aliment& a, Node** aux, bool& existeix) const{
    existeix = false;
    Node* i = a_inici;
    while(!existeix && i->seg->valor < a){
    }
}

//Operadors
ostream& operator <<(ostream& o, const Magatzem& m){
    Magatzem::Node* ptr = m.a_inici;
    while(ptr != NULL){
        cout << ptr->valor;
        ptr = ptr->seg;
    }
}

Magatzem& Magatzem::operator =(const Magatzem& m){
    a_inici = new Node{m.a_inici->valor, NULL};
    Node* ptr = a_inici;
    Node* i = m.a_inici->seg;
    while(i != NULL){
        ptr->seg = new Node{i->valor, NULL};
        i = i->seg;
        ptr = ptr->seg;
    }
    return *this;
}

Magatzem& Magatzem::operator +=(const Magatzem& m){
    return *this + m;
}
Magatzem& Magatzem::operator +=(const Aliment& a){
    return *this + a;
}

Magatzem& Magatzem::operator +(const Magatzem& m){
    Magatzem aux = *this;
    Node* i = m.a_inici;
    while(i != NULL){
        aux = aux + i->valor;
    }
    return aux;
}

Magatzem& Magatzem::operator +(const Aliment& a){
    bool existeix;
    Node* pos;
    cerca_aliment(a, &pos , existeix);
    if(existeix) pos->valor += a;
    else {
        Node* ins = new Node{a, pos->seg};
        pos->seg = ins;
    }
    return *this;
}
