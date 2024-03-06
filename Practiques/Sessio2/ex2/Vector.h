#ifndef VECTOR_H
#define VECTOR_H

class Vector{
private:
    //Atributs
    double x, y, z;
    bool hemisferi_nord;

public:
    //Constructors
    Vector();
    //Pre: -- ; Post: Inicialitza el vector als valors entrats per teclat;
    Vector(double x, double y, double z);
    //Pre: -- ; Post: Inicialitza el vector a (x,y,z);

    //Consultors
    Vector suma(Vector v) const;
    //Pre: -- ; Post: retorna el vector suma amb "v";
    Vector resta(Vector v) const;
    //Pre: -- ; Post: retorna el vector resta amb "v";
    Vector multiplicacio_real(double r) const;
    //Pre: -- ; Post: retorna el vector inicila multiplicat pel real r;
    Vector producte_vectorial(Vector v) const;
    //Pre: -- ; Post: retorna el vector resultant del producte vectorial amb "v";
    bool esta_hemisferi_nord() const;
    //Pre: -- ; Post: retorna true si el vector està a l'hemisferi nord;
    void mostrar() const;
    //Pre: -- ; Post: mostra el vector;
    
};

#endif