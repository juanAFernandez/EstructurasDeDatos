#!/bin/csh
@ inicio = 100000
#Hasta un total de 500 millones de elementos en el vector.
@ fin = 500000000
@ incremento = 500000
set ejecutable = busqueda_lineal
set salida = tiempos_busqueda.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución de tamaño = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end

#Si quietamos # se muestra por pantalla