#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>
#include "var.hh"
#include "expr.hh"
#include "class.hh"
#include "fonc.hh"

using namespace std;

/**
 * Une variable qui est objet
 */
class Object  : public Variable {

	private:
  	Class* classe;           // Classe de l'objet
		string nom;             // Nom de l'objet
		vector<Variable*> vars; // Attributs

	public:
		Object(string n, Class* c);
		~Object();
		string getType() const;
    void setVar(string name, Expression* val);
		inline vector<Variable*> getVars() const { return vars; }
		inline const Class* getClass() const     { return classe; }
		inline const string getName() const      { return nom; }
    Variable* getVar(string n) const;
    Fonction* getFonction(string n) const;
		void visit(Visitor& visitor);
		void print() const;
};

#endif
