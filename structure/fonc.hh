#ifndef _FONC_H
#define _FONC_H

#include <vector>
#include <string>
#include "decl.hh"
#include "inst.hh"

class Fonction  {

	private:
		string name;
		vector<Decl*> param;
		Instruction* instruct;
		
	public:
		Fonction(vector<Fonction*> v);
		~Fonction();

		bool containsParam(string var) const;
		
		Decl* getParam(string var) const;
		
		inline const Instruction* getInst() const { return instruct; }
		
		void visit(Visitor& visitor) const;
  
};

#endif
