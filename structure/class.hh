#ifndef _CLASS_H
#define _CLASS_H

#include <string.h>
#include "data.hh"
#include "method.hh"

class Class  {

	private:
		Data* data;
		Method* method;
		string name;
		Class* mere;

	public:
		Class(char* n, Data* d, Method* m);
		Class(Class* mere, char* n, Data* d, Method* m);
		~Class();

		inline const Data* getData() const { return data; }
		inline const Method* getMethod() const { return method; }
		inline const string getName() const { return name; }

		void visit(Visitor& visitor) const;

};

#endif
