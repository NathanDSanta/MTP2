#include "Categoria.h"

Categoria::Categoria(string p_nom, int p_unitats){nom = p_nom; unitats = p_unitats;}

/* void Categoria::mostrar() const{
    cout << nom << " - " << unitats << endl
} */
bool Categoria::operator ==(const Categoria& c) const{return nom == c.nom;}
bool Categoria::operator <(const Categoria& c) const{return nom < c.nom;}
void Categoria::operator +=(const Categoria& c){unitats += c.unitats;}

bool Categoria::satisfer_demanda(int quantitat) const{return unitats >= quantitat;}