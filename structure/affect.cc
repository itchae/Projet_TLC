#include "affect.hh"


Affect::Affect(vector<string> v, vector<Expression*> e)
{
	//copie le vecteur v dans le vecteur vars
	vars.reserve(v.size());
	copy(v.begin(),v.end(),back_inserter(vars));
	exprs.reserve(e.size());
	copy(e.begin(),e.end(),back_inserter(exprs));
}

Affect::~Affect() {
	for (int i = 0; i < exprs.size(); i++){
		delete exprs[i];
	}
}

void Affect::visit(Visitor& visitor) const {
  return visitor.visitAffect(this);
}
