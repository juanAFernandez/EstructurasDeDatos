#include <iostream>
#include <Lista.h>
#include <ListaT.h>

using namespace std;

int main(void){

  cout << "\n## Prueba lista y lista con templates ##\n" << endl;

  //Creamos un objeto.
  Lista listaPrueba;
  ListaT<int> listaPruebaT;

  //Añadimos elementos tanto al final como al principio.
  for(int i=0; i<=10; ++i){
    listaPrueba.insertarAlFinal(i);
    listaPruebaT.insertarAlFinal(i);
    listaPrueba.insertarAlPrincipio(i);
    listaPruebaT.insertarAlPrincipio(i);
  }

  //Imprimimos la lista
  cout << listaPrueba.getNumeroElementos() << " elementos en la lista." << endl;
  cout << listaPruebaT.getNumeroElementos() << " elementos en la lista." << endl;
  listaPrueba.imprimeLista();
  listaPruebaT.imprimeLista();

  ListaT<string> listaPruebaString;
  listaPruebaString.insertarAlFinal("Hola");
  listaPruebaString.insertarAlFinal(" soy una lista");
  listaPruebaString.insertarAlFinal(" de String ");

  listaPruebaString.imprimeLista();

}
