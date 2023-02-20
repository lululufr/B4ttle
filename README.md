# B4ttle
Langage C projet deuxième année

Participants : 

Lucas MILLER 

Alexis ELEFTERIOU

Anthony-James MONTOUT

-----------------------------------------------------------------

La commande pour compiler est la suivante :

gcc -g main.c -o B4ttle -lcurses -lSDL -lSDL_image -lSDL_ttf

-----------------------------------------------------------------

Ce projet est un "pokemon" like. Le but est de tuer tous les adversaires présent sur la carte. 

Vous devrez pour ca utiliser les joueurs à votre dispositions ( membre de l'ESGI)

Les adversaires ont un deck de carte composé de personnage aléatoire. 
Le votre est défini par un fichier texte présent dans le Fichier Deck/Deck.

Chaque carte est un fichier texte 100% modifiable. 

Les combats se déroule ainsi : 
Le joueur principale commence -> Ses 4 cartes doivent effectuer une action entre ( attaquer, utiliser la compétence, passer son tour) -> une fois les 4 cartes jouées c'est au tour de l'adversaire.
Ainsi de suite jusqu'a la mort de toutes les cartes de l'adversaire. 


Lorsqu'un enemies est tué celui ci change d'apparence. 

IL est possible également de modifier ses cartes, il suffit pour cela de modifier le fichier texte Firstmap.txt ou SecondMap.txt.

Il est engalement possible de consulter toutes les descriptions de carte dans le premier menu dans bibliotheque. 


-----------------------------------------------------------------

En ce qui concerne le code, nous avons opté pour un code le plus dynamique possible a default d'un beau visuel de rendu.
Nous avons utilisé :
- Structures et Structure de Rendu
- SDL 1.2
- ncurses
- Listes Chainés
- Pointeurs de Fonctions
- Lecture de Fichier et de dossier

-----------------------------------------------------------------

<marquee>Rapport </marquee>


Comment lancer votre projet ? Quelles sont ses dépendances ?

Nous avons lancé notre projet suite a une envie de créer un petit jeu vidéo, nous nous sommes avant tout servi de nos connaissance algorythmique apprise a l'ESGI.
Mais aussi de nos cours de Git, qui nous ont permis de versionner correctement notre projet, et de coder chacun dans différente branche. 
Également les cours de linux ont été utilse car nous avons pu créer des des scripts en bash afin de généré nos structures de cartes rapidements


Le contexte et l’organisation de votre groupe pour répondre à la problématique : avez-vous établi un planning ?
Qui a fait quoi et pourquoi ?

En se qui concerne l'organisation, nous avons fait un planning, nous avons essayé de maintenir un rythme de se voir 1 fois par semaine au minimum pour coder ensemble.
Les taches ont été réparties entre Alexis et Lucas qui ont travaillé en binôme sur TOUS les éléments du code.
On pourrait dire cependant que chacun a pris des spécialités : Lucas sur la partie SDL et Alexis sur la partie Back. 
Mais dans l'ensemble les taches ont été reparties équitablement a 50%.



<b>Pourquoi avez-vous organisé le code de cette manière ? Quels sont les éléments du cours ou du langage C que vous avez
utilisé pour le mener à bien ? 
Ces choix ont-ils été pertinent pour avancer plus rapidement dans votre code, garder en maintenabilité ?</b>

On a essayé de faire un code le plus dynamique possible, il est très simple de créer une carte et une map sans avoir à changer énormément de choses dans le code.
On a également essayé de séparer l'aspect "back-end" du "front-end" du code le plus possible pour le rendre le plus maintenable possible.
Ca nous a beaucoup aidé lors de l'écriture du code qui était plus propre et compréhensible.
Nous avons utilisé :
- Structures et Structure de Rendu
- SDL 1.2
- ncurses
- Listes Chainés
- Pointeurs de Fonctions
- Lecture de Fichier et de dossier


<b>Quelles fonctionnalités proposez-vous dans ce projet ? Comment les avez-vous optimisées ? Valorisez l’apport de vos connaissances en algorithmique et leur intérêt pour ce projet en langage C. </b>

Les fonctionnalité proposé sont nombreuses, mais celle que nous avons voulu mettre en avant est le dynamisme de notre code.
En effet il est possible de changer absolument tout, il est possible de créer ses propres cartes et map.


<b>Avez-vous rencontré des difficultés techniques, organisationnelles, relationnelles pour réaliser ce projet ? 
Comment les avez-vous dépassées ?</b>

Nous avons en effet rencontré BEAUCOUP de difficulté. N'ayant rien voulu coder en DUR, nous avons souvent rencontré des erreurs de segmentations indécelable par n'importe quel debugger. 
NOus avons par exemple passé plusieurs soirées à essayer de debugger une seule petite fonction. 
IL reste encore quelques erreurs dans notre code, comme une erreur de segmentation a cause d'une fonction qui donne des cartes aléatoires à l'adversaire.

<b>La concordance du projet avec votre formation. Quelles sont les aptitudes qui ont été requises de vous et comment
votre formation à l’ESGI (ce cours ou d’autres) vous a aidé ou fait défaut ?
Avez-vous aimé réaliser ce projet ? Pourquoi ?</b>

Nous avons dû travailler en équipe pour faire un projet sur lequel on n'était pas tous d'accord par rapport à l'approche qu'on
avait pour le réaliser. Comme nous faisons souvent des projets en groupe à l'ESGI, c'est un gros point à noter car nous trouvions
assez rapidement des compromis/solutions.
L'aspect très "pratique" de l'ESGI nous a également aidé lorsque nous devions faire des choses plus complexes.
Nous avons en effet pris beaucoup de plaisir a faire ce projet -> le fait d'avoir un choix de sujet libre et de pouvoir passer du temps a réaliser un projet comme celui ci a la fois amusant et instructif est quelque chose de tres appréciable.


<form>
Avez vous aimez notre projet ? 
    <input type="texte" placeholder="votre avis"></input>
    <input type="button" value="GO"></input>
</form>
