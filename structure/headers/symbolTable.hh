#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H

#include <string>
#include <vector>
#include "class.hh"
#include "var.hh"
#include "expr.hh"

using namespace std;

/**
 * Table des symboles contenant les declarations faites dans le programme et qui sont accessibles
 */
class SymbolTable  {

	private:
		SymbolTable& operator= (const SymbolTable&){}
		SymbolTable (const SymbolTable&){}
		static SymbolTable m_instance;
		SymbolTable();
		~SymbolTable();
		static vector<Class*> classes;
		static vector<Variable*> vars;

	public:
		static SymbolTable& Instance();
		void cleanAll();
    void addClass(Class* c);
		Class* findClass(string name) const;
		void addVar(Variable* v);
		Variable* findVar(string name) const;
		/**
		 * Permet de retrouver le resultat de l
		 * @param  d [description]
		 * @param  m [description]
		 * @return   [description]
		 */
		Expression* findResultOfMethodOfClass(string d, string m, vector<Expression*> e) const;
};

#endif
