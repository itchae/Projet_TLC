#include "headers/affect.hh"

/**--------------------------------------------------------------------------**/
Affect::Affect(string v, vector<Expression*> e)
	: exprs(e)
{
	vars.push_back(v);
}

/**--------------------------------------------------------------------------**/
Affect::Affect(string v, Expression* e){
	exprs.push_back(e);
	vars.push_back(v);
}

/**--------------------------------------------------------------------------**/
Affect::Affect(vector<string> v, vector<Expression*> e)
	: vars(v), exprs(e)
{
}

/**--------------------------------------------------------------------------**/
Affect::~Affect() {
	for (int i = 0; i < exprs.size(); i++){
		delete exprs[i];
	}
}

/**--------------------------------------------------------------------------**/
void Affect::visit(Visitor& visitor) {
  return visitor.visitAffect(this);
}
