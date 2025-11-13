#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Déclarer comme extern (ne pas définir)
extern FILE *yyin;
extern FILE *yyout;
extern int yylex();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <fichier_entree>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return 1;
    }

    yyout = fopen("sortie.txt", "w");
    if (yyout == NULL) {
        perror("Erreur lors de la création du fichier de sortie");
        fclose(yyin); 
        return 1;
    }

    printf("Analyse du fichier '%s'...\n", argv[1]);
    
    yylex(); 

    fclose(yyin);
    fclose(yyout);

    printf("Traitement terminé. Le résultat est dans 'sortie.txt'.\n");

    return 0;
}