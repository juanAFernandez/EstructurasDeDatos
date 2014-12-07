#include <iostream>
#include "palabra.h"
using namespace std;

int main(){


  Palabra nueva;
  nueva.cargarPalabras("perro;dog;doggy;");
  cout << nueva.getPalabraOrigen() << endl;





}
