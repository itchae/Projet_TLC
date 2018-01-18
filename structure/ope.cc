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
void Operator::calcul(){
  switch(this->symbol){
    case PLUS : cout<<"PLUS"<<endl;
          break;
    case MOINS : cout<<"MOINS"<<endl;
          break;
    case MULT : cout<<"MULT"<<endl;
          break;
    case INF : cout<<"INF"<<endl;
          break;
    case SUP : cout<<"SUP"<<endl;
          break;
    case EGALITE : cout<<"EGALITE"<<endl;
          break;
    case DIFF : cout<<"DIFF"<<endl;
          break;
    default: cout<<"Opérateur non implémenté";

  }
}
