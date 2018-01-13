#include "headers/affect.hh"

/**--------------------------------------------------------------------------**/
Affect::Affect(Decl* v, vector<Expression*> e)
	: var(v), exprs(e)
{
}

/**--------------------------------------------------------------------------**/
Affect::Affect(Decl* v, Expression* e)
	: var(v)
{
	exprs.push_back(e);
}

/**--------------------------------------------------------------------------**/
Affect::~Affect() {
	for (int i = 0; i < exprs.size(); i++){
		delete exprs[i];
	}
}

/**--------------------------------------------------------------------------**/
void Affect::visit(Visitor& visitor) const {
  return visitor.visitAffect(this);
}
