//Asignación de Objetos 2: Cuando el constructor de copia por defecto del compilador
//resulta insuficiente y obtenemos resultados erroneos.

#include <iostream>
using namespace std;


class Persona{

private:
	string nombre;
	* unsigned int edad;

public:

	Persona(){};

	Persona(string nuevoNombre){
		nombre=nuevoNombre;
	}
	Persona(string nuevoNombre, int nuevaEdad){
		nombre=nuevoNombre;
		edad=nuevaEdad;
	}

	void setNombre(string nuevoNombre){
		nombre=nuevoNombre;
	}
	void setEdad(int nuevaEdad){
		edad=nuevaEdad;
	}
	string getNombre(){
		return nombre;
	}
	int getEdad(){
		return edad;
	}


};


int sumaEdades(Persona a, Persona b){
	return a.getEdad()+b.getEdad();

}


int main(){

	Persona a;
	a.setNombre("juan");
	a.setEdad(25);

	Persona b("maria",25);


	cout << "Dirección de memoria de a: " << &a << endl;
	cout << "Dirección de memoria de b: " << &b << endl;
	
	/*Las asignación entre objetos está permitida y lo que se hace es copiar los valores miembro de un
	objeto a los de otro. El compilador al igual que con los constructores crea un operador de asignación por defecto,
	que copia los valores de todos los datos miembro de un objeto a otro.
	El constructor de copia se limita a realizar una copia bit a bit de las variables del objeto original (el de la derecha) 
	al objeto copia (el de la izquierda).
	*/
	
	a=b;


	//Parece que ha fucionado,vamos a ver donde están almacenadas esos objetos:
	cout << "Dirección de memoria de a: " << &a << endl;
	cout << "Dirección de memoria de b: " << &b << endl;


	cout << sumaEdades(a,b);

	/*
	Salida:

	Ubuntu> g++ asignacionObjetos.cpp -o prueba; ./prueba 
	Dirección de memoria de a: 0xbfd4ebb4
	Dirección de memoria de b: 0xbfd4ebbc
	Dirección de memoria de a: 0xbfd4ebb4
	Dirección de memoria de b: 0xbfd4ebbc
	50
	Ubuntu>
	*/




}