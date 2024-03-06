#ifndef PUNT2D_H
#define PUNT2D_H

class Punt2D {
public:
    Punt2D();
    //Mètodes consultors
    double distancia(Punt2D p) const;

private:
    double a_x, a_y;
};

#endif