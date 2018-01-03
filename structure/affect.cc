#include "affect.hh"


Affect::Affect(vector<string> v, vector<Expression*> e)
{
	//copie le vecteur v dans le vecteur vars
	param.reserve(v.size());
	copy(v.begin(),v.end(),back_inserter(vars));
	param.reserve(e.size());
	copy(e.begin(),e.end(),back_inserter(exprs));
}

Affect::~Affect() {
  delete expr;
}

void Affect::visit(Visitor& visitor) const {
  return visitor.visitAffect(this);
}
