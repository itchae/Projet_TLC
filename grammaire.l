%{
#include <stdio.h>
#include <stdlib.h>

%}
CHIFFRE 	[1-9]
ENTIER 		[+-]?{CHIFFRE}+
REEL 		{ENTIER}("."{CHIFFRE}+)? 

BOOL 		["true""TRUE""false""FALSE"]


PLUS		"+"
MOINS		"-"
MUL			"*"
DIV			"/"
EXPO		"^"
SQRT		"sqrt"

CLASS		"class"
IS			"is"
METHOD 		"method"
END 		"end"
AFF			":="
PAROUV		"("
PARFER		")"
DATA 		"data"
PV			";"
VIRG		","
POINT		"."
DPOINT		":"

RETURN		"return"
FLOAT 		"float"
INTEGER		"integer"
BOOLEAN		"boolean"
EXTENDS 	"extends"



NOM			[a-zA-Z]+

%%
{CLASS}|{IS}|{METHOD}|{END}|{DATA}|{RETURN}|{EXTENDS}	{ printf("Mot clé \n");}

{PV}|{AFF}|{PAROUV}|{PARFER}|{VIRG}|{POINT}|{DPOINT}	{ printf("Ponctuation \n");}

{PLUS}|{MOINS}|{MUL}|{DIV}|{EXPO}|{SQRT} 				{ printf("Opérateurs \n"); }

{ENTIER}|{REEL} 										{ printf("Chiffre \n"); }

{FLOAT}|{INTEGER}|{BOOLEAN} 							{ printf("Type\n"); }

{NOM} 													{ printf("Nom \n"); }

.|\n|\t 

%%
int main(){
	yylex();
}
