
Informe de Eficiencia 2
-----------------------

###Algoritmo de ordenación Burbuja, ++Mejor y Peor Caso++

######Hardware Usado

El equipo donde se ha realizado la compilación y ejecución del programa es un Portatil Acer Aspire 5920 con las siguientes características:

* Procesador de doble núcleo: Intel(R) Core(TM)2 Duo CPU T5450 a 1.66GHz
* 4GB de Ram

######Sistema Operativo

Ubuntu 12.04.4 LTS  32 bits

######Compilador utilizado y opciónes de compilación

Se ha usado gcc versión 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu5) 


######Desarrollo completo del cálculo de la eficiencia teórica y gráfica


Para calcular la eficiencia teórica realizamos el cálculo de las operaciones elementales que hay dentro del código principal del algoritmo de ordenación Burbuja.

```sh
void ordenar(int *v, int n){
	for(int i=0; i<n-1; i++)
    	for(int j=0; j<n-i-1; j++)
        	if(v[j]>v[j+1]){
            	int aux = v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
}
```
Haciendo el calculo de forma simplificada y quedandonos con el orden podemos decir que este algoritmo tiene una eficiencia de 0(n^2), cuadrática. En la gráfica de la izquierda podemos ver la curva de n cuadrado y a la derecha los tiempos que empiricamente se han obtenido.

![Imagen 1][1]  ![Imagen 2][2]

 [1]: graficaxCuadrado.jpeg
 [2]: graficaSalida.jpeg 

Para el cálculo de los tiempos ejecutamos el script ejecuciones_ordenacion.csh que ejecuta a su vez de forma controlada el ejecutable a partir de Ejercicio1.cpp que previamente hemos compilado. Durante la ejecución del script los datos resultado del ejecutable se van escribiendo en tiempos_ordenacion.dat que después usamos con gnuplot para crear la gráfica.
En concreto hemos usado ordenacionBurbuja.gp para que gnuplot nos cree la gráfica como nos interesa, superpuesta encima de la de n cuadrado.



Si superponemos ambas gŕaficas podemos comparar la eficiencia teórica que hemos calculado que tendrá nuestro algoritmo con el resultado empírico de la ejecución

![Imagen 3](graficaDoble.jpeg)

Como vemos la eficiencia teórica calculada se ajusta bastante a la empírica, pese que al principio los resultados empíricos nos muestras un crecimiento menor al de la curva cuadrada a partir de las 20000 unidades de vector el tiempo empieza a ser distinto pero siguiendo la misma tendencia de la curva, siendo en su mayoría los tiempos superiores a los de esta.




#####Detalles:

En linux para conocer el modelo de nuestra CPU además de otros muchos datos de los núcleos de la misma podemos ejecutar: `cat /cpu/info` .

Para conocer la versión del S.O. `cat /etc/issue` y para conocer la arquitectura (32 o 64 bits) `uname -m` donde veremos x86_64 para 64 bits ó i686 para las de 32.

Para conocer la versión de nuestro compilador  podemos hacer `g++ -v` .

El script que nos dan de ejemplo está escrito en C-Shell (csh), cuya sintaxis es similar a C, estos ficheros no pueden ejecutarse bajo bash (el shell por defecto de Ubuntu) y por tanto tendremos que instalarlo si queremos ejecutarlo `sudo apt-get install csh` .

Para la creación de las gráficas con gnuplot usamos los script .gp asi: `gnuplot ordenacionBurbuja.gp`, que en este caso nos dejará la gráfica en jpeg donde se haya ejcutado gnuplot.










Los tiempos de ejución para el mejor y peor caso han sido de 329 y 900 seg respectivamente, se decir responde a un crecimiento cuadrático tal que así: