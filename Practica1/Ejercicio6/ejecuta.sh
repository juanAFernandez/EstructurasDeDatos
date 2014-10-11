#!/bin/bash

#Compilación del fuente sin optimización
g++ ordenacionBurbuja.cpp -o ordenacionBurbuja
#Compilación del fuente con optimización
g++ -O3 ordenacionBurbuja.cpp -o ordenacionBurbujaOptimizado


#Ejecución de los programas en bucle

#Inicialización de las variables necesarias
let INICIO=100
let FIN=30000
let INCREMENTO=500
let RANDOM_MAXIMO=10000

#Ejecución del bucle de ejecución con análisis de tiempo total de ejecuciones
T1="$(date +%s)"
let I=$INICIO
while [ $I -le $FIN ]; do
	echo Tamao del vector: $I
	./ordenacionBurbuja $I $RANDOM_MAXIMO >> tSinOptimizacion.dat
	let I=I+INCREMENTO
done
T1="$(($(date +%s)-T1))"

#Ejecución del bucle de ejecución con análisis de tiempo total de ejecuciones
T2="$(date +%s)"
let I=$INICIO
while [ $I -le $FIN ]; do
        echo Tamaño del vector: $I
        ./ordenacionBurbujaOptimizado $I $RANDOM_MAXIMO >> tConOptimizacion.dat
        let I=I+INCREMENTO
done
T2="$(($(date +%s)-T2))"


#Creación de las gráficas a partir de los resultados

gnuplot graficaComparativaOptimizacion.gp

echo "Tiempo total de ejecución sin optimización: ${T1} segundos."
echo "Tiempo total de ejecución con optimización: ${T2} segundos."

#Limpieza de ficheros

rm *.dat
rm ordenacionBurbuja
rm ordenacionBurbujaOptimizado
