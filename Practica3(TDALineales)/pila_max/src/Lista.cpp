#include <iostream>
#include "Lista.h"
using namespace std;

//Constructor del TDA Lista
Lista::Lista(){
  //Creamos la cabecera y hacemos que el puntero inicial cabecera apunte a ella.
  cabecera = new Celda;
  //Ponemos a null el puntero a siguiente ya que no existe tal.
  cabecera->siguiente=NULL;
  //Establecemos a cero el número de elementos.
  numElementos=0;
}

//Para conocer el número de elementos:
int Lista::getNumeroElementos(){
  return numElementos;
}

//Para imprimir el contenido de la lista:
void Lista::imprimeLista(){

  //Si no hubiera celdas que mostrar.
  if(cabecera->siguiente==NULL){
    cout << "No hay elementos que mostrar" << endl;
  //Si las hubiera.
  }else{
    //Creamos un puntero y lo colocamos al principio.
    Celda * puntero = cabecera->siguiente;
    //Recorremos la estructura mientas no encontremos un puntero a siguiente a NULL.
    while(puntero!=NULL){
      cout << puntero->elemento << " ";
      puntero=puntero->siguiente;
    }
    cout << endl;
  }
}

//Para insertar un elemento al final de la lista.
void Lista::insertarAlFinal(int dato){

  //1º. Creamos una nueva celda con el elemento pasado.
    Celda * nueva = new Celda;
    nueva->elemento=dato;
    nueva->siguiente=NULL;

  //2º. Recorremos la estructura hasta dar con el último elemento.
    //Creamos un puntero apuntando a la cabecera.
    Celda *puntero = cabecera;
    //Lo movemos hasta la última celda.
    while(puntero->siguiente!=NULL){
      puntero=puntero->siguiente;
    }

  //3º. Añadimos la nueva celda creada.
    //Una vez en la última accedemos al campo siguiente para enlazarlo a la nueva celda creada.
    puntero->siguiente=nueva;
    ++numElementos;
    //Una vez hecho salimos y el puntero nueva se eliminará como cualquier dato local de una función.
}

//Para insertar un dato al principio de la lista.
void Lista::insertarAlPrincipio(int dato){

  //Gracias a tener una celda como cabecera el procedimiento es idéntico haya o no elementos en la lista.

  //1º. Creamos la nueva celda con el parámetro pasado.
    Celda * nueva = new Celda;
    nueva->elemento=dato;
    nueva->siguiente=NULL;

  //2º. Hacemos que la nueva celda apunte a la primera celda de la lista:
    nueva->siguiente=cabecera->siguiente;

  //3º. Hacemos que cabecera apunte al nuevo elemento para hacer que la nueva celda se termine de insertar.
    cabecera->siguiente=nueva;
    ++numElementos;
  //4º. Al terminar la función el puntero nueva se elminará como variable local de la función que es.
}
