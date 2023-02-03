set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 600, 400
set output 'T1.png'
unset errorbars
set nopolar
set grid nopolar
set datafile separator ';'
set title "Diagramme pour la Température avec le mode T1" 
set xlabel "Identifiant de la station"
set ylabel "Minimum, maximum et moyenne"
set ytics 5
set mytics 1
set xrange [ * : * ] noreverse writeback
set yrange [ * : * ] noreverse writeback
set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front noinvert bdefault
NO_ANIMATION = 1
plot "fichier_trie.csv" using 1:3, "fichier_trie.csv" using 1:4, "fichier_trie.csv" using 1:5
replot