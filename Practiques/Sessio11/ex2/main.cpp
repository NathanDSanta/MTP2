#include <iostream>
using namespace std;

bool numero_sort(int num){
    bool sort;
    if(num < 10){
        if(num == 8) sort = true;
        else sort = false;
    } else{
        if(num%10 == 8) sort = true;
        else sort = numero_sort(num/10);
    }
    return sort;
}

int main(){
    cout << "ENTRA UN VALOR ENTER NO NEGATIU: " << endl;
    int num;
    cin >> num;
    while(num < 0){
        cout << "ENTRA UN VALOR ENTER NO NEGATIU: " << endl;
        cin >> num;
    }
    if(!numero_sort(num)) cout << "NO ";
    cout << "ES UN NUMERO DE LA SORT" << endl; 
    return 0;
}