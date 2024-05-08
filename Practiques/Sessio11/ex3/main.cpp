#include <iostream>
using namespace std;

void eliminacio_digit(long long num, int sort){
    if(num < 10){
        if(num%10 != sort) cout << num;
    }
    else{
        eliminacio_digit(num/10, sort);
        if(num%10 != sort)cout << num%10; 
    }
}

int main(){
    long long num;
    cout << "ENTRA UN ENTER NO NEGATIU: " << endl;
    cin >> num;
    while(num < 0){
        cout << "ENTRA UN ENTER NO NEGATIU: " << endl;
        cin >> num;        
    }
    int mala_sort;
    cout << "ENTRA EL DIGIT DE LA MALA SORT: " << endl;
    cin >> mala_sort;
    while(mala_sort >= 10 || mala_sort < 0){
        cout << "ENTRA EL DIGIT DE LA MALA SORT: " << endl;
        cin >> mala_sort;        
    }
    cout << "VALOR FINAL: " << endl;
    eliminacio_digit(num, mala_sort);
    return 0;
}