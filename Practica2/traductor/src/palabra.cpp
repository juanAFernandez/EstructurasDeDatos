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
	
	cout << "La linea es: " << lineaTemporal << endl;

	/*Convertirmos el string a un vector de char
	const char *linea;
	linea = lineaTemporal.c_str();
	*/


	//2ª opción: 

	//Primera pasada donde seleccionamos la palabra origen #####:

	//Buscamos la posición del símbolo de división --> ;
	string simbolo=";";
	int posSimbolo = lineaTemporal.find(simbolo);
	cout << posSimbolo;

	//Ahora copiamos ese segmento de string en el nuestro.
	palabraOrigen=lineaTemporal.substr(0,posSimbolo);
	cout << "Palabra origen:" << palabraOrigen << endl;

	cout << "La linea sigue siendo: " << lineaTemporal << endl;

	//Ahora hay que quitar esa parte de la linea para repetir el proceso, para eso usamos:
	lineaTemporal.erase(0,posSimbolo+1);

	cout << "La linea queda: " << lineaTemporal << endl << endl << endl;


	//Resto de n pasadas donde seleccionamos las palabras que iran en traduccionesDestino " vector<string> traduccionesDestino; "
	bool fin=false;
	int numeroTraduccionObtenida=0;
	string palabraTraducida;
	while (fin != true){

		cout << "inicio" << endl;

		//Sacamos la posición del símbolo ";"
		posSimbolo=lineaTemporal.find(simbolo);
		cout << "Posición ; =" << posSimbolo << endl;

		if(posSimbolo<0)
			fin=true;
		
	   if(!fin){
	   palabraTraducida=lineaTemporal.substr(0,posSimbolo);
	   cout << "Palabra traducida extraida " << numeroTraduccionObtenida << " : " << palabraTraducida << endl;
	   traduccionesDestino.push_back(palabraTraducida);
	   lineaTemporal.erase(0,posSimbolo+1);
	   cout << "La linea queda: " << lineaTemporal << endl;
	   numeroTraduccionObtenida++;

		}

		cout << "fin" << endl;

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

