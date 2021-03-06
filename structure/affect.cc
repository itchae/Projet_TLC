#include "headers/affect.hh"

/**--------------------------------------------------------------------------**/
Affect::Affect(vector<string> v, Expression* e)
	: vars(v)
{
	exprs.push_back(e);
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
	while (vars.size()>0){
	  delete vars.back();
	 	vars.pop_back();
  }
}

/**--------------------------------------------------------------------------**/
void Affect::visit(Visitor& visitor) {
  return visitor.visitAffect(this);
}
