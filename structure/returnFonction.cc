#include "headers/returnFonction.hh"

/**--------------------------------------------------------------------------**/
ReturnFonction::ReturnFonction(string name, vector<Decl*> v, Expression* e)
	: name(name), expr(e), params(v)
{
}

/**--------------------------------------------------------------------------**/
string ReturnFonction::getName() {
  return name;
}

/**--------------------------------------------------------------------------**/
void ReturnFonction::print() const {
  if (expr==NULL){
    throw invalid_argument("expression inexistante");
  }else{
    expr->print();
  }
}

/**--------------------------------------------------------------------------**/
Expression* ReturnFonction::calcul() const {
  if (expr==NULL){
    throw invalid_argument("expression inexistante");
  }else{
    return expr->calcul();
  }
}

/**--------------------------------------------------------------------------**/
string ReturnFonction::getType() const {
  if (expr==NULL){
    throw invalid_argument("expression inexistante");
  }else{
    return expr->getType();
  }
}

/**--------------------------------------------------------------------------**/
void ReturnFonction::visit(Visitor& visitor) {
  //return visitor.visitFonc(this);
}
