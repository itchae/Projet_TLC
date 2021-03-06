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

  vector<Instruction*> insts;

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

  /**
   * methode erreur, affiche le message d'erreur et ferme le programme
   */
  void yyerror(const char* msg){
  	cerr << "ERROR : " << msg << endl;
    exit (EXIT_FAILURE);
  }

  /**
   * transforme un char* en string
   */
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
    Decl* decl;
};

%token<sval> T_NAME
%token<ival> T_INTEGER
%token<fval> T_FLOAT
%token<bval> T_BOOLEAN
%token T_TYPEFLOAT T_TYPEBOOLEAN T_TYPEINTEGER
%token T_PLUS T_MINUS T_TIMES T_DIVIDE T_POWER T_SQRT
%token T_INF T_SUP T_INFEG T_SUPEG
%token T_PLEFT T_PRIGHT T_COMMA T_POINT T_COLON T_SEMICOLON T_ASSIGNMENT
%token T_CLASS T_EXTENDS T_DATA T_IS T_METHOD T_RETURN T_END

%type<exp> expression
%type<data> data
%type<meth> method
%type<inst> instruction
%type<sval> type
%type<cl> classe

%left T_PLUS T_MINUS
%left T_TIMES T_DIVIDE
%left T_SQRT
%left NEG
%right T_POWER

%start axiome

%%

axiome : bloc               {Bloc* b = new Bloc(insts); b->visit(interpretor); delete b;}
       |                    {}
       ;

bloc   :  instruction T_SEMICOLON bloc  {insts.insert(insts.begin(),$1);}
       |                                {}
       ;

/* Definit les instructions possibles */
instruction : call T_ASSIGNMENT expression		                  {$$ = new Affect(vars,$3); vars.clear(); exprs.clear();}
	  	      | T_PLEFT assignment T_PRIGHT 			                {$$ = new Affect(vars,exprs);
                                                                  vars.clear();
                                                                  exprs.clear();}
           | T_NAME T_IS type                                   {$$ = new Decl(toString($1),toString($3));}
           | call                                               {$$ = new Call(vars,exprs); exprs.clear(); vars.clear();}
           | classe                                             {$$ = new DeclClass($1);}
           ;

/**
* renvoie la variable ou methode utilisee
*/
call  : T_NAME T_PLEFT paramUtil T_PRIGHT   { vars.insert(vars.begin(),toString($1)); }
      | T_NAME T_PLEFT T_PRIGHT             { vars.insert(vars.begin(),toString($1)); }
      | T_NAME T_POINT call                 { vars.insert(vars.begin(),toString($1)); }
      | T_NAME                              { vars.insert(vars.begin(),toString($1)); }
      ;

/**
* parametres pour utiliser une methode, exemple : fonction(1,h) les parametres sont 1 et h
*/
paramUtil : expression T_COMMA paramUtil             {exprs.insert(exprs.begin(),$1);}
          | expression                               {exprs.insert(exprs.begin(),$1);}
          ;

/* signature de la classe */
classe : T_CLASS T_NAME T_IS data method T_END T_NAME 										            { if (toString($2).compare(toString($7))!=0) yyerror("nom de debut et de fin de classe non identitiques");
                                                                                        $$ = new Class(toString($2),$4,$5);}
	  	 | T_CLASS T_NAME T_EXTENDS T_NAME T_IS data method T_END T_NAME		            { if (toString($2).compare(toString($9))!=0) yyerror("nom de debut et de fin de classe non identitiques");
                                                                                        if (toString($2).compare(toString($4))==0) yyerror("classe mere identique a la classe");
                                                                                        $$ = new Class(toString($4),toString($2),$6,$7);}
	  	;

/* Emplacement data contenant les déclarations des variables */
data : T_DATA declaration  								{$$ = new Data(params); params.clear();}
     | 																		{$$ = new Data(params); params.clear();}
     ;

/* Déclarations des variables */
declaration : T_NAME T_IS type T_SEMICOLON declaration 	  {Decl* d = new Decl(toString($1),toString($3)); params.insert(params.begin(),d);}
            | 																					  {}
            ;

