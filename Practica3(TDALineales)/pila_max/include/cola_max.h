/**
  * @file cola_max.h
  * @brief Fichero cabecera del TDA cola_max
  *
  * Implementa una cola de valores enteros donde cada elemento de esta es una celda
  * que guarda tanto el valor pasado como el valor máximo actual en la cola en el momento de la insercción.
  */

#ifndef __cola_max_h__
#define __cola_max_h__
#include <Pila.h>

//Implementación del TDA cola_max. Una cola de enteros con máximo, donde en este caso
//el primero de la cola incluye su valor y el máximo de toda la cola.

struct elemento{
  int entero; //Valor del elemento de la lista.
  int maximoPila; //Valos máximo de todos los valores de la lista.

  friend ostream& operator << (ostream &os , const elemento &obj){
    os << "[" << obj.entero << "|" << obj.maximoPila << "]";
    return os;
  }

};

class cola_max{

  private:
    Pila <elemento> pilaElementos;

  public:

    //Para insertar un valor en el tope de la pila
    void poner(int valor);

    void quitar();

    //Para obtener una copia del elemento principio de la cola
    elemento inicio();

    //Para saber si
    bool vacia();

    void invertirPila();

    int getNumeroElementos();

};
#endif
