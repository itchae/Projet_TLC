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
  if (name!=null) delete name;
  if (data!=null) delete data;
  if (method!=null) delete method;
  if (mere!=null) delete mere;
}

void Class::visit(Visitor& visitor) const {
  return visitor.visitBlock(this);
}
