#ifndef _RETURNFONC_H
#define _RETURNFONC_H

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
		ReturnFonction(string name, vector<Decl*> v, Expression* e);
		~ReturnFonction();
    inline const string getName() const { return name; }
    inline const Expression* getExpr() const { return expr; }
		void print() const;
    Expression* calcul() const;
    string getType() const;
    void visit(Visitor& visitor);
};

#endif
