#include "headers/var.hh"

//--------------------------------------------------------------------------//
Variable::Variable(string n, Expression* e)
  : name(n), var(e)
{

}

//--------------------------------------------------------------------------//
Variable::Variable(string n) : name(n){

}

//--------------------------------------------------------------------------//
Variable::~Variable(){
  if (var!=NULL) delete var;
}

//--------------------------------------------------------------------------//
void Variable::visit(Visitor& visitor){

}
