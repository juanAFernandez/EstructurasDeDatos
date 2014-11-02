/**
  * @file palabra.cpp
  * @brief Fichero implementación de los métodos de la clase palabra.
  *
 */

#include <iostream>
#include <string>
#include "palabra.h"
using namespace std;

//Constructor por defecto
Palabra::Palabra(){};



string Palabra::getPalabraOrigen(){
	//Devuelve la palabra en el idioma origen
	return palabraOrigen;
}
vector <string> Palabra::getTraduccionesDestino(){
	//Devuelve el vector de las traducciones	
	return traduccionesDestino;
}


int Palabra::numeroTraducciones(){
	return traduccionesDestino.size();
}

void Palabra::load(string lineaTemporal){
	/*Método con el que dad una linea completa extraemos la primera palabra (hasta encontrar delimitador ;) y la guardamos en palabraOrigen
	  para después en bucle hacer lo mismo con la siguientes e introducirlas en un vector de traduccionesDestino
	*/

	//cout << "La linea original es: " << lineaTemporal << endl;

	//Primera pasada donde seleccionamos la palabra origen #####:

	//Buscamos la posición del símbolo de división --> ;
	string simbolo=";";
	int posSimbolo = lineaTemporal.find(simbolo);
	//cout << "El símbolo ; se encuentra en la posición " << posSimbolo << endl;

	//Ahora copiamos ese segmento de string en el nuestro.
	palabraOrigen=lineaTemporal.substr(0,posSimbolo);
	//cout << "Palabra origen extraida: " << palabraOrigen << endl;

	//Ahora hay que quitar esa parte de la linea para repetir el proceso, para eso usamos:
	lineaTemporal.erase(0,posSimbolo+1);

	//cout << "Tras la extracción la linea queda: " << lineaTemporal << endl;


	//Resto de n pasadas donde seleccionamos las palabras que iran en traduccionesDestino " vector<string> traduccionesDestino; "
	bool fin=false;
	int numeroTraduccionObtenida=0;
	string palabraTraducida;
	while (fin != true){

		//cout << "\nInicio while" << endl;

		//Sacamos la posición del símbolo ";"
		posSimbolo=lineaTemporal.find(simbolo);
		//cout << "El símbolo ; se encuentra en la posición " << posSimbolo << endl;

		if(posSimbolo<0)
			fin=true;
		
	   if(!fin){
	   palabraTraducida=lineaTemporal.substr(0,posSimbolo);
	   //cout << "Palabra traducida extraida " << numeroTraduccionObtenida << " : " << palabraTraducida << endl;
	   traduccionesDestino.push_back(palabraTraducida);
	   lineaTemporal.erase(0,posSimbolo+1);
	   //cout << "La linea queda: " << lineaTemporal << endl;
	   numeroTraduccionObtenida++;

		}

		//cout << "Fin while" << endl;

	}








	//Buscamos el simbolo ;
	//int pos;
	//for (pos=0; linea[pos]!=';'; pos++){}

	//Copiamos hasta el simbolo en un nuevo vector de char.
	
	// ### FALTA CÓDIGO ### //
	

	//Revertimos convertiendo a string de nuevo
	//std::string palabreja(linea);

	//Introducimos la palabra obtenida en palabraOrigen
	//palabraOrigen=palabreja;


//http://www.cplusplus.com/reference/string/string/  en concreto "find" , "substr", 

}

