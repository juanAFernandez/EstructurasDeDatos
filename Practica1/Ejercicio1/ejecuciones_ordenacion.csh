#!/bin/csh
@ inicio = 100
@ fin = 50000
@ incremento = 100
set ejecutable = Ejercicio1
set salida = tiempos_ordenacion.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000` >> $salida
  @ i += $incremento
end
