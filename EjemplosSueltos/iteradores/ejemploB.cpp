#include <iostream>
using namespace std;

/*Podemos encontrarnos el problema de un contenedor que queremos recorrer no deba
ser modificable y para ello tenemos que declara un Iterados constante par que no
se pueda modificar el contenido, entonces tendremos dos tipos de iteradores. */

typedef double * Iterador;
typedef const double * IteradorConstante;

//Por tanto cada uno debe tener su función Begin(...) y End(...)

Iterador Begin(double * v, int n){return v;}
Iterador End(double * v, int n){return v+n;}
IteradorConstante Begin(const double * v, int n){return v;}
IteradorConstante End(const double *v, int n){return v+n;}

/*Vemos que tenemos Begin y End sobrecargadas, dos versiones, y será el compilador quién
decida la más adecuada, distinguiendo entre vectores modificables y constantes.
Para usar un iterador sobre un vector tendremos que seleccionar el que corresponda,
dependiendo del tipo de contenedor que tengamos.*/

//Funciones extra:

void EscribirElementos(const double *v, int n){
  IteradorConstante p;
  for(p=Begin(v,n); p!=End(v,n); ++p)
    cout << *p << " ";
  cout << endl;
}

void Rellenar(double * v, int n){
  Iterador p;
  int i=1;
  for(p=Begin(v,n); p!=End(v,n); ++p){
    *p=i;
    i++;
  }
}

/*Además, un objeto de tipo Iterador puede asignarse a uno IteradorConstante,
pero no al revés, ya que un puntero a algo que se puede modificar (de lectura/escritura)
puede asignarse a un puntero de sólo lectura (más restrictivo). */



int main(){

  int n=20;
  double v[n];

  Iterador p;
  for(p=Begin(v,n); p!=End(v,n); ++p){
    *p=0.0;
  }

  Rellenar(v,n);
  EscribirElementos(v,n);


}
