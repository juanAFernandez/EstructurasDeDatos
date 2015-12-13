/*
@author Juan Antonio Fernández Sánchez
@date Diciembre 2015

@use: concatenar datos/spanish_english datos/english_french datos/spanish_french

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
//Función principal que realiza la concatenación.
void concatenar(const Traductor & traductorA, Traductor & traductorB, Traductor & traductorDestino){
  //ImprimeTraductor(traductorA, cout);

  //Recorremos cada una de las palabras del traductor A
  for (Traductor::const_iterator it=traductorA.begin(); it!=traductorA.end(); ++it){

      //Creamos una palabra temporal que será la que añadamos al traductor concatenado.
      Palabra palabraTemporal;
      //Añadimos la original del idioma original:
      palabraTemporal.setPalabraOrigen(it->first);

      //Buscamos cada una de las palabras destino del traductor original en el segundo traductor pasado
      //y todas las traducciones que encontremos las pasamos a las destino de la palabra que estamos construyendo.

      for(Palabra::const_iterator itPalabra=it->second.begin(); itPalabra!=it->second.end(); ++itPalabra){

        if(depuracion) cout << "Concatenando: " << *itPalabra << ", " << endl;
        //Cargamos las traducciones de la palabra buscada (en el segundo traductor) en un vector.
        vector<string> trads=traductorB.getTraducciones(*itPalabra);
        if(depuracion) cout << "encontradas " << trads.size() << " en el segundo diccionario" << endl << endl;
        //Si existe esa palabra y hay traducciones para ella el vector se habrá rellenado.
        if(trads.size()!=0){
          //En ese caso las recorremos y las añadimos a la palabra temporal.
          for (vector<string>::iterator itVector = trads.begin() ; itVector!=trads.end(); ++itVector){
            if(depuracion) cout << *itVector << endl;
            palabraTemporal.addPalabraDestino(*itVector);
          }
        }
      }

      //Si la palabra se ha formado bien y tiene origen y al menos un destino se añade al traductor concatenación.
      if(palabraTemporal.getPalabraOrigen().size()!=0 && palabraTemporal.getNumeroPalabrasDestino()!=0){
        traductorDestino.addPalabra(palabraTemporal);
        if(depuracion){
          cout << "Palabra a añadir:" << endl;
          palabraTemporal.imprimePalabra();
          cout << " -- " << endl;
        }
      }

  }

  if(depuracion) cout << "Palabras concatenadas:" << traductorDestino.getNumeroPalabras() << endl << endl;

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

      concatenar(t_a, t_b, resultado);
      ImprimeTraductor(resultado ,fout);

      cout << "\n### Traductor resultado  " << argv[2] << " ### \n" << endl;

      ImprimeTraductor(resultado ,cout);

      cout << endl;

     }



}
