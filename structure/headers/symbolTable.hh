#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H

#include <string.h>
#include <vector>
#include "class.hh"

class SymbolTable  {

	private:
    SymbolTable& operator= (const SymbolTable&){}
    SymbolTable (const SymbolTable&){}
    static SymbolTable m_instance;
    SymbolTable();
    ~SymbolTable();
    static vector<Class*> classes;

	public:
		static SymbolTable& Instance();
    void addClass(Class* c);
		Class* findClass(string name) const;
};

#endif
