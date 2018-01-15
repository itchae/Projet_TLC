#include "headers/class.hh"

//--------------------------------------------------------------------------//
Class::Class(string n, Data* d, Method* m)
  : name(n), data(d), method(m)
{
}

//--------------------------------------------------------------------------//
Class::Class(Class* mere, string n, Data* d, Method* m)
  : mere(mere), name(n), data(d), method(m)
{
  if (mere == NULL) throw invalid_argument("Classe mere");
}

//--------------------------------------------------------------------------//
Class::~Class() {
  if (data!=NULL) delete data;
  if (method!=NULL) delete method;
  if (mere!=NULL) delete mere;
}

//--------------------------------------------------------------------------//
bool Class::operator==(Class& rhs) const{
  if (name.compare(rhs.getName())==0) return true;
  return false;
}

//--------------------------------------------------------------------------//
string Class::getType() const {
  return "class";
}

//--------------------------------------------------------------------------//
void Class::visit(Visitor& visitor) const {
  return visitor.visitClass(this);
}
