#include "CuaPeticions.h"

CuaPeticions::CuaPeticions(){
    a_inicial = NULL;
    a_final = NULL;
    seg_hora_disponible = PRIMER_TORN;
}

CuaPeticions::~CuaPeticions(){
    while(a_inicial != NULL){
        Node* aux = a_inicial;
        a_inicial = a_inicial->seg;
        delete aux;
    }    
}

//Consultors

void CuaPeticions::mostrar() const{
    if(!buida()) cout << "L'estat actual de la cua es el seguent: " << endl;
    else cout << "Cua buida! " << endl;
    Node* i = a_inicial;
    while(i != NULL){
        i->valor.mostrar();
        i = i->seg;
    }
}

bool CuaPeticions::dia_acabat() const{
    return buida() && sense_hores();
}

bool CuaPeticions::buida() const{return a_inicial == NULL;}

bool CuaPeticions::sense_hores() const{return seg_hora_disponible >= 13;}
//Modificadors

void CuaPeticions::afegir(const Peticio& p){
    Node* aux = new Node {p, NULL};
    if(a_inicial == NULL){
        a_inicial = aux;
        a_final = aux;
    }
    else {
        a_final->seg = aux;
        a_final = a_final->seg;
    }
}

void CuaPeticions::nova_peticio(){
    if(sense_hores()) cout << "JA NO HI HA HORES DISPONIBLES PER AVUI! " << endl << "TORNI A INTENTAR-HO DEMA!" << endl;
    else {
        cout << "NOM: " << endl;
        string nom; cin >> nom;
        cout << "ID (DNI / NIE): " << endl;
        string id; cin >> id;
        Peticio p(nom, id, seg_hora_disponible);
        afegir(p);
        cout << "PETICIO ENREGISTRADA CORRECTAMENT" << endl;
        seg_hora_disponible++;
    }
}

void CuaPeticions::processar_recollida(){
    if(!buida()){
        Node* aux = a_inicial;
        a_inicial = a_inicial->seg;
        aux->valor.recollida();
        delete aux;
        if(!dia_acabat()) mostrar();
    }
}
