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
 * \subsection step1 Paso 1: Opening the box
 *
 * \section uso_sec Uso
 *  
 * Para usar
 */

#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;
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
   
   //Se define el traductor.
   Traductor T;

   //Palabra prueba;

   /*
   Si hacer c=a+b es lo mismo que hacer c=operator+(a,b);
   f>>T es lo mismo que hacer operator>>(f,T) donde f es un objeto ifstream y T uno traductor.
   */

   cout << "### Cargando traductor ###"<< endl;

   f>>T; //Cargamos en memoria, en el traductor.

   //Nuestra clase tiene que tener sobrecargado el operador >> para poder pasarle un flujo.
   






   //La abstracción es básica y por tanto la documentación será imprescindible.



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