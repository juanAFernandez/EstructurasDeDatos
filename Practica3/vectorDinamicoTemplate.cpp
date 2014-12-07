/**
  * @file vectorDinamicoTemplate.cpp
  * @brief Implementación del T.D.A. vectorDinamico para cualquier tipo de dato
  *
  * @author Juan Antonio Fernández Sánchez
  * @date Noviembre 2014
  */

#include <cassert>

//#include "vectorDinamicoTemplate.h"

//Constructor que reserva cierta cantidad de memoria.
template <class TYPE>
vectorDinamico<TYPE>::vectorDinamico(int n){
  assert(n>=0);
    if(n>0)
      datos = new TYPE[n];
    numElementos=n;
}



/*
//Constructor que crea un vector a partir del contenido de otro.
template <class T>
vectorDinamico<T>::vectorDinamico<T>(const vectorDinamico& original){
  numElementos=original.numElementos;
  if(numElementos>0){
    datos = new float[numElementos];
    for(int i=0; i<numElementos; i++)
      datos[i]=original.datos[i];
  }
  else datos=0;
}

//Destructor que libera la memoria reservada por el vector.
template <class T>
vectorDinamico<T>::~vectorDinamico(){
  if(numElementos>0) //Si el vector contiene datos.
    delete[] datos; //Liberamos la memoria que ocupan estos datos.
}

template <class T>
int vectorDinamico<T>::size() const {
  return numElementos;
}

template <class T>
float& vectorDinamico<T>::operator[](int i){
  assert(0<=i && i<numElementos);
  return datos[i];
}

template <class T>
const float& vectorDinamico<T>::operator[] (int i) const{
  assert(0<=i && i<numElementos);
}

template <class T>
void vectorDinamico<T>::resize(int n){
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

template <class T>
vectorDinamico<T>& vectorDinamico<T>::operator=(const vectorDinamico<T>& original){
  if(this!=&original){
    numElementos=original.numElementos;
    datos=new float[numElementos];
    for(int i=0; i<numElementos; ++i)
      datos[i]=original.datos[i];
  }
  return *this;
}
*/
