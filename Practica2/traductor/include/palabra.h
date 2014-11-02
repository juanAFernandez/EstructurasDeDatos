/**
  * @file palabra.h
  * @brief Fichero cabecera del T.D.A. palabra
  *
  */
#ifndef __PALABRA
#define __PALABRA

#include <iostream>
#include <vector>
using namespace std;

/**
  *  @brief T.D.A. palabra
  *
  * Una instancia del tipo de dato abstracto palabra es un objeto compuesto
  * por las traducciones en un determinado idioma de una palabra origen.
  * Esta tipo de dato incluye tanto la palabra en el idioma origen como
  *	las traducciones en el idioma destino.
  *
  * Un ejemplo de su uso:
  * @include usoPalabra.cpp
  *
  * @author Juan Antonio Fernández Sánchez
  * @date Octubre 2014
  */	

class Palabra{
private:

  /**
  * @page Palabra Representación del Tipo de Dato Abstracto Palabra
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.traduccionesDestino!=0
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Palabra representa al valor
  *
  * (palabraIdiomaOrigen,palabraIdiomaDestino_0, ... , palabraIdiomaDestino_n)
  *
  */

	string palabraOrigen; /**< palabra en el idioma origen */

	vector<string> traduccionesDestino; /**< vector de las traducciones de  la palabra @e origen al idioma destino */

public:
	/**
	* @brief Constructor por defecto de clase, no hace nada.
	*/
	Palabra();
	
	/**
	* @brief Para establecer la palabra origen en palabra
	* @param palabra palabra en el idioma origen 
	* @pre La palabra pasada debe tener contenido
	*/
	void setPalabra(string palabra);
	
	/**
	* @brief Extrae la palabra origen del T.D.A.
	* @return Devuelve la palabra origen del T.D.A.
	*/
	string getPalabraOrigen();

	/**
	* @brief Para extraer las traducciones de la palabra origen.
	* @return Devuelve un vector de string que contiene las traducciones.
	*
	*/
	vector <string> getTraduccionesDestino();

	/**
	* @brief Para consultar el número de traducciones que tiene una palabras
	* @return Devuelve el tamaño (número de palabras) del vector trducciones destino.
	*/
	int numeroTraducciones();

	/**
	* @brief Método que desde un string y bajo un determinado formato extrae de este la palabra origen y las destino almacenandolas correctamente.
	* @pre La cadena string debe tener contenido y en el formato especificado para que el método funcione correctamente.
	*/
	void load(string lineaTemporal);
};
#endif