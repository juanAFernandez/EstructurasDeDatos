#include "palabra.h"

void Palabra::setPalabraOrigen(string palabraOrigen){
  palabra.first=palabraOrigen;
}

string Palabra::getPalabraOrigen(){
  return palabra.first;
}

void Palabra::setPalabraDestino(set <string> palabrasDestino){
  palabra.second=palabrasDestino;
}

set <string> Palabra::getPalabrasDestino(){
  return palabra.second;
}

void Palabra::cargarPalabras(string lineaTemporal){

    //Buscamos la posición del símbolo de división --> ;
    string simbolo=";";
    int posSimbolo = lineaTemporal.find(simbolo);

    //Ahora copiamos ese segmento de string en el nuestro.
    palabra.first=lineaTemporal.substr(0,posSimbolo);

    //Ahora hay que quitar esa parte de la linea para repetir el proceso, para eso usamos:
    lineaTemporal.erase(0,posSimbolo+1);

    //Resto de n pasadas donde seleccionamos las palabras que iran en traduccionesDestino " vector<string> traduccionesDestino; "
    bool fin=false;
    int numeroTraduccionObtenida=0;
    string palabraTraducida;
    while (fin != true){

      //Sacamos la posición del símbolo ";"
      posSimbolo=lineaTemporal.find(simbolo);

      if(posSimbolo<0)
        fin=true;

       if(!fin){
       palabraTraducida=lineaTemporal.substr(0,posSimbolo);
       palabra.second.insert(palabraTraducida);
       lineaTemporal.erase(0,posSimbolo+1);
       numeroTraduccionObtenida++;
      }
    }
}
