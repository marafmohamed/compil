// Fichier: tokens2.h
#ifndef TOKENS2_H
#define TOKENS2_H

/* 
 * On utilise une énumération pour donner des noms clairs
 * aux types de jetons que yylex() va retourner.
 */
enum {
    T_MOT = 1,    
    T_NOMBRE,      
    T_INCONNU       
};

#endif 