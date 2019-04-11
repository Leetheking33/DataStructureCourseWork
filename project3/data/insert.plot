set terminal postscript color
set output "insert.ps"
set title "AVL vs Scape Goat"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/AVLinsert.out" using 1:2 with lines
plot [:][:] "data/SGinsert.out" using 1:2 with lines
