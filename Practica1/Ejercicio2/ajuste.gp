f(x)=a*x**2 + b*x + c
fit f(x) "tiempos_ordenacion.dat" via a, b, c
set terminal jpeg
set output "graficaAjuste.jpeg"
plot "tiempos_ordenacion.dat", f(x)
