/**
  * @file pila_max_cola.h
  * @brief Fichero cabecera del TDA pila_max_cola
  *
  * Implementa una pila con máximo a partir del uso de una cola.
  */
#ifndef __pila_max_cola_h__
#define __pila_max_cola_h__
#include <cola.h>

struct elemento{
  int entero; //Valor del elemento de la lista.
  int maximoPila; //Valos máximo de todos los valores de la lista.

  friend ostream& operator << (ostream &os , const elemento &obj){
    os << "[" << obj.entero << " | " << obj.maximoPila << "]";
    return os;
  }

};

class pila_max_cola{

  private:
    Cola <elemento> colaElementos;

    void invertirCola();

  public:

    //Para insertar un valor en el tope de la pila
    void poner(int valor);

    void quitar();

    //Para obtener una copia del elemento de la pila
    elemento tope();

    //Para saber si
    bool vacia();

};
#endif
