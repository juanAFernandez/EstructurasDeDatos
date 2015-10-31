/**
  * @file Palabra.h
  * @brief Fichero cabecera del TDA Palabra
  *
  */

#ifndef __PALABRA
#define __PALABRA

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

/**
  *  @brief T.D.A. Palabra
  *
  * Una instancia @e palabra del tipo de datos abstracto @c Palabra es un objeto
  * que representa una palabra junto a sus traducciones en unos determinados idiomas
  * origen y destino. Este tipo de datos se representa con una palabra (origen)
  * y un conjunto de palabras destino en un vector, donde todos los objetos
  * son de tipo string.
  *
  * Un ejemplo de su uso:
  * @include usoPalabra.cpp
  *
  * @author Juan A. Fernández
  * @date Octuble 2015
  */

class Palabra {

   private:

     /**
      * @page repPalabra Representación del TDA Palabra
      *
      *
      * @section faPalabra Función de abstracción
      *
      * Un objeto válido @e palabra del TDA Palabra representa una palabra junto a sus traducciones en dos idiomas dados:
      *
      * palabra.palabraOrigen=Palabra en el idioma origen (p.e. Español)
      *
      * palabra.palabrasDestino=Palabras que son traducción de la origen (p.e. Inglés)
      *
      * palabra.numPalabrasDestino=Es un contador de las palabras destino.
      *
      * Ejemplo:
      *
      *   p.palabraOrigen="hola"
      *
      *   p.palabrasDestino=["hello","hi"]
      *
      *   p.numPalabrasDestino=2
      */

      string palabraOrigen; /** Palabra Origen de la que se tienen las traducciones */
      string * palabrasDestino; /** Puntero que apunta a las traducciones de la palabra en el idioma origen */
      int numPalabrasDestino; /** Número de palabras destino (traducciones) que la palabra origen tiene*/

   public:

      /**
      * @brief Constructor por defecto de la clase. Crea una palabra con el vector de destinos inicializado a 0.
      */
      Palabra();

      /**
      * @brief Guarda el string pasado como palabra en el idioma origen del objeto.
      * @param nuevaPalabraOrigen es palabra que se almacenará como palabra en el idioma origen.
      */
      void setPalabraOrigen(string nuevaPalabraOrigen);

      /**
      * @brief Devuelve la palabra que el objeto tiene guardada como palabra en el idioma origen.
      * @return Un string, que es la palabra origen.
      */
      string getPalabraOrigen();

      /**
      * @brief Añade una palabra al conjunto de palabras destino que son traducciones para la palabra origen.
      * @param nuevaPalabraDestino es un palabra en formato string, una traducción de la palabra origen que se añade al conjunto.
      */
      void addPalabraDestino(string nuevaPalabraDestino);

      /**
      * @brief Devuelve el conjunto de las palabras destino, traducciones de la palabra almacenada en idioma origen.
      * @return Un vector de string donde cada elemento es una palabra (traducción de la palabra origen).
      */
      vector<string> getPalabrasDestino();

};

#endif
