%{
#include <stdio.h>
#include <stdlib.h>

%}

%%

[+-]?[0-9]+			{printf("T_INTEGER ");}
[+-]?[0-9]+\.[0-9]+ {printf("T_FLOAT ");}
"true"|"false"		{printf("T_BOOLEAN ");}

"float"				{printf("T_TYPEFLOAT ");}
"boolean"			{printf("T_TYPEBOOLEAN ");}
"integer"			{printf("T_TYPEINTEGER ");}

"+"					{printf("T_PLUS ");}
"-"					{printf("T_MINUS ");}
"*"					{printf("T_MULTIPLY ");}
"/"					{printf("T_DIVIDE ");}
"^"					{printf("T_EXPO ");}
"sqrt"				{printf("T_SQRT ");}

"("					{printf("T_PLEFT ");}
")"					{printf("T_PRIGHT ");}
","					{printf("T_COMMA ");}
"."					{printf("T_POINT ");}
":"					{printf("T_COLON ");}
";"					{printf("T_SEMICOLON ");}
":="				{printf("T_ASSIGNMENT ");}

"class"				{printf("T_CLASS ");}
"extends"			{printf("T_EXTENDS ");}
"is"				{printf("T_IS ");}
"data"				{printf("T_DATA ");}
"method"			{printf("T_METHOD ");}
"return"			{printf("T_RETURN ");}
"end"				{printf("T_END ");}

[a-zA-Z]+			{printf("T_NAME ");}

\n 					{printf("\n");}

.|\t  				/* ignore all whitespace */

%%
int main(){
	yylex();
}
