#include <iostream>
#include "cola_max.h"
using namespace std;

elemento cola_max::inicio(){
  //cout << "ANtes de invertir: " << (pilaElementos.tope()).entero << endl;
  invertirPila();
  //cout << "Después de invertir: " << (pilaElementos.tope()).entero << endl;
  elemento a=pilaElementos.tope();
  invertirPila();
  return a;
}

void cola_max::poner(int valor){
  //cout << "Valor a poner" << valor;

  //1ºCreamos una celda con el nuevo elemento.
    elemento nuevo;
    nuevo.entero=valor;
    //Aun no decidimos cual será el valor máximo de la pila.

  //2ºDecidimos si el valor pasado es el máximo.
    //Si no hay elementos aún.
    if(pilaElementos.getNumeroElementos()==0){
      //El elemento pasado será el máximo
      nuevo.maximoPila=valor;

      //cout << "Celda puesta: " << nuevo.entero << " | "<< nuevo.maximoPila << endl;

      //Introducimos el elemento en la lista:
      pilaElementos.poner(nuevo);
    }else{
      //Accedemos al elemento top de la lista y vemos su valor y decidimos si el máximo ha variado.
      //invertirPila();
      elemento tope = pilaElementos.tope();
      //invertirPila();

      //Si el valor del tope es mayor que el que vamos a introducir, sigue siendo el mayor.
      if(tope.maximoPila > valor)
        nuevo.maximoPila=tope.maximoPila;
      else
        nuevo.maximoPila=valor;


      //Despues lo introducimos:
      pilaElementos.poner(nuevo);

    //  cout << "Celda puesta: " << nuevo.entero << " | "<< nuevo.maximoPila << endl;
    //  cout << "num" << pilaElementos.getNumeroElementos() << endl;

    }

}

void cola_max::quitar(){
//  cout << "Tam" << pilaElementos.getNumeroElementos() << endl;
//  cout << "ANtes de quitar entero tope: " << (pilaElementos.tope()).entero << endl;
  invertirPila();
  pilaElementos.quitar();
  invertirPila();
//    cout << "Después de quitar entero tope: " << (pilaElementos.tope()).entero << endl;
//    cout << "Tam" << pilaElementos.getNumeroElementos() << endl;
}

bool cola_max::vacia(){
  return pilaElementos.vacia();
}

void cola_max::invertirPila(){
  //cout << "ANtes de invertir num elem: " << pilaElementos.getNumeroElementos() << endl;
  //cout << "ANtes de invertir entero tope: " << (pilaElementos.tope()).entero << endl;

  int tam=pilaElementos.getNumeroElementos();

  if(tam!=0){

    //Creamos un vector e introducimos una copia exacta de la cola
    elemento elementos[tam];

    //Extraemos los elementos de la cola
    for(int i=0; i<tam; i++){
      //cout << "Extrayendo" << pilaElementos.tope().entero << endl;
      elementos[i]=pilaElementos.tope();
      //Después de obtener el elemento de la frente se quita.
      pilaElementos.quitar();
    }

    //cout << "TAM DESPUES DE QUITAR TODOS" << colaElementos.num_elementos() << endl;

    //Al final introducimos los elementos del vector al revés:
    for(int i=0; i<tam; ++i)
      pilaElementos.poner(elementos[i]);
  }

  //cout << "Después de invertir num elem : " << pilaElementos.getNumeroElementos() << endl;
  //cout << "Después de invertir entero tope: " << (pilaElementos.tope()).entero << endl;
  //cout << endl << endl;
}
int cola_max::getNumeroElementos(){
  return pilaElementos.getNumeroElementos();
}
