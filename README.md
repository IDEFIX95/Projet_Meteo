Projet Meteo

Bonjour on va vous presenter le projet meteo.

Nous avons rencontrées plusieurs problémes.

Mais on a essayé de faire de notre mieux. Le script Shell fonctionne parfaitement pour filtrer correctement le fichierdentree. 

Autre choses toutes les options n'ont pas de graphique. Seul les modes -t1 , -h , -m, -p1 et -p2 ont des graphiques.
  
 Malheuresement n'ayant pas installer GnuPlot suffissamment tot nous avons pas pu mettre des graphiques dans le docx.



Pour executer le programme shell:
  ./donneefiltre.bash suivit des options obligatoires. Avec notamment -f suivit du fichier d'entrée avec toutes les données.
  
  
  exemeple d'execution: ./donneefiltre.bash -S -t1 -f meteo_filtered_data_v1.csv
  
  Un fichier sera alors créé suite a l'execution de ce code.
  
  Avec notamment un graphique crée a partir des options rentrées.
  
  Vous pouvez retrouver des options geographiques, les options obligatoire et l'option date. 
  
  L'option date va notamment filtrer par date le fichier initiale et va en resortir un nouveau. Pour ensuite l'envoyer au C.
  
  La plupart des verifications pour le shell sont faites. 
  
  la date se rentre de la maniere suivant YYYY-MM-DD. Une chose tres importante il ne faut pas oublier le "," lorsque l'on fait -d YYYY-MM-DD,YYYY-MM-DD. 
  
  Notre probleme a été sur le C. Ayant pas reussit a temps a bien faire le tri C. Nous avons été dans l'obligation d'utiliser les -sorts malheuresement.
  
  Vous pouvez alors consulter la commande "--help" en cas de probleme.
  
  Oh est une derniere chose vous pouvez mettre les options dans n'importe quelle ordre cela fonctionne.
   
Merci de votre lecture.
