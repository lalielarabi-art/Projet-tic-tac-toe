TIC-TAC-TOE 

DESCRIPTION

Jeu du morpion (Tic-Tac-Toe) développé en C++ permettant de jouer à deux joueurs ou contre une IA.

STRUCTURE DU PROJET

Projet individuel/
├── CMakeLists.txt
├── README.md
├── main.cpp
├── Player.hpp
├── Player.cpp
├── Board.hpp
├── Board.cpp
├── Game.hpp
└── Game.cpp

PROBLEMES RENCONTRÉS ET SOLUTIONS

Le premier problème que j’ai rencontré c’est la conversion de box en ligne et colonne. Exemple : le 2 correspond à la ligne 0 et la colonne 1. J’ai cherché deux formules et j’ai trouvé en travaillant modulo 3 et avec des entiers.  
-Colonne= (box-1)%3
-Ligne=(box-1)/3

J’ai eu un problème avec le nombre de tours car je voulais 9 tours max. Au début j’ai travaillé avec une boucle if et un rang max de 9, mais le problème c’est que deux tours sont joués par itération donc je me retrouvais avec la possibilité de faire 18 tours. J’ai donc réduit le rang maximum à 4 mais je n’avais plus que 8 tours. Donc j’ai rajouté un tour de jeu du 1er joueur si personne n’avait encore gagné en dehors de la boucle.

Il a fallu trouver un moyen pour que l’IA ne joue que sur des cases vides. J’ai donc créé un tableau qui contient les cases qui sont encore disponibles. Pour cela il a fallu que je trouve une formule qui me donnait box en fonction de ligne i et colonne j. J’ai donc trouvé : box=3*i +1+j

Pour l'amélioration j'ai choisi de faire un ia capable de bloquer les coups de l'adversaire et gagné plus vite. Pour ça j'ai regardé pour chaque colonnes, lignes et diagonales si il y avait 1 case vide et 2 pions à l'ia. Si oui l'ia joue alors sur la case vide. Ensuite, j'ai regardé pour chaque colonnes, lignes et diagonales si il y avait 1 case vide et 2 pions à l'adversaire. Si oui l'ia joue alors sur la case vide. Sinon elle joue aléatoirement.

