#ifndef _CALLEXP_H
#define _CALLEXP_H

#include <vector>
#include <string>
#include "expr.hh"

using namespace std;

/**
 * Classe permettant de stocker les informations relatives a un appel de fonction return ou alors un appel d'attribut
 */
class CallExp : public Expression {

	private:
		/**
		 * contient la liste d'appels (exemple : a.b.method(), donc contient a et b et method)
		 */
		vector<string> objs;
		vector<Expression*> params;

	public:
		CallExp(vector<string> c, vector<Expression*> p);
		~CallExp();
		/**
		 * retourne le nom de la fonction (en derniere position)
		 * @return le nom de la fonction (en derniere position)
		 */
		string getName();
		inline vector<string> getObjs() { return objs; }
		inline vector<Expression*> getParams() { return params; }
		void visit(Visitor& visitor);

};

#endif
