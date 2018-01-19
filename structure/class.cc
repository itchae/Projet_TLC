#include "headers/class.hh"

//--------------------------------------------------------------------------//
Class::Class(string n, Data* d, Method* m)
  : nom(n), data(d), method(m)
{
}

//--------------------------------------------------------------------------//
Class::Class(string mere, string n, Data* d, Method* m)
  : mere(mere), nom(n), data(d), method(m)
{
  if (mere == NULL) throw invalid_argument("Classe mere");
}

//--------------------------------------------------------------------------//
Class::~Class() {
  if (data!=NULL) delete data;
  if (method!=NULL) delete method;
}

//--------------------------------------------------------------------------//
bool Class::operator==(Class& rhs) const{
  if (nom.compare(rhs.getName())==0) return true;
  return false;
}

//--------------------------------------------------------------------------//
string Class::getType() const {
  return nom;
}

//--------------------------------------------------------------------------//
void Class::visit(Visitor& visitor) {
  //return visitor.visitClass(this);
}
