#ifndef _DATA_H
#define _DATA_H

#include <vector>
#include <string>
#include "decl.hh"

using namespace std;

/**
 * Classe permettant de stocker les declarations faites dans une classe
 */
class Data {

	private:
		vector<Decl*> vars;

	public:
		Data(vector<Decl*> v);
		~Data();
		bool contains(string var) const;
		Decl* getDecl(string var) const;
		inline vector<Decl*> getDecls() const { return vars; }
		void visit(Visitor& visitor) const;

};

#endif
