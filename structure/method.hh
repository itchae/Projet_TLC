#ifndef _METHOD_H
#define _METHOD_H

#include <vector>
#include <string>
#include "fonc.hh"

class Method  {

	private:
		vector<Fonction*> vars;
		
	public:
		Data(vector<Fonction*> v);
		~Data();

		bool contains(string var) const;
		
		Decl* getFonction(string var) const;
		
		void visit(Visitor& visitor) const;
  
};

#endif
