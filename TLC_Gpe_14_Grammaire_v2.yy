%{
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include "structure/headers/vivacite.hh"

using namespace std;

extern int yylex();

/**
 * parametres d'une methode
 */
vector<Decl*> params;

/**
 * fonctions declarees dans un emplacement method
 */
vector<Fonction*> fonctions;

/**
 * table des symboles
 */
SymbolTable& symbol = SymbolTable::Instance();

void yyerror(const char* msg){
	std::cerr << "ERROR : " << msg << std::endl;
}

string toString(char* msg){
  string res(msg);
  return res;
}

%}

%union {
    int ival;
    bool bval;
    float fval;
    char* sval;
		Instruction* term;
		Expression* exp;
		Class* cl;
		Method* meth;
		Data* data;
		Fonction* fonc;
    Decl* decl;
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
%type<data> data
%type<meth> method
%type<fonc> fonction
/*%type<cl> type*/
%type<decl> declaration

%left T_PLUS T_MINUS
%left T_TIMES T_DIVIDE
%left T_SQRT
%left NEG
%right T_POWER

%start classe

%%

/* Axiome : signature de la classe */
classe : T_CLASS T_NAME T_IS data method T_END T_NAME T_SEMICOLON 										{ Class* c = new Class(toString($2),$4,$5);
                                                                                      symbol.addClass(c);}
	  	 | T_CLASS T_NAME T_EXTENDS T_NAME T_IS data method T_END T_NAME T_SEMICOLON		{ Class* mere = symbol.findClass($4);
                                                                                      Class* c = new Class(mere,toString($2),$6,$7);
                                                                                      symbol.addClass(c);}
	  	;

/* Emplacement data contenant les déclarations des variables */
data : T_DATA declaration  								{$$ = new Data(params);}
     | 																		{$$ = new Data(params);}
     ;

/* Déclarations des variables */
declaration : T_NAME T_IS T_NAME T_SEMICOLON declaration 	{$$ = new Decl(toString($1),toString($3));}
            | 																					  {}
            ;

/* Emplacement méthod contenant les fonctions */
method : T_METHOD fonction 								{$$ = new Method(fonctions);}
       | 																	{}
       ;

/* Signatures des fonctions */
fonction : T_NAME T_PLEFT parametre T_PRIGHT T_IS corps T_SEMICOLON fonction 		{$$ = new Fonction(toString($1),params,$6);}
         | 																																			{}
         ;

/* Paramètres de la fonction */
parametre : T_NAME T_COLON T_NAME T_COMMA parametre 		{ Decl* d = new Decl(toString($1),toString($3));
                                                        params.push_back(d);}
		  		| T_NAME T_COLON T_NAME  											{ Decl* d = new Decl(toString($1),toString($3));
                                                        params.push_back(d);}
          | 																					{}
          ;

/* Types possibles des variables */
/*type : T_TYPEBOOLEAN														{$$ = new Class("c",NULL,NULL);}
	 	 | T_TYPEFLOAT 															{$$ = new Class("c",NULL,NULL);}
	 	 | T_TYPEINTEGER														{$$ = new Class("c",NULL,NULL);}
	 	 | T_NAME																		{$$ = new Class("c",NULL,NULL);}
	 	 ;*/

/* Corps de la fonction : affectation ou retourne une expression */
corps : T_NAME T_ASSIGNMENT expression					{$$ = new Affect(symbol.findDecl(toString($1)),$3);}
	  	| T_PLEFT assignment T_PRIGHT  						{printf("FIN ");}
      | T_RETURN expression		 									{printf("RETURN ");}
      ;

/* Affectations multiples (ex : (x,y):=(1,2) */
assignment : T_NAME T_COMMA assignment T_COMMA expression						{printf("MULTIASSIGN1 ");}
		   		 | T_NAME T_PRIGHT T_ASSIGNMENT T_PLEFT expression				{printf("MULTIASSIGN2 ");}
		   		 ;

expression : expression T_PLUS expression 				{$$ = new Operator(PLUS,$1,$3);}
           | expression T_MINUS expression 				{$$ = new Operator(MOINS,$1,$3);}
           | expression T_TIMES expression 				{$$ = new Operator(MULT,$1,$3);}
           | expression T_DIVIDE expression 			{$$ = new Operator(DIV,$1,$3);}
           | T_SQRT T_PLEFT expression T_PRIGHT 	{$$ = $3;}
           | expression T_POWER T_INTEGER 		 		{$$ = $1;}
           | T_PLEFT expression T_PRIGHT 			   	{$$ = $2;;}
           | T_MINUS expression %prec NEG  				{$$ = $2;}
           | T_INTEGER 														{$$ = new Integer($1);}
           | T_FLOAT 															{$$ = new Float($1);}
           /*| T_NAME																{$$ = symbol.findAffect($1)->getExprs();}*/
		   		 | T_BOOLEAN														{$$ = new Boolean($1);}
           | T_NAME T_POINT T_NAME								{printf("PARAM ");}
           ;

%%
