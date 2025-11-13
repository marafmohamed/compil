%{
/*
 * Section 1 : Définitions et Code C
 */
#include <stdio.h>
#include "tokens.h" // On inclut notre fichier d'en-tête pour avoir accès aux définitions des tokens.

// La variable pour le compteur est toujours ici.
// Elle sera accessible depuis main.c grâce au mot-clé "extern".
int majuscules_count = 0;
%}

/* Options Flex */
%option noyywrap

/* 
 * Section 2 : Règles de l'analyseur
 * Chaque action retourne maintenant une valeur correspondant au token reconnu.
 */
%%

[A-Z]       { 
                majuscules_count++; 
                return T_MAJUSCULE; /* On retourne le type du token */
            }

[a-z]       {
                return T_MINUSCULE;
            }

[0-9]+      {
                return T_NOMBRE;
            }

[ \t]+      { 
                return T_ESPACE; /* On peut choisir d'ignorer ou de retourner un token pour les espaces */
            }

\n          {
                return T_SAUT_LIGNE;
            }

.           {
                return T_INCONNU; /* Pour tout autre caractère */
            }

%%
