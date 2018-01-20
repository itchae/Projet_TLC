#include "headers/decl_classe.hh"

/**--------------------------------------------------------------------------**/
DeclClass::DeclClass(Class* c) : classe(c) {
}

/**--------------------------------------------------------------------------**/
DeclClass::~DeclClass() {
  delete classe;
}

/**--------------------------------------------------------------------------**/
void DeclClass::visit(Visitor& visitor) {
  return visitor.visitDeclClass(this);
}
