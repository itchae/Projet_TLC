#include <iostream>
#include "TLC_Gpe_14_Grammaire_v2.tab.hh"

using namespace std;

extern FILE *yyin;
extern char* yytext;

int main(){
	int res = yyparse();
	cout<<"FIN PARSER : "<<res<<endl;
	return 0;
}
