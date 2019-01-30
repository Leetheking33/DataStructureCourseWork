set terminal postscript color
set output "problem1.ps"
set title "Problem 1"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/problem1.out" using 1:2 with lines
