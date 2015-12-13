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
#include <map>

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


    //Ahora palabra es un map de palabras donde la clave es la palabra en el idioma origen,
    //Aun sabiendo que estaremos manteniendo redundancia de información en el sistema es la manera
    //que se nos propone de realizar la implementación.
    map<string, Palabra> palabras;


    //Palabra *palabras; /**Puntero al conjunto de palabras que forman el traductor. */
    //int numPalabras; /**Contador del número de palabras que contiene el traductor. */


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
    * @brief Para añadir una nueva palabra al traductor.
    * @param nuevaPalabra Palabra a añadir al traductor.
    */
    void addPalabra(Palabra nuevaPalabra);

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

    class iterator {

      public:

        map<string, Palabra>::iterator puntero;

        iterator& operator= (const iterator& orig){
          puntero=orig.puntero; return *this;
        }
        iterator& operator++(){
          puntero++; return *this;
        }
        bool operator!=(const iterator& orig){
          return puntero!=orig.puntero;
        }
        const pair<const string, Palabra > &operator *(){
          return *puntero;
        }
        map<string, Palabra >::iterator operator->(){
          return puntero;
        }

    };

    iterator begin() {
      iterator i;
      //Usamos el iterador del set que compone el segundo campo del pair de la palabra.
      i.puntero=palabras.begin();
      return i;
    }
    iterator end(){
      iterator i;
      //Hacemos lo mismo que hemos hecho antes.
      i.puntero=palabras.end();
      return i;
    }


    class const_iterator {

      public:

        map<string, Palabra>::const_iterator puntero;

        const_iterator& operator= (const iterator& orig){
          puntero=orig.puntero; return *this;
        }
        const_iterator& operator++(){
          puntero++; return *this;
        }
        bool operator!=(const const_iterator &orig){
          return puntero!=orig.puntero;
        }
        const pair<const string, Palabra > &operator *(){
          return *puntero;
        }
        const map<string, Palabra >::const_iterator operator->(){
          return puntero;
        }

    };

    const_iterator begin() const {
      const_iterator i;
      //Usamos el iterador del set que compone el segundo campo del pair de la palabra.
      i.puntero=palabras.begin();
      return i;
    }
    const_iterator end() const {
      const_iterator i;
      //Hacemos lo mismo que hemos hecho antes.
      i.puntero=palabras.end();
      return i;
    }
    //Devuelve un puntero al elemento buscado
    iterator buscarPalabra(string palabra){
      iterator iterator;
      iterator.puntero=palabras.find(palabra);
      return iterator;
    }


};

/**

Para poder usar iteradores constantes y que no pueda modificarse el dato al que se apunte por el
tenemos que modificar los métodos del iterador const añadiéndoles un c delante para que cuando se
invoquen begin y end no se usen los que devuelven un iterador normal (no constante), obviamene
entronces tendremos que usar cbegin y cend en lugar de begin y end. Esto hace que puedan usarse
los iteradores constante y no constante nosbre un objeto de tipo traductor no constante sin problema.

Sin embargo cuando tengamos un objeto de tipo traductor que si es constante no es necesario cambiar el
nombre de los métodos ya que al trabajar sobre un constante la sobrecarga funciona y se usan los begin y end
apropiados de las dos versiones de idéntico nombre implementadas.

**/


#endif
