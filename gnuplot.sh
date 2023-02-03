#!/bin/gnuplot -persist
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
plot "./fichier_trie.csv" using 1:3, "./fichier_trie.csv" using 1:4, "./fichier_trie.csv" using 1:5
replot

set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 600, 400
set output 'P1.png'
unset errorbars
set nopolar
set grid nopolar
set datafile separator ';'
set title "Diagramme pour la Pression avec le mode P1" 
set xlabel "Identifiant de la station"
set ylabel "Minimum, maximum et moyenne"
set ytics 5
set mytics 1
set xrange [ * : * ] noreverse writeback
set yrange [ * : * ] noreverse writeback
set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front noinvert bdefault
NO_ANIMATION = 1
plot "./fichier_trie.csv" using 1:3, "./fichier_trie.csv" using 1:4, "./fichier_trie.csv" using 1:5
replot

set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 600, 400
set output 'T2.png'
set nopolar
set grid nopolar
set datafile separator ';' 
set title "Diagramme pour la Température pour le mode T2"
set xlabel "Jour et Heure des mesures"
set ylabel "Moyenne des mesures"
set xtics 5
set mxtics 2
set ytics 5
set mytics 1
set key fixed right top vertical noreverse enhanced autotitle box lt black 
set samples 50,50
set xrange [ * : * ] noreverse writeback
set yrange [ * : * ] noreverse writeback
set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front noinvert bdefault
NO_ANIMATION = 1
plot "./fichier_trie.csv" using 1:2
replot

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
plot "./fichier_trie.csv" using 1:2
replot

set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 600, 400
set output 'h.png'
set border 4095 front lt black linewidth 1.000 dashtype solid
set style data lines 
set view map scale 1
set samples 50,50
set title "Diagramme pour l'Altitude"
set xlabel "Longitude (Axe Ouest-Est)"
set ylabel "Latitude (Axe Sud-Nord)"
