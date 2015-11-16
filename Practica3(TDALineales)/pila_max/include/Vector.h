/**
  * @file Vector.h
  * @brief Fichero cabecera del TDA Vector
  *
  * Implementa un vector dinámico capaz de almacenar valores de tipo entero.
  */

#ifndef __Vector_h__
#define __Vector_h__

/**
*
* @brief T.D.A. Vector
*
* Una instancia @e vector del tipo de datos abstracto @c Vector es un objeto que representa
* un array de elemento (datos) organizados secuencialmente a la que se pueden añadir,
* eliminar y modificar datos.
* Su implimetación se puede realizar mediante dos vías principalmente: estática y dinámica.
* En este caso se ha optado por la dinámica, dotándo al vector de la capcidad de modificar su tamaño
* o disminuirlo en tiempo de ejecución, con las ventajas que esto supone.
*
* @image html ./doc/doxys/stack.jpg
*
* Un ejemplo de su uso:
* @include pruebaVector.cpp
*
* @author Juan A.Fernández
* @date Noviembre 2015
*/
class Vector{

  private:

    int * elementos;
    int numElementos;

  public:

    Vector();

    void insertarAlFinal(int elemento);
    void eliminarUltimo();
    void imprimeVector();
    int getNumeroElementos();


};


#endif
