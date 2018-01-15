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
		Class* mere; // Classe mère
		string name; // Nom
		Data* data; // Attributs
		Method* method; // Méthodes
		

	public:
		Class(string n, Data* d, Method* m);
		Class(Class* mere, string n, Data* d, Method* m);
		Class(Data *data);
		~Class();
		bool operator==(Class& rhs) const;
		string getType() const;
		inline const Data* getData() const { return data; }
		inline const Method* getMethod() const { return method; }
		inline const string getName() const { return name; }
		void visit(Visitor& visitor) const;

};

#endif
