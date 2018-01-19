#include "headers/var.hh"

//--------------------------------------------------------------------------//
Variable::Variable(){
}

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
void Variable::setVar(Expression* e) {
  if (var!=NULL) delete var;
  var = e;
}

//--------------------------------------------------------------------------//
string Variable::getType() const {
  return type;
}

//--------------------------------------------------------------------------//
void Variable::visit(Visitor& visitor){

}

//--------------------------------------------------------------------------//
void Variable::print() const{
  cout<<"Variable"<<name<<" = ";
  var->print();

}
