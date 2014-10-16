#include <iostream>
#include <string>

#include "palabra.h"

using namespace std;

//Constructor por defecto
Palabra::Palabra(){};

//Constructor 
Palabra::Palabra(string palabra){
	palabraOrigen=palabra;
	a=5;
}


void Palabra::setPalabra(string palabra){
		palabraOrigen=palabra;
}

string Palabra::getPalabraOrigen(){
	return palabraOrigen;
}

int Palabra::size(){
	return palabraOrigen.length();
}

void Palabra::load(string lineaTemporal){
	//Proceso en el que sacamos la primera palabra y la guardamos en palabraOrigen y guardamos las otras en el vector.
	
	//cout << lineaTemporal << endl;

	//Convertirmos el string a un vector de char
	const char *linea;
	linea = lineaTemporal.c_str();


	//Buscamos el simbolo ;
	int pos;
	for (pos=0; linea[pos]!=';'; pos++){}

	//Copiamos hasta el simbolo en un nuevo vector de char.
	
	// ### FALTA CÓDIGO ### //
	

	//Revertimos convertiendo a string de nuevo
	std::string palabreja(linea);

	//Introducimos la palabra obtenida en palabraOrigen
	//palabraOrigen=palabreja;

}

