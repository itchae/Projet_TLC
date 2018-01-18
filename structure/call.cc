#include "headers/fonc.hh"

/**--------------------------------------------------------------------------**/
Call::Call(string o, string m, vector<Expression*> p)
	: objet(o), methode(m), params(p)
{
}

/**--------------------------------------------------------------------------**/
Call::~Call() {
  while (params.size()>0){
	  delete params.back();
	  params.pop_back();
  }
}

/**--------------------------------------------------------------------------**/
void Call::visit(Visitor& visitor) const {
  return visitor.visitCall(this);
}
