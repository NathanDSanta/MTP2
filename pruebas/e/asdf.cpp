#include <iostream>
using namespace std;

void change_x(int **p, int **q){
    int *c = *p;
    *p = *q;
    *q = c;
}

int main(){
    int t[2];
    int *x = t, *y = t + 1;
    *x = 2;
    *y = 4;
    change_x(&x , &y);
    cout << *x << " - " << *y << endl;
    return 0;
}