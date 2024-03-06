#ifndef DATA_H
#define DATA_H

class Data{
private:
    //Atributs
    int a_dia, a_mes, a_any;

    //Consultors
    bool validar_data() const;
    //Pre: -- ; Post: cert si data vàlida, i fals altrament

public:
    //Constructors
    Data();
    //Pre: -- ; Post: és la data 1/1/2001 (data per defecte)
    Data(int d, int m, int a);
    //Pre: -- ; Post: és la data d/m/a si és correcta o 1/1/2001 en cas contrari

    //Consultors
    void mostrar(int format) const;
    //Pre: format 1 o 2; Post: mostra la data actual en format d/m/a o d-mes-a
    bool es_menor(const Data &d) const;
    //Pre: --; Post; cert si d és una data posterior a l'actual, fals altrament

    //Modificadors
    void llegir(int format);
    //Pre: format 1 o 2; Post: llegeix dates en format AAAAMMDD o d m a, fins a llegir-ne una de correcta

};

#endif // !DATA_H