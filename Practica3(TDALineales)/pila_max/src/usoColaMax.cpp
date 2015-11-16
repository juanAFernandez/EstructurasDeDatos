/**
  * @file usoColaMax.cpp
  * @brief Fichero de prueba del TDA cola_max
  *
  */
#include <iostream>
#include <cola_max.h>
using namespace std;

//Programa de ejemplo del T.D.A. Cola con máximo, que funciona de forma similar a pila con máximo pero esta vez se trata de
//una cola con máximo y debajo tiene implementada una pila.

int main(void){

  //Declaramos una cola
  cola_max cola;

  //Introducimos en la cola los valores 5,10,3,12 y 1.
  cola.poner(5);
  cola.poner(10);
  cola.poner(3);
  cola.poner(12);
  cola.poner(1);


  while (!cola.vacia() ){
    elemento x = cola.inicio();
    cola.quitar();
    cout << x << " ";
  }
  cout << endl;

  //Al ir extrayéndolos de la cola se debería ver por terminal la secuencia:
  //[5 | 5] [10 | 10] [3 | 10] [12 | 12] [1 | 12]




}
