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
            echo "Choix des numeros non comprise entre 1 et 3"
            exit 1
        fi
        ;;
    p)
        pression=${OPTARG}
        numero='^[1-3]+$'
        if ! [[ $pression =~ $numero ]];then
            echo "Choix du numero invalide. Veuillez selectionner un numero de mode compris entre 1 et 3"
            exit 1
        elif [ "$pression" -eq 1 ]
            then
            pression1=$pression
            echo ${pression1}
            echo "bien joué"
            
        elif [ "$pression" -eq 2 ]
            then
            pression2=$pression
            echo "bien joué"
        
        elif [ "$pression" -eq 3 ]
            then
            pression3=$pression
            echo "bien joué"
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



if [ "$temperature" -eq 1 ]
        then
        temperature1=$temperature
        #awk  -F BEGIN{OFS=";"} FS=";" '{print $1,$2,$11,$12,$13}'  meteo_filtered_data_v1.csv > temp1.csv
       cut -d';' -f1 $fichierdentree > temp1.csv
        echo "bien joué en cours de transfert"
elif [ "$temperature" -eq 2 ]
            then
            temperature2=$temperature
            #echo ${temperature2}
            echo "bien joué"
elif [ "$temperature" -eq 3 ]
            then
            temperature3=$temperature
            echo "bien joué"
        fi        
shift $((OPTIND-1))
echo "Analyse des options terminée"





















































exit 0