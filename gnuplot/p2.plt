set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 600, 400
set output 'P2.png'
set nopolar
set grid nopolar
set datafile separator ';' 
set title "Diagramme pour la Pression pour le mode P2"
set xlabel "Jour et Heure des mesures"
set ylabel "Moyenne des mesures"
set xtics 5
set mxtics 2
set ytics 5
set mytics 1
set key fixed right top vertical noreverse enhanced autotitle box lt black linewidth 1.000 dashtype solid
set samples 50,50
set xrange [ * : * ] noreverse writeback
set yrange [ * : * ] noreverse writeback
set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front noinvert bdefault
NO_ANIMATION = 1
plot "fichier_trie.csv" using 1:2
replot