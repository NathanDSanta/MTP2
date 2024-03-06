#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 1000;

struct Llibre{
    string titol, isbn, editorial, autor;
    int estoc_l1, estoc_l2;
};

typedef Llibre vec_llibres[MAX];

struct Llibres{
    vec_llibres t;
    int n;
};

void obrir_fitxers(ifstream& fin1, ifstream& fin2){
    cout << "ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 1: " << endl;
    string nom;
    cin >> nom;
    fin1.open(nom.c_str());

    cout << "ENTRA EL NOM DE FITXER DE L'INVENTARI DE LA LLIBRERIA 2: " << endl;
    cin >> nom;
    fin2.open(nom.c_str());
}

Llibre llegir_llibre(ifstream& fin){
    Llibre l;
    fin >> l.titol >> l.isbn >> l.editorial >> l.autor >> l.estoc_l1;
    l.estoc_l2 = 0;
    return l;
}

void llegir_fitxers(Llibres& vec, ifstream& fin1, ifstream& fin2){
    Llibre l1 = llegir_llibre(fin1);
    Llibre l2 = llegir_llibre(fin2);
    vec.n = 0;
    while(!fin1.eof() && !fin2.eof()){
        if(l1.titol == l2.titol){
            vec.t[vec.n] = l1;
            vec.t[vec.n].estoc_l2 = l2.estoc_l1;
            vec.n++;
            l1 = llegir_llibre(fin1);
            l2 = llegir_llibre(fin2);
        } else if(l1.titol < l2.titol){
            vec.t[vec.n] = l1;
            vec.n++;
            l1 = llegir_llibre(fin1);
        } else {
            vec.t[vec.n] = l2;
            vec.t[vec.n].estoc_l1 = 0;
            vec.t[vec.n].estoc_l2 = l2.estoc_l1;
            vec.n++;
            l2 = llegir_llibre(fin2);
        }
    }
    while(!fin1.eof()){
        vec.t[vec.n] = l1;
        vec.n++;
        l1 = llegir_llibre(fin1);
    }
    while(!fin2.eof()){
        vec.t[vec.n] = l2;
        vec.t[vec.n].estoc_l1 = 0;
        vec.t[vec.n].estoc_l2 = l2.estoc_l1;
        vec.n++;
        l2 = llegir_llibre(fin2);
    }
}

void mostrar_llibre(Llibre l){
    cout << l.estoc_l1 << " - " << l.estoc_l2 << " "
        << l.titol << ", " << l.autor << " Ed. "
        << l.editorial << " - " << l.isbn << endl;
}

void mostrar_llibres(const Llibres& vec){
    cout << "Estocs Titol, Autor Editorial - ISBN" << endl;
    for(int i = 0; i < vec.n; i++){
        mostrar_llibre(vec.t[i]);
    }
}

void intercanviar(Llibre& a, Llibre& b){
    Llibre aux = a;
    a = b;
    b = aux;
}

void ordenar_per_isbn(Llibres& vec){
    int pos_min;
    for(int i = 0; i < vec.n; i++){
        pos_min = i;
        for(int j = i + 1; j < vec.n; j++){
            if(vec.t[j].isbn < vec.t[pos_min].isbn) pos_min = j;
        }
        intercanviar(vec.t[i], vec.t[pos_min]);
    }
}

int main(){
    ifstream botiga_1, botiga_2;
    obrir_fitxers(botiga_1, botiga_2);
    Llibres alfabetic;
    llegir_fitxers(alfabetic,botiga_1,botiga_2);
    cout << "INVENTARI PER ORDRE ALFABETIC" << endl;
    mostrar_llibres(alfabetic);
    Llibres isbn = alfabetic;
    ordenar_per_isbn(isbn);
    cout << endl << "INVENTARI PER ORDRE D'ISBN" << endl;
    mostrar_llibres(isbn);
    return 0;
}