set multiplot
set size 1,0.5

set origin 0.0,0.5
plot "tiempos_busqueda.dat" with lines title "Busqueda Lineal"

set origin 0.0,0.0
plot [0:50000] [0:50000] x

unset multiplot
