/**
  * @file vectorDinamico.cpp
  * @brief Implementación del T.D.A. vectorDinamico
  *
  * @author Juan Antonio Fernández Sánchez
  * @date Noviembre 2014
  */
#include "vectorDinamico.h"
#include <cassert>

//Constructor que reserva cierta cantidad de memoria.
vectorDinamico::vectorDinamico(int n){
	assert(n>=0);
		if(n>0)
			datos = new float[n];
		numElementos=n;
}

//Constructor que crea un vector a partir del contenido de otro.
vectorDinamico::vectorDinamico(const vectorDinamico& original){
	numElementos=original.numElementos;
	if(numElementos>0){
		datos = new float[numElementos];
		for(int i=0; i<numElementos; i++)
			datos[i]=original.datos[i];
	}
	else datos=0;
}

//Destructor que libera la memoria reservada por el vector.
vectorDinamico::~vectorDinamico(){
	if(numElementos>0) //Si el vector contiene datos.
		delete[] datos; //Liberamos la memoria que ocupan estos datos.
}

int vectorDinamico::size() const {
	return numElementos;
}

float& vectorDinamico::operator[](int i){
	assert(0<=i && i<numElementos);
	return datos[i];
}

const float& vectorDinamico::operator[] (int i) const{
	assert(0<=i && i<numElementos);
}

void vectorDinamico::resize(int n){
	assert(n>=0);
	if(n!=numElementos){
		if(n!=0){
			float * nuevos_datos;
			nuevos_datos=new float[n];
			if(numElementos>0){
				int minimo;
				minimo=numElementos<n?numElementos:n;
				for(int i=0; i<minimo; ++i)
					nuevos_datos[i]=datos[i];
				delete[] datos;
			}
		  numElementos=n;
			datos=nuevos_datos;
		}
		else{
			if(numElementos>0)
				delete[] datos;
			datos=0;
			numElementos=0;
		}
	}
}

vectorDinamico& vectorDinamico::operator=(const vectorDinamico& original){
	if(this!=&original){
		numElementos=original.numElementos;
		datos=new float[numElementos];
		for(int i=0; i<numElementos; ++i)
			datos[i]=original.datos[i];
	}
	return *this;
}
