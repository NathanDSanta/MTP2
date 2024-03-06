#ifndef DATA_H
#define DATA_H

class Data{
private:
    //Atributs
    int dia, mes, any;

public:
    //Constructors
    Data();
    //Pre: -- ; Post: Data incialitzada a {0,0,0};
    Data(int data);
    //Pre: -- ; Post: llegeix la data amb format AAAAMMDD

    //Consultors
    int obtenir_dia() const;
    //Pre: -- ; Post: retorna el dia;
    int obtenir_mes() const;
    //Pre: -- ; Post: retorna el mes;
    int obtenir_any() const;
    //Pre: -- ; Post: retorna l'any; 
    bool es_menor(Data d) const;
    //Pre: -- ; Post: retorna true si la data es menor que "d", i fals altrament
    bool es_aniversari(Data d) const;
    //Pre: -- ; Post: retorna true si la data es l'aniversari segons "d", i fals altrament
    int calcular_edat(Data d) const;
    //Pre: -- ; Post: retorna l'edat segons la data d;
    bool validar_data() const;
    //Pre: -- ; Post: retorna true si la data es valida i més gran que "d", i fals altrament

}; 

#endif