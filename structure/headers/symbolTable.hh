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
 * Table des symboles contenant les variables et classes declarees
 * La classe est un singleton donc unique
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
		/**
		 * Renvoie l'unique instance de la classe
		 */
		static SymbolTable& Instance();

		/**
		 * Supprime tous les objets de la table
		 */
		void cleanAll();

		/**
		 * Ajoute la classe si elle n'existe pas deja dans la table des symboles
		 * @param c la classe a ajouter
		 */
    void addClass(Class* c);

		/**
		 * Renvoie la classe correspondant au nom sinon renvoie NULL
		 * @param  name le nom de la classe que l'on cherche
		 * @return la classe correspondant au nom sinon renvoie NULL
		 */
		Class* findClass(string name) const;

		/**
		 * Ajoute la variable si elle n'existe pas deja dans la table des symboles
		 * @param v la variable a ajouter
		 */
		void addVar(Variable* v);

		/**
		 * Renvoie la variable correspondant au nom sinon renvoie NULL
		 * @param  s le nom de la classe que l'on cherche
		 * @return la variable correspondant au nom sinon renvoie NULL
		 */
		Variable* findVar(vector<string> s) const;

		/**
		 * Renvoie le resultat d'une fonction de type return fonction
		 * @param  s liste des appels, exemple pour a.b.c.methode(), la liste contient a,b,c,methode
		 * @param  e liste des parametres
		 * @return renvoie le resultat de la methode, sinon NULL
		 */
		Expression* resultOfReturnFonction(vector<string> s, vector<Expression*> e) const;
};

#endif
