/**
  * @file traductor.h
  * @brief Fichero cabecera del T.D.A. traductor
  *
  */
#ifndef __TRADUCTOR
#define __TRADUCTOR

#include <iostream>
//Para trabajar con el tipo de dato vector de la STL
#include <vector>
//Para trabajar con flujos
#include <fstream>
//Para usar el tipo de dato abstracto palabra creado por nosotros. 
#include "palabra.h" 

using namespace std;

/**
  *  @brief T.D.A. traductor
  *
  * Una instancia de este tipo de dato es un traductor que contiene una lista de objetos
  * del tipo palabra que incluyen tanto la palabra origen como las traducciones.
  *
  * Un ejemplo de su uso:
  * @include pruebatraductor.cpp
  *
  * @author Juan Antonio Fernández Sánchez
  * @date Octubre 2014
  */	


class Traductor{

	/**
  	* @page Traductor Representación del Tipo de Dato Abstracto Traductor
  	*
  	* @section invConjunto Invariante de la representación
  	*
  	* El invariante es \e rep.palabrasDisponibles!=0
  	*
  	* @section faConjunto Función de abstracción
  	*	
  	* Un objeto válido @e rep del TDA Traductor representa al valor
  	*
	* (palabrasDisponibles=[0..n])
  	*
  	*/

	private:

		vector<Palabra>palabrasDisponibles; /**< vector de palabras disponibles por el traductor */

	public:	

		/**
		* @brief Para conocer la posición de una palabra en el vector de palabras
		* @param palabra La palabra a localizar en el traductor para saber si está disponible
		* @return Devuelva la posición de la palabra pasada en el vector
		*/
		int posPalabra(string palabra);

		/**
		* @brief Para conocer el número de palabras cargadas por el traductor.
		* @return Devuelve el número de palabras del que el traductor dispone.
		*/
		int getNumeroPalabras();

		/**
		* @brief Para obtener las traducciones disponibles a una palabra pasada.
		* @param palabra La palabra de la que se quieren obtener las traducciones
		* @return Devuelve un vector de string con las traducciones de esa palabra
		*/
		vector<string> getTraducciones(string palabra);


		/**
		* @brief Esta función recorrerá el fichero y cargará todas las palabras (origen y destinos) en nuestro vector de palabras disponibles
		* @param flujo Este parámetro es el flujo de datos abierto sobre el fichero que contiene las traducciones para que esta función trabaje con el.
		*/
		void loadTraducciones(istream &flujo);

		/**
		* @brief Sobrecarga del operador >>
		* @param entrada El flujo abierto sobre el fichero que contiene las traducciones.
		* @param t Objeto de tipo traductor que recoge el control de del flujo sobre un objeto de tipo traductor para que una función trabaje con el
		*/
		friend istream& operator>> (istream& entrada, Traductor& t);


};
#endif