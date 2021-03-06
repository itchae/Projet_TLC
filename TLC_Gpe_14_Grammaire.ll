%{
  #include <string.h>
  #include "structure/headers/vivacite.hh"
  #include "TLC_Gpe_14_Grammaire_v2.tab.hh"
%}


%%

[0-9]+				{yylval.ival = atoi(yytext); return T_INTEGER;}
[0-9]+\.[0-9]+ 		{yylval.fval = atof(yytext); return T_FLOAT;}
"true"|"false"		{yylval.bval = strdup(yytext); return T_BOOLEAN;}

"float"				{return T_TYPEFLOAT;}
"boolean"			{return T_TYPEBOOLEAN;}
"integer"			{return T_TYPEINTEGER;}



"+"					{return T_PLUS;}
"-"					{return T_MINUS;}
"*"					{return T_TIMES;}
"/"					{return T_DIVIDE;}
"^"					{return T_POWER;}
"sqrt"			{return T_SQRT;}
"<"           {return T_INF;}
">"           {return T_SUP;}
"<="          {return T_INFEG;}
">="          {return T_SUPEG;}


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

[a-zA-Z]+			{yylval.sval = strdup(yytext); return T_NAME;}

.|\n|\t  			/* ignore all whitespace */

%%
