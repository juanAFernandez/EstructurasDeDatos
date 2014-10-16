#ifndef __PALABRA
#define __PALABRA

#include <iostream>
#include <vector>
using namespace std;

//Hay que sobrecargar el operator de entrada en palabra para que lea una linea.

//Este tambień irá sobrecargado en traductor par que a su vez invoque a este.	

class Palabra{
private:
	//Declaramos el string palabraOrigen que almacenará la palabra.
	string palabraOrigen;

	//El vector almacenará todas las posibles traducciones
	vector<string> traduccionesDestino;
public:
	/**
	* @brief Constructor de la clase
	*/
	Palabra();
	


	/**
	* @brief setPalabra
	* @param palabra Origen que se almacenará
	* @return Inicia la palabra con el parámetro pasado
	*/
	void setPalabra(string palabra);

	string getPalabraOrigen();

	vector <string> getTraduccionesDestino();

	int numeroTraducciones();

	void load(string lineaTemporal);




	//Hacer función que sea leer linea....

	//friend iostream & openn >> (stream &, Palabra &p)...


};

#endif

