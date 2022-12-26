#!/bin/bash

if [ ! -f $1 ] || [ ! -e $1 ] || (( $# != 1 ));then
    echo "choix du fichier mauvais"
    exit 1
fi

doc1=$(tail +3 $1 | wc -l)
if (($doc1 == 1));then
    cat $1
else
    head -n2 $1
    tail +3 $1 | sort -t: -k2nr
fi
