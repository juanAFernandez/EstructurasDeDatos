/**
  * @file ListaT.h
  * @brief Fichero cabecera del TDA ListaT (templates)
  *
  * Implementa el tipo de dato lista como una secuencia de celdas enlazadas con cabecera,
  * para su gestión en memoria de forma eficiente, esta vez con uso de templates, por lo que la lista
  * puede ser de cualquier objeto.
  */

#ifndef __ListaT_h__
#define __ListaT_h__

/**
*
* @brief T.D.A. ListaT
*
* Una instancia @e lista del tipo de datos abstracto @c Lista es un objeto que representa
* un conjunto de elemento (datos) organizados secuencialmente a la que se pueden añadir,
* eliminar y modificar datos. Esta vez los datos pueden ser cualesquiera ya que la implementación
* se ha realizado con templates.
*
* @image html ./doc/doxys/stack.jpg
*
* Un ejemplo de su uso:
* @include pruebaLista.cpp
*
* @author Juan A.Fernández
* @date Noviembre 2015
*/

template <class T>
class ListaT{

  private:

    //Estructura de cada una de las celdas de la lista
    struct Celda{
      //Elementos de la estructura:
      T elemento; //Elemento que contiene la información, en este caso un entero.
      Celda * siguiente; //Punto que apunta a la siguiente celda.
    }; /** Estructura de cada celda. */

    //Al tratarse de una lista construida con celdas enlazadas con cabecera lo primero que encontramos será la cabecera.
    Celda * cabecera; /**Puntero a la cabecera de la lista que no es un elemento válido dentro de ella sino un punto de contol de inicio. */

    //Después tenemos el número de elementos.
    int numElementos; /**Número de elemento dentro de la lista.*/


  public:

    /**
    * @brief Constuctor por defecto de la clase. Inicializa la lista con una celda sin dato y con el puntero
    * a siguiente a null que representa el comienzo de la lista. Esta nueva celda no se contabiliza como elemento
    * de la la lista y por tanto a efectos prácticos esta está vacía. Este elemento sólo aporta ventajas cara a la
    * implementación.
    */
    ListaT();

    /**
    * @brief Inserta un elemento al final de la lista.
    * @param elemento Elemento de tipo enetero que se quiere introducir al final de la lista.
    */
    void insertarAlFinal(T elemento);
    /**
    * @brief Inserta un elemento al principio de la lista.
    * @param elemento Elemento de tipo entero que se quiere introducir al principio de la lista.
    */
    void insertarAlPrincipio(T elemento);
    /**
    * @brief Para conocer el número de elementos que tiene la lista.
    * @return Entero que indica el número de elementos que la lista tiene.
    */
    int getNumeroElementos();
    /**
    * @brief Imprime por pantalla el contenido de la lista.
    */
    void imprimeLista();

    /**
    * @brief Devuelve una copia del último elemento del array.
    * @return Un elemento de tipo T que se encuentra en la última posición.
    */
    T getUltimo();

    /**
    * @brief Elimina el último elemento de la lista.
    */
    void delUltimo();

    /**
    * @brief Para conocer si la lista está vacía.
    * @return True si la lista no tiene elementos o false si contiene.
    */
    bool vacia();

};
#include "ListaT.cpp"
#endif
