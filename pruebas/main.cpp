#include <iostream>
using namespace std;

void print(int arg) {
  cout << arg << endl;
  cout << "Hello, World!" << endl;
}

int main() {
  cout << "Hello, World!" << endl;
  print(1);
  int i = 0;
  while (i < 10) {
    cout << i << endl;
    i++;
  }

  return 0;
}
