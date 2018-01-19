#include "headers/ope.hh"

/**--------------------------------------------------------------------------**/
Operator::Operator(OperatorSymbol symbol, const Expression *left, const Expression *right)
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
Expression* Operator::calculOperation(){
  switch(symbol){
    case PLUS : return (left->plus(*right));
          break;
    case MOINS : return (left->moins(*right));
          break;
    case MULT : return (left->mult(*right));
          break;
    case POW : return (left->pow(*right));
          break;
    case SQRT : return (left->sqrt(*right));
          break;
    case INF : return (left->inferieur(*right));
          break;
    case SUP : return (left->superieur(*right));
          break;
    case SUPEG : return (left->supeg(*right));
          break;
    case INFEG : return (left->infeg(*right));
          break;
    case EGALITE : return (left->egalite(*right));
          break;
    case DIFF : return (left->diff(*right));
          break;
    default: cout<<"Opérateur non implémenté";
              return NULL;

  }
  return NULL;
}

void Operator::print() const{
  cout<<symbol<<endl;
}
