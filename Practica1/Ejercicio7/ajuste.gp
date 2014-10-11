f(x)=a*x**3 + b*x**2 + c*x + d
fit f(x) "tiemposMultiplicacion.dat" via a, b, c, d
set terminal jpeg
set output "graficaAjuste.jpeg"
plot "tiemposMultiplicacion.dat", f(x)
