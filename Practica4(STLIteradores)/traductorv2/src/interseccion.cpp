/*
@author Juan Antonio Fernández Sánchez
@date Diciembre 2015

@use: interseccion datos/spanish_english datos/english_french datos/inter_spanishfrench_english

*/
#include <Traductor.h>
#include <fstream>
#include <iostream>
using namespace std;

//Varibale global para el control de la depuración.
bool depuracion;

void ImprimeTraductor(const Traductor &T,ostream &os){
   Traductor::const_iterator it;


   for (it=T.begin(); it!=T.end();++it){
       os<<(*it).first<<";";
       Palabra::const_iterator it_d;
       for (it_d=(*it).second.begin(); it_d!=(*it).second.end();++it_d)
	        os<<(*it_d)<<";";
       os << "\n";
   }

}
//Función principal que realiza la intersección
void interseccion(Traductor & traductorA, Traductor & traductorB, Traductor & traductorDestino){
  //ImprimeTraductor(traductorA, cout);

  cout << "Interseccionando" << endl;



  //Recorremos cada una de las palabras del traductor A
  for (Traductor::iterator it=traductorA.begin(); it!=traductorA.end(); ++it){

      /*Buscamos si la palabra está tambiénen el diccionario B y en caso de que esté
      entonces significará que esa palabra es interscción y se añadirá al destino.
      */

      //Vamos a busar una palabra mediante el buscador que devuelve un iterador
      //cout << it->first;
      Traductor::iterator itAElemento = traductorB.buscarPalabra(it->first);
      cout << itAElemento->first;

      //FALTA DE TIEMPO//


  }

  //if(depuracion) cout << "Palabras concatenadas:" << traductorDestino.getNumeroPalabras() << endl << endl;

}


int main(int argc, char * argv[]){

  depuracion=false;

  if (argc!=4){
      cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
      cout<<".-Dime el nombre de fichero del segundo traductor a concatenar" << endl;
      cout<<".-Dime el nombre de fichero del traductor resultado."<<endl;
      return 0;
   }

   ifstream flujo1 (argv[1]);
   if (!flujo1){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Traductor t_a;
   flujo1>>t_a;

   ifstream flujo2 (argv[2]);
   if (!flujo2){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
   }

   Traductor t_b;
   flujo2>>t_b;


   Traductor resultado;


     ofstream fout(argv[3]);
     if (!fout){
	      cout<<"No puedo crear el fichero "<<argv[2]<<endl;
	      return 0;
     }else{

      interseccion(t_a, t_b, resultado);
      ImprimeTraductor(resultado ,fout);

      cout << "\n### Traductor resultado  " << argv[2] << " ### \n" << endl;

      ImprimeTraductor(resultado ,cout);

      cout << endl;

     }



}
