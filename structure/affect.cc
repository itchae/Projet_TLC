#include "headers/affect.hh"

/**--------------------------------------------------------------------------**/
Affect::Affect(vector<string> v, vector<Expression*> e)
	: vars(v), exprs(e)
{
}

/**--------------------------------------------------------------------------**/
Affect::Affect(string s, Expression* e) {
	vars.push_back(s);
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
