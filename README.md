#  Welcome to Project TankBattleWar!

Project TankBattleWar is a game inspired by " Word of Tanks". 

# Unreal Engine

The TankBattleWar project is created in Unreal Engine in the version 5.1.0. 

# Correction

Barème :

2/4 - Refactorisation du Tank
3/3 - Explication ancienne / nouvelle architecture (diagramme)
1/1 - Projet sur Github
2/3 - Nommage fonction et variable
0/1 - Nommage Commit / Branche
3/3 - Code fonctionnel
1/2 - Sécurité
0/2 - Commentaires
1/1 - ReadMe (en page d'accueil Github)

13/20

Global :

Nom du projet -> c'est pas lisible et sujet à confusion
Classe Tank -> Présence des forward declaration (inutile), présence du BeginPlay() (inutile), présence d'include non nécessaires (inutile), présence de la classe ATank dans d'autres classe (inutile)
Diagramme introuvable dans UE -> il faut vérifier qu'il est affichable dans le projet, il se trouve trop "haut" dans la hiérachie (tu as les 3 points quand même)
Forward declaration -> mauvaise déclaration + inutilité de certaines
Indendation à revoir (pas agréable à lire)

Relativement incomplet, avec un peu de rigueur, ce serait vraiment bien

