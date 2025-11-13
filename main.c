// main.c
#include <stdio.h>
#include "tokens.h" 
extern int yylex();         // La fonction de l'analyseur générée par Flex
extern char *yytext;        // Le texte du token reconnu
extern int majuscules_count; // Notre compteur défini dans analyseur.l

int main(void) {
    // Variable pour stocker le token retourné par yylex()
    int token;

    printf("Veuillez entrer du texte (terminez avec Ctrl+D) :\n");

    // Boucle qui appelle yylex() jusqu'à la fin de l'entrée.
    // yylex() retourne 0 quand il n'y a plus rien à analyser.
    while((token = yylex())) {
        
        // On utilise un switch pour agir en fonction du token reçu
        switch(token) {
            case T_MAJUSCULE:
                printf("Token: MAJUSCULE, Texte: '%s'\n", yytext);
                break;
            case T_MINUSCULE:
                printf("Token: MINUSCULE, Texte: '%s'\n", yytext);
                break;
            case T_NOMBRE:
                printf("Token: NOMBRE, Texte: '%s'\n", yytext);
                break;
            case T_SAUT_LIGNE:
                printf("-> Saut de ligne\n");
                break;
            case T_ESPACE:
                // On choisit de ne rien afficher pour les espaces pour garder la sortie propre
                break;
            case T_INCONNU:
                printf("Token: INCONNU, Texte: '%s'\n", yytext);
                break;
            default:
                printf("Token non géré !\n");
                break;
        }
    }

    // Affichage final après la fin de la boucle
    printf("\n--- Analyse terminée ---\n");
    printf("Nombre total de lettres majuscules reconnues : %d\n", majuscules_count);

    return 0;
}