#include "class.hh"

Class::Class(char* n, Data* d, Method* m)
  : data(d), method(m)
{
	name = strdup(n);
}

Class::Class(Class* mere, char* n, Data* d, Method* m)
  : mere(mere), data(d), method(m)
{
	name = strdup(n);
}

Class::~Class() {
  if (data!=NULL) delete data;
  if (method!=NULL) delete method;
  if (mere!=NULL) delete mere;
}

void Class::visit(Visitor& visitor) const {
  return visitor.visitClass(this);
}
