#include <iostream>
#include "pila_max_cola.h"
using namespace std;

elemento pila_max_cola::tope(){

  invertirCola();
  elemento a = colaElementos.frente();
  invertirCola();

  return a;
}

void pila_max_cola::invertirCola(){

  //cout << "ANtes de invertir: " << colaElementos.num_elementos() << endl;

  int tam=colaElementos.num_elementos();

  if(tam!=0){

    //Creamos un vector e introducimos una copia exacta de la cola
    elemento elementos[tam];

    //Extraemos los elementos de la cola
    for(int i=0; i<tam; i++){
      elementos[i]=colaElementos.frente();
      //Después de obtener el elemento de la frente se quita.
      colaElementos.quitar();
    }

    //cout << "TAM DESPUES DE QUITAR TODOS" << colaElementos.num_elementos() << endl;

    //Al final introducimos los elementos del vector al revés:
    for(int i=tam-1; i>=0; i--)
      colaElementos.poner(elementos[i]);
  }

  //cout << "Después de invertir: " << colaElementos.num_elementos() << endl;

}

void pila_max_cola::poner(int valor){

  //1ºCreamos una celda con el nuevo elemento.
    elemento nuevo;
    nuevo.entero=valor;
    //Aun no decidimos cual será el valor máximo de la pila.

  //2ºDecidimos si el valor pasado es el máximo.
    //Si no hay elementos aún.
    if(colaElementos.num_elementos()==0){
      //cout << "Introduciendo un elemento" << endl;
      //El elemento pasado será el máximo
      nuevo.maximoPila=valor;
      //Introducimos el elemento en la lista:
      colaElementos.poner(nuevo);
      //cout << "La cola tiene " << colaElementos.num_elementos() << "elementos" << endl;
    }else{
      //Accedemos al elemento top de la lista y vemos su valor y decidimos si el máximo ha variado.
      //cout << "Introduciendo un elemento. Num actual: " << colaElementos.num_elementos() << endl;
      //Invertimos la cola
      invertirCola();

      //cout << "Despues de invertir : " << colaElementos.num_elementos() << endl;
      elemento tope = colaElementos.frente();

      //Reinvertimos la cola
      invertirCola();

      //Si el valor del tope es mayor que el que vamos a introducir, sigue siendo el mayor.
      if(tope.maximoPila > valor)
        nuevo.maximoPila=tope.maximoPila;
      else
        nuevo.maximoPila=valor;

      //Despues lo introducimos:
      colaElementos.poner(nuevo);

    }

}

void pila_max_cola::quitar(){
  invertirCola();
  colaElementos.quitar();
  invertirCola();
}

bool pila_max_cola::vacia(){
  return colaElementos.vacia();
}
