/**
  * @file VectorT.h
  * @brief Fichero cabecera del TDA VectorT (templates)
  *
  * Implementa un vector dinámico con templates para que pueda contener cualquier tipo de objeto.
  */
#ifndef __VectorT_h__
#define __VectorT_h__

//Ahora con templates
template <class T>
class VectorT{

  private:

    T * elementos;
    int numElementos;

  public:

    VectorT();

    void insertarAlFinal(T elemento);
    void eliminarUltimo();
    void imprimeVector();
    int getNumeroElementos();

    /**
    * @brief Devuelve una copia del último elemento del array.
    * @return Un elemento de tipo T que se encuentra en la última posición.
    */
    T getUltimo();

    /**
    * @brief Para conocer si la lista está vacía.
    * @return True si la lista no tiene elementos o false si contiene.
    */
    bool vacia();


};
#include "VectorT.cpp"

/*Incluimos las implementaciones en el archivo de cabecera para resolver los problemas de compilación.*/

#endif
