set terminal postscript color
set output "binarySearch.ps"
set title "binarySearch"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/binarySearch.out" using 1:2 with lines
