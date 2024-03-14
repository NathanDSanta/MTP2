#include "Producte.h"

Producte::Producte(){codi = ""; nom = ""; marca = ""; categoria = ""; unitats = 0;}

Producte::Producte(ifstream& fin){
    fin >> codi;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(fin, nom);
    getline(fin, marca);
    fin >> unitats;
    caducitat = Data(fin);
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(fin, categoria);
}

void Producte::mostrar() const{
    cout << "c:" << codi << " - " << nom
         << "(" << marca << ") - n: " << unitats
         << ", cad:";
    caducitat.mostrar();
    cout << " [" << categoria << "]" << endl;
}

void Producte::intercanviar(Producte& p){
    Producte aux = *this;
    *this = p;
    p = aux;
}

bool Producte::ordenar_per(const Producte& p,char criteri) const{
    bool va_abans = false;
    if(criteri == 'N'){
        va_abans = nom < p.nom;
        if(nom == p.nom){
            va_abans = marca < p.marca;
            if(marca == p.marca) va_abans = caducitat < p.caducitat;
        }
    }
    else{
        va_abans = caducitat < p.caducitat;
        if(caducitat == p.caducitat){
            va_abans = nom < p.nom;
            if(nom == p.nom) va_abans = marca < p.marca;
        }
    }
    return va_abans;
}

bool Producte::operator <(const Producte& p) const{return codi < p.codi;}
bool Producte::operator <<(const Data& d) const{return caducitat < d;}
bool Producte::operator ==(const Producte& p) const {return codi == p.codi && nom == p.nom && marca == p.marca && caducitat == p.caducitat && categoria == p.categoria;}
void Producte::operator +=(const Producte& p) {unitats += p.unitats;}

Categoria Producte::crear_categoria() const{return Categoria(categoria, unitats);}