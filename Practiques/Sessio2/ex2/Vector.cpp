#include <iostream>
#include <iomanip>
#include "Vector.h"
using namespace std;

Vector::Vector(){
    cout << "ENTRAR COMPONENT X: " << endl;
    cin >> x;
    cout << "ENTRAR COMPONENT Y: " << endl;
    cin >> y;
    cout << "ENTRAR COMPONENT Z: " << endl;
    cin >> z;
    if(z > 0) hemisferi_nord = true;
    else hemisferi_nord = false;
}
Vector::Vector(double x1, double y1, double z1){x = x1; y = y1; z = z1; if(z > 0) hemisferi_nord = true; else hemisferi_nord = false;}

Vector Vector::suma(Vector v) const {return Vector(x + v.x, y + v.y, z + v.z);}
Vector Vector::resta(Vector v) const {return Vector(x - v.x, y - v.y, z - v.z);}
Vector Vector::multiplicacio_real(double r) const {return Vector(x*r, y*r, z*r);}
Vector Vector::producte_vectorial(Vector v) const {return Vector (y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);}

bool Vector::esta_hemisferi_nord() const{return z > 0;}

void Vector::mostrar() const{cout << "RESULTAT: (" << x << ", " << y << ", " << z << ")" << endl;}

