#ifndef CERCLE_H
#define CERCLE_H
#include "Punt2D.h"

class Cercle{
private:
    //Atributs
    Punt2D a_centre;
    double a_radi;

public:
    Cercle();

    //Metodes consultors
    void posicio_relativa_a(const Cercle& c, int& interiors, int& secants, bool& exteriors) const;
    //Pre: interios >= 0, secants >= 0
};

#endif // !CERCLE_H