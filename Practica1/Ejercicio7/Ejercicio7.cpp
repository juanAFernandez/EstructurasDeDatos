/*

*/

#include <iostream> // Para hacer uso de la entrada y salida
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

void imprimeMatriz(int **matriz, int tam){

  for(int i=0; i<tam; i++){
    for(int j=0; j<tam; j++){
      cout << "[" << matriz[i][j] << "] " ;
    }
    cout << endl;
  }
}

/*Función que multiplica dos matrices a las que le pasamos los punteros a
estas y su tamaño. 
*/
void multiplicaMatrices (int **matrizA, int **matrizB, int **matrizResultado, int tam){
  
for(int k=0; k<tam; k++)
  for(int i=0; i<tam; i++)
    for(int j=0; j<tam; j++)
      matrizResultado[k][i]+=matrizA[k][j]*matrizB[j][i];

}

void inicializaMatriz(int **matriz, int tam, int max){
  
  //Terminamos de inicializar la matriz.
  for(int i=0; i<tam; i++)
    matriz[i] = new int[tam];

  //Inicializamos la "aletoriedad"
  srand(time(0));

  //Rellenamos la matriz
  for(int i=0; i<tam; i++)
    for(int j=0; j<tam; j++){
      if(max!=0)
        matriz[i][j]=rand() % max;
      else
        matriz[i][j]=max;
    }

}


void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "1.TAM: nº de filas y columnas de la matriz" << endl;
  cerr << "2.MAX: Máximo en la generación de aleatorios" << endl;
  cerr << "Se genera una matriz de tamaño TAM x TAM con elementos de 0 a MAX" << endl;
  exit(EXIT_FAILURE);
}



int main(int argc, char * argv[])
{
  //Lectura de parámetros, en esta versión sólo son necesarios dos parámetros.
  if (argc!=3)
    //Llama a sintaxis para que explique al usuario como funciona el código.
    sintaxis();

  //Capturamos el tamaño de la matriz y el valor máximo para rand()
  int tam=atoi(argv[1]); 
  int max=atoi(argv[2]);    
  if (tam<=0 || max <0)
    sintaxis();
  
  //Declaración de la matriz y reserva de memoria. 
  //Usando puntero a vector de punteros.
  int **matrizA=new int*[tam];
  int **matrizB=new int*[tam];
  int **matrizResultado=new int*[tam];

  //Inicialización de las matrices.
  inicializaMatriz(matrizA, tam, max);
  //Para que los números salgan distintos debemos de dejar algo de tiempo (para la máquina)
  sleep(1); 
  inicializaMatriz(matrizB, tam, max);
  inicializaMatriz(matrizResultado,tam, 0);

    
  if(tam<=10){
    cout << "Inicialización de la matriz A:" << endl;
    imprimeMatriz(matrizA,tam);
    cout << "Inicialización de la matriz B:" << endl;
    imprimeMatriz(matrizB,tam);
  }

  //# Cálculo del tiempo de ejecución #######

  clock_t tini,tfin;

  // Anotamos el tiempo de inicio
  tini=clock();
      
  multiplicaMatrices(matrizA, matrizB, matrizResultado, tam);

  // Anotamos el tiempo de finalización   
  tfin=clock();

  //##########################################

  if(tam<=10){
    cout << "Matriz resultado:" << endl;
    imprimeMatriz(matrizResultado,tam);
  }


  // Mostramos resultados en un formato correcto para gnuplot
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
  
  // Liberamos memoria dinámica del vector usado.
  delete[] matrizA;
  delete[] matrizB;
  delete[] matrizResultado;    
}
