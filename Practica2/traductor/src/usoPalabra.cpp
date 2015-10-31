/**
  * @file usoPalabra.cpp
  * @brief Fichero de uso del TDA Palabra
  *
*/

#include <iostream>
#include <Palabra.h>
#include <string.h>

using namespace std;

int main(void){

  Palabra a;

  a.setPalabraOrigen("Dog");
  cout << a.getPalabraOrigen() << "\n";
  a.addPalabraDestino("perrete");
  cout << a.getPalabrasDestino() << "\n";
  a.addPalabraDestino("chucho");
  cout << a.getPalabrasDestino() << "\n";

  /*

  SALIDA:

    > bin/usoPalabra
      Dog
      perrete
      perrete	chcucho

  */

  return 0;

}
