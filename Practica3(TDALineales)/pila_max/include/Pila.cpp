/**
  * @file Pila.cpp
  * @brief Fichero implementación del TDA Pila (templates)
  *
  * Implementa los métodos del TDA Pila que se encuentra en el dirctorio include por la forma de realizar la compilación separada.
  */
#include <iostream>
using namespace std;

//Gracias a la implementación que hicimos de ListaT.h realizar la de Pila es trivial.

template <class T>
void Pila<T>::poner(T elemento){
  pila.insertarAlFinal(elemento);
}

template <class T>
T Pila<T>::tope(){
  return pila.getUltimo();
}

template <class T>
bool Pila<T>::vacia(){
  return pila.vacia();
}

template <class T>
void Pila<T>::quitar(){
  pila.delUltimo();
}

template <class T>
int Pila<T>::getNumeroElementos(){
  return pila.getNumeroElementos();
}
