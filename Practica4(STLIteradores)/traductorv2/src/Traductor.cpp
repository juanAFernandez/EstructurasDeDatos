#include<iostream>
#include <string>
#include "Traductor.h"

using namespace std;


/*Constructor del TDA Traductor, inicializando el puntero que apuntará a la lista de
palabras a NULL y el numero de palabras a 0.
*/
Traductor::Traductor(){
  //palabras = NULL;
  //numPalabras=0;
}

/*
Añade una palabra al map que contiene todas las palabras del diccionario.
*/
void Traductor::addPalabra(Palabra nuevaPalabra){


 /*
 Al tratarse de un mapa necesitamos una clave y un dato y para la clave se usará
 la palabra en el idioma origen aunque estemos manteniendo información duplicada,
 al tenerla tb. en el dato.
 */

 //Introducimos la palabra usando como clave la palabra en el idioma origen que al estar en
 //un pair está en el primer campo.
 palabras[nuevaPalabra.getPalabraOrigen()]=nuevaPalabra;

  /*

  //Si aún no hay ninguna palabra en el vector de estas:
  if(numPalabras==0){
    palabras = new Palabra[1];
    palabras[0]=nuevaPalabra;
    numPalabras++;
  }
  //Si el traductor ya tiene palabras cargadas:
  else{
    //1º: Reservamos espacio en memoria para un vector de un tamaño numPalabras + 1
    Palabra * nuevasPalabras = new Palabra[numPalabras+1];
    //2º: Copiamos las palabras del antiguo al nuevo:
    for(int i=0; i<numPalabras; i++)
      nuevasPalabras[i]=palabras[i];
    //3º: Añadimos la nueva palabra:
    nuevasPalabras[numPalabras]=nuevaPalabra;
    //4º: Aumentamos el número de palabras:
    numPalabras++;
    //5º: Liberamos la memoria del antiguo vector:
    delete [] palabras;
    //6º: Asociamos el antiguo puntero a la nueva estructura:
    palabras = nuevasPalabras;

  }

  */

}

/*
Trocea las partes de una linea dividiendo por los el símbolo ";" usando todos los parámetros
pasados por referencia sin devolver nada para que sea más sencillo.
*/
void Traductor::split(string linea, string * &vector, int &numPalabras, char simboloDeSeparacion){

    char simbolo = simboloDeSeparacion;
    //char simbolo = char(';');

    numPalabras=0;

    for(unsigned i=0; i<linea.length(); i++){
        if(linea[i]==simbolo)
            numPalabras++;
    }

    vector = new string[numPalabras];
    int palabra=0;



    //Valores con los que jugar:
    int inicio=0; //Posicion inicial
    int n=0; //Tamaño de la copia.

    for(unsigned i=0; i<linea.length(); i++){
        if(linea[i]==simbolo){
            n=i-inicio;

            //Se añade la palabra al vector dinamico
            vector[palabra]=linea.substr(inicio, n);
            //cout << vector[palabra] << endl;
            palabra++;
            inicio=i+1;
        }
    }
}



/*
Para cargar todas las palabras que maneja el traductor a partir del flujo abierto de
un fichero desde el que se leen todas las palabras convirtiéndose a objetos de tipo
Palabra y añadiendolas al traductor.
*/
void Traductor::cargaTraductor(ifstream & f){

  string linea;

  string * vector;
  int numPalabrasExtraidas;

  if(f.is_open()){
    while(getline(f, linea)){
      split(linea, vector, numPalabrasExtraidas, ';');
      Palabra tmp;
      tmp.setPalabraOrigen(vector[0]);
      for(int i=1; i<numPalabrasExtraidas; i++)
        tmp.addPalabraDestino(vector[i]);
      //Una vez cargada la palabra la cargamos al traductor:
      addPalabra(tmp);
    }
    f.close();
  }
}

/*No necesita ser definida dentro del espacio de nombres de Traductor porque no es una función que le pertenezca, aunque es su amiga,
y por es en el .h se declara dentro de la parte pública. */
ifstream& operator>> (ifstream& is, Traductor& t){
  t.cargaTraductor(is);
  return is;
}

/*
Devuelve un strign traducción a partir de una cadena compuesta por muchas palabras que se le pasa.
*/
string Traductor::getTraduccion(string frase){

  /*Añadimos un espacio en blanco para que case con la forma en que la función split funciona con los ficheros de traducciones donde
  hay al final un separador más que se cuenta para conocer el número total de palabras.
  */
  frase+=" ";

  //Vector donde se almacenarán las palabras extraidas de la frase.
  string * vectorResultados;
  //Entero donde split va a guardar el número de frases que sea capaz de sacar.
  int numPalabrasExtraidas;

  //Frase de salida
  string fraseSalida = "";

  /*En este caso volvemos a usar split para realizar la segementación de la frase pasada en palabras sueltas
  usando como token un espacio en blanco ' '. Todo pasado por referencia.
  */
  split(frase, vectorResultados, numPalabrasExtraidas, ' ');

  //Realizamos la traducción de las que encontremos:

    //Usamos un vector temporal para las traducciones intermedias.
    vector<string> tmp;

    for(int i=0; i<numPalabrasExtraidas; i++){
      tmp = getTraducciones(vectorResultados[i]);
      /*Si la palabra se encontraba en el diccionario del traductor el vector tendrá contenido y se usará
      la primera palabra de las "destino". En caso de no contener se introduce la palabra original.
      */
      if(tmp.size()>0)
        fraseSalida+=tmp[0];
      else
        fraseSalida+=vectorResultados[i];

      //Añadimos un espacio:
      fraseSalida+=" ";
    }

  return fraseSalida;
}

/*
Función básica que devuelve un vector de string con las traducciones de una palabra buscada.
En el caso de que no se encuentre se devuelve el vector vacío, para que se detecte en el programa
principal y se muestre el mensaje correspondiente.
*/
vector<string> Traductor::getTraducciones(string palabraBuscada){

  //Creamos el vector:
  vector<string> vectorResultados;
  //bool encontrado = false;


  //En esta versión vamos a buscar si la palabra buscada está en el traductor usando el méTodo
  //"find" de map y para ello necesitamos un iterador, ya que devuelve un iterador a la posición del elemento
  //buscado si es que lo encuentra o a la posición final en otro caso.

  //Creamos el iterador:
  map<string, Palabra>::iterator it;
  //Busamos en el map la palabra buscada.
  it=palabras.find(palabraBuscada);
  //Si se han encontrado la palabra:
  if(it!=palabras.end())
      vectorResultados = it->second.getPalabrasDestino();



  /*
  for(int i=0; i<numPalabras && !encontrado; i++){
    if(palabras[i].getPalabraOrigen().compare(palabraBuscada)==0){
        vectorResultados =  palabras[i].getPalabrasDestino();
        encontrado=true;
    }
  }
  */

  //Devolvemos al final el vector tenga o no contenido.
  return vectorResultados;
}


/*
Para conocer el número de palabras que posee el traductor.
*/
int Traductor::getNumeroPalabras(){
  return palabras.size();
  //return numPalabras;
}
