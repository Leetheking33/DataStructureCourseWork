set terminal postscript color
set output "sequential.ps"
set title "Sequential"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/sequential.out" using 1:2 with lines
