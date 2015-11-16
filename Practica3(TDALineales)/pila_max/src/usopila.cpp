#include <iostream>
#include <Pila.h>
using namespace std;

//Programa de ejemplo del T.D.A. Pila

int main(void){

  //Declaramos una pila de enteros.
  Pila<int> pila;

  //La llenamos de elementos:
  for(int i=0; i<10; ++i)
    pila.poner(i);

  //Imprimimos su contenido sacando los elementos.
  while(!pila.vacia()){
    cout << pila.tope() << endl;
    pila.quitar();
  }
}
