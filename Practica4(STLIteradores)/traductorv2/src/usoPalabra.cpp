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

  vector<string> palabrasDestino2 = a.getPalabrasDestino();
  cout << a.getNumeroPalabrasDestino();
  cout << palabrasDestino2.size();

  a.setPalabraOrigen("Dog");


  cout << a.getPalabraOrigen() << "\n";

  a.addPalabraDestino("perrete");
  a.addPalabraDestino("chucho");
  a.addPalabraDestino("perrito");

  cout << "Usando iteradores: " << endl;
  for(Palabra::iterator it=a.begin(); it!=a.end(); ++it)
    cout << *it;

  cout << endl;
  //Recuperamos las palabras destino
  vector<string> palabrasDestino = a.getPalabrasDestino();

  cout << "Usando la devolución del vector normal:" << endl;
  for(unsigned int i=0; i<palabrasDestino.size(); ++i)
    cout << palabrasDestino[i] << endl;

 /*
  SALIDA:

    > make runPalabra
      Dog
      chucho
      perrete

      (Las palabras destino son introducidas en orden en el contendor que las aloja, que es un set)

      La ejecución se realiza mediante:
      make runUsoPalabra
  */

  return 0;

}
