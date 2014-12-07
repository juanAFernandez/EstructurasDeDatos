/**
* @file pruebaVectorDinamico.cpp
* @brief Fichero main() para la prueba del T.D.A. vectorDinamico
*
* @author Juan Antonio Fernández Sánchez
* @date Noviembre 2014
*/
#include <iostream>
#include "vectorDinamico.h"

using namespace std;

int main(){

	vectorDinamico prueba(5);
	cout << prueba.size() << endl;

	prueba.resize(20);
	cout << prueba.size() << endl;


}
