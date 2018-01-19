#ifndef _CALLVAR_H
#define _CALLVAR_H

#include <vector>
#include <string>
#include "expr.hh"

using namespace std;

/**
 * Classe permettant de stocker les informations relatives a un appel de fonction
 */
class CallVar : public Expression {

	private:
		string var;

	public:
		CallVar(string v);
		~CallVar();
		void visit(Visitor& visitor);

};

#endif
