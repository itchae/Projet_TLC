%{
  #include <iostream>
  #include "stdio.h"
  #include <stdlib.h>
  #include <vector>
  #include <string>
  #include <string.h>
  #include "structure/headers/vivacite.hh"

  using namespace std;

  extern int yylex();

  vector<string> vars;

  vector<Decl*> params;

  /**
   * vector d'expressions utilisées pour les affectations multiples
   */
  vector<Expression*> exprs;

  /**
   * fonctions declarees dans un emplacement method
   */
  vector<Fonction*> fonctions;

  /**
   * table des symboles
   */
  SymbolTable& symbol = SymbolTable::Instance();

  /**
   * interpretateur des instructions du langage
   */
  Interpretor interpretor;

  void yyerror(const char* msg){
  	cerr << "ERROR : " << msg << endl;
    exit (EXIT_FAILURE);
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
		Instruction* inst;
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
%type<data> data
%type<meth> method
%type<fonc> fonction
%type<inst> instruction corps
%type<sval> type

%left T_PLUS T_MINUS
%left T_TIMES T_DIVIDE
%left T_SQRT
%left NEG
%right T_POWER

%start axiome

%%

axiome : classe axiome                        {/*Classe* c = $1; c->visit(interpretor); delete c;*/}
       | instruction T_SEMICOLON axiome       {Instruction* i = $1; i->visit(interpretor); delete i;}
       |                                      {}
       ;

/* Definit les instructions possibles */
instruction : T_NAME T_ASSIGNMENT expression		                {$$ = new Affect(toString($1),$3);}
	  	      | T_PLEFT assignment T_PRIGHT 			                {$$ = new Affect(vars,exprs);
                                                                  vars.clear();
                                                                  exprs.clear();}
           | T_NAME T_IS type                                   {$$ = new Decl(toString($1),toString($3));}
           | T_NAME T_POINT T_NAME T_PLEFT paramUtil T_PRIGHT   {$$ = new Call(toString($1),toString($3),exprs); exprs.clear();}
           ;

/**
* parametres pour utiliser une methode, exemple : fonction(1,h) les parametres sont 1 et h
*/
paramUtil : expression T_COMMA paramUtil             {exprs.push_back($1);}
          | expression                               {exprs.push_back($1);}
          ;

/* signature de la classe */
classe : T_CLASS T_NAME T_IS data method T_END T_NAME T_SEMICOLON 										{ if (toString($2).compare(toString($7))!=0) yyerror("nom de debut et de fin de classe non identitiques");
                                                                                      Class* c = new Class(toString($2),$4,$5);
                                                                                      symbol.addClass(c);}
	  	 | T_CLASS T_NAME T_EXTENDS T_NAME T_IS data method T_END T_NAME T_SEMICOLON		{ if (toString($2).compare(toString($9))!=0) yyerror("nom de debut et de fin de classe non identitiques");
                                                                                      Class* mere = symbol.findClass($4);
                                                                                      Class* c = new Class(mere,toString($2),$6,$7);
                                                                                      symbol.addClass(c);}
	  	;

/* Emplacement data contenant les déclarations des variables */
data : T_DATA declaration  								{$$ = new Data(params); params.clear();}
     | 																		{$$ = new Data(params); params.clear();}
     ;

/* Déclarations des variables */
declaration : T_NAME T_IS type T_SEMICOLON declaration 	  {Decl* d = new Decl(toString($1),toString($3)); params.push_back(d);}
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
          | 																					  {}
          ;

/* Types possibles des variables */
type : T_TYPEBOOLEAN														{string str = "boolean";
                                                    char *cstr = new char[str.length() + 1];
                                                    strcpy(cstr, str.c_str());
                                                    $$ = cstr;}
	 	 | T_TYPEFLOAT 															{string str = "float";
                                                   char *cstr = new char[str.length() + 1];
                                                   strcpy(cstr, str.c_str());
                                                   $$ = cstr;}
	 	 | T_TYPEINTEGER														{string str = "integer";
                                                   char *cstr = new char[str.length() + 1];
                                                   strcpy(cstr, str.c_str());
                                                   $$ = cstr;}
	 	 | T_NAME																		{$$ = $1;}
 	   ;

/* Corps de la fonction : affectation ou retourne une expression */
corps : instruction                             {$$ = $1;}
      | T_RETURN expression		 									{$$ = new Return($2);}
      ;

/* Affectations multiples (ex : (x,y):=(1,2) */
assignment : T_NAME T_COMMA assignment T_COMMA expression						{vars.push_back(toString($1));
                                                                      exprs.insert(exprs.begin(),$5);}
		   		 | T_NAME T_PRIGHT T_ASSIGNMENT T_PLEFT expression				{vars.push_back(toString($1));
                                                                      exprs.insert(exprs.begin(),$5);}
		   		 ;

/**
 * definit une expression, par exemple : 45+6 est une expression
 */
expression : expression T_PLUS expression 				                   {$$ = new Operator(PLUS,$1,$3);}
           | expression T_MINUS expression 				                   {$$ = new Operator(MOINS,$1,$3);}
           | expression T_TIMES expression 				                   {$$ = new Operator(MULT,$1,$3);}
           | expression T_DIVIDE expression 			                   {$$ = new Operator(DIV,$1,$3);}
           | T_SQRT T_PLEFT expression T_PRIGHT 	                   {$$ = $3;}
           | expression T_POWER T_INTEGER 		 		                   {$$ = $1;}
           | T_PLEFT expression T_PRIGHT 			   	                   {$$ = $2;}
           | T_MINUS expression %prec NEG  				                   {$$ = $2;}
           | T_INTEGER 														                   {$$ = new Integer($1);}
           | T_FLOAT 															                   {$$ = new Float($1);}
		   		 | T_BOOLEAN													                     {$$ = new Boolean($1);}
           | T_NAME T_POINT T_NAME T_PLEFT paramUtil T_PRIGHT        {$$ = symbol.findResultOfMethodOfClass($1,$3,exprs);
                                                                      exprs.clear();}
           | T_NAME                                                  {Affect *a = symbol.findAffect($1);
                                                                      if (a==NULL) yyerror("valeur de variable non trouvee");
                                                                      $$ = a->getExprs()[0];}
           ;

%%
