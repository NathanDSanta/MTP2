#include <iostream>
#include <cmath>
#include "Punt2D.h"
using namespace std;

//Constructors
Punt2D::Punt2D(){
    cout << "Entra el centre de la circumferencia, x y: " << endl;
    cin >> a_x >> a_y;
}


//Consultors
double Punt2D::distancia(Punt2D p) const{return sqrt((a_x-p.a_x)*(a_x-p.a_x)+(a_y-p.a_y)*(a_y-p.a_y));}
