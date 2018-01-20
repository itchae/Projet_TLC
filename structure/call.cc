#include "headers/call.hh"

/**--------------------------------------------------------------------------**/
Call::Call(vector<string> c, vector<Expression*> p)
	: objs(c), params(p)
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
string Call::getName() {
 if (objs.size()>0){
	 return objs[objs.size()-1];
 }else{
	 return "";
 }
}

/**--------------------------------------------------------------------------**/
void Call::visit(Visitor& visitor) {
  return visitor.visitCall(this);
}
