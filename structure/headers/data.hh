#ifndef _DATA_H
#define _DATA_H

#include <vector>
#include <string>
#include "var.hh"

using namespace std;

/**
 * Classe permettant de stocker les declarations faites dans une classe
 */
class Data {

	private:
		vector<Variable*> vars;

	public:
		Data(vector<Variable*> v);
		~Data();
		bool contains(string var) const;
		Variable* getVar(string var) const;
		inline vector<Variable*> getVars() const { return vars; }
		void visit(Visitor& visitor);

};

#endif
