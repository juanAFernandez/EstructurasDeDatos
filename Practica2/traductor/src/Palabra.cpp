#include<iostream>
#include<string.h>
#include "Palabra.h"
using namespace std;

//Construcor de TDA palabra, que prepara las variables para su uso posterior.
Palabra::Palabra(){
  palabraOrigen = "";
  palabrasDestino = NULL;
  numPalabrasDestino = 0;
}

//Set de la palabra en el idioma origen
void Palabra::setPalabraOrigen(string nuevaPalabraOrigen){
  palabraOrigen=nuevaPalabraOrigen;
}

//Devuelva la palabra en el idioma origen.
string Palabra::getPalabraOrigen(){
  return palabraOrigen;
}

//Para añadir una palabra a la colección de las palabras destino.
void Palabra::addPalabraDestino(string nuevaPalabraDestino){

  //Si no hay ninguna palabra en el vector de las de destino, se reserva memoria para una palabra y se añade esta.
  if(numPalabrasDestino==0){
    //Resvervamos memoria.
    palabrasDestino = new string[1];
    //Almacenamos los datos.
    palabrasDestino[0] = nuevaPalabraDestino;
    //Intrementamos el número de de palabras destino.
    numPalabrasDestino++;
  }else{
    /*Si hay más de una palabra en el vector de palabras destino, creamos un nuevo vector
    copiamos el contenido y añadimos el nuevo.*/
    string *nuevoVector;
    //Reservamos memoria pra una palabra más.
    nuevoVector = new string[numPalabrasDestino+1];
    //Pasamos las palabras de una a otra estructura.
    for(int i=0; i<numPalabrasDestino; i++)
      nuevoVector[i]=palabrasDestino[i];
    //Intcrementamos el número de palabras que estamos amacenando.
    numPalabrasDestino++;
    //Aadimos la nueva palabra a memoria.
    nuevoVector[numPalabrasDestino-1]=nuevaPalabraDestino;
    //Liberamos la memoria que ocupa la vieja colección.
    delete [] palabrasDestino;
    //Guardamos la dirección de memoria de la nueva estructura.
    palabrasDestino = nuevoVector;
  }
}

//Devuelve un vector con las palabras destino de la palabra.
vector<string> Palabra::getPalabrasDestino(){
  //Creamos un vector de la STL para almacenar las palabras (en unos sitios usamos STL y en otros no para usar ambos,
  // aunque podríamos haber seguido trabajando con memoria y punteros).
  vector<string> vectorPalabrasDestino;
  //Introducimos las plabras.
  for (int i=0; i<numPalabrasDestino; i++){
    vectorPalabrasDestino.push_back(palabrasDestino[i]);
  }
  //Devolvemos el vector creado.
  return vectorPalabrasDestino;
}
