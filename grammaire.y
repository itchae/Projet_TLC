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
    bool bval;
    float fval;
    char* sval;
};

%token<sval> T_NAME 
%token<ival> T_INTEGER 
%token<fval> T_FLOAT 
%token<bval> T_BOOLEAN 
%token T_TYPEFLOAT T_TYPEBOOLEAN T_TYPEINTEGER 
%token T_PLUS T_MINUS T_TIMES T_DIVIDE T_POWER T_SQRT
%token T_PLEFT T_PRIGHT T_COMMA T_POINT T_COLON T_SEMICOLON T_ASSIGNMENT
%token T_CLASS T_EXTENDS T_DATA T_IS T_METHOD T_RETURN T_END

%type<fval> operation

%left T_PLUS T_MINUS	
%left T_TIMES T_DIVIDE
%left T_SQRT
%left NEG
%right T_POWER

%start S

%%

S : T_CLASS T_NAME T_IS data method T_END T_NAME T_SEMICOLON {}
  | T_CLASS T_NAME T_EXTENDS T_NAME T_IS data method T_END T_NAME T_SEMICOLON {}
  ;

/* Emplacement data contenant les déclarations des variables */
data : T_DATA declaration  {}
     | {}
     ;

/* Déclarations des variables */
declaration : T_NAME T_IS T_TYPEINTEGER T_SEMICOLON declaration {}
            | T_NAME T_IS T_TYPEFLOAT T_SEMICOLON declaration {}
            | T_NAME T_IS T_TYPEBOOLEAN T_SEMICOLON declaration {}
            | {}
            ;

/* Emplacement méthod contenant les fonctions */
method : T_METHOD fonction {}
       | {}
       ;

fonction : T_NAME T_PLEFT parametre T_PRIGHT T_IS T_RETURN corps T_SEMICOLON fonction {}
         | {}
         ;

/* Paramètres de la fonction */
parametre : T_NAME T_COLON T_FLOAT {}
          | T_NAME T_COLON T_INTEGER {}
          | T_NAME T_COLON T_BOOLEAN {}
          | {}
          ;

corps : T_NAME T_ASSIGNMENT operation {}
      | T_NAME T_ASSIGNMENT T_BOOLEAN {}
      ;

operation : operation T_PLUS operation 			{$$ = $1 + $3;}
          | operation T_MINUS operation 		{$$ = $1 - $3;}
          | operation T_TIMES operation 		{$$ = $1 * $3;}
          | operation T_DIVIDE operation 		{$$ = $1 / $3;}
          | T_SQRT T_PLEFT operation T_PRIGHT 	{}
          | operation T_POWER T_INTEGER 		{$$ = powI($1,$3);}
          | T_PLEFT operation T_PRIGHT 			{$$ = $2;}
          | T_MINUS operation %prec NEG  		{$$=-$2;}
          | T_INTEGER 							{$$ = $1;}
          | T_FLOAT 							{$$ = $1;}
          ;

%%

int main(){
	return yyparse ();
}
