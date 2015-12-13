#Traductor versión 2

En esta versión se desarrollan los mismos tipos de datos Palabra (usando esta vez los contenedores de la STL *pair y (set o multiset)*) y Traductor (usando el contenedor *map o multimap* de la STL).

 #### Elección del contenedor para Palabra:
 En la versión anterior Palabra tenía como atributos privados
 un string que representaba la palabra origen y un vector en memoria
 dinámica de strings con las palabras destino, además de un entero
 que contabilizaba el número de palabras destino.

 Con **pair** podremos guardar pares y es idóneo porque el tipo de dato Palabra necesita una palabra
 origen y una lista de palabras destino. A su vez las palabras destino no pueden repetirse por lo que
 puede usarse el contenedor set en lugar de multiset y además tendremos estas ordenadas por las características
 del set.

 


 En la versión anterior

* Para compilar ejecutar:
  `make`

* Para construir la documentacion:
  `make documentacion`

	Entrada a la documentación en doc/html/index.html

* Para correr traductor:  `make runTraductor`

	*Sabiendo que la ejecución ejecuta el traductor con el fichero de palabras por defecto, español->inglés.*

* Ejemplo de ejecución:
