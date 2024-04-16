#ifndef V_INT_H
#define V_INT_H
#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node* seg;
};

class Vint{
    public:
        
        Vint();
        ~Vint();

    private:
        //Atributs
        Node *a_inici;

        //Operadors
        friend istream& operator >>(istream& i, Vint& vector); 
        friend ostream& operator <<(ostream& o, const Vint& vector); 


};

#endif // !V_INT_H