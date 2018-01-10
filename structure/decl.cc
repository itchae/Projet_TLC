#include "headers/decl.hh"

Decl::Decl(string var, Type type) : var(var), type(type) {
}

Decl::~Decl() {

}

void Decl::visit(Visitor& visitor) const {
  return visitor.visitDecl(this);
}
