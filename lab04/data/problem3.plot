set terminal postscript color
set output "problem3.ps"
set title "Problem 3"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/problem3.out" using 1:2 with lines

