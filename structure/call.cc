#include "headers/call.hh"

/**--------------------------------------------------------------------------**/
Call::Call(string n, vector<string> c, vector<Expression*> p)
	: nom(n), objs(c), params(p)
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
void Call::visit(Visitor& visitor) {
  return visitor.visitCall(this);
}
