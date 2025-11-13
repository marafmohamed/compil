/* FICHIER NUMÉRO 1 : enregistre-le sous le nom analyseur.l */
%{
#include <stdio.h>

extern FILE *yyin;
extern FILE *yyout;
%}

%option noyywrap

%%
"2CS"           { yymore(); }
"SIL"           { fprintf(yyout, "1CS"); }
"SIQ"           { fprintf(yyout, "1CS"); }
\n              { ECHO; }
.               { ECHO; }
%%

