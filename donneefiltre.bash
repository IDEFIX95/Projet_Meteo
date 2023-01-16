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
count=0
x_max=0
x_min=0
y_max=0
y_min=0

fichierdentree=''
option_oblig=0
option_geo=0

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
numero_coordonne=10
numero_temperature=11
numero_temp_min=12
numero_temp_max=13
numero_altitude=14
numero_commune=15


# les variables pour les zones geographiques
france_corse=0
guyane_francaise=0
saint_pierre_et_mique=0
antille=0
ocean_indien=0
antarctique=0


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
                option="z"
                make main.c
                echo "bien joué"
            ;;
            abr)
                abr=1
                option="z"

                echo "bien joué"
            ;;
            avl)
                avl=1
                option="z"
                echo "bien joué"
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
            #echo "bien joué"
            option_oblig=$(($option_oblig+1))
            ;;
        F)
            france_corse=${option}
            #awk -F";" 'NR {print '$numero_coordonne'}' meteo_filtered_data_v1.csv
            option_geo=$(($option_geo+1))
            ;;
        G)
            guyane_francaise=${option}
            option_geo=$(($option_geo+1))
        ;;
        S)
            saint_pierre_et_mique=${option}
           # echo "bien joué"
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
            echo "bonjour"
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

#Pour la temperature

if [ "$temperature" -eq 1 ]
       then
       #temperature1=$temperature
       #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f"$numero_station","$numero_date","$numero_temperature","$numero_temp_min","$numero_temp_max" "$fichierdentree" > temp1.csv
       
       #echo "$option_oblig"
       #echo "bien joué en cours de transfert"
fi
if [ "$temperature" -eq 2 ]
        then
        #temperature2=$temperature
        cut -d';' -f"$numero_date","$numero_temperature" "$fichierdentree" > temp2.csv
        #echo ${temperature2}
        #echo "bien joué"
fi
if [ "$temperature" -eq 3 ]
        then
        #temperature3=$temperature
        cut -d';' -f"$numero_station","$numero_date","$numero_temperature" "$fichierdentree" > temp3.csv
        #echo "bien joué"
fi        

# Condition pour la pression


if [ "$pression" -eq 1 ]
       then
       
       #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f"$numero_station","$numero_pression_station","$numero_variation_pression" "$fichierdentree" > press1.csv
       
       #echo "$option_oblig"
       #echo "bien joué en cours de transfert"
fi
if [ "$pression" -eq 2 ]
       then
       
       #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f"$numero_date","$numero_pression_station","$numero_variation_pression" "$fichierdentree" > press2.csv
       #echo "bien joué en cours de transfert"
fi
if [ "$pression" -eq 3 ]
       then
       #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f"$numero_station","$numero_date","$numero_pression_station","$numero_variation_pression" "$fichierdentree" > press3.csv
       #echo "bien joué en cours de transfert"
fi

# Condition pour le vent

if [ "$vent" == "w" ];then
    echo "bien joué"
    cut -d';' -f"$numero_station","$numero_direct_vent","$numero_vitesse_du_vent_moy" "$fichierdentree" > vent.csv
fi

# Condition pour l'altitude

if [ "$altitude" == "h" ];then
   # echo "bien joué"
    cut -d';' -f"$numero_station","$numero_altitude" "$fichierdentree" > altitude.csv
fi

# Condition pour l'humidité

if [ "$humidite" == "m" ];then
    echo "bien joué"
   cut -d';' -f"$numero_station","$numero_humidite" "$fichierdentree" > humidite.csv
fi


## Condition pour les lieux geographiques

if [ "$france_corse" == "F" ];then
    echo "bien joué"
     awk -F ";" '{split('$numero_coordonne', coord, ";"); x = coord[1]; y = coord[2]; if (x < 48 && x > 46 && y > 55 && y < 57 ) {print x,y}}' "$fichierdentree"
fi  


if [ "$guyane_francaise" == "G" ];then
    echo "bien joué"
    awk -F ";" '{split('$numero_coordonne', coord, ";"); x = coord[1]; y = coord[2]; if (x < 48 && x > 46 && y > 55 && y < 57 ) {print x,y}}' "$fichierdentree"
fi  


if [ "$saint_pierre_et_mique" == "S" ];then
    echo "bien joué"
    
    grep $x_max=48 $x_min=46 $y_min=55 $y_max=57 | awk -F ";" '{split( $numero_coordonne, coord, ";"); x = coord[1]; y = coord[2]; if (x < 48 && x > 46 && y > 55 && y < 57 ) {print x,y}}' "$fichierdentree" 
fi  


if [ "$antille" == "A" ];then
    echo "bien joué"
    awk -F ";" '{split( $numero_coordonne, coord, ";"); x = coord[1]; y = coord[2]; if (x < 48 && x > 46 && y > 55 && y < 57 ) {print x,y}}' "$fichierdentree"
fi  


if [ "$ocean_indien" == "O" ];then
    echo "bien joué"
     awk -F ";" '{split('$numero_coordonne', coord, ";"); x = coord[1]; y = coord[2]; if (x < 48 && x > 46 && y > 55 && y < 57 ) {print x,y}}' "$fichierdentree"
fi  


if [ "$antarctique" == "Q" ];then
    echo "bien joué"
     awk -F ";" '{split('$numero_coordonne', coord, ";"); x = coord[1]; y = coord[2]; if (x < 48 && x > 46 && y > 55 && y < 57 ) {print x,y}}' "$fichierdentree"
fi  

#echo "$option_oblig"

# Test pour les options obligatoire et geographiques

#if (( "$option_oblig" < 1));then
#    echo "Impossible aucune option saisie"
 #   exit 1
#fi

if (( "$option_geo" > 1));then
    echo "Impossible d'executer trop d'option de lieux choisie."
    exit 1
fi


shift $((OPTIND-1))
echo "Analyse des options terminée"










exit 0
