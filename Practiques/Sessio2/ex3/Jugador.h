#ifndef  JUGADOR_H
#define JUGADOR_H
#include <iostream>
using namespace std;

class Jugador{

private:
    //Constants
    static const int N_PUNTS = 5;
    static const int ORDRE_PUNTS[N_PUNTS];

    //Atributs
    string nom;
    int punts, jocs;
    bool guanyat;

    //Consultors
    void mostrar_jugador() const;
    //Pre: --; Post: mostra el jugador;

    //Modificadors
    void augmentar_joc(Jugador& j);
    //Pre: -- ; Post: Augmenta els jocs del jugador
public:
    //Constructors
    Jugador();
    //Pre: -- ; Post: Demana el nom i inicialitza el jugador amb el nom entrat per teclat;

    //Consultors
    string obtenir_nom() const;
    //Pre: --; Post: retorna el nom del jugador;
    bool obtenir_guanyat() const;
    //Pre: --; Post: retorna el boleà guanyat del jugador;

    //Modificadors
    void augmentar_punts(Jugador& j);
    //Pre: -- ; Post: augmenta els punts del jugador;

    static void mostrar_jugadors(Jugador A, Jugador B);
    //Pre: -- ; Post: mostra els 2 jugadors.
};

#endif // ! JUGADOR_H