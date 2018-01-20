#include "headers/callExp.hh"

/**--------------------------------------------------------------------------**/
CallExp::CallExp(vector<string> c, vector<Expression*> p)
	: objs(c), params(p)
{
}

/**--------------------------------------------------------------------------**/
CallExp::~CallExp() {
  while (params.size()>0){
	  delete params.back();
	  params.pop_back();
  }
}

/**--------------------------------------------------------------------------**/
string CallExp::getName() {
 if (objs.size()>0){
	 return objs[objs.size()-1];
 }else{
	 return "";
 }
}

/**--------------------------------------------------------------------------**/
void CallExp::visit(Visitor& visitor) {
  return visitor.visitCallExp(this);
}
