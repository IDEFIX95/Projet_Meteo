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
fichierdentree=''
option_oblig=0

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

#if (( $# != 1));then
    #echo "Impossible aucune option saisie"
   # exit 1
#fi

##Gestion des parametres
while getopts ":t:p:whmdf:-:" option
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
            ;;
            sup)
                sup=1
                echo "la suppression txt va etre executées"
                rm *.txt
                echo "la suppression des csv vont etre executées sous demande"
                rm -i *.csv
                option_oblig+=1
            ;;
            *)
                echo "option longue non permise --${OPTARG}"
                exit 1
            ;;
        esac
    else
        case "$option" in       #Test des options courtes
        t)
            temperature=${OPTARG}
            numero='^[1-3]+$'
            if ! [[ $temperature =~ $numero ]];then
            echo "Choix des numeros invalide. Veuillez reselectionner un numero de mode compris entre 1 et 3"
            exit 1
            fi
            ;;
        p)
            pression=${OPTARG}
            numero='^[1-3]+$'
            if ! [[ $pression =~ $numero ]];then
            echo "Choix du numero invalide. Veuillez reselectionner un numero de mode compris entre 1 et 3"
            exit 1
            fi      
            ;;
        w)
            vent=${OPTARG}
            echo "bien joué"
            ;;
        h)
            altitude=${OPTARG}
            echo "bien joué"
            ;;
        m)
            humidite=${OPTARG}
            echo "bien joué"
            ;;
        f)
            fichierdentree=${OPTARG}
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


#Pour la temperature

if [ "$temperature" -eq 1 ]
       then
       temperature1=$temperature
       #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f"$numero_station","$numero_date","$numero_temperature","$numero_temp_min","$numero_temp_max" "$fichierdentree" > temp1.csv
       option_oblig+=1
       #echo $option_oblig
       echo "bien joué en cours de transfert"
fi
if [ "$temperature" -eq 2 ]
        then
        temperature2=$temperature
        cut -d';' -f"$numero_date","$numero_temperature" "$fichierdentree" > temp2.csv
        #echo ${temperature2}
        echo "bien joué"
fi
if [ "$temperature" -eq 3 ]
        then
        temperature3=$temperature
        cut -d';' -f"$numero_station" "$fichierdentree" > temp3.csv
        #echo "bien joué"
fi        

#Pour la pression


if [ "$pression" -eq 1 ]
       then
       temperature1=$temperature
       #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f1,2,7,8 $fichierdentree > press1.csv
       option_oblig+=1
       #echo $option_oblig
       #echo "bien joué en cours de transfert"
fi
if [ "$pression" -eq 2 ]
       then
       temperature1=$temperature
       #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f2,7,8 $fichierdentree > press2.csv
       #echo "bien joué en cours de transfert"
fi
if [ "$pression" -eq 3 ]
       then
       temperature1=$temperature
       #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f1,2,7 $fichierdentree > press3.csv
       #echo "bien joué en cours de transfert"
fi

#echo "$option_oblig"

if (( $option_oblig < 1));then
    echo "Impossible aucune option saisie"
    exit 1
fi

shift $((OPTIND-1))
echo "Analyse des options terminée"


















































exit 0