set terminal postscript color
set output "problem5.ps"
set title "Problem 5"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/problem5.out" using 1:2 with lines

