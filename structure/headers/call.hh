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
		 * contient la liste d'appels (exemple : a.b.method(), donc contient a et b et method)
		 */
		vector<string> objs;
		vector<Expression*> params;

	public:
		Call(vector<string> c, vector<Expression*> p);
		~Call();
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
