#include "Magatzem.h"


//Constructors -- Destructor
Magatzem::Magatzem(){
    a_inici = NULL;
}

Magatzem::Magatzem(const Magatzem& m){
    *this = m;
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
    string nom;
    cin >> nom;
    bool existeix;
    Node *pos, *antpos;
    cerca_aliment(Aliment(nom), &pos, &antpos, existeix);
    if(!existeix) cout << "[ No tenim " << nom << " al magatzem! ]" << endl;
    else pos->valor.descripcio();
}

//Mètodes modificadors
void Magatzem::servir_aliment(){
    Aliment serv; cin >> serv;
    Node *pos, *antpos; bool existeix;
    cerca_aliment(serv, &pos, &antpos, existeix);
    Aliment dif;
    if(existeix) dif = pos->valor - serv;
    if(!existeix) serv.no_existeix();
    else if(dif <= 0){
        if(dif == 0)cout << "[ Aliments servits! ]" << endl;
        else pos->valor.insuficients();
        *this -= pos->valor;
    } else{
        pos->valor -= serv;
        cout << "[ Aliments servits! ]" << endl;
    }

}

//Metodes privats
void Magatzem::cerca_aliment(const Aliment& a, Node** aux, Node** antpos, bool& existeix) const{
    existeix = false;
    Node *i = a_inici, *ant = NULL;    
    while(!existeix && i != NULL && i->valor <= a){
        if(i->valor == a) existeix = true;
        else {
            ant = i;
            i = i->seg;
        };
    }
    *aux = i;
    *antpos = ant;
}

//Operadors
ostream& operator <<(ostream& o, const Magatzem& m){
    cout << "[ ALIMENTS ]" << endl;
    Magatzem::Node* ptr = m.a_inici;
    while(ptr != NULL){
        o << ptr->valor;
        ptr = ptr->seg;
    }
    return o;
}

Magatzem& Magatzem::operator =(const Magatzem& m){
    if(m.a_inici == NULL) a_inici = NULL; 
    else{
        a_inici = new Node{m.a_inici->valor, NULL};
        Node* ptr = a_inici;
        Node* i = m.a_inici->seg;
        while(i != NULL){
            ptr->seg = new Node{i->valor, NULL};
            i = i->seg;
            ptr = ptr->seg;
        }
    }
    return *this;
}

void Magatzem::operator +=(const Magatzem& m){
    *this = *this + m;
}
void Magatzem::operator +=(const Aliment& a){
    *this = *this + a;
}

Magatzem Magatzem::operator +(const Magatzem& m){
    Node* i = m.a_inici;
    while(i != NULL){
        *this = *this + i->valor;
    }
    return *this;
}

Magatzem Magatzem::operator +(const Aliment& a){
    if(a_inici == NULL) 
        a_inici = new Node{a, NULL};
    else{
        bool existeix;
        Node *pos, *antpos;
        cerca_aliment(a, &pos, &antpos, existeix);
        if(existeix) pos->valor += a;
        else {
            Node *ins = new Node{a, pos};
            if(antpos != NULL) antpos->seg = ins;
            else a_inici = ins;
        }
    }
    cout << "[ Aliment inserit correctament. ]" << endl;
    return *this;
}

Magatzem Magatzem::operator -(const Aliment& a){
    bool existeix;
    Node *pos, *antpos;
    cerca_aliment(a, &pos, &antpos, existeix);
    if(existeix){
        Node* aux = pos;
        if(antpos == NULL) a_inici = pos->seg;
        else antpos->seg = pos->seg;
        delete aux;
    } 
    return *this;
}

void Magatzem::operator -=(const Aliment& a){
    *this = *this - a;
}

Magatzem Magatzem::operator -(const Magatzem& m){
    Node* i = m.a_inici;
    while(i != NULL){
        *this = *this - i->valor;
    }
    return *this;
}

void Magatzem::operator -=(const Magatzem& m){
    *this = *this - m;
}
