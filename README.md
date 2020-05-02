# asteroid

![CI](https://github.com/cyrillajarge/asteroid/workflows/CI/badge.svg?branch=master)

## Pré-requis

Les librairies SDL2 et GLM sont utilisées. Elles sont normalement incluses dans le dépôt.

Le projet nécessite C++17.

## Compilation
`cmake CMakeLists.txt`
puis
`make`

L'exécutable se trouve dans le répertoire `bin`(`bin/main` par défaut).

## Fonctionnalités

Notre jeu Asteroids permet de jouer en solo ou à 2 en coopération (le tir ami est désactivé).
Les vaisseaux des deux joueurs sont identifiables par une couleur différente dans le jeu. Les informations relatives à chaque joueur sont de la même couleur que leur vaisseau.  

## Niveaux

Un **système de niveau** est également présent. La configuration des niveaux est récupéré à partir d'un fichier **levels.txt** situé dans le répertoire **config**. Initialement, 6 niveaux sont définis manuellement. Au delà de ces 6 niveaux, de nouveaux niveaux sont créé de manière automatique et incrémentale. Si des niveaux supplémentaires sont nécessaires lors d'une partie, ils seront créé en se basant sur le dernier niveau défini.     
Le fichier des niveaux doit être défini selon la manière suivante:
```
  0:5:10
  1:6:15
  ...
```
Un niveau par ligne. Le premier élément désigne le numéro du niveau, le second le nombre d'astéroïde et le troisième la vitesse des astéroïdes.

## Scores

Un tableau des scores est disponible, il est sauvegardé dans le fichier `.asteroids` qui est généré dans le répertoire `HOME` de l'utilisateur.

Les scores sont encodés en base 64 grâce aux fonctions de [René Nyffenegger](https://github.com/ReneNyffenegger/cpp-base64).

## Commandes

Les commandes par défaut sont :

|Joueur|1|2|
|:--:|:-:|:-:|
|Accélérer|Flèche haut|Z|
|Ralentir|Flèche bas|S|
|Tourner à gauche|Flèche gauche|Q|
|Tourner à droite|Flèche droite|D|
|Tirer (classique)|Espace|Shift gauche|
|Tirer (spécial)|N|Ctrl gauche|
|Changer d'arme|Shift droite|Tab|

Les mappings sont disponibles et modifiables dans le fichier `InputManager.cpp`.

## Armes

Deux armes sont disponibles actuellement : la gattling et le lance-rocket.

* Gattling : son spécial double la vitesse de tir pendant un court instant
* Lance-rocket : son spécial tire des rockets dans toutes les directions

La cadence de tir est plus faible pour l'arme **Lance-rocket** que pour l'arme **Gattling**.
Les tir spéciaux dispose d'un temps de cooldown avant de pouvoir à nouveau être utilisés. Ce temps de cooldown sont réinitialisés à chaque changement d'arme ou après chaque utilisation.


## Interfaces utilisateurs
Le jeu dispose de plusieurs intefaces utilisateurs:
* l'interface de départ
* l'interface "in-game"
* l'interface de fin de partie

Un certain nombre de composants sont disponibles afin de constituer ces interfaces. Nous avons implémenté 4 composants réparti dans deux catégories:
* Élément clickable:
  * Le bouton
  * La checkbox
* Élément non-clickable:
  * La textbox
  * Le textinput
  
Sur **l'inteface de départ** il est possible de sélectionner le mode de jeu à l'aide d'une checkbox ainsi que de définir un gamertag ou un nom d'équipe à l'aide d'un textinput. Il y a également un bouton pour commencer à jouer.   
Dans **l'interface "in-game"** sont affichés le gamertag/nom d'équipe, le score pour les deux joueurs, l'arme actuelle des joueurs, l'arme actuelle des joueurs et leurs temps cooldown.  
Dans l'interface de fin de partie sont affichés le score final ainsi que le niveau atteint. Le ou les joueur(s) ont la possibilité de refaire directement une partie. Il y a également un bouton permettant d'afficher un tableau des scores.
