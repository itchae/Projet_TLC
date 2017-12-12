
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "grammaire.tab.hh"

using namespace std;

extern FILE *yyin;
extern char* yytext;

int main(){
	int res = yyparse();
	cout<<"FIN PARSER : "<<res<<endl;
	return 0;
}
