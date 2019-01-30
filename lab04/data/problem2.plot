set terminal postscript color
set output "problem2.ps"
set title "Problem 2"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/problem2.out" using 1:2 with lines

