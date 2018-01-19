#ifndef _VOIDFONC_H
#define _VOIDFONC_H

#include <vector>
#include <string>
#include "decl.hh"
#include "fonc.hh"
#include "inst.hh"

using namespace std;

/**
 * Classe permettant de stocker les informations d'une fonction déclarée (nom, parametres, instructions)
 */
class VoidFonction : public Fonction  {

	private:
		string name;
		vector<Decl*> params;
		Instruction* instruct;

	public:
		VoidFonction(string name, vector<Decl*> v, Instruction* instruct);
		~VoidFonction();

		/**
		 * @return renvoie vrai si la fonction n'a pas de parametre (vector vide)
		 */
		bool noParams() const;
		bool containsParam(string var) const;
		Decl* getParam(string var) const;
		inline string getName() const { return name; }
		inline Instruction* getInst() const { return instruct; }
		void visit(Visitor& visitor);

};

#endif
