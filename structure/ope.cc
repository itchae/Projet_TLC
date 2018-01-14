#include "headers/ope.hh"

/**--------------------------------------------------------------------------**/
Operator::Operator(OperatorSymbol symbol, Expression *left, Expression *right)
  : symbol(symbol), left(left), right(right)
{
}

/**--------------------------------------------------------------------------**/
Operator::~Operator() {
  delete left;
  delete right;
}

/**--------------------------------------------------------------------------**/
string Operator::getType() const {
  return ""; //TODO
}

/**--------------------------------------------------------------------------**/
void Operator::visit(Visitor& visitor) const {
  return visitor.visitOperator(this);
}
