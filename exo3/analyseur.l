%{
#include "tokens.h"
%}

/* Options pour Flex */
%option noyywrap

%%

"%"[abc]+"%"          { 
                        return T_LANG_L;
                      }

[a-zA-Z0-9]{8}        { 
                        return T_MOT_DE_PASSE;
                      }

[a-zA-Z][a-zA-Z0-9]*  { 
                        return T_IDENTIFICATEUR;
                      }

[ \t\n]+              { 

                      }

.                     { 
                        return T_INCONNU;
                      }
%%
