#include <iostream>
using namespace std;

typedef int Vec_int[30];

bool es_prefix(Vec_int vec_1, Vec_int vec_2, int m_1, int m_2){
    bool prefix;
    if(m_2 == 0){
        prefix = true;
    }
    else if(vec_1[m_2] != vec_2[m_2]){
        prefix = false;
    }
    else{
        prefix = es_prefix(vec_1, vec_2, m_2-1, m_2-1);
    }
    return prefix;
}

int main(){
    Vec_int a = {10,7,2,3,5}, b = {10,5,2};
    int n_a = 5, n_b = 3;
    bool prefix = es_prefix(a,b,n_a - 1,n_b - 1);
    cout << prefix;
    return 0;
}