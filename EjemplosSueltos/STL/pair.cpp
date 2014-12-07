#include <iostream>
#include <utility>
using namespace std;

int main(){

  cout << "Prueba del tipo pair" << endl;

  pair<string,double> producto1;
  pair<string,double> producto2("tomates",2.30);

  cout << producto2.first << endl;

}
