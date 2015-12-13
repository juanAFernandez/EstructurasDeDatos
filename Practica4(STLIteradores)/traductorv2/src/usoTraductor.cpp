/**
  * @file usoTraductor.cpp
  * @brief Fichero de uso del TDA Traductor
  *
*/

#include <iostream>
#include <Traductor.h>
#include <string.h>

using namespace std;

int main(void){

  Traductor traductor;

  const char ruta_diccionario[]="datos/spanish_english";
  ifstream f;
  f.open(ruta_diccionario);
  f>>traductor; //Cargamos en memoria, el traductor.
  cout << "Usando " << ruta_diccionario << endl;
  cout << "Num palabras cargadas: " << traductor.getNumeroPalabras() << endl << endl;

  //Ahora probamos el iterador creado en Traductor para recorrer todas las palabras de este:

  //for(Traductor::iterator it=traductor.begin(); it!=traductor.end(); ++it)
    //cout << it->first << endl;


  //for (Traductor::const_iterator it=traductor.cbegin(); it!=traductor.cend(); ++it)
    //cout << it->first << endl;

  //Ahora bien, vamos a crear un traductor constante:
  Traductor tradConst = traductor;
  for (Traductor::iterator it=tradConst.begin(); it!=tradConst.end(); ++it){
    cout << it->first << "-> ";
    for(Palabra::iterator itPalabra=it->second.begin(); itPalabra!=it->second.end(); ++itPalabra)
      cout << *itPalabra << " ";
    cout << endl;
  }




  /*
  Debe de funcionar al igual que funciona este ejemplo:
  map<char, int> mapa;

  mapa['a']=10;
  mapa['b']=20;

  //Vamos a usar un iterador para recorrer la estructura:
  for(map<char, int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
    cout << it->first << " >> " << it->second << "\n";
  */

  return 0;

}
