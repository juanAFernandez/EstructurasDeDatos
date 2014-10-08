#!/bin/bash
echo ""
echo "--------------------------------------------------------------------"
echo "Comparación del mejor y peor caso en Algoritmo de Ordenación Burbuja"
echo "--------------------------------------------------------------------"
echo ""
echo "Cálculo de los tiempos de ejecución en el Mejor Caso:"
sleep 2
T1="$(date +%s)"
./ejecucionesOrdenacionMejorCaso.csh
T1="$(($(date +%s)-T1))"

echo "Cálculo de los tiempos de ejecución en el Peor Caso:"
sleep 2
T2="$(date +%s)"
./ejecucionesOrdenacionPeorCaso.csh
T2="$(($(date +%s)-T2))"

echo "Creación de gráficas en fichero graficaDoble.jpeg"

gnuplot creacionGraficas.gp

echo "Tiempo de ejecución Mejor Caso: ${T1} segundos."
echo "Tiempo de ejecución Peor Caso:  ${T2} segundos."


