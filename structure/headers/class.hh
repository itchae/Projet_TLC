#ifndef _CLASS_H
#define _CLASS_H

#include <string>
#include "data.hh"
#include "method.hh"
#include "expr.hh"

using namespace std;

/**
 * Classe permettant de stocker toutes les informations relatives à une classe
 */
class Class  : Expression {

	private:
		string mere; // Classe mère
		string nom; // Nom de la classe
		Data* data; // Attributs
		Method* method; // Méthodes


	public:
		Class(string n, Data* d, Method* m);
		Class(string mere, string n, Data* d, Method* m);
		~Class();
		bool operator==(Class& rhs) const;
		string getType() const;
		inline const Data* getData() const { return data; }
		inline const Method* getMethod() const { return method; }
		inline const string getName() const { return nom; }
		void visit(Visitor& visitor);
		void print() const;
};

#endif
