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

%type<fval> expression

%left T_PLUS T_MINUS	
%left T_TIMES T_DIVIDE
%left T_SQRT
%left NEG
%right T_POWER

%start S

%%

/* Axiome : signature de la classe */
S : T_CLASS T_NAME T_IS data method T_END T_NAME T_SEMICOLON 						{printf("CLASS \n");}
  | T_CLASS T_NAME T_EXTENDS T_NAME T_IS data method T_END T_NAME T_SEMICOLON	{printf("CLASS EXTENDS \n");}
  ;

/* Emplacement data contenant les déclarations des variables */
data : T_DATA declaration  {printf("DATA ");}
     | {}
     ;

/* Déclarations des variables */
declaration : T_NAME T_IS type T_SEMICOLON declaration 	{printf("DECLARATION ");}
            | {}
            ;

/* Emplacement méthod contenant les fonctions */
method : T_METHOD fonction {printf("METHODE ");}
       | {}
       ;

/* Signatures des fonctions */
fonction : T_NAME T_PLEFT parametre T_PRIGHT T_IS corps T_SEMICOLON fonction {printf("FONCTION ");}
         | {}
         ;

/* Paramètres de la fonction */
parametre : T_NAME T_COLON type 	{printf("PARAMETRE ");}
          | {printf("NOPARAM ");}
          ;

/* Types possibles des variables */
type : T_TYPEBOOLEAN	{printf("BOOL ");}
	  | T_TYPEFLOAT 	{printf("FLOAT ");}
	  | T_TYPEINTEGER	{printf("INTEGER ");}
	  | T_NAME			{printf("NAME ");}
	  ;

/* Corps de la fonction : affectation ou retourne une expression */
corps : T_NAME T_ASSIGNMENT expression		{printf("ASSIGN ");}
		| T_PLEFT assignment T_PRIGHT  		{printf("FIN ");}
      | T_RETURN expression		 			{printf("RETURN ");}
      ;
			  
/* Affectations multiples (ex : (x,y):=(1,2) */
assignment : T_NAME T_COMMA assignment T_COMMA expression		{printf("MULTIASSIGN1 ");}
			  | T_NAME T_PRIGHT T_ASSIGNMENT T_PLEFT expression	{printf("MULTIASSIGN2 ");}
			  ;

expression : expression T_PLUS expression 			{printf("PLUS ");}
           | expression T_MINUS expression 			{printf("MOINS ");}
           | expression T_TIMES expression 			{printf("FOIS ");}
           | expression T_DIVIDE expression 			{printf("DIVISE ");}
           | T_SQRT T_PLEFT expression T_PRIGHT 	{printf("SQRT ");}
           | expression T_POWER T_INTEGER 		 	{printf("POWER ");}
           | T_PLEFT expression T_PRIGHT 			   {printf("PARENTHESE ");}
           | T_MINUS expression %prec NEG  			{printf("NEG ");}
           | T_INTEGER 										{printf("INTEGER ");}
           | T_FLOAT 										{printf("FLOAT ");}
           | T_NAME											{printf("NAME ");}
           | T_NAME T_POINT T_NAME						{printf("PARAM ");}
           ;

%%
