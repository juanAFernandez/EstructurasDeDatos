/**
  * @file traductor.cpp
  * @brief Fichero implementación de los métodos de la clase traductor
  *
 */

#include <iostream>
#include "traductor.h"

using namespace std;

//Implementación de la función posPalabra
int Traductor::posPalabra(string palabra){
	int posPalabra=-1;
		for(unsigned int i=0; i<palabrasDisponibles.size(); i++){
			//Comparamos dos string

			if( palabra.compare(palabrasDisponibles[i].getPalabraOrigen())==0 )
				posPalabra=i;

		}

		//cout << "La posición de la palabra ha sido: " << posPalabra << endl;

		//Si devuelve -1 significará que la palabra no ha sido encontrada (no existe) en el diccionario.
		return posPalabra;
}

//Implementación de la función getNumeroPalabras
int Traductor::getNumeroPalabras(){ return palabrasDisponibles.size();}

//Implementación de la función getTraducciones
vector<string> Traductor::getTraducciones(string palabra){
		//Hay que encontrar la palabra en el vector palabrasDisponibles
		vector<string> error;
		error.push_back(" ## ERROR ## Palabra no encontrada en el diccionario, pruebe de nuevo.");
		if (posPalabra(palabra)==-1)
			return error;

		return palabrasDisponibles[posPalabra(palabra)].getTraduccionesDestino();
}

//Implementación de la función loadTraducciones
void Traductor::loadTraducciones(istream &flujo){

			//Tenemos el flujo aquí, entonces trabajamos con el:
			string lineaTemporal;
			
			
			
			/*Introducción de las palabras en el vector "palabrasDisponibles" mediante un bucle
			while que usa la función flujo.good() para parar.
			*/

			while(flujo.good()){
			Palabra tmp;
			getline(flujo,lineaTemporal);
			tmp.load(lineaTemporal);
			palabrasDisponibles.push_back(tmp);

			//Descomentar para ver como se van cargando las lineas.
			//cout << lineaTemporal << endl;

			}

			cout << "Cargadas: " << getNumeroPalabras() << " palabras. " << endl;


}

//Implementación de la sobrecarga del operador >>
istream& operator>> (istream& entrada, Traductor& t){
	//Si ya tenemos el flujo abierto, usémoslo!!! además ya ha sido abierto el fichero.

      //Cogemos el flujo y hacemos algo en el objeto t.
		//string lineaTemporal;
		//getline(entrada,lineaTemporal);

		t.loadTraducciones(entrada);

		//TRABAJAR AQUÍ, DONDE SE DEBERÍA LLAMAR A loadTraducciones.

		//TAMBIÉN HAY QUE SOBRECARGAR EL OPERADOR DE ENTRADA DE PALABRA!!!!!!

		return entrada;

}