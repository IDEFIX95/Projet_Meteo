#!/bin/bash

#if [ ! -e $1 ] || [ ! -f $1 ];then #test si l'option est un fichier et qu'il existe
 #   echo "choix du fichier mauvais"
    #exit 1
#fi

# les variables pour les options
temperature=0
pression=0
vent=0
humidite=0
altitude=0

fichierdentree=''

date=0
date_max=''
date_min=''


datedentree=''
fichiersortie=''


option_oblig=0
option_geo=0
option_tri=0
option_date=0

#les variables pour les numeros de champ du fichier d'entrée du csv
numero_station=1
numero_date=2
numero_pression_au_niveau_mer=3
numero_direct_vent=4
numero_vitesse_du_vent_moy=5
numero_humidite=6
numero_pression_station=7
numero_variation_pression=8
numero_precipitation=9
#numero_coordonne=10
numero_temperature=11
numero_temp_min=12
numero_temp_max=13
numero_altitude=14
numero_commune=15



#if (( $# != 1));then
    #echo "Impossible aucune option saisie"
   # exit 1
#fi

##Gestion des parametres
while getopts ":FGSAOQwhmf:d:t:p:-:" option;
do
    # Commencons par la gestion des options longues
    if [ "$option" = '-' ]
    then
        case "$OPTARG" in
            tab)
                tab=1
                make all
                echo "bien joué"
                option_tri=$(($option_tri+1))
            ;;
            abr)
                abr=1
                make all
                echo "bien joué"
                option_tri=$(($option_tri+1))
            ;;
            avl)
                avl=1
                make all
                echo "bien joué"
                option_tri=$(($option_tri+1))
            ;;
            help)
                help=1
                echo "creation du fichier help"
                touch dochelp.txt
                chmod 744 dochelp.txt
                option_oblig=$(($option_oblig+1))
            ;;
            sup)
                sup=1
                echo "la suppression txt va etre executées"
                rm *.txt
                echo "la suppression des csv vont etre executées sous demande"
                rm -i *.csv
                option_oblig=$(($option_oblig+1))
            ;;
            *)
                echo "option longue non permise --${OPTARG}"
                exit 1
            ;;
        esac
    else
        case "$option" in           #Test des options courtes
        f)
            fichierdentree=${OPTARG}
            ;;      
        t)
            temperature=${OPTARG}
            numero='^[1-3]+$'
            if ! [[ $temperature =~ $numero ]];then
            echo "Choix des numeros invalide. Veuillez reselectionner un numero de mode compris entre 1 et 3"
            exit 1
            fi
            option_oblig=$(($option_oblig+1))
            ;;
        p)
            pression=${OPTARG}
            numero='^[1-3]+$'
            if ! [[ $pression =~ $numero ]];then
            echo "Choix du numero invalide. Veuillez reselectionner un numero de mode compris entre 1 et 3"
            exit 1
            fi   
            option_oblig=$(($option_oblig+1))
            ;;
        w)
            vent=${option}
            #echo "bien joué"
            option_oblig=$(($option_oblig+1))
            ;;
        h)
            altitude=${option}
            #echo "bien joué"
            option_oblig=$(($option_oblig+1))
            ;;
        m)
            humidite=${option}
            option_oblig=$(($option_oblig+1))
            ;;
        F)
            france_corse=${option}
            option_geo=$(($option_geo+1))
            ;;
        G)
            guyane_francaise=${option}
            option_geo=$(($option_geo+1))
        ;;
        S)
            saint_pierre_et_mique=${option}
            option_geo=$(($option_geo+1))
        ;;
        A)
            antille=${option}
            option_geo=$(($option_geo+1))
        ;;
        O)
            ocean_indien=${option}
            option_geo=$(($option_geo+1))
        ;;
        Q)
            antarctique=${option}
            option_geo=$(($option_geo+1))
        ;;
        d)
            date=${option}
            datedentree=${OPTARG}
            date_min=${datedentree%%,*}
            date_max=${datedentree##*,}
            echo "$date_min"
            echo "$date_max"
            date_verification="#^[0-9]{4}"
            option_date=$(($option_date+1))
        ;;
        :)
            echo "Erreur: -${OPTARG} argument recommander."
            exit 1
            ;;
        --)
            break
            ;;
        *)
            echo "Erreur: -${OPTARG} l'option n'existe pas"
            exit 1
            ;;
        esac
    fi
done

## Les nombreux testent à effectuer pour l'instant programmer comme cela

# Test pour les options obligatoire et geographiques
if (( "$option_geo" > 1));then
    echo "Impossible d'executer trop d'option de lieux choisie."
    exit 1
fi


#if (( "$option_oblig" < 1));then
 #   echo "Impossible aucune option obligatoire saisie"
  #  exit 1
#fi

## Condition pour les lieux geographiques

if [ "$france_corse" == "F" ];then
    echo "bien joué"
    awk -F ";" '{numero_coordonne=10;
         split( $numero_coordonne, coord, ",");
         x = coord[1];
         y = coord[2]; 
         if (x >41 && x <51 && y >-6 && y <11)  print $0}' "$fichierdentree" > france_corse.csv
    fichiersortie='france_corse.csv'
fi  


if [ "$guyane_francaise" == "G" ];then
    echo "bien joué"
    awk -F ";" '{numero_coordonne=10;
         split( $numero_coordonne, coord, ",");
         x = coord[1];
         y = coord[2]; 
         if (x >1 && x <7 && y >-55 && y <-50)  print $0}' "$fichierdentree" > guyane_francaise.csv
    fichiersortie='guyane_francaise.csv'
fi


if [ "$saint_pierre_et_mique" == "S" ];then
    echo "bien joué"
    awk -F ";" '{numero_coordonne=10;
         split( $numero_coordonne, coord, ",");
         x = coord[1];
         y = coord[2]; 
         if (x >46 && x <48 && y >-57 && y <-55)  print $0}' "$fichierdentree" > saint_pierre_et_mique.csv
    fichiersortie='saint_pierre_et_mique.csv'
fi  


if [ "$antille" == "A" ];then
    echo "bien joué"
   awk -F ";" '{numero_coordonne=10;
         split( $numero_coordonne, coord, ",");
         x = coord[1];
         y = coord[2]; 
         if (x >12 && x <19 && y >-75 && y <-58)  print $0}' "$fichierdentree" > antille.csv
   fichiersortie='antille.csv'
fi  


if [ "$ocean_indien" == "O" ];then
    echo "bien joué"
    awk -F ";" '{numero_coordonne=10;
         split( $numero_coordonne, coord, ",");
         x = coord[1];
         y = coord[2]; 
         if (x >-55 && x <-10 && y >41 && y <113)  print $0}' "$fichierdentree" > ocean_indien.csv
   fichiersortie='ocean_indien.csv'
fi  


if [ "$antarctique" == "Q" ];then
    echo "bien joué"
    awk -F ";" '{numero_coordonne=10;
         split( $numero_coordonne, coord, ",");
         x = coord[1];
         y = coord[2]; 
         if (x >-83 && x <-61 && y >-172 && y <177)  print $0}' "$fichierdentree" > antarctique.csv
   fichiersortie='antarctique.csv'

fi  

# date / horaires

if [ "$date" == "d" ];then
    echo "bien joué"
   # datedentree='^[1-3]+$'
   #tail -n+2 "$fichierdentree" | awk -F "[T;]"  '{ numero_date=2; if($numero_date >date_min && $numero_date <date_max) print $numero_date}' > datefiltrer.csv #'{#numero_date=2; 
    sed 's/T/,/g' "$fichierdentree" | awk -F ";" -v min_date="$date_min" -v max_date="$date_max" '{numero_date=2; split ( $numero_date, coord , ","); date = coord[1]; horaires = coord[2]; if(date >min_date && date <max_date) print $0}' >  datefiltrer.csv
    
fi

#sed

if [ "$option_geo" -eq 1 ];then
    fichierdentree="$fichiersortie"
fi


#Pour la temperature

if [ "$temperature" -eq 1 ];
       then
       tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_station","$numero_date","$numero_temperature","$numero_temp_min","$numero_temp_max" > temp1.csv
       if [ "$option_geo" -eq 1 ];then
            rm "$fichierdentree"
       fi
fi

if [ "$temperature" -eq 2 ];
        then
        tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_date","$numero_temperature" > temp2.csv
        if [ "$option_geo" -eq 1 ];then
            rm "$fichierdentree"
        fi
        
fi

if [ "$temperature" -eq 3 ];
        then
        tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_station","$numero_date","$numero_temperature" > temp3.csv
        if [ "$option_geo" -eq 1 ];then
            rm "$fichierdentree"
        fi
fi        

# Condition pour la pression


if [ "$pression" -eq 1 ];
    then
    tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_station","$numero_pression_station","$numero_variation_pression"  > press1.csv
    if [ "$option_geo" -eq 1 ];then
        rm "$fichierdentree"
    fi
    
fi

if [ "$pression" -eq 2 ];
    then
    tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_date","$numero_pression_station","$numero_variation_pression"  > press2.csv
    if [ "$option_geo" -eq 1 ];then
        rm "$fichierdentree"
    fi 
    
fi

if [ "$pression" -eq 3 ];
    then
    tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_station","$numero_date","$numero_pression_station","$numero_variation_pression" > press3.csv
    if [ "$option_geo" -eq 1 ];then
        rm "$fichierdentree"
    fi 
    
fi


# Condition pour le vent


if [ "$vent" == "w" ];then
    tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_station","$numero_direct_vent","$numero_vitesse_du_vent_moy" > vent.csv
    if [ "$option_geo" -eq 1 ];then
        rm "$fichierdentree"
    fi
fi



# Condition pour l'altitude



if [ "$altitude" == "h" ];then
    tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_station","$numero_altitude" > altitude.csv
    if [ "$option_geo" -eq 1 ];then
        rm "$fichierdentree"
    fi
fi



# Condition pour l'humidité


if [ "$humidite" == "m" ];then
   echo "bien joué"
   tail -n+2 "$fichierdentree" | cut -d';' -f"$numero_station","$numero_humidite" > humidite.csv
   if [ "$option_geo" -eq 1 ];then
        rm "$fichierdentree"
   fi
fi



shift $((OPTIND-1))
echo "Analyse des options terminée"









exit 0



