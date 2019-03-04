set terminal postscript color
set output "insertionSort.ps"
set title "Insertion Sort"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/insertionSort.out" using 1:2 with lines
