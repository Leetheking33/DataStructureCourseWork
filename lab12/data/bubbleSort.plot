set terminal postscript color
set output "bubbleSort.ps"
set title "Bubble Sort"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/bubbleSort.out" using 1:2 with lines
