/**
  * @file Pila.h
  * @brief Fichero cabecera del TDA Pila (templates)
  *
  * Implementa una pila (LIFO) clásica con templates para cualquier tipo de objeto.
  */
#ifndef __Pila_h__
#define __Pila_h__

#include <ListaT.h>

template <class T>
class Pila{

  private:
    //La implementación de la pila la vamos a realizar con una lista (que ya tenemos implementada con templates)
    ListaT<T>pila;

  //Los método públicos son exactamente los mismo que hemos usado antes para las pilas de los tres tipos.
  public:

    /*
    * @brief Para poner un elemento de tipo T encima de la pila.
    * @param valor Entero que se quiere poner en el top de la pila.
    */
    void poner(T elemento);

    /**
    * @brief Para cononcer el elemento del tope de la pila.
    * @return Copia del valor del tope de la pila. Un objeto de tipo elemento.
    */
    T tope();

    /**
    * @brief Para conocer si la lista está vacía.
    * @return True si no tiene ningún elemento y False en caso contrario.
    */
    bool vacia();

    /*
    * @brief Quita un elemento del tope de la pila.
    */
    void quitar();

    /**
    * @brief Para conocer el número de elementos que tiene la pila
    * @return Entero que indica el número de elementos que la pila tiene.
    */
    int getNumeroElementos();


};
#include "Pila.cpp"
#endif
