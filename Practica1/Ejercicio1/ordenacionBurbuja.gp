set terminal jpeg 
set output "graficaDoble.jpeg"

set multiplot

set size 0.895,1
set origin 0.105,0.0
plot "tiempos_ordenacion.dat" title "Busqueda Burbuja"


set size 1
set origin 0.0,0.0
set style line 1 lc rgb '#0060ad' lt 1 lw 1 pt 7 ps 1.5 
plot [0:40000] x**2 ls 1

unset multiplot
