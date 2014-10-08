set terminal jpeg
set output "graficaDoble.jpeg"
plot "tiemposOrdenacionMejorCaso.dat","tiemposOrdenacionPeorCaso.dat"
