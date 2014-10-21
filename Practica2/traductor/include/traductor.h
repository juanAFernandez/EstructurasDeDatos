#ifndef __TRADUCTOR
#define __TRADUCTOR

#include <iostream>
#include <vector>
#include <fstream> //Para trabajar con flujos
#include "palabra.h" //Para usar el tipo de datos creado por nosotros palabra.
using namespace std;


class Traductor{

private:

	/*Un traductor tiene un vector lleno de palabras (que a su vez es una estructura que 
	incluye una palabra y sus traducciones)
	*/
	vector<Palabra>palabrasDisponibles;


public:

	//Ahora se supone que traductor debe poder recibir el control sobre unflujo de datos que sea el abrir 
	//un fichero de texto y cargar en un vector todas las palabras (tipo de datos nuevo que incluye las traducciones).

	int posPalabra(string palabra){

		int posPalabra=-1;
		for(int i=0; i<palabrasDisponibles.size(); i++){
			//Comparamos dos string

			if( palabra.compare(palabrasDisponibles[i].getPalabraOrigen())==0 )
				posPalabra=i;

		}

		//cout << "La posición de la palabra ha sido: " << posPalabra << endl;

		//Si devuelve -1 significará que la palabra no ha sido encontrada (no existe) en el diccionario.
		return posPalabra;
	}

	int getNumeroPalabras(){
		return palabrasDisponibles.size();
	}

	//Función que dada una palabra nos devuelve un vector de string con las traducciones.
	vector<string> getTraducciones(string palabra){

		//Hay que encontrar la palabra en el vector palabrasDisponibles

		vector<string> error;
		error.push_back(" ## ERROR ## Palabra no encontrada en el diccionario, pruebe de nuevo.");
		if (posPalabra(palabra)==-1)
			return error;

		return palabrasDisponibles[posPalabra(palabra)].getTraduccionesDestino();

	}



	//Esta función recorrerá el fichero y cargará todas las palabras (origen y destinos) en nuestro vector de palabras disponibles
	void loadTraducciones(istream &flujo){

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

			//Sacando una:

			//cout << "Nº de traducciones: " << palabrasDisponibles[5].numeroTraducciones() << endl;

			//TRABAJAR AQUÍ

	}



	//Sobrecarga del opeardor >> istream (input stream)


	friend istream & operator>> (istream & entrada, Traductor & t){

		//Si ya tenemos el flujo abierto, usémoslo!!! además ya ha sido abierto el fichero.

      //Cogemos el flujo y hacemos algo en el objeto t.
		//string lineaTemporal;
		//getline(entrada,lineaTemporal);

		t.loadTraducciones(entrada);

		//TRABAJAR AQUÍ, DONDE SE DEBERÍA LLAMAR A loadTraducciones.

		//TAMBIÉN HAY QUE SOBRECARGAR EL OPERADOR DE ENTRADA DE PALABRA!!!!!!

		return entrada;

	} 

	//Cuando introduzcamos una palabra el traductor debe de devolvernos todas las traducciones.
	
	//vector<string> getTraducciones(string palabra);
};


	







#endif