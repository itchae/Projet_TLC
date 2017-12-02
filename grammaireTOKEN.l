%{
#include <stdio.h>
#include <stdlib.h>

%}




%%

<<<<<<< HEAD:grammaireTOKEN.l
[+-]?[0-9]+			{yylval.ival = atoi(yytext); return T_INTEGER;}
[+-]?[0-9]+\.[0-9]+ {yylval.fval = atof(yytext); return T_FLOAT;}
"true"|"false"		{return T_BOOLEAN;}
=======
>>>>>>> master:grammaire.l

"float"				{return T_TYPEFLOAT;}
"boolean"			{return T_TYPEBOOLEAN;}
"integer"			{return T_TYPEINTEGER;}

"+"					{return T_PLUS;}
"-"					{return T_MINUS;}
"*"					{return T_MULTIPLY;}
"/"					{return T_DIVIDE;}
"^"					{return T_EXPO;}
"sqrt"				{return T_SQRT;}

"("					{return T_PLEFT;}
")"					{return T_PRIGHT;}
","					{return T_COMMA;}
"."					{return T_POINT;}
":"					{return T_COLON;}
";"					{return T_SEMICOLON;}
":="				{return T_ASSIGNMENT;}

"class"				{return T_CLASS;}
"extends"			{return T_EXTENDS;}
"is"				{return T_IS;}
"data"				{return T_DATA;}
"method"			{return T_METHOD;}
"return"			{return T_RETURN;}
"end"				{return T_END;}

<<<<<<< HEAD:grammaireTOKEN.l
[a-zA-Z]+			{return T_NAME;}
=======
"true"|"false"		{return T_BOOLEAN;}

[a-zA-Z]+			{return T_NAME;}
[+-]?[0-9]+\.[0-9]+ {yylval.fval = atof(yytext); return T_FLOAT;}
[+-]?[0-9]+			{yylval.ival = atoi(yytext); return T_INTEGER;}
>>>>>>> master:grammaire.l

.|\n|\t  			/* ignore all whitespace */

%%
int main(){
	yylex();
}
