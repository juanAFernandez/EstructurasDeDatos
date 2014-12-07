//Destructor
template <class T>
VectorDinamico<T>::~VectorDinamico(){
  if(nelementos>0)
    delete[] datos;
  }

  //Consultor de tamaño
  template<class T>
  int VectorDinamico<T>::Size() const{
    return nelementos;
  }



  /*Constructor de la clase, inicializa reservando la memoria necesaria para
  el número de elementos nelementos.*/

  template <class T>
  VectorDinamico<T>::VectorDinamico(int n){
    assert(n>0);
    if(n>0)
      datos=new T[n];
      nelementos=n;
    }


    /*Constructor de copias*/
    template <class T>
    VectorDinamico<T>::VectorDinamico(const VectorDinamico<T>& original){
      nelementos=original.nelementos;
      if(nelementos>0){
        datos=new T[nelementos];
        for(int i=0; i<nelementos; ++i)
          datos[i]=original.datos[i];
        }
        else
          datos=0;
        }





        /*Operador de asignación.*/
        template<class T>
        VectorDinamico<T>& VectorDinamico<T>::operator=(const VectorDinamico<T>& original){
          if(this!=&original){
            if(nelementos>0)
              delete[] datos;
              nelementos=original.nelementos;
              datos= new T[nelementos];
              for(int i=0; i<nelementos; i++)
                datos[i]=original.datos[i];
              }
              return *this;
            }
