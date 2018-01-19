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
		/**
		 * nom de la methode a utiliser
		 */
		string nom;
		/**
		 * contient la liste d'appels (exemple : a.b.method(), donc contient a et b)
		 */
		vector<string> objs;
		vector<Expression*> params;

	public:
		Call(string n, vector<string> c, vector<Expression*> p);
		~Call();
		inline string getName() { return nom; }
		inline vector<string> getObjs() { return objs; }
		inline vector<Expression*> getParams() { return params; }
		void visit(Visitor& visitor);

};

#endif
