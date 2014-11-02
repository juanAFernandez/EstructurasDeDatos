/**
  * @file usoPalabra.cpp
  * @brief Fichero implementación para probar el funcionamiento de objetos palabra.
  *
 */
#include <iostream>
#include <fstream> //Para trabajar con flujos
#include "palabra.h"


using namespace std;

/**
* @brief Función principal del programa.
*/
int main (void){

	//cout << "usoPalabra" << endl;

	//Código en el que vamos a probar la clase palabra y sus métodos

	Palabra prueba;

	//Palabra prueba2;


	//Abrimos el fichero:
	ifstream flujoEntrada;
	flujoEntrada.open ("file.txt", std::ifstream::in);

	//Extraemos la linea y la guardamos en un string temporal:
	string lineaTemporal;
	getline(flujoEntrada,lineaTemporal);

	//Cargamos esa linea en una instancia de palabra
	prueba.load(lineaTemporal);

	cout << prueba.getPalabraOrigen() << endl;
	
	cout << prueba.numeroTraducciones() << endl;

	vector<string> vector=prueba.getTraduccionesDestino();




	return 0;

	/*
	Una forma sencilla de poder ejecutar el código compilando y enlazando los tres ficheros:
	g++ src/usoPalabra.cpp src/palabra.cpp -Iinclude -o bin/usoPalabra ; ./bin/usoPalabra 

	*/

}
