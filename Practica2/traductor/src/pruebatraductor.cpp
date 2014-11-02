/**
  * @file pruebatraductor.cpp
  * @brief Fichero implementación para probar el funcionamiento del T.D.A. traductor.
  *
 */

/*! \mainpage Documentación 
 *
 * \section intro_sec Introducción
 *
 * This is the introduction.
 *
 * \section install_sec Instalación
 *
 * \subsection step1 Paso 1: Descargar el código
 *
 * Se puede descargar desde https://github.com/juanAFernandez/EstructurasDeDatos/tree/master/Practica2/traductor
 *
 * \subsection step2 Paso 2: Ejecutar make
 *
 * Para que todo compile sólo tenemos que ejecutar make en la carpeta principal donde estan las carpetas.
 *
 * \subsection step3 Paso 3: Lanzar la documentación
 *
 * Para crear la documentación sólo hacemos make documentacion y tendremos el index.html en docs
 *
 * \section uso_sec Uso
 *  
 * Para usar el programa sólo tenemos que ejecutarlo indicándole el diccionario a usar: 
 * ./bin/pruebatraductor datos/spanish_english  
 * Estos diccionarios lo tenemos disponibles en la carpeta datos.
 *
 * \section colaboracion Colaboración
 *
 * Para proponer cualquier mejora en el código o aportar alguna correción sería interesante hacer fork en GitHub.
 */

//Fichero de prueba del T.D.A. Traductor
#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
* @brief Función principal del programa.
*/
int main(int argc, char * argv[]){



  if (argc!=2){
      cout<<"Dime el nombre del fichero con las traducciones"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   //Se declara el traductor.
   Traductor T;


   cout << "### Cargando traductor ###"<< endl;

   f>>T; //Cargamos en memoria, en el traductor.

   while(true){

   string a;
   cout<<"Dime una palabra en el idioma origen (q para salir): ";
   getline(cin,a);
   
   if(a.compare("q")==0){
    cout << "bye! "<< endl;
    return 0;
   }

   vector<string> trads=T.getTraducciones(a);
   
   //Mostramos las palabras destino
   
   cout<<a<<"--> ";
   for (unsigned int i=0;i<trads.size(); ++i){
     cout<<trads[i];
     if(i<trads.size()-1)
      cout << "; ";
   }

   cout<<endl;
   
   
   }



}