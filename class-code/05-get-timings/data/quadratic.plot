set terminal postscript color
set output "output.ps"
set title "quadratic"
set xlabel "N"
set ylabel "Time (seconds)"

plot [:][:] "data/quadratic.out" using 1:2 with lines
