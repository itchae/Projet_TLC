#ifndef _FONC_H
#define _FONC_H

#include <vector>
#include <string>
#include "decl.hh"
#include "expr.hh"
#include "fonc.hh"

using namespace std;

/**
 * Classe permettant de stocker les informations d'une fonction déclarée (nom, parametres, instructions)
 */
class ReturnFonction : public Fonction  {

	private:
		string name;
		vector<Decl*> params;
		Expression* expr;

	public:
		ReturnFonction(string name, vector<Decl*> v, Instruction* instruct);
		~ReturnFonction();

		/**
		 * @return renvoie vrai si la fonction n'a pas de parametre (vector vide)
		 */
		bool noParams() const;
		bool containsParam(string var) const;
		Decl* getParam(string var) const;
		string getType() const;
		inline const string getName() const { return name; }
		inline const Instruction* getExpr() const { return expr; }
		void visit(Visitor& visitor);
		void print() const;

};

#endif
