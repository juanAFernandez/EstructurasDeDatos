/**
  * @file Lista.h
  * @brief Fichero cabecera del TDA Lista
  *
  * Implementa el tipo de dato lista como una secuencia de celdas enlazadas con cabecera,
  * para su gestión en memoria de forma eficiente.
  */

#ifndef __Lista_h__
#define __Lista_h__

/**
*
* @brief T.D.A. Lista
*
* Una instancia @e lista del tipo de datos abstracto @c Lista es un objeto que representa
* un conjunto de elemento (datos) organizados secuencialmente a la que se pueden añadir,
* eliminar y modificar datos.
* Su implementación puede realizarse de muchas formas, aunque el comportamiento a alto nivel o uso
* debe ser siempre el mismo de forma abstracta.
* En este caso la implementación se ha realizado con celdas enlazadas con cabecera, usando como celda
* el tipo de dato @e Celda declarado dentro de la propia clase Lista.
*
* @image html ./doc/doxys/stack.jpg
*
* Un ejemplo de su uso:
* @include pruebaLista.cpp
*
* @author Juan A.Fernández
* @date Noviembre 2015
*/

class Lista{

  private:

    //Estructura de cada una de las celdas de la lista
    struct Celda{
      //Elementos de la estructura:
      int elemento; //Elemento que contiene la información, en este caso un entero.
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
    Lista();

    /**
    * @brief Inserta un elemento al final de la lista.
    * @param elemento Elemento de tipo enetero que se quiere introducir al final de la lista.
    */
    void insertarAlFinal(int elemento);
    /**
    * @brief Inserta un elemento al principio de la lista.
    * @param elemento Elemento de tipo entero que se quiere introducir al principio de la lista.
    */
    void insertarAlPrincipio(int elemento);
    /**
    * @brief Para conocer el número de elementos que tiene la lista.
    * @return Entero que indica el número de elementos que la lista tiene.
    */
    int getNumeroElementos();
    /**
    * @brief Imprime por pantalla el contenido de la lista.
    */
    void imprimeLista();

};
#endif
