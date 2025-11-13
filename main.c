#include <stdio.h>
#include "tokens.h" 
extern int yylex();         
extern char *yytext;       
extern int majuscules_count;
int main(void) {
    int token;

    printf("Veuillez entrer du texte (terminez avec Ctrl+D) :\n");

    
    while((token = yylex())) {
        
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
                break;
            case T_INCONNU:
                printf("Token: INCONNU, Texte: '%s'\n", yytext);
                break;
            default:
                printf("Token non géré !\n");
                break;
        }
    }

    printf("\n--- Analyse terminée ---\n");
    printf("Nombre total de lettres majuscules reconnues : %d\n", majuscules_count);

    return 0;
}
