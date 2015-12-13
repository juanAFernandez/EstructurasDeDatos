/*
Adaptación del código proporcionado.
@author Juan Antonio Fernández Sánchez
@date Diciembre 2015
*/
#include <Traductor.h>
#include <fstream>
#include <iostream>
using namespace std;

//Función que transforma un traductor en otro.
void GetTraductorInverso(const Traductor & t_origen, Traductor & t_destino){

/*
El objetivo de esta función es convertir un traductor dado en otro inverso.
Así si una palabra en el dicconario original ingles->español como hola puede
tener las traducciones hello y hi en el traductor inverso resultado
tendríamos que las palabras originales serían hello y hi y que ambas tendrían
como traducción hola.

Entonces la dinámica será recorrer cada una de las palabras del traductor origen,
en cada una de ellas recorreremos las palabras destino y cada una de ellas se
convertirá en una nueva palabra en el traductor inverso, donde sus palabra destino
será esta origen del original. Si la palabra ya existe en el diccionario.

hi-> hola
hello -> hola

debe convertirse en :
hola -> hi, hello
*/

//1º Recorremos el traductor origen con el iterador que para ello hemos implementado.
//Entramos en cada palabra
for (Traductor::const_iterator it=t_origen.begin(); it!=t_origen.end(); ++it){

  //cout << "analizando" << it->first << "-> ";

  //Recorremos cada una de las palabras destino de la palabra origen.
  for(Palabra::const_iterator itPalabra=it->second.begin(); itPalabra!=it->second.end(); ++itPalabra){
    //cout << *itPalabra << " ";

    //Tenemos que crear una palabra:
    Palabra tmp;
    //La palabra origen es la destino del traductor original
    tmp.setPalabraOrigen(*itPalabra);
    //La palabra destino es la original.
    tmp.addPalabraDestino(it->first);

    t_destino.addPalabra(tmp);

  }
}




}




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


int main(int argc, char * argv[]){

  if (argc!=2 && argc!=3){
      cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
      cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }

   Traductor t_ori;
   f>>t_ori; //Cargamos en memoria, en el traductor.
   Traductor t_des;

   GetTraductorInverso(t_ori,t_des);

   if (argc==2)
      ImprimeTraductor(t_des,cout);
   else{
     ofstream fout(argv[2]);
     if (!fout){
	cout<<"No puedo crear el fichero "<<argv[2]<<endl;
	return 0;
     }
      ImprimeTraductor(t_des,fout);

   }
}
