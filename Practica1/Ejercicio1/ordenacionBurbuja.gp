set terminal jpeg 
set output "graficaDoble.jpeg"

set multiplot
set size 1,0.5

set origin 0.0,0.5
plot "tiempos_ordenacion.dat" title "Busqueda Burbuja"

set origin 0.0,0.0
plot [0:40000] x**2

unset multiplot
