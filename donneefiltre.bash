#!/bin/bash

if [ ! -e $1 ] || [ ! -f $1 ];then #test si l'option est un fichier et qu'il existe
    echo "choix du fichier mauvais"
    #exit 1
fi
#else
   # echo "bien joué"
if (( $# != 1));then
    echo "Impossible aucune option saisie"
    exit 1
fi

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
    case "$option" in
    t)
        temperature=${OPTARG}
        echo "bien joué"
        ;;
    p)
        pression=${OPTARG}
        echo "bien joué"
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
shift $((OPTIND-1))
echo "Analyse des options terminée"





















































exit 0