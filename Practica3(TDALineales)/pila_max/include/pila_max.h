/**
  * @file pila_max.h
  * @brief Fichero para precompilación para selección de TDA a usar.
  *
  * Aunque se ha probado, no funciona.
  */
//Especificaremos el valor para decir con que tipo de objeto compilamos.
#define CUAL_COMPILA 3

#if CUAL_COMPILA==1
  #include <pila_max_vd.h>
#elif CUAL_COMPILA==2
  #include <pila_max_lista.h>
#else
  #include <pila_max_cola.h>
#endif
