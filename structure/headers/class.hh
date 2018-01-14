#ifndef _CLASS_H
#define _CLASS_H

#include <string>
#include "data.hh"
#include "method.hh"

using namespace std;

/**
 * Classe permettant de stocker toutes les informations relatives à une classe
 */
class Class  {

	private:
		Data* data;
		Method* method;
		string name;
		Class* mere;

	public:
		Class(string n, Data* d, Method* m);
		Class(Class* mere, string n, Data* d, Method* m);
		Class(Data *data);
		~Class();
		bool operator==(Class& rhs) const;
		inline const Data* getData() const { return data; }
		inline const Method* getMethod() const { return method; }
		inline const string getName() const { return name; }
		void visit(Visitor& visitor) const;

};

#endif
