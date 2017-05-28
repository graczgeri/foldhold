set term png size 1280, 720
set out "euler_plot.png"

set title "Euler fit"

set autoscale

set xlabel "x"
set ylabel "y"

plot "euler.dat" using 1:2 w lines
