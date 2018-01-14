#include <iostream>

using namespace std;

extern FILE *yyin;
extern char* yytext;
extern int yyparse();

int main(){
	int res = yyparse();
	cout<<"FIN PARSER : "<<res<<endl;
	return 0;
}
