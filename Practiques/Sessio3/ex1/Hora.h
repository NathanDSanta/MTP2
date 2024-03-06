#ifndef HORA_H
#define HORA_H

class Hora{
private:
    //Atributs
    int a_h, a_m;

    //Consultors
    bool validar_hora() const;
    //Pre: --; Post: Cert si hora és valida, i fals altrament

public:
    //Constructors
    Hora();
    //Pre: -- ; Post: és l'hora 00:00;
    Hora(int h, int m);
    //Pre: -- ; Post: és l'hora h:m si és vàlida, 00:00 en cas contrari;

    //Consultors
    void mostrar() const;
    //Pre: --; Post: mostra l'hora en format hh:mm (sempre amb dos dígits)
    bool es_menor(const Hora& h) const;
    //Pre: --; Post: cert si l'hora actual és anterior a h, i fals altrament;
    int durada(const Hora& h) const;
    //Pre: h és menor que l'hora actual; Post: retorna els minuts entre l'hora h i l'hora actual (assumint del mateix dia)

    //Modificadors
    void llegir();
    //Pre: --; Post: llegeix hores en format HHMM, fins a llegir-ne una de correcta
};

#endif // !HORA_H