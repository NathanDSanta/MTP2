#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PRODUCTES = 5000;
const int MAX_CATEGORIES = 1000;

struct Data{
    int dia, mes, any;
};

struct Producte{
    string codi, nom, marca, categoria;
    Data caducitat;
    int unitats;
};

struct Categoria{
    string nom;
    int unitats;
};

typedef Producte Vec_productes[MAX_PRODUCTES];
typedef Categoria Vec_categories[MAX_CATEGORIES];

struct Productes{
    Vec_productes t;
    int n;
};

struct Categories{
    Vec_categories t;
    int n;
};



Data demanar_data(string missatge){
//Pre: cert
//Post: mostra missatge i llegeix data
    Data data;
    cout << missatge << endl;
    cin >> data.any >> data.mes >> data.dia;
    return data;
}

string demanar_string(string missatge){
//Pre: cert
//Post: mostra missatge i llegeix cadena de caràcters
    string aux;
    cout << missatge << endl;
    cin >> aux;
    return aux;
} 

char demanar_char(string missatge){
//Pre: cert
//Post: mostra missatge i llegeix caràcter
    cout << missatge << endl;
    char aux;
    cin >> aux;
    return aux;
}

int demanar_int(string missatge){
//Pre: cert
//Post: mostra missatge i llegeix enter
    cout << missatge << endl;
    int aux;
    cin >> aux;
    return aux;
}



Producte llegir_producte(ifstream& fin){
//Pre: cert
//Post: llegeix producte de fitxer
    Producte p;
    fin >> p.codi >> p.nom >> p.marca >> p.unitats >> p.caducitat.any >> p.caducitat.mes >> p.caducitat.dia >> p.categoria; 
    return p;
}

bool es_menor_data(Data d1, Data d2){
//Pre: cert
//Post: retorna true si d1 < d2, i fals altrament
    bool es_menor = false;
    es_menor = d1.any < d2.any;
    if(d1.any == d2.any){
        es_menor = d1.mes < d2.mes;
        if(d1.mes == d2.mes) es_menor = d1.dia < d2.dia;
    }
    return es_menor;
}

bool es_igual_data(Data d1, Data d2){
//Pre: cert
//Post: retorna true si d1 = d2, i fals altrament
    return d1.any == d2.any && d1.mes == d2.mes && d1.dia == d2.dia;
}

void inserir_producte(const Producte& p, Productes& vec){
//Pre: 0 <= vec.n < MAX_PRODUCTES
//Post: p inserit a vec.t[0..vec.n - 1]
    int i = vec.n;
    while (i > 0 && p.codi < vec.t[i - 1].codi){
        vec.t[i] = vec.t[i - 1];
        i--;
    } 
    vec.t[i] = p;
    vec.n++;
}

void inserir_categoria(Categories& vec, string nom, int unitats){
//Pre: 0 <= vec.n < MAX_CATEGORIA
//Post: categoria amb "nom" i "unitats" inserida a vec.t[0..vec.n - 1]
    int i = vec.n;
    while(i > 0 && nom < vec.t[i - 1].nom){
        vec.t[i] = vec.t[i - 1];
        i--;
    }
    Categoria c = {nom, unitats}; 
    vec.t[i] = c;
    vec.n++;
}

void cerca_dicotomica_categoria(const Categories& vec, string nom, bool& existeix, int& pos){
//Pre: 0 <= vec.n <= MAX_CATEGORIES
//Post: existeix = true si categoria amb "nom" existeix, pos = posició on es troba, i fals altrament, pos = posició d'inserció.
    int esq = 0, drt = vec.n - 1, mig = 0;
    existeix = false;
    while (!existeix && drt >= esq){
        mig = (esq + drt)/2;
        if(vec.t[mig].nom == nom) existeix = true;
        else if(vec.t[mig].nom < nom) esq = mig + 1;
        else drt = mig - 1;
    }
    if(existeix) pos = mig;
    else pos = esq;
}

void cerca_dicotomica_producte(const Productes& vec, string codi, bool& existeix, int& pos){
//Pre: 0 <= vec.n <= MAX_PRODUCTES
//Post: existeix = true si producte amb "codi" existeix, pos = posició on es troba, i fals altrament, pos = posició d'inserció.
    int esq = 0, drt = vec.n - 1, mig;
    existeix = false;
    while (!existeix && drt >= esq){
        mig = (esq + drt)/2;
        if(vec.t[mig].codi == codi) existeix = true;
        else if(vec.t[mig].codi < codi) esq = mig + 1;
        else drt = mig - 1;
    }
    if(existeix) pos = mig;
    else pos = esq;    
}

void actualitzar_categories(Categories& vec, string nom, int unitats){
//Pre: 0 <= vec.n < MAX_CATEGORIES
//Post: actualitza vector categories, insereix 1 categoria si no existeix, actualitza el nombre d'unitats si existeix.
    bool existeix;
    int pos;
    cerca_dicotomica_categoria(vec, nom, existeix, pos);
    if(existeix) vec.t[pos].unitats+=unitats;
    else inserir_categoria(vec, nom, unitats);
}

void afegir_producte(const Producte& p, Productes& vec){
//Pre: 0 <= vec.n < MAX_PRODUCTES
//Post: si ja existeix el producte p, s'actualitza el nombre d'unitats, altrament s'insereix a vec.t[0..vec.n-1]
    bool existeix; int pos;
    cerca_dicotomica_producte(vec, p.codi, existeix, pos);
    if (existeix) vec.t[pos].unitats += p.unitats;
    else inserir_producte(p, vec);
}


