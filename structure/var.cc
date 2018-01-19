#include "headers/var.hh"

//--------------------------------------------------------------------------//
Variable::Variable(string n, Expression* e)
  : name(n), var(e)
{

}

//--------------------------------------------------------------------------//
Variable::Variable(string n, string t) : name(n), type(t){

}

//--------------------------------------------------------------------------//
Variable::~Variable(){
  if (var!=NULL) delete var;
}

//--------------------------------------------------------------------------//
string Variable::getType() const {
  return type;
}

//--------------------------------------------------------------------------//
void Variable::visit(Visitor& visitor){

}
