# asteroid

## Pré-requis

Les librairies SDL2 et GLM sont utilisées. Elles sont normalement incluses dans le dépôt.

## Compilation
`cmake CMakeLists.txt`
puis
`make`

L'exécutable se trouve dans le répertoire `bin`(`bin/main` par défaut).

## Fonctionnalités

Notre jeu Asteroids permet de jouer en solo ou à 2 en coopération (le tir ami est désactivé).
Un tableau des scores est disponible, il est sauvegardé dans le fichier `.hemoroids` qui est généré dans le répertoire `HOME` de l'utilisateur.

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

