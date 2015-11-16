/**
  * @file pila_max_lista.h
  * @brief Fichero cabecera del TDA pila_max_lista
  *
  * Implementa una pila con máximo a partir del uso de una lista.
  */
#ifndef __pila_max_lista_h__
#define __pila_max_lista_h__
#include <ListaT.h>

struct elemento{
  int entero; //Valor del elemento de la lista.
  int maximoPila; //Valos máximo de todos los valores de la lista.

  friend ostream& operator << (ostream &os , const elemento &obj){
    os << "[" << obj.entero << "|" << obj.maximoPila << "]";
    return os;
  }

};


class pila_max_lista{

  private:

    //Ahora declaramos una lista que contendrá los objetos.
    ListaT<elemento> listaElementos;


  //Después declaramos los métodos que necestará el tipo de dato.
  public:


    /*
    * @brief Para poner un entero encima de la pila.
    * @param valor Entero que se quiere poner en el top de la pila.
    */
    void poner(int valor);

    /**
    * @brief Para cononcer el elemento del tope de la pila.
    * @return Copia del valor del tope de la pila. Un objeto de tipo elemento.
    */
    elemento tope();

    /**
    * @brief Para conocer si la lista está vacía.
    * @return True si no tiene ningún elemento y False en caso contrario.
    */
    bool vacia();

    /*
    * @brief Quita un elemento del tope de la pila.
    */
    void quitar();


};
#endif
