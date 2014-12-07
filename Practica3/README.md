#Practica 3

Todavía trabajamos a bajo nivel **sin poder usar la STL**

Ir paso a paso.

Empezar con Vector Dinámico y adaptarlo a template. Hacemos un fichero para probarlo. Implementamos la pila más vector dinaḿico, hacemos otro programa test.Después pasamos con una cola.

La cola está representada con una lista debajo.

Implementar el tope con una cola necesita otra auxiliar.

Podemos elegir una u otra representación en función de una variable global que hayamos definido.

Pila.h
```sh
#define CUAL_COMPILO 1
	if CUAL_COMPILO == 1
    	#include "Pila_max_VD.h"
    elif
    	CUAL_COMPILO == 2
        #include "Pila_max_lista.h"
    else
    	#...
```
Hay que sobrecargar el operador sobre el struct
