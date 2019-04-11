set terminal postscript color
set output "delete.ps"
set title "AVL vs Scape Goat"
set xlabel "i"
set ylabel "Time (Seconds)"

plot [:][:] "data/AVLdelete.out" using 1:2 with lines
plot [:][:] "data/SGdelete.out" using 1:2 with lines
