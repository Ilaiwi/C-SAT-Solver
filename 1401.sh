#!/bin/csh


set solver=$1
set instance=$2

echo Extract model for $1 and $2
grep -e '^[v]' ./results/result.$solver.$2.txt| cut -d'v' -f2 >> temp.txt

echo Check model
./solving_14_01_main ./instances/$2 temp.txt
