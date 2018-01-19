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
Operator::Operator(OperatorSymbol symbol, Expression *left)
  : symbol(symbol), left(left)
{
    calcul();
}

/**--------------------------------------------------------------------------**/
Operator::~Operator() {
  delete left;
  delete right;
}

/**--------------------------------------------------------------------------**/
string Operator::getType() {
  return left->getType();
}

/**--------------------------------------------------------------------------**/
void Operator::visit(Visitor& visitor) {
  //return visitor.visitOperator(this);
}

/**--------------------------------------------------------------------------**/
Expression* Operator::calculOperation(){
  Float* f;
  Boolean* b;
  Integer* i;
  switch(symbol){
    case PLUS :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->plus(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->plus(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->plus(*f);
          return NULL;
          break;
    default: cout<<"Opérateur non implémenté";
              return NULL;

  }
  return NULL;
}

void Operator::print(){
  cout<<symbol<<endl;
}
