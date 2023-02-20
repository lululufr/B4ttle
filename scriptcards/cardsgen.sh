#!/bin/bash
i=1
while read line
do
((i++))
touch $line
echo "$line
0$i
10
15
Description personnage
Competence (s)
Description Competence
" > $line
done < gensdelaclasse.txt

