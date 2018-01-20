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
    case MOINS :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->moins(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->moins(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->moins(*f);
          return NULL;
          break;
    case MULT :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->mult(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->mult(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->mult(*f);
          return NULL;
          break;
    case POW :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->pow(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->pow(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->pow(*f);
          return NULL;
          break;
    case SQRT :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->racineCarree();
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->racineCarree();
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->racineCarree();
          return NULL;
          break;
    case INF :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->inferieur(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->inferieur(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->inferieur(*f);
          return NULL;
          break;
    case SUP :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->superieur(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->superieur(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->superieur(*f);
          return NULL;
          break;
    case SUPEG :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->superieurEgal(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->superieurEgal(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->superieurEgal(*f);
          return NULL;
          break;
    case INFEG :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->inferieurEgal(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->inferieurEgal(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->inferieurEgal(*f);
          return NULL;
          break;
    case EGALITE :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->egalite(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->egalite(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->egalite(*f);
          return NULL;
          break;
    case DIFF :
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->diff(*b);
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->diff(*i);
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->diff(*f);
          return NULL;
          break;
    case NEGA:
          b = dynamic_cast<Boolean*>(right);
          if (b!=NULL) return left->neg();
          i = dynamic_cast<Integer*>(right);
          if (i!=NULL) return left->neg();
          f = dynamic_cast<Float*>(right);
          if (f!=NULL) return left->neg();
          return NULL;
          break;
    default: cout<<"Opérateur non implémenté";
              return NULL;

  }
  return NULL;
}

void Operator::print(){
  Expression* exp = calculOperation();
  if (exp!=NULL) exp->print();
}
