#include <iostream>
#include "Vector.h"
using namespace std;

Vector::Vector(){
  elementos = NULL;
  numElementos=0;
}

void Vector::insertarAlFinal(int elemento){


  //Si el vector no contiene ningún elemento se inicializa el puntero reservando memoria para un elemento.
    if(elementos==NULL){
      //Se reserva memoria dinámica
      elementos = new int[1];
      //Se inserta el elemento en la primera posición
      elementos[0]=elemento;
      //Se incrementa el contador de elementos:
      ++numElementos;
  //Si el vector tiene elementos lo que hay que hacer es redimensionarlo.
    }else{
      //Creamos un puntero a una estructura nueva con un elementos más que la actual:
      int *tmp = new int[numElementos+1];
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

void Vector::eliminarUltimo(){
  /*Cuando queremos eliminar el último elemento no sirve con marcarlo libre o reducir el numElementos porque al añadir
  estaremos reservando memoria para un elmento más del que necesitamos, entonces para evitar esto vamos a reducir el tamaño
  del vector en una posición aunque no sea la solución más eficiente, ya que lo idal sería mantener dos contadores, uno de posición
  y otro de memoria reservada. */
  
  //Reservamos memoria para un número de elementos numElementos -1
  --numElementos;
  if(numElementos!=0){
    int *tmp = new int[numElementos];
    //Copiamos todos los elementos a la nueva estructura:
    for(int i=0; i<numElementos; ++i)
      tmp[i]=elementos[i];
    //Hacemos que nuestro puntero apunte a la nueva estrucutra
    elementos=tmp;
  }else{ //Si estamos elimintando el último elemento simplemente ponemos el puntro a la estructura a NULL.
    elementos=NULL;
  }


}

void Vector::imprimeVector(){

  for(int i=0; i<numElementos ; ++i){
    cout << elementos[i] << " ";
  }
  cout << endl;

}

int Vector::getNumeroElementos(){
  return numElementos;
}
