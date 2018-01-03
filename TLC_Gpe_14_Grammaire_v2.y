%{
#include <iostream>
#include "stdio.h"
#include <vector>
#include "vivacite.hh"

extern int yylex();

vector<Decl*> params;

void yyerror(const char* msg){
	std::cerr << "ERROR : " << msg << std::endl;
}

%}

%union {
    int ival;
    bool bval;
    float fval;
    char* sval;
	Instruction*  term;
	Expression* exp;
	Sequence* seq;
	Class* class;
	Method* meth;
	Data* data;
	Type* type;
	vector<Decl*> params;
	Fonction* fonc;
};

%token<sval> T_NAME 
%token<ival> T_INTEGER 
%token<fval> T_FLOAT 
%token<bval> T_BOOLEAN 
%token T_TYPEFLOAT T_TYPEBOOLEAN T_TYPEINTEGER 
%token T_PLUS T_MINUS T_TIMES T_DIVIDE T_POWER T_SQRT
%token T_PLEFT T_PRIGHT T_COMMA T_POINT T_COLON T_SEMICOLON T_ASSIGNMENT
%token T_CLASS T_EXTENDS T_DATA T_IS T_METHOD T_RETURN T_END

%type<exp> expression
%type<term> corps
%type<class> class
%type<type> type
%type<data> data
%type<meth> method
%type<params> parametre
%type<fonc> fonction

%left T_PLUS T_MINUS	
%left T_TIMES T_DIVIDE
%left T_SQRT
%left NEG
%right T_POWER

%start class

%%

/* Axiome : signature de la classe */
class : T_CLASS T_NAME T_IS data method T_END T_NAME T_SEMICOLON 						{$$ = new Class($2,$4,$5);}
	  | T_CLASS T_NAME T_EXTENDS T_NAME T_IS data method T_END T_NAME T_SEMICOLON		{printf("CLASS EXTENDS \n");}
	  ;

/* Emplacement data contenant les déclarations des variables */
data : T_DATA declaration  								{printf("DATA ");}
     | 													{}
     ;

/* Déclarations des variables */
declaration : T_NAME T_IS type T_SEMICOLON declaration 	{printf("DECLARATION ");}
            | 											{}
            ;

/* Emplacement méthod contenant les fonctions */
method : T_METHOD fonction 								{printf("METHODE ");}
       | 												{}
       ;

/* Signatures des fonctions */
fonction : T_NAME T_PLEFT parametre T_PRIGHT T_IS corps T_SEMICOLON fonction 		{$$ = new Fonction($1,$3,$6);}
         | 																			{}
         ;

/* Paramètres de la fonction */
parametre : T_NAME T_COLON type T_COMMA parametre 		{params.push_back(new Decl($1,$3);
															$$ = params;}
		  | T_NAME T_COLON type  						{params.push_back(new Decl($1,$3);
															$$ = params;}
          | 											{$$ = params;}
          ;

/* Types possibles des variables */
type : T_TYPEBOOLEAN									{$$ = BOOLEAN;}
	 | T_TYPEFLOAT 										{$$ = FLOAT;}
	 | T_TYPEINTEGER									{$$ = INTEGER;}
	 | T_NAME											{$$ = $1;}
	 ;

/* Corps de la fonction : affectation ou retourne une expression */
corps : T_NAME T_ASSIGNMENT expression					{$$ = new Affect(*$1,$3);}
	  | T_PLEFT assignment T_PRIGHT  					{printf("FIN ");}
      | T_RETURN expression		 						{printf("RETURN ");}
      ;
			  
/* Affectations multiples (ex : (x,y):=(1,2) */
assignment : T_NAME T_COMMA assignment T_COMMA expression							{printf("MULTIASSIGN1 ");}
		   | T_NAME T_PRIGHT T_ASSIGNMENT T_PLEFT expression						{printf("MULTIASSIGN2 ");}
		   ;

expression : expression T_PLUS expression 				{$$ = new Operator(PLUS,$1,$3);}
           | expression T_MINUS expression 				{$$ = new Operator(MOINS,$1,$3);}
           | expression T_TIMES expression 				{$$ = new Operator(MULT,$1,$3);}
           | expression T_DIVIDE expression 			{$$ = new Operator(DIV,$1,$3);}
           | T_SQRT T_PLEFT expression T_PRIGHT 		{$$ = sqrt($1,$3);}
           | expression T_POWER T_INTEGER 		 		{$$ = powI($1,$3);}
           | T_PLEFT expression T_PRIGHT 			   	{$$ = $2;;}
           | T_MINUS expression %prec NEG  				{$$ = -$1;}
           | T_INTEGER 									{$$ = $1;}
           | T_FLOAT 									{$$ = $1;}
           | T_NAME										{$$ = new Decl(*$1);}
		   | T_BOOLEAN									{$$ = $1;}
           | T_NAME T_POINT T_NAME						{printf("PARAM ");}
           ;

%%
