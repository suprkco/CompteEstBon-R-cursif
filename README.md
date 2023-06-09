# CompteEstBon-Récursif

Le code est un programme en langage C qui permet de trouver une solution mathématique pour atteindre un résultat donné en utilisant une liste de six chiffres donnée.

## Concept & fonctionement de recherche par force brute

Le concept de recherche par force brute est de tester toutes les combinaisons possibles pour trouver la solution. Dans notre cas, on teste toutes les combinaisons possibles de paires de chiffres et de toutes les opérations mathématiques (+, -, *, /) pour chaque paire de chiffres. Si l'opération est réalisable, on appelle la fonction de manière récursive avec les chiffres restants pour trouver la solution pour les chiffres restants. On stocke le résultat et la liste des opérations dans une structure. Finalement, on renvoie la liste d'opérations qui donne la meilleure solution pour atteindre le résultat donné.

## Exemple

la liste initiale est : 4 4 9 6 8 5 
et le resultat a trouver est 173
etape 1 : 9 - 4 = 5
etape 2 : 5 * 4 = 20
etape 3 : 20 + 8 = 28
etape 4 : 28 * 6 = 168
etape 5 : 168 + 5 = 173

la liste initiale est : 3 1 4 5 7 5
et le resultat a trouver est 774
etape 1 : 1 + 7 = 8
etape 2 : 5 * 7 = 35
etape 3 : 35 - 4 = 31
etape 4 : 31 * 5 = 155
etape 5 : 155 * 5 = 775

la liste initiale est : 7 7 8 3 3 3
et le resultat a trouver est 693
etape 1 : 7 + 3 = 10
etape 2 : 8 + 3 = 11
etape 3 : 11 * 7 = 77
etape 4 : 77 * 3 = 231
etape 5 : 231 * 3 = 693

## Installation

Pour compiler le programme, il faut utiliser la commande suivante:

    gcc -o compteEstBon compteEstBon.c

Pour lancer le programme, il faut utiliser la commande suivante:
    
        ./compteEstBon
