#include <iostream>
#include <vector>
using namespace std;


/*Alias, que nos permite poner un "nombre" en vez de la expresión concreta,
así en vez de poner siempre "double *" podemos poner Iterador.*/
typedef double * Iterador;

//Función que devuelve el principio del contenedor:
Iterador Begin(double *v, int n){
  return v;
}

//Función que devuelve el final del contenedor:
Iterador End(double *v, int n){
  return v+n;
}

void AnularElementos(double *v, int n){
  Iterador p;
  for(p=Begin(v,n); p!=End(v,n); ++p)
    *p=0.0;
}

void EscribirElementos(double *v, int n){
  Iterador p;
  for(p=Begin(v,n); p!=End(v,n); ++p){
    cout << *p << endl;
  }
}





int main(){

  vector<int> vectorEnteros;

  vectorEnteros.push_back(1);
  vectorEnteros.push_back(2);
  vectorEnteros.push_back(3);


  //La forma clásica de recorrer un vector:
  for(int i=0; i<vectorEnteros.size(); i++){
    cout << vectorEnteros[i] << endl;
  }

  //Recorriéndolo con punteros:

  int n=20; //Tamaño del vector

  double v[n];

  double *p;       //El iterador
  double *final;   //Para no tener quer ecalcular v+n

  final =v+n;

  int i=0;
  for(p=v; p!=final; ++p){
    *p=i;
    i++;
  }

  /*Para recorrer los elementos del vector v, empezamos por el primer elemento,
  que se obtiene directamente del vector de v, es decir, el comienzo del recorrido está en un
  puntero al primer elemento. La iteración termina al llegar a la posición final, es decir,
  al elemento que está después del último.*/

  for(p=v; p!=final; ++p)
    cout << *p << endl;


  /*Para definir un iterador sobre un contenedor cualquiera, vamos a utilizar un nuevo tipo (Iterador),
  una funcińo para obtener el comienzo (Begin, devuelve un iterador al primer elemento) y una función
  que  nos indique el final (End, que nos devuelve un iterador al elemento después del último).*/

  //Ver declaración y definición arriba del main.

  Iterador it;

  cout << "Usando nuestro iterador definido" << endl;

  for(it=Begin(v,n); it!=End(v,n); ++it){
    cout << *it << endl;
  }

  AnularElementos(v, n);
  EscribirElementos(v, n);





}
