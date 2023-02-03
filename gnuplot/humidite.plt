set terminal jpeg size 800,600
        set xyplane relative 0
        set title "humidité des stations"
        set output 'graphiqueGnuplot/{$zone}_${tableau_arg[$p]}_Graphique.jpeg'
        set xlabel "Longitude"
        set ylabel "Latitude"
        set zlabel "humidité"
        set xtics
        set ytics  
        set datafile separator ";"
        set pm3d map interpolate 4,4 flush begin nohidden3d
        set dgrid3d 50,50
        set autoscale noextend
        set zrange[ * : * ]
        set palette rgbformulae -5, 2, 5
        set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front  noinvert bdefault
        NO_ANIMATION = 1
        splot "humidite_sortie.csv" u 3:4:1 with pm3d
        reset
EOF