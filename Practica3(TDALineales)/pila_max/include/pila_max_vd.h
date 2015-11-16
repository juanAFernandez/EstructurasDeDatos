/**
  * @file pila_max_vd.h
  * @brief Fichero cabecera del TDA pila_max_vd
  *
  * Implementa una pila con máximo a partir del uso de una vector dinámico.
  */
#ifndef __pila_max_vd_h__
#define __pila_max_vd_h__
#include <VectorT.h>

struct elemento{
  int entero; //Valor del elemento de la lista.
  int maximoPila; //Valos máximo de todos los valores de la lista.

  friend ostream& operator << (ostream &os , const elemento &obj){
    os << "[" << obj.entero << " | " << obj.maximoPila << "]";
    return os;
  }

};

class pila_max_vd{

  private:
    VectorT <elemento> vectorElementos;

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
