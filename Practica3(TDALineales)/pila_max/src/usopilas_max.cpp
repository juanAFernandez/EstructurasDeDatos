#include <iostream>
//Debería funcionar usando pila_max p, pero no lo hace.
#include "pila_max.h"

using namespace std;

int main(){

  //Prueba de la implementación de pila con máx implementada con una lista.
  //pila_max_lista p;

  //Prueba de la implementación con un vector dinámico.
  //pila_max_vd p;

  //Prueba de la implementación con una cola.
  pila_max_cola p;

  //int i;

  /**
  for ( i=10; i>=0 ; i--)
    p.poner(i);
  **/

  p.poner(5);
  p.poner(10);
  p.poner(3);
  p.quitar();
  p.poner(12);
  p.poner(1);


  int i=0;
  while (!p.vacia() ){
    cout << "paso " << i;
    i++;
    elemento x = p.tope();
    p.quitar();
    cout << x << endl;
  }


  return 0;
}
