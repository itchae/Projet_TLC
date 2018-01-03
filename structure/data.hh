#ifndef _DATA_H
#define _DATA_H

#include <vector>
#include <string>
#include "decl.hh"

class Data  {

	private:
		vector<Decl*> vars;
		
	public:
		Data(vector<Decl*> v);
		~Data();

		bool contains(string var) const;
		
		Decl* getDecl(string var) const;
		
		void visit(Visitor& visitor) const;
  
};

#endif
