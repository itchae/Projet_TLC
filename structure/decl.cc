#include "headers/decl.hh"

/**--------------------------------------------------------------------------**/
Decl::Decl(string var, string* type) : var(var), type(type) {
  /*if (type==NULL) throw invalid_argument("Type NULL");*/
}

/**--------------------------------------------------------------------------**/
Decl::~Decl() {
}

/**--------------------------------------------------------------------------**/
void Decl::visit(Visitor& visitor) const {
  return visitor.visitDecl(this);
}
