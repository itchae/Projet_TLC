#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H

#include <string.h>
#include <vector>
#include "class.hh"
#include "affect.hh"
#include "decl.hh"

class SymbolTable  {

	private:
		SymbolTable& operator= (const SymbolTable&){}
		SymbolTable (const SymbolTable&){}
		static SymbolTable m_instance;
		SymbolTable();
		~SymbolTable();
		static vector<Class*> classes;
		static vector<Decl*> decls;
		static vector<Affect*> affects;

	public:
		static SymbolTable& Instance();
    void addClass(Class* c);
		Class* findClass(string name) const;
		void addDecl(Decl* d);
		Decl* findDecl(string name) const;
		void addAffect(Affect* a);
		Affect* findAffect(string name) const;
};

#endif
