set terminal postscript color
set output "selectionSort.ps"
set title "Selection Sort"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/selectionSort.out" using 1:2 with lines
