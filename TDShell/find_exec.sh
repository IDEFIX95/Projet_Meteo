#!/bin/bash
if  (( $# != 1 )) || [ ! -d $1 ] ; then
    exit 1    
fi 
for k in $(ls $1) ; do
    if [ -x $1/$k ] ; then
        echo $k
        echo `du -h $1/$k`
    fi
done

