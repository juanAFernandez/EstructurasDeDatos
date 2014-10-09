/*
Ejercicio 4 ##Versión 2##
En esta segunda versión vamos a modificar el código del Ejercicio 1 para que la ordenación se realice en el peor de los
casos posibles, es decir cuando el vector se encuentra totalmente desordenado. Para ello vamos a modificar la parte del código donde se 
rellena el vector para que lo haga de forma completamente desordenado, es decir, para que se rellene al revés, de mayor a menor.
*/

#include <iostream> // Para hacer uso de la entrada y salida
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

//Donde
// v -> Es el vector que vamos a ordenar
// n -> Es el número de elementos del vector
void ordenar (int *v, int n){
  for(int i=0; i<n-1; i++)
    for(int j=0; j<n-i-1; j++)
        if (v[j]>v[j+1]){
          int aux = v[j];
          v[j]=v[j+1];
          v[j+1]=aux;
        }
}

void imprime (int *v, int n){
  for(int i=0; i<n; i++)
    cout << "[" << v[i] << "]";
  cout << endl;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos crecientes de 0 a TAM-1" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros, en esta versión sólo son necesarios dos parámetros.
  if (argc!=2)
    //Llama a sintaxis para que explique al usuario como funciona el código.
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  if (tam<=0)
    sintaxis();
  if (tam<=20)
    cout << "Para tamaños <=20 el vector se imprime por pantalla:" << endl;

  
  // Generación del vector totalmente desordenado
  int *v=new int[tam];       // Reserva de memoria
  srand(time(0));// Inicialización del generador de números pseudoaleatorios

  int pos=0;
  for (int i=tam-1; i>=0; i--){  // Recorrer vector
    v[pos] = i;    // Generar el vector de forma ordenada usando el índice del bucle. [0,vmax[
    pos++;
  }

  if(tam<=20){
    cout << "Inicialización del vector:" << endl;
    imprime(v,tam);
  }

  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();
  
  ordenar(v, tam);

  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();


  // Mostramos resultados
  if(tam<=20){
    cout << "Vector ordenado:" << endl;
    imprime(v, tam);
  }
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
  
  delete [] v;     // Liberamos memoria dinámica del vector usado.
}
