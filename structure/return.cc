#include "headers/return.hh"

/**--------------------------------------------------------------------------**/
Return::Return(Expression* e) : expr(e) {

}

/**--------------------------------------------------------------------------**/
Return::~Return() {
  delete expr;
}

/**--------------------------------------------------------------------------**/
string Return::getType() const {
  if (expr!=NULL) return expr->getType();
  return "";
}

/**--------------------------------------------------------------------------**/
void Return::visit(Visitor& visitor) {
  //return visitor.visitDecl(this);
}
