#include <iostream>
#include <Vector.h>
#include <VectorT.h>

using namespace std;

int main(void){

  cout << "\n## Probando el TDA Vector y VectorT (uso de plantillas) ##\n" << endl;

  //Creamos un objeto de tipo vector, sin plantilla.
  Vector vectorPrueba;

  //Creamos un objeto de tipo template, en este caso un vector de enteros.
  VectorT <int> v;

  //Añadimos elementos tanto al final como al principio.
  for(int i=0; i<=10; ++i){
    vectorPrueba.insertarAlFinal(i);
    v.insertarAlFinal(i);
    //listaVector.insertarAlPrincipio(i);
    vectorPrueba.eliminarUltimo();
    v.eliminarUltimo();
  }

  //Imprimimos la lista
  cout << vectorPrueba.getNumeroElementos() << " elementos en la lista." << endl;
  vectorPrueba.imprimeVector();

  //Imprimimos la lista
  cout << v.getNumeroElementos() << " elementos en la lista." << endl;
  v.imprimeVector();

}
