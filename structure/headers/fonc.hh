#ifndef _FONC_H
#define _FONC_H

#include <vector>
#include <string>
#include "decl.hh"
#include "expr.hh"
#include "return.hh"

using namespace std;

/**
 * Classe permettant de stocker les informations d'une fonction déclarée (nom, parametres, instructions)
 */
class Fonction : public Expression  {

	private:
		string name;
		vector<Decl*> params;
		Instruction* instruct;

	public:
		Fonction(string name, vector<Decl*> v, Instruction* instruct);
		~Fonction();
		
		/**
		 * @return renvoie vrai si la fonction n'a pas de parametre (vector vide)
		 */
		bool noParams() const;
		bool containsParam(string var) const;
		Decl* getParam(string var) const;
		string getType() const;
		inline const string getName() const { return name; }
		inline const Instruction* getInst() const { return instruct; }
		void visit(Visitor& visitor);


};

#endif
