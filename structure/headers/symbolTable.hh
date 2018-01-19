#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H

#include <string>
#include <vector>
#include "class.hh"
#include "var.hh"
#include "expr.hh"
#include "object.hh"
#include "returnFonction.hh"

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
		Variable* findVar(vector<string> s) const;

		/**
		 * Renvoie le resultat d'une fonction de type return fonction
		 * @param  s liste des appels, exemple pour a.b.c.methode(), la liste contient a,b,c,methode
		 * @param  e liste des parametres
		 * @return   renvoie le resultat de la methode, sinon NULL
		 */
		Expression* resultOfReturnFonction(vector<string> s, vector<Expression*> e) const;
};

#endif
