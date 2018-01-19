#include "headers/ope.hh"

/**--------------------------------------------------------------------------**/
Operator::Operator(OperatorSymbol symbol, Expression *left, Expression *right)
  : symbol(symbol), left(left), right(right)
{
  if(left->getType().compare(right->getType()) != 0){
    throw ("Problème de type ! ");
  }else{
    calcul();
  }
}

/**--------------------------------------------------------------------------**/
Operator::~Operator() {
  delete left;
  delete right;
}

/**--------------------------------------------------------------------------**/
string Operator::getType() const {
  return left->getType();
}

/**--------------------------------------------------------------------------**/
void Operator::visit(Visitor& visitor) {
  //return visitor.visitOperator(this);
}

/**--------------------------------------------------------------------------**/
Expression* Operator::calcul(){
  Expression expr;
  switch(symbol){
    case PLUS : expr = left+right;
          break;
    case MOINS : expr = left-right;
          break;
    case MULT : expr = left*right;
          break;
    case INF : expr = left<right;
          break;
    case SUP : expr = left>right;
          break;
    case SUPEG : expr = left>=right;
          break;
    case INFEG : expr = left<=right;
          break; 
    case EGALITE : cout<<"EGALITE"<<endl;
          break;
    case DIFF : cout<<"DIFF"<<endl;
          break;
    default: cout<<"Opérateur non implémenté";

  }
  return NULL; //TODO
}

void Operator::print() const{
  cout<<symbol<<endl;
}
