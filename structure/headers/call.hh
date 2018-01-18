#ifndef _CALL_H
#define _CALL_H

#include <vector>
#include <string>
#include "expr.hh"
#include "inst.hh"

using namespace std;

/**
 * Classe permettant de stocker les informations relatives a un appel de fonction
 */
class Call : public Instruction {

	private:
		string objet;
    string methode;
		vector<Expression*> params;

	public:
		Call(string o, string m, vector<Expression*> p);
		~Call();
		void visit(Visitor& visitor) const;

};

#endif
