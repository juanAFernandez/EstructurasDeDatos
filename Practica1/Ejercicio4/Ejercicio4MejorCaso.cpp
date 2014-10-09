/*
Ejercicio 4 ##Versión 1##
En esta primera versión vamos a modificar el código del Ejercicio 1 para que la ordenación se realice en el mejor de los
casos posibles, es decir cuando el vector ya se encuentra ordenado. Para ello vamos a modificar la parte del código donde se 
rellena el vector para que lo haga de forma ordenada.
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
  
  // Generación del vector ESTA VEZ DE FORMA YA ORDENADA
  int *v=new int[tam];       // Reserva de memoria
  srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  for (int i=0; i<tam; i++)  // Recorrer vector
    v[i] = i;    // Generar el vector de forma ordenada usando el índice del bucle. [0,vmax[
  
  if(tam<=20){
    cout << "Inicialización del vector:" << endl;
    imprime(v,tam);
  }

  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();
  
  //int x = vmax+1;  // Buscamos un valor que no está en el vector
  //buscar(v,tam,x); // de esta forma forzamos el peor caso de que tengan que recorrerse todo el código.
  ordenar(v, tam);

  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

 if(tam<=20){
    cout << "Vector ordenado:" << endl;
    imprime(v, tam);
  }

  // Mostramos resultados
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
  
  delete [] v;     // Liberamos memoria dinámica del vector usado.
}
