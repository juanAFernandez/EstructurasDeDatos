#include <iostream>
#include "pila_max_vd.h"
using namespace std;

elemento pila_max_vd::tope(){
  return vectorElementos.getUltimo();
}

void pila_max_vd::poner(int valor){

  //1ºCreamos una celda con el nuevo elemento.
    elemento nuevo;
    nuevo.entero=valor;
    //Aun no decidimos cual será el valor máximo de la pila.

  //2ºDecidimos si el valor pasado es el máximo.
    //Si no hay elementos aún.
    if(vectorElementos.getNumeroElementos()==0){
      //El elemento pasado será el máximo
      nuevo.maximoPila=valor;
      //Introducimos el elemento en la lista:
      vectorElementos.insertarAlFinal(nuevo);
    }else{
      //Accedemos al elemento top de la lista y vemos su valor y decidimos si el máximo ha variado.
      elemento tope = vectorElementos.getUltimo();

      //Si el valor del tope es mayor que el que vamos a introducir, sigue siendo el mayor.
      if(tope.maximoPila > valor)
        nuevo.maximoPila=tope.maximoPila;
      else
        nuevo.maximoPila=valor;

      //Despues lo introducimos:
      vectorElementos.insertarAlFinal(nuevo);

    }

}

void pila_max_vd::quitar(){
  vectorElementos.eliminarUltimo();
}

bool pila_max_vd::vacia(){
  return vectorElementos.vacia();
}