void llegir_fitxer(ifstream& fin, Productes& curt, Productes& llarg, Categories& cat, Data llindar){
//Pre: cert
//Post: llegeix fitxer i utilitza la data llindar per classificar els productes llegits en 3 vectors diferents.
    curt.n = 0;
    llarg.n = 0;
    cat.n = 0;
    Producte p = llegir_producte(fin);
    while(!fin.eof()){    
        if(es_menor_data(p.caducitat, llindar)) afegir_producte(p,curt);
        else afegir_producte(p,llarg);
        actualitzar_categories(cat, p.categoria, p.unitats);
        p = llegir_producte(fin);
    }
}

void menu(){
//Pre: cert
//Post: mostra el menu
    cout << "OPCIONS: " << endl
        << "N -> Ordenar per nom" << endl
        << "D -> Ordenar per data" << endl
        << "A -> Actualitzar" << endl
        << "C -> Comanda" << endl
        << "M -> Menu" << endl
        << "S -> Sortir" << endl;

}

void mostrar_producte(Producte p){
//Pre: cert
//Post: mostra el producte p
    cout << "c:" << p.codi << " - " << p.nom << " (" << p.marca << ") - n:"
         << p.unitats << ", cad:" << p.caducitat.dia << "-" << p.caducitat.mes
         << "-" << p.caducitat.any << " [" << p.categoria << "]" << endl;
}

void mostrar_tots_productes(const Productes& vec){
//Pre: 0 <= vec.n <= MAX_PRODUCTES
//Post: mostra els productes de vec.t[0..vec.n-1]
    cout << "Llistat de productes de caducitat curta:" << endl;
    for(int i = 0; i < vec.n; i++){
        mostrar_producte(vec.t[i]);
    }
}

bool es_menor_producte(Producte a, Producte b, char criteri){
//Pre: criteri = N o D
//Post: retorna true si el producte a és menor que b depenent del "criteri", i fals altrament
    bool es_menor = false;
    if(criteri == 'N'){
        es_menor = a.nom < b.nom;
        if(a.nom == b.nom){
            es_menor = a.marca < b.marca;
            if(a.marca == b.marca) es_menor = es_menor_data(a.caducitat, b.caducitat);
        }
    } else{
        es_menor = es_menor_data(a.caducitat, b.caducitat);
        if(es_igual_data(a.caducitat,b.caducitat)){
            es_menor = a.nom < b.nom;
            if(a.nom == b.nom) es_menor = a.marca < b.marca;
        }
    }
    return es_menor;
}

void intercanviar_producte(Producte& a, Producte& b){
//Pre: a = A, b = B
//Post: a = B, b = A
    Producte aux = a;
    a = b;
    b = aux;
}

void ordenar_productes(Productes& vec, char criteri){
//Pre: 0 <= vec.n <= MAX_PRODUCTES
//Post: vec.t[0..vec.n-1] ordenat segons "criteri".
    for(int i = 0; i < vec.n; i++){
        int pos_min = i;
        for(int j = i + 1; j < vec.n; j++){
            if(es_menor_producte(vec.t[j], vec.t[pos_min], criteri)) pos_min = j;
        }
        intercanviar_producte(vec.t[i],vec.t[pos_min]);
    }
}

void actualitzar_vectors_caducitat(Productes& curt, Productes& llarg, Data d){
//Pre: 0 <= curt.n < MAX_PRODUCTES, 0 <= llarg.n < MAX_PRODUCTES
//Post: productes de llarg.t[0..llarg.n-1] que tenen una caducitat més propera que "d", són eliminats i inserits a curt.t[0..curt.n-1]
    int n_bons = 0;
    for(int i = 0; i < llarg.n; i++){
        if(es_menor_data(d,llarg.t[i].caducitat)) llarg.t[n_bons] = llarg.t[i];
        else afegir_producte(llarg.t[i],curt);
    }
    llarg.n = n_bons;
}

int main(){
    Data llindar = demanar_data("Entra una data (any mes dia): ");
    string nom_fitxer = demanar_string("Entra el nom del fitxer: ");
    ifstream fin(nom_fitxer.c_str());
    if(!fin.is_open()) cout << "Fitxer no trobat" << endl;
    else {
        Productes c_curta, c_llarga;
        Categories categories;
        llegir_fitxer(fin, c_curta, c_llarga, categories, llindar);
        menu();
        bool sortir = false;
        while(!sortir){
            char opcio = demanar_char("Opcio: ");
            switch(opcio){
                case 'N':       //Al no posar break, puc fer servir el codi per ambdòs casos, ja que són idèntics.
                case 'D':{
                    Productes curta_ordenats = c_curta;
                    ordenar_productes(curta_ordenats, opcio);
                    mostrar_tots_productes(curta_ordenats);
                    break;
                }
                case 'A':{
                    Data nova_data = demanar_data("Entra la nova data (any mes dia):");
                    actualitzar_vectors_caducitat(c_curta, c_llarga, nova_data);
                    break;
                }
                case 'C':{
                    string categ = demanar_string("Categoria: ");
                    int quant = demanar_int("Quantitat:");
                    bool satisfer; bool existeix; int pos;
                    cerca_dicotomica_categoria(categories, categ, existeix, pos);
                    satisfer = existeix && categories.t[pos].unitats >= quant;
                    if(satisfer) cout << "-- Es pot satisfer --" << endl;
                    else cout << "-- No es pot satisfer --" << endl;
                    break;
                }
                case 'M':
                    menu();
                    break;
                case 'S':
                    sortir = true;
                    break;
            }
        }
    }
    return 0;
}