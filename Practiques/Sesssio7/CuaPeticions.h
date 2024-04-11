#ifndef CUAPETICIONS_H
#define CUAPETICIONS_H
#include <iostream>
#include "Peticio.h"
using namespace std;

class CuaPeticions{
    private:
        //Constants
        static const int PRIMER_TORN = 9;
        static const int ULTIM_TORN = 12;

        //Structs
        struct Node{
            Peticio valor;
            Node* seg;
        };
        
        //Atributs
        Node* a_inicial;
        Node* a_final;
        int seg_hora_disponible;

    public:
        //Constructors -- Destructor
        CuaPeticions();
        //Pre: --; Post: incialitza la cua
        ~CuaPeticions();
        //Pre: --; Post: destrueix la cua

        //Mètodes consultors
            void mostrar() const;
            //Pre: --; Post: mostra la cua
            bool dia_acabat() const;
            //Pre: --; Post: retorna si el dia ha acabat;
            bool buida() const;
            //Pre: --; Post: retorna true si la llista està buida;
            bool sense_hores() const;
            //Pre: --; Post: retorna true si ja no hi ha hores disponibles;

        //Mètodes modificadors
            void afegir(const Peticio& p);
            //Pre: --; Post: afegeix una peticio a la cua
            void nova_peticio();
            //Pre: --; Post: demana, verifica i afegeix una peticio a la cua (si és correcte)
            void processar_recollida();
            //Pre: --; Post: si no esta buida, processa una recollida


};

#endif // !CUAPETICIONS_H