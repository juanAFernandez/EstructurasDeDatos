#include <iostream>
using namespace std;

/*Una de las principales ventajas de usar plantillas es la compactación de código. Antes si teníamos
que implementar una función para distintos tipos de datos debíamos de repetir dicha implementación lo que
hacía el código más grande, dificil de mantener y lioso.*/

void Intercambiar(int& a, int& b){
  int aux=a;
  a=b;
  b=aux;
}
void Intercambiar(float& a, float& b){
  float aux=a;
  a=b;
  b=aux;
}
void Intercambiar(string& a, string& b){
  string aux=a;
  a=b;
  b=aux;
}

/*Tenemos que repetir el trabajo para cada nuevo tipo que aparece, se puede intuir que es más simple
llevar a cabo una generalización eliminando los detalles que diferencian a las funciones y quedándonos
con lo importante, lo que hacen. C++ ofrece algo muy simple para implementar esto*/

template <class T>
void Intercambiar2(T& a, T&b){
  T aux=a;
  a=b;
  b=aux;
}

/*La comodidad de este mecanismo se debe a que es el propio compilador el que se encarga de realizar
las instanciaciones necesarias y producir una versión de la función para cada tipo que se necesite.*/

template <class T>
void Muestra(T a, T b){
  cout << "a:" << a << " b:" << b << endl;
}

template <class T>
void Muestra(T * a, int tam){
  for(int i=0; i<tam; i++)
    cout << *(a+i) <<  " ";
  cout << endl;
}


template <class T>
void OrdenarSeleccion(T* vector, int n){
  for(int i=0; i<n-1; i++){
    int minimo=i;
    for(int j=i+1; j<n; j++)
      if(vector[j]<vector[minimo])
        minimo=j;
    Intercambiar2(vector[i],vector[minimo]);
  }
}

/*Una llamada a esta función provoca una instanciación de la función de ordenación para el tipo concreto,
que a su vez, implica una instancaición de la función Intercambiar que se llama en el cuerpo de la función.
Observer que el compilador deduce el tipo de la función que necesita, evitando la necesidad de indicar que la
función se debe intanciar para el tipo T*/

int main(){

  int a=2;
  int b=5;
  Intercambiar(a,b);
  cout << "a:" << a << " b:" << b << endl;

  //Así podremos llamar a Intercambiar2 y Muestra sea cual sea el tipo:

  a=1; b=2;
  Intercambiar2(a,b);
  Muestra(a,b);

  string msgA="hola", msgB="adios";
  Intercambiar2(msgA,msgB);
  Muestra(msgA,msgB);

  double doubleA=3.1416, doubleB=0.99;
  Intercambiar2(doubleA,doubleB);
  Muestra(doubleA,doubleB);

  /*Una llamada con un tipo cualquiera es válida, ya que el compilador instancia la versión
  de la función que corresponde al tipo correcto, y realiza la llamada correspondiente, así
  evitamos tener que volver a escribir funciones. La palabra "class" usada indica que puede
  ser cualquier tipo, no significa que T deba ser una clase.
  */

  //Ejemplo de uso en una orderación por selección:
  int tamVector=20;
  int v[tamVector];
  int cont=0;
  for(int i=tamVector-1; i>=0; i-- ){
    v[i]=cont;
    cont ++;
  }
  Muestra(v, tamVector);
  OrdenarSeleccion(v, tamVector);
  Muestra(v, tamVector);



}
