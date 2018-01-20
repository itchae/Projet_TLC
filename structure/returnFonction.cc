#include "headers/returnFonction.hh"

/**--------------------------------------------------------------------------**/
ReturnFonction::ReturnFonction(string name, vector<Decl*> v, Expression* e)
	: name(name), expr(e), params(v)
{
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

ReturnFonction::~ReturnFonction(){
	while (params.size()>0){
	  delete params.back();
	 	params.pop_back();
  }
	if(expr!=NULL){
		delete expr; 
	}
}
