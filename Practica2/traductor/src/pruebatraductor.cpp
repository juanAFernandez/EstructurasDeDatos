/**
  * @file pruebatraductor.cpp
  * @brief Fichero prueba del TDA Traductor
  * Ejecución:
  * > bin/pruebaTraductor datos/spanish_english
  *
  * @author Juan A. Fernández
  * @date Octuble 2015
*/
#include "Traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
* Traduce una sola palabra ofreciendo una salida más o menos formateada con las
* traducciones de esta.
*
*/
void traducePalabra(Traductor t, string palabra){

  vector<string> trads=t.getTraducciones(palabra);

  if(trads.size()!=0){

    // Escrbimos
    cout<<palabra<<" --> ";

    for (unsigned i=0;i<trads.size(); ++i)
      cout<<trads[i]<<" ; ";

    cout<<endl;

  }else{
    cout << "Oups! Palabra " <<"\""<<palabra<<"\""<< " no encontrada en el diccionario." << endl;

  }
};

/**
* Con esta función traducimos frases enteras, ofreciendo una traducción MUY CUTRE!.
*/
void traduceFrase(Traductor t, string frase){
  cout << t.getTraduccion(frase) << endl;
};


int main(int argc, char * argv[]){

  //Mensaje de bienvenida:
  cout <<"\n### Traductor Simple v1.0### " << endl;
  cout <<"Autor: Juan A. Fernández" << endl;
  cout <<"Fecha: Octuble 2015" << endl;
  cout <<"Código: https://github.com/juanAFernandez/EstructurasDeDatos/ \n\n";

  if (argc!=2){
      cout<<"Dime el nombre del fichero con las traducciones"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Traductor t;
   //t.cargaTraductor(f);
   f>>t; //Cargamos en memoria, en el traductor.
   cout << "Usando " << argv[1] << endl;
   cout << "Num palabras cargadas: " << t.getNumeroPalabras() << endl << endl;



   string a;
   bool esUnaPalabra=false;
   bool esUnaFrase=false;


   //Bucle infinito del programa:
   while(true){

     esUnaPalabra=esUnaFrase=false;

     cout<<"Dime una palabra o frase en el idioma origen (Crtl+C para salir): ";
     getline(cin,a);
     //Busca si la cadena introducida contiene espacios en blanco.
     int spac = a.find(" " , 0);

     //Si no tiene (no se encuentra " ") se trata de una palabra.
     if(spac==-1)
      esUnaPalabra=true;
     else
      //Si se encuentran es una frase.
      esUnaFrase=true;

     //Dependiendo del resultado se procesa de una u otra manera.
     if(esUnaPalabra)
      traducePalabra(t, a);

     if(esUnaFrase)
      traduceFrase(t, a);

  }

}
