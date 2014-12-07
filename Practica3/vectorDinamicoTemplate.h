/**
  * @file vectorDinamico.h
  * @brief Fichero cabecera del T.D.A. vectorDinamicoTemplate
  *
  * @author Juan Antonio Fernández Sánchez
  * @date Noviembre 2014
  */
#ifndef _vectorDinamicoTemplate_h
#define _vectorDinamicoTemplate_h
#include <cassert>

//CUando tenemos template el h es el que incluye al cpp (al revés de lo normal). Además el .cpp del template se pone en include.

//El operador corchetes nos sirve para poder acceder, set, get, instertar, borrar. Con esto ya podemos implementar la pila (son funciones necesarias).


template <class TYPE>
class vectorDinamico{

  private:

    TYPE *datos;
    int numElementos;

  public:

    //	##	Constructores:
    /**
    * @brief Primer constructor del T.D.A. vector dinámico que incializa el objeto reservando un tamaño de memoria
    * que le es pasado por parámetro.
    * @param n Número de elementos que el vector en principio tendrá. Será el indicador necesario para reservar la memoria.
    */

    vectorDinamico<TYPE>(int n);



    /**
    * @brief Segundo constructor del T.D.A. vector dinámico que crea un objeto a partir del contenido de otro.
    * @param original Vector original a partir del cual se crear el nuevo vector, copiando el contenido de este al nuevo.
    */
    //vectorDinamico<T>(const vectorDinamico<T>& original);

    //	##	Destructor:
    /**
    * @brief Destructor del T.D.A. vector dinámico que se encarga de liberar toda la memoria reservada para los elementos de este.
    */
    //~vectorDinamico<T>(); //Libera la memoria reservada por el vector dinámico.

    /**
    * @brief Numero de componentes del vector
    * @return Devuelve el número de componentes que puede almacenar en cada instante el vector.
    */
    //int size() const;

    /**
    * @brief Sobrecarga del operador corchete []
    * @param i Entero índice de acceso al vector.
    * @return Devuelve la direcicón de memoria de un float.
    */
    //T& operator[] (int i);

    /**
    *
    *
    */
    //const T& operator[] (int i) const;

    /**
    * @brief Función para redimensionar el tamaño del vector.
    * @param n Número de elementos que se quiere que tenga el vector.
    */
    //void resize(int n);

    //vectorDinamico<T>& operator=(const vectorDinamico<T>& original);






};

//Constructor que reserva cierta cantidad de memoria.
template <class TYPE>
vectorDinamico<TYPE>::vectorDinamico(int n){
  assert(n>=0);
    if(n>0)
      datos = new TYPE[n];
    numElementos=n;
}



#endif
