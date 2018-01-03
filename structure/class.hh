#ifndef _CLASS_H
#define _CLASS_H

#include <string.h>

class Class  {

	private:
		Data* data;
		Method* method;
		char* name;
		Class* mere;
		
	public:
		Class(char* n, Data* d, Method* m);
		Class(Class* mere, char* n, Data* d, Method* m);
		~Class();

		inline const Data* getData() const { return data; }
		inline const Method* getMethod() const { return method; }
		inline const char* getName() const { return name; }
		
		void visit(Visitor& visitor) const;
  
};

#endif
