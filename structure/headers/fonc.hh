#ifndef _FONC_H
#define _FONC_H

#include "visitor.hh"

/**
 * Classe permettant de stocker les informations d'une fonction déclarée (nom, parametres, instructions)
 */
class Fonction {

	private:

	public:
		virtual ~Fonction() {}
		virtual string getName() = 0;
		virtual void visit(Visitor& visitor) = 0;

};

#endif
