set terminal postscript color
set output "problem4.ps"
set title "Problem 4"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/problem4.out" using 1:2 with lines

