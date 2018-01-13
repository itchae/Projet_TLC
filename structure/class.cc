#include "headers/class.hh"

/**--------------------------------------------------------------------------**/
Class::Class(char* n, Data* d, Method* m)
  : data(d), method(m)
{
	name = strdup(n);
}

/**--------------------------------------------------------------------------**/
Class::Class(Class* mere, char* n, Data* d, Method* m)
  : mere(mere), data(d), method(m)
{
	name = strdup(n);
  if (mere == NULL) throw invalid_argument("Classe mere");
}

/**--------------------------------------------------------------------------**/
Class::~Class() {
  if (data!=NULL) delete data;
  if (method!=NULL) delete method;
  if (mere!=NULL) delete mere;
}

/**--------------------------------------------------------------------------**/
bool Class::operator==(Class& rhs) const{
  if (name.compare(rhs.getName())==0) return true;
  return false;
}

/**--------------------------------------------------------------------------**/
void Class::visit(Visitor& visitor) const {
  return visitor.visitClass(this);
}
