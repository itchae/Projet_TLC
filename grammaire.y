%{
#include <iostream>
#include "stdio.h"

extern int yylex();

void yyerror(const char* msg){
	std::cerr << "ERROR : " << msg << std::endl;
}

int powI(int x, int y){
	int res=x;
	for (int i=0; i<y-1; i++){
		res *= x;
	}
	return res;
}		

%}

%union {
    int ival;
    float fval;
    char* sval;
};

%type<p> expr CNUM
%type<s> ID

%token T_NAME T_INTEGER T_FLOAT T_BOOLEAN 
%token T_TYPEFLOAT T_TYPEBOOLEAN T_TYPEINTEGER 
%token T_PLUS T_MINUS T_TIMES T_DIVIDE T_POWER T_SQRT
%token T_PLEFT T_PRIGHT T_COMMA T_POINT T_COLON T_SEMICOLON T_ASSIGNMENT
%token T_CLASS T_EXTENDS T_DATA T_IS T_METHOD T_RETURN T_END

%left T_PLUS T_MINUS	
%left T_TIMES T_DIVIDE
%right T_POWER T_SQRT

%start S

%%

S : T_CLASS T_NAME T_IS data method T_END T_NAME T_SEMICOLON

/* Emplacement data contenant les déclarations des variables */
data : T_DATA declaration  
     |
     ;

/* Déclarations des variables */
declaration : T_NAME T_IS T_INTEGER T_SEMICOLON declaration
            | T_NAME T_IS T_FLOAT T_SEMICOLON declaration
            | T_NAME T_IS T_BOOLEAN T_SEMICOLON declaration
            |
            ;

/* Emplacement méthod contenant les fonctions */
method : T_METHOD fonction
       |
       ;

fonction : T_NAME T_PLEFT parametre T_PRIGHT T_IS T_RETURN corps T_SEMICOLON fonction
         |
         ;

/* Paramètres de la fonction */
parametre : T_NAME T_COLON T_FLOAT
          | T_NAME T_COLON T_INTEGER
          | T_NAME T_COLON T_BOOLEAN
          |
          ;

corps : /* TODO */

%%
