#include <stdio.h>
#include <string.h>     
#include "token2.h"    

extern int yylex();     
extern char *yytext;    

int main() {
    int jeton; 

    printf("Veuillez entrer une chaîne de caractères à analyser.\n");
    printf("Appuyez sur Ctrl+D sur une nouvelle ligne pour terminer.\n");
    printf("------------------------------------------------------\n");


    while((jeton = yylex())) {
        
        switch(jeton) {
            case T_MOT:
                printf("-> Mot reconnu          : '%s' (taille: %zu)\n", yytext, strlen(yytext));
                break;

            case T_NOMBRE:
                printf("-> Nombre reconnu        : '%s' (taille: %zu)\n", yytext, strlen(yytext));
                break;

            case T_INCONNU:
                printf("-> Caractère indésirable : '%s' (taille: %zu)\n", yytext, strlen(yytext));
                break;
            
            default:
                printf("Jeton non reconnu !\n");
                break;
        }
    }

    printf("------------------------------------------------------\n");
    printf("Analyse terminée.\n");

    return 0;
}