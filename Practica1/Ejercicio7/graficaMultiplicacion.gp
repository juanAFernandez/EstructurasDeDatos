set terminal jpeg 
set output "graficaMultiplicacion.jpeg"

set multiplot

set size 1,0.5

set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5   # --- blue 
set origin 0.0,0.0
plot [80:520] [] "tiemposMultiplicacion.dat" title "Multiplicación Matrices" with linespoints ls 1

set origin 0.0,0.5
plot [80:520] x**3 title "Función cúbica x^3"

unset multiplot




set terminal wxt size 1000,400 enhanced font 'Verdana,10' persist

set multiplot

set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5   # --- blue 
set size 0.9680,1
set origin 0.031,0.0
plot [80:520] [] "tiemposMultiplicacion.dat" title "Multiplicación Matrices" with linespoints ls 1

set size 1,1
set origin 0.0,0.0
plot [80:520] x**3

unset multiplot

