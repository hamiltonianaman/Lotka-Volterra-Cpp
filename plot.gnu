set term svg size 1200,800 
set output "plot1.svg"
set grid
set key font ",20"
set xlabel "Time" font ",30"
set ylabel "Population" font ",30"
set tics font ", 20"
p[0:15]  "output.dat" u 1:2 title "Prey" w l lw 2 lt 7,"output.dat" u 1:3 title "Predator" w l lw 2 lt 8


set term svg size 1200,800 
set output "plot2.svg"
set grid
set key font ",20"
set xlabel "Prey" font ",30"
set ylabel "Predator" font ",30"
set tics font ", 20"
p "output.dat" u 2:3  w l lw 2 lt 7 notitle
