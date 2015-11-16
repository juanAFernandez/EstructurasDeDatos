/**
  * @file VectorT.cpp
  * @brief Fichero implementación del TDA VectorT (templates)
  *
  * Fichero de implemtación de los métodos del dato, que está en /include debido a la compilación separada que se hace.
  */
#include <iostream>
using namespace std;

template <class T>
VectorT<T>::VectorT(){
  elementos = NULL;
  numElementos=0;
}

template <class T>
void VectorT<T>::insertarAlFinal(T elemento){


  //Si el vector no contiene ningún elemento se inicializa el puntero reservando memoria para un elemento.
    if(elementos==NULL){
      //Se reserva memoria dinámica
      elementos = new T[1];
      //Se inserta el elemento en la primera posición
      elementos[0]=elemento;
      //Se incrementa el contador de elementos:
      ++numElementos;
  //Si el vector tiene elementos lo que hay que hacer es redimensionarlo.
    }else{
      //Creamos un puntero a una estructura nueva con un elementos más que la actual:
      T *tmp = new T[numElementos+1];
      //Copiamos los elementos la nueva estructura:
      for(int i=0; i<numElementos; ++i)
        tmp[i]=elementos[i];
      //Insertamos el nuevo elemento
      tmp[numElementos]=elemento;
      //Aumentamos el num de elementos:
      ++numElementos;
      //HAcemos que nuestro antiguo puntero apunte a la nueva estructura:
      elementos=tmp;
      //Al salir el puntero tmp y la estructura reservada será liberada.
    }

}

template <class T>
void VectorT<T>::eliminarUltimo(){
  /*Cuando queremos eliminar el último elemento no sirve con marcarlo libre o reducir el numElementos porque al añadir
  estaremos reservando memoria para un elmento más del que necesitamos, entonces para evitar esto vamos a reducir el tamaño
  del vector en una posición aunque no sea la solución más eficiente, ya que lo idal sería mantener dos contadores, uno de posición
  y otro de memoria reservada.*/

  //Reservamos memoria para un número de elementos numElementos -1
  --numElementos;
  if(numElementos!=0){
    T *tmp = new T[numElementos];
    //Copiamos todos los elementos a la nueva estructura:
    for(int i=0; i<numElementos; ++i)
      tmp[i]=elementos[i];
    //Hacemos que nuestro puntero apunte a la nueva estrucutra
    elementos=tmp;
  }else{ //Si estamos elimintando el último elemento simplemente ponemos el puntro a la estructura a NULL.
    elementos=NULL;
  }


}


template <class T>
void VectorT<T>::imprimeVector(){

  for(int i=0; i<numElementos ; ++i){
    cout << elementos[i] << " ";
  }
  cout << endl;

}

template <class T>
int VectorT<T>::getNumeroElementos(){
  return numElementos;
}

template <class T>
T VectorT<T>::getUltimo(){
  return elementos[numElementos-1];
}


template <class T>
bool VectorT<T>::vacia(){
  if (numElementos==0)
    return true;
  else
    return false;
}
