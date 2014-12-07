/**
  * @file vectorDinamico.h
  * @brief Fichero cabecera del T.D.A. vectorDinamico
  *
  * @author Juan Antonio Fernández Sánchez
  * @date Noviembre 2014
  */
#ifndef _vectorDinamico_h
#define _vectorDinamico_h

//CUando tenemos template el h es el que incluye al cpp (al revés de lo normal). Además el .cpp del template se pone en include.

//El operador corchetes nos sirve para poder acceder, set, get, instertar, borrar. Con esto ya podemos implementar la pila (son funciones necesarias).

class vectorDinamico{

	private:

		float *datos;
		int numElementos;

	public:

		//	##	Constructores:
		/**
		* @brief Primer constructor del T.D.A. vector dinámico que incializa el objeto reservando un tamaño de memoria
		* que le es pasado por parámetro.
		* @param n Número de elementos que el vector en principio tendrá. Será el indicador necesario para reservar la memoria.
		*/
		vectorDinamico(int n);
		/**
		* @brief Segundo constructor del T.D.A. vector dinámico que crea un objeto a partir del contenido de otro.
		* @param original Vector original a partir del cual se crear el nuevo vector, copiando el contenido de este al nuevo.
		*/
		vectorDinamico(const vectorDinamico& original);

		//	##	Destructor:
		/**
		* @brief Destructor del T.D.A. vector dinámico que se encarga de liberar toda la memoria reservada para los elementos de este.
		*/
		~vectorDinamico(); //Libera la memoria reservada por el vector dinámico.

		/**
		* @brief Numero de componentes del vector
		* @return Devuelve el número de componentes que puede almacenar en cada instante el vector.
		*/
		int size() const;

		/**
		* @brief Sobrecarga del operador corchete []
		* @param i Entero índice de acceso al vector.
		* @return Devuelve la direcicón de memoria de un float.
		*/
		float& operator[] (int i);

		/**
		*
		*
		*/
		const float& operator[] (int i) const;

		/**
		* @brief Función para redimensionar el tamaño del vector.
		* @param n Número de elementos que se quiere que tenga el vector.
		*/
		void resize(int n);

		vectorDinamico& operator=(const vectorDinamico& original);






};

#endif
