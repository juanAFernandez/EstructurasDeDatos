#include <iostream> // Para hacer uso de la entrada y salida
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

//Donde
// v -> Es el vector donde vamos a realizar la búsqueda
// n -> Es el número de elementos del vector
// x -> Es el elemento a buscar en el vector (que no encontrará pues no se encuentra en el)
int buscar(const int *v, int n, int x)
{
  int i=0;
  while (i<n && v[i]!=x) 
    i=i+1;
  if (i<n) 
    return i;
  else
    return -1;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=3)
    //Llama a sintaxis para que explique al usuario como funciona el código.
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  int vmax=atoi(argv[2]);    // Valor máximo
  if (tam<=0 || vmax<=0)
    sintaxis();
  
  // Generación del vector aleatorio
  int *v=new int[tam];       // Reserva de memoria
  srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  for (int i=0; i<tam; i++)  // Recorrer vector
    v[i] = rand() % vmax;    // Generar aleatorio [0,vmax[
  
  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();
  
  int x = vmax+1;  // Buscamos un valor que no está en el vector
  buscar(v,tam,x); // de esta forma forzamos el peor caso de que tengan que recorrerse todo el código.
  
  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
  
  delete [] v;     // Liberamos memoria dinámica del vector usado.
}
