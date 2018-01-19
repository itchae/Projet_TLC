#include "headers/callVar.hh"

/**--------------------------------------------------------------------------**/
CallVar::CallVar(string v)
	: var(v)
{
}

/**--------------------------------------------------------------------------**/
CallVar::~CallVar() {

}

/**--------------------------------------------------------------------------**/
void CallVar::visit(Visitor& visitor) {
  //return visitor.visitCall(this);
}
