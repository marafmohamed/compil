
#include <stdio.h>
#include "tokens.h" 

extern int yylex();
extern char *yytext;

int main() {
    int jeton;

    printf("Analyseur Lexical - Exercice 3\n");
    printf("Entrez votre texte (terminez avec Ctrl+D sur une ligne vide) :\n");
    printf("=============================================================\n");

    while((jeton = yylex())) {
        
        switch(jeton) {
            case T_LANG_L:
                printf("  [Langage L]   -> '%s'\n", yytext);
                break;

            case T_MOT_DE_PASSE:
                printf("  [Mot de Passe]-> '%s'\n", yytext);
                break;
                
            case T_IDENTIFICATEUR:
                printf("  [Identif.]    -> '%s'\n", yytext);
                break;

            case T_INCONNU:
                printf("  [Inconnu]     -> '%s'\n", yytext);
                break;
        }
    }

    printf("=============================================================\n");
    printf("Analyse terminée.\n");

    return 0;
}