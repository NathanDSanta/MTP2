#ifndef PUNT2D_H
#define PUNT2D_H
#include <iostream>
using namespace std;

class Punt2D {
public:
    Punt2D();
    Punt2D(double x, double y);

    //Mètodes consultors
    double coordenada_x() const;
    double coordenada_y() const;
    double distancia(Punt2D p) const;
    void mostrar() const;
    bool es_igual(Punt2D p) const;
    Punt2D punt_mig(Punt2D p) const;

    //Mètodes modificadors
    void moure(double x, double y);
    void moure(Punt2D p);
    void llegir();

private:
    double a_x, a_y;
};

#endif