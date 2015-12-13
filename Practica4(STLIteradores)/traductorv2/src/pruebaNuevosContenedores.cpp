/**
  * @file usoNuevosContenedores.cpp
  * @brief Fichero de prueba con los contenedores usados en la versión 2 del traductor.
*/

#include <iostream>
#include <utility>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main(void){

  cout << "Prueba de pair \n";
  //Podemos inicializar pair con los valores como parámetros.
  pair<string, int> pareja("hola",64727);
  //Podemos no inicializarla.
  pair<string, int> pareja2;

  //Añadiendo sus datos después.
  pareja2.first="Segunda pareja";
  pareja2.second=4627281;

  cout << "Primer elemento p1: " << pareja.first << "\n";
  cout << "Segundo elemento p1: " << pareja.second << "\n";

  cout << "Primer elemento p2: " << pareja2.first << "\n";
  cout << "Segundo elemento p2: " << pareja2.second << "\n";

  cout << "Prueba de set \n";

  set<string>palabrasDestino;
  palabrasDestino.insert("hola");
  cout << "Elementos en el contenedor: " << palabrasDestino.size() << endl;

  //Vamos a construir una pareja (pair) de sting y set de strings.
  pair< string, set<string> > palabra;

  //Establecemos la palabra origen en el primer elemento:
  palabra.first="hola";
  //Introducimos palabras destino en el segundo elemento (el set de strings)
  palabra.second.insert("hello");
  palabra.second.insert("hi");
  palabra.second.insert("hi, brother");

  //Vamos a recorrer el set del pair con un interador:
  for(set<string>::iterator it = palabra.second.begin(); it!=palabra.second.end(); ++it){
    cout << *it;
  }


  cout << "Número de palabras destino: " << palabra.second.size() << endl;

  cout << "Prueba de map" << endl;


  map<char, int> mapa;

  mapa['a']=10;
  mapa['b']=20;

  //Vamos a usar un iterador para recorrer la estructura:
  for(map<char, int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
    cout << it->first << " >> " << it->second << "\n";


}