/* Emplacement méthod contenant les fonctions */
method : T_METHOD fonction 								{$$ = new Method(fonctions); fonctions.clear();}
       | 																	{$$ = new Method(fonctions); fonctions.clear();}
       ;

/* Signatures des fonctions */
fonction : T_NAME T_PLEFT parametre T_PRIGHT T_IS instruction T_SEMICOLON fonction 	          {VoidFonction* v = new VoidFonction(toString($1),params,$6);
                                                                                                params.clear();
                                                                                                fonctions.insert(fonctions.begin(),v); }
         | T_NAME T_PLEFT parametre T_PRIGHT T_IS T_RETURN expression T_SEMICOLON fonction    {ReturnFonction* r = new ReturnFonction(toString($1),params,$7);
                                                                                                params.clear();
                                                                                                fonctions.insert(fonctions.begin(),r);}
         |                                                                                    {}
         ;

/* Paramètres de la fonction */
parametre : T_NAME T_COLON type T_COMMA parametre 		{ Decl* d = new Decl(toString($1),toString($3));
                                                          params.insert(params.begin(),d);}
		  		| T_NAME T_COLON type  											{ Decl* d = new Decl(toString($1),toString($3));
                                                          params.insert(params.begin(),d);}
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

/* Affectations multiples (ex : (x,y):=(1,2) */
assignment : T_NAME T_COMMA assignment T_COMMA expression						{vars.insert(vars.begin(),toString($1));
                                                                      exprs.push_back($5);}
		   		 | T_NAME T_PRIGHT T_ASSIGNMENT T_PLEFT expression				{vars.insert(vars.begin(),toString($1));
                                                                       exprs.push_back($5);}
		   		 ;

/**
 * definit une expression, par exemple : 45+6 est une expression
 */
expression : expression T_PLUS expression 				                   {$$ = new Operator(PLUS,$1,$3);}
           | expression T_MINUS expression 				                   {$$ = new Operator(MOINS,$1,$3);}
           | expression T_TIMES expression 				                   {$$ = new Operator(MULT,$1,$3);}
           | expression T_DIVIDE expression 			                   {$$ = new Operator(DIV,$1,$3);}
           | expression T_SUP expression                             {$$ = new Operator(SUP,$1,$3);}
           | expression T_SUPEG expression                           {$$ = new Operator(SUPEG,$1,$3);}
           | expression T_INF expression                             {$$ = new Operator(INF,$1,$3);}
           | expression T_INFEG expression                           {$$ = new Operator(INFEG,$1,$3);}
           | T_SQRT T_PLEFT expression T_PRIGHT 	                   {$$ = new Operator(SQRT,$3);}
           | expression T_POWER T_INTEGER 		 		                   {$$ = $1;}
           | T_PLEFT expression T_PRIGHT 			   	                   {$$ = $2;}
           | T_MINUS expression %prec NEG  				                   {$$ = new Operator(NEGA,$2);}
           | T_INTEGER 														                   {$$ = new Integer($1);}
           | T_FLOAT 															                   {$$ = new Float($1);}
		   		 | T_BOOLEAN													                     {$$ = new Boolean($1);}
           | callExp                                                 {Variable* v = symbol.findVar(vars);
                                                                       if (v==NULL){
                                                                         yyerror("variable inexistante");
                                                                       }else{
                                                                        $$=v;
                                                                       }}
           ;

/**
 * renvoie la variable ou le resultat de la ReturnFonction
 */
callExp  : T_NAME T_PLEFT paramUtil T_PRIGHT { vars.insert(vars.begin(),toString($1));
                                               Expression* exp = symbol.resultOfReturnFonction(vars, exprs);
                                               if (exp==NULL){
                                                 yyerror("methode inexistante");
                                               }
                                               exprs.clear(); vars.clear();}
      | T_NAME                              {vars.insert(vars.begin(),toString($1));

                                               exprs.clear(); vars.clear();}
      | T_NAME T_POINT callExp             {vars.insert(vars.begin(),$1);}
      ;

%%
