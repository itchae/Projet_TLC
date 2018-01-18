#ifndef _METHOD_H
#define _METHOD_H

#include <vector>
#include <string>
#include "fonc.hh"

using namespace std;

/**
 * Classe permettant de stocker les déclarations de fonctions dans une classe
 */
class Method  {

	private:
		vector<Fonction*> vars;

	public:
		Method(vector<Fonction*> v);
		~Method();
		bool contains(string var) const;
		Fonction* getFonction(string var) const;
		void visit(Visitor& visitor);

};

#endif
