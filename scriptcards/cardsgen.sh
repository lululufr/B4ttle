#!/bin/bash
i=1
while read line
do
((i++))
	touch $line
  	echo "$line | 0$i | Point de Vie | Attaque | Defense | Description personnage | Competence(s) | Description Competence |" > $line.txt
done < gensdelaclasse.txt

