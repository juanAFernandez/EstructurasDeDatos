#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO
#include <assert.h>

/*Con esta definición la forma de referirse a un tipo concreto será la
declaración de un vector dinámico especificando el tipo base que contiene.*/

template <class T>
class VectorDinamico{

  private:

    T* datos;
    int nelementos;

  public:

    /*Constructor*/
    VectorDinamico<T>(int n=0);

    /*Constructor de copias*/
    VectorDinamico<T>(const VectorDinamico<T>& original);

    /*Destructor*/
    ~VectorDinamico<T>();


    int Size() const;
  //  T& operator[] (int i);
  //  const T& operator[] (int i) const;
  //  void Resize (int n);
    /*Operador de asignacion*/
    VectorDinamico<T>& operator=(const VectorDinamico<T>& original);

};

#include "vectorDinamico.cpp"
#endif
