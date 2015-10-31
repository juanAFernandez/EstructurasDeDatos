/**
  * @file Traductor.h
  * @brief Fichero cabecera del TDA Traductor
  *
*/
#ifndef __TRADUCTOR
#define __TRADUCTOR

#include <iostream>
#include <string.h>
#include <fstream>
#include <Palabra.h>
#include <vector>

using namespace std;

/**
  *  @brief T.D.A. Traductor
  *
  * Una instancia @e t del tipo de datos abstracto @c Traductor es un objeto
  * que representa un cojunto de objetos de tipo Palabra que conforman un traductor.
  * Entonces un objeto de este tipo ofrece no sólo la instancia sino la interfaz de uso
  * gracias a sus métodos para por ejemplo, ver la traducciones de una de sus palabras contenida.
  *
  *
  * Un ejemplo de su uso:
  * @include pruebatraductor.cpp
  *
  * @author Juan A. Fernández
  * @date Octuble 2015
  */

class Traductor{

  private:

    /**
     * @page repTraductor Representación del TDA Traductor
     *
     *
     * @section faTraductor Función de abstracción
     *
     * Un objeto válido @e t del TDA Traductor representa una colección de objetos de tipo palabra. Así el
     * traductor sólo mantiene referenciados estos objetos en memoria y los utiliza.
     *
     * Entonces un objetos válido sería:
     *  palabras -> colección de palabras.
     *  numPalabras -> número de palabras almacenadas.
     *
     */

    Palabra *palabras; /**Puntero al conjunto de palabras que forman el traductor. */
    int numPalabras; /**Contador del número de palabras que contiene el traductor. */

    /**
    * @brief Para añadir una nueva palabra al traductor.
    * @param nuevaPalabra Palabra a añadir al traductor.
    */
    void addPalabra(Palabra nuevaPalabra);

    /**
    * @brief Función auxiliar para dividir una cadena de texto según el separador ";", necesaria para leer los ficheros fuentes de palabras.
    * @param linea Linea de texto que posee las palabras divididas por el símbolo ";"
    * @param vector Referencia al vector donde se van a guardar las palabras obtenidas.
    * @param numPalabras Referencia al entero donde alamcenar el número de palabras extraidas.
    * @param simboloDeSeperacion Simbolo que se interpretará como token de fragmentación de la cadena.
    */
    void split(string linea, string * &vector, int &numPalabras, char simboloDeSeperacion);

  public:

    /**
    * @brief Constructor por defecto de la clase. Prepara las variables, el puntero a NULL y el número de palabras a 0.
    */
    Traductor();

    /**
    * @brief Realiza la carga del traductor a través de un flujo de un fichero abierto.
    * @param f Flujo de stream de un fichero previamente abierto.
    */
    void cargaTraductor(ifstream & f);

    /**
    * @brief Devuelve el número de palabras que el traductor contiene.
    * @return Entero, número de palabras que el traductor contiene.
    */
    int getNumeroPalabras();

    /**
    * @brief Para conocer la o las traducciones de una palabra que esté en el diccionario.
    * @param palabraBuscada Palabra de la que queremos conocer sus traducciones.
    * @return Devuelve un vector con las palabras encontradas que son traducción de la pasada o un vector vacío en el caso de no encontrarla.
    */
    vector<string> getTraducciones(string palabraBuscada);

    /*
    * @brief Permite realizar la traducción (treméndamente básica) de frases completas basándose en las palabras que el traductor conoce.
    * @param frase Frase que se quiere traducir.
    * @return Devuelve una cadena con su versión de la traducción para esa frase.
    */
    string getTraduccion(string frase);

    /*
    * @brief Para rellenar las palabras de un traductor a partir del flujo de un fichero de texto abierto, es una sobrecarga del operador.
    * @param is Flujo del fichero.
    * @param t Objeto de tipo traductor que es el que queda a la derecha del operador.
    */
    //Se declara dentro de la parte pública por ser su amiga, ya que puede acceder a las parte privada de la clase.
    friend ifstream& operator>> (ifstream& is, Traductor& t);

};


#endif
