#include "headers/decl.hh"

/**--------------------------------------------------------------------------**/
Decl::Decl(string var, string type) : var(var), type(type) {
}

/**--------------------------------------------------------------------------**/
Decl::~Decl() {
}

/**--------------------------------------------------------------------------**/
void Decl::visit(Visitor& visitor) {
  return visitor.visitDecl(this);
}

void Decl::print(){
  cout<<getVar()<<"."<<<<endl; 
}
