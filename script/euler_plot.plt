set term png size 1280, 720
set out "rk4.png"

set title "Runge Kutta 4 fit"

set autoscale

set xlabel "x"
set ylabel "y"

plot "rk4.dat" using 6:7 w lines
