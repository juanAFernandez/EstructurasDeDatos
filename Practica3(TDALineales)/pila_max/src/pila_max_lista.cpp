#include <iostream>
#include "pila_max_lista.h"
using namespace std;

elemento pila_max_lista::tope(){
  return listaElementos.getUltimo();
}

void pila_max_lista::poner(int valor){

  //1ºCreamos una celda con el nuevo elemento.
    elemento nuevo;
    nuevo.entero=valor;
    //Aun no decidimos cual será el valor máximo de la pila.

  //2ºDecidimos si el valor pasado es el máximo.
    //Si no hay elementos aún.
    if(listaElementos.getNumeroElementos()==0){
      //El elemento pasado será el máximo
      nuevo.maximoPila=valor;
      //Introducimos el elemento en la lista:
      listaElementos.insertarAlFinal(nuevo);
    }else{
      //Accedemos al elemento top de la lista y vemos su valor y decidimos si el máximo ha variado.
      elemento tope = listaElementos.getUltimo();

      //Si el valor del tope es mayor que el que vamos a introducir, sigue siendo el mayor.
      if(tope.maximoPila > valor)
        nuevo.maximoPila=tope.maximoPila;
      else
        nuevo.maximoPila=valor;

      //Despues lo introducimos:
      listaElementos.insertarAlFinal(nuevo);

    }

}

void pila_max_lista::quitar(){
  listaElementos.delUltimo();
}

bool pila_max_lista::vacia(){
  return listaElementos.vacia();
}
