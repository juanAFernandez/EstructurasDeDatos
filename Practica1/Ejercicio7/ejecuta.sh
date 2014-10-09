#!/bin/bash

#Compilación del fuente
g++ Ejercicio7.cpp -o Ejercicio7

#Ejecución del programa en bucle 

#Inicialización de las variables necesarias
let INICIO=100
let FIN=500
let INCREMENTO=10
let RANDOM_MAXIMO=10

#Ejecución del bucle de ejecución con análisis de tiempo total de ejecuciones
T1="$(date +%s)"
let I=$INICIO
while [ $I -le $FIN ]; do
	echo Matriz de tamaño: $I
	./Ejercicio7 $I $RANDOM_MAXIMO >> tiemposMultiplicacion.dat
	let I=I+INCREMENTO
done
T1="$(($(date +%s)-T1))"

#Creación de las gráficas a partir de los resultados

gnuplot graficaMultiplicacion.gp


echo "Tiempo de ejecución del análisis: ${T1} segundos."