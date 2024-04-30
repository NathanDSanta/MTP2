#include "Baralla.h"

int main(){
    cout << "ENTRA LA LLAVOR: " << endl;
    int llavor;
    cin >> llavor;
    if(llavor < 0) llavor *= -1;
    if(llavor == 0) llavor = 1;
    Baralla cartes(llavor);
    cout << cartes;
    return 0;
}