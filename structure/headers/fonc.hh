#ifndef _FONC_H
#define _FONC_H

#include <vector>
#include <string>
#include "decl.hh"
#include "inst.hh"

using namespace std;

/**
 * Classe permettant de stocker les informations d'une fonction déclarée (nom, parametres, instructions)
 */
class Fonction  {

	private:
		string name;
		vector<Decl*> param;
		Instruction* instruct;

	public:
		Fonction(string name, vector<Decl*> v, Instruction* instruct);
		~Fonction();
		/**
		 * renvoie vrai si la fonction n'a pas de parametre (vector vide)
		 * @return renvoie vrai si la fonction n'a pas de parametre (vector vide)
		 */
		bool noParam() const;
		bool containsParam(string var) const;
		Decl* getParam(string var) const;
		inline const string getName() const { return name; }
		inline const Instruction* getInst() const { return instruct; }
		void visit(Visitor& visitor) const;

};

#endif
