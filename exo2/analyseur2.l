/* Fichier: analyseur2.l */
%{
#include <string.h> 
#include "token2.h" 
%}

/* Options pour Flex */
%option noyywrap

LETTRE      [a-zA-Z]
CHIFFRE     [0-9]


MOT         {LETTRE}({LETTRE}|{CHIFFRE})*
NOMBRE      {CHIFFRE}+

%%

{MOT}       { 
                return T_MOT; 
            }

{NOMBRE}    { 
                return T_NOMBRE; 
            }

[ \t\n]+    { 
            
            }

.           { 
                return T_INCONNU; 
            }

%%
