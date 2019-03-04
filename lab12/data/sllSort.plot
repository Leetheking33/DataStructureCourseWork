set terminal postscript color
set output "sllSort.ps"
set title "Sll Sort"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/sllSort.out" using 1:2 with lines
